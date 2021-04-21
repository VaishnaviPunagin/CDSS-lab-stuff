#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
FILE *fp;
int i,addrl,l,j,staddrl;
char name[10],line[50],namel[10],addr[10],rec[10],ch,staddr[10];
printf("enter program name:");
scanf("%s",name);
fp=fopen("abssrc.txt","r");
fscanf(fp,"%s",line);
for(i=2,j=0;i<8,j<6;i++,j++)
namel[j]=line[i];
namel[i]='\0';
printf("name from obj.%s\n",namel);
if(strcmp(name,namel)==0)
{
	do{
		fscanf(fp,"%s",line);
		if(line[0]=='T'){
			for(i=2,j=0;i<8,j<6;i++,j++)
				staddr[j]=line[i];
				staddr[j]='\0';
				staddrl=atoi(staddr);
				i=12;
		while(line[i]!='$')
		{
		if(line[i]!='^')
		{
		printf("00%d\t%c%c\n",staddrl,line[i],line[i+1]);
		staddrl++;
		i=i+2;
		}
		else
			 i++;
		}}
	else if(line[0]='E')
	fclose(fp);
	}
	while(!feof(fp));
}
}
