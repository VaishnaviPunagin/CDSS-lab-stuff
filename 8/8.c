#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    int i,j,staddr1;
    char name[10],line[50],name1[10],staddr[10];
    printf("enter program name:" );
    scanf("%s",name);
    fp=fopen("abssrc.txt","r");
    fscanf(fp,"%s",line);
    for(i=2,j=0;i<8,j<6;i++,j++)
        name1[j]=line[i];
    name1[j]='\0';
    printf("name from obj. %s\n",name1);
    if(strcmp(name,name1)==0)
    {
        do
        {
            fscanf(fp,"%s",line);
            if(line[0]=='T')
            {
                for(i=2,j=0;i<8,j<6;i++,j++)
                    staddr[j]=line[i];
                staddr[j]='\0';
                staddr1=atoi(staddr);
                i=12;
                while(line[i]!='$')
                {
                    if(line[i]!='^')
                    {
                        printf("00%d \t %c%c\n", staddr1,line[i],line[i+1]);
                        staddr1++;
                        i=i+2;
                    }
                    else i++;
                }
            }
            else if(line[0]='E')
                fclose(fp);
        }while(!feof(fp));
    }
    return 0;
}
