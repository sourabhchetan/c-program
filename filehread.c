#include<stdlib.h>
#include<stdio.h>
int main()
{
    FILE *fp;
    char ch;
    fp = fopen("abc.txt","r");
    if(fp==NULL)
    {
        printf("Error");
        exit(1);
    }
    ch = fgetc(fp);
    printf("%c",ch);
    rewind(fp);
    ch=fgetc(fp);
    printf("%c",ch);
    fclose(fp);
    return 0;
}