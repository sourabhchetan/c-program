#include<stdlib.h>
#include<stdio.h>
int main()
{
    FILE *fp;
    char ch;
    fp=fopen("abc.txt","r+");
    if(fp==NULL)
    {
        exit(1);
    }
    fseek(fp,3,SEEK_SET);
    ch=fgetc(fp);
    printf("%c",ch);
    fclose(fp);
    return 0;
}