#include<stdlib.h>
#include<stdio.h>
int main()
{
    FILE *fp;
    int x;
    char str[50];
    fp=fopen("abc.txt","r+");
    if(fp==NULL);
    {
        exit(1);
    }
    x=ftell(fp);
    printf("%d",x);
    fseek(fp,5,SEEK_SET);
    x=ftell(fp);
    printf("%d",x);
    fclose(fp);
    return 0;
}
