#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>


void action(){};



void player(char *name, int playerId, int fd)
{
    fd = open("sharedFile.bin", O_RDONLY);
    int points = 0, randomValue, oldScore[1];
    long int ss = 0;
    while (1)
    {
        signal(SIGUSR1, action);
        pause();
        printf("------------------------------------\n");
        
        if (playerId == 1) 
        {
            lseek(fd, 0, SEEK_SET);
            read(fd, oldScore, sizeof(int));
            printf("ONE: My current score is :: %d\n", oldScore[0]);
        }
        else if (playerId == 2) 
        {
            lseek(fd, sizeof(int), SEEK_SET);
            read(fd, oldScore, sizeof(int));
            printf("TWO: My current score is :: %d\n", oldScore[0]);
        }
        else 
        {
            lseek(fd, 2 * sizeof(int), SEEK_SET);
            read(fd, oldScore, sizeof(int));
            printf("THREE: My current score is :: %d\n", oldScore[0]);
        }
        close(fd);
        
        printf("%s: Generating my random number!\n", name);
        randomValue = (int)time(&ss) % 50 + 1;
        printf("%s: I got %d points\n", name, randomValue);
        
        int old = oldScore[0];
        oldScore[0] = old + randomValue;
        printf("%s: My score now is :: %d points\n------------------------------------\n\n", name, oldScore[0]);
        
        fd = open("sharedFile.bin", O_WRONLY);
        if (playerId == 1) 
        {
            lseek(fd, 0, SEEK_SET);
            write(fd, oldScore, sizeof(int));
        }
        else if (playerId == 2) 
        {
            lseek(fd, sizeof(int), SEEK_SET);
            write(fd, oldScore, sizeof(int));
        }
        else 
        {
            lseek(fd, 2 * sizeof(int), SEEK_SET);
            write(fd, oldScore, sizeof(int));
        }
        close(fd);
        
        sleep(3);
        kill(getppid(), SIGUSR1);
    }
}

void checkWinner(int fd, char *name)
{
    int currentScore[1];
    
    read(fd, currentScore, sizeof(int));
    printf("\n");
    
    if (strcmp(name, "ONE") == 0)
        printf("Referee: Player ONE's current score :: ");
    else if (strcmp(name, "TWO") == 0)
        printf("Referee: Player TWO's current score :: ");
    else
        printf("Referee: Player THREE's current score :: ");
    printf("%d\n", currentScore[0]);
    sleep(3);
    
    if (currentScore[0] >= 100)
    {
        printf("\n------------GAME OVER--------------\n\n------------------------------------\n");
        printf("Referee: Player %s won the game!!!!\n------------------------------------\n\n", name);
        kill(0, SIGTERM);
    }
}


int main(int argc, char *argv[])
{
    int fd;
    pid_t pid1, pid2, pid3;
    printf("------------------------------------------------------------------------------------------------\nHello there! Welcome to the Random Number Game: a 3-player game, with another process being the mediator/referee that keeps scores!\nEach player is a process.\nEach one of the player processes generates a random number turn after turn.\nThe referee process keeps track of these scores, and declares a winner once one of the players cross 100 points!\n------------------------------------------------------------------------------------------------\n\n");
    sleep(5);

    
    if ((fd = open("sharedFile.bin", O_CREAT | O_WRONLY | O_TRUNC, 0777)) == -1)
    {
        perror("Uh oh, The sharedFile.bin coukd not open, File problem, Check what you're doing wrong oops.\n\n");
        exit(1);
    }
    else
    {
        
        int threeZeros[3];
        threeZeros[0] = 0;
        threeZeros[1] = 0;
        threeZeros[2] = 0;
        write(fd, threeZeros, 3 * sizeof(int));
        close(fd);
    }

    
    if ((pid1 = fork()) == 0)
        player("ONE", 1, fd);
    if ((pid2 = fork()) == 0)
        player("TWO", 2, fd);
    if ((pid3 = fork()) == 0)
        player("THREE", 3, fd);
    sleep(1);
    signal(SIGUSR1, action);
    while (1)
    {
        
        fd = open("sharedFile.bin", O_RDONLY);
        checkWinner(fd, "ONE");
        printf("Referee: Player ONE plays\n\n");
        kill(pid1, SIGUSR1);
        pause();
        checkWinner(fd, "TWO");
        printf("Referee: Player TWO plays\n\n");
        kill(pid2, SIGUSR1);
        pause();
        checkWinner(fd, "THREE");
        printf("Referee: Player THREE plays\n\n");
        kill(pid3, SIGUSR1);
        pause();
    }
}
