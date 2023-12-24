#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE* fptr = NULL;
    fptr = fopen("test.txt", "w");
    if(fptr == NULL)
    {
        puts("Fail to open test.txt file\n");
        exit(0);
    }
    else
    {
        puts("test.txt file created.\n");
        puts("Enter the String:\n");
        char str[100] = {0};
        while(1)
        {
            fgets(str,sizeof(str), stdin);
            if(strncmp(str,"exit",4)==0)
            {
                break;
            }
            fputs(str, stdout);
        }
    }
    fclose(fptr);
    return 0;
}

//----------------------------------------
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

int main()
{
    int fd = open("test.txt", O_CREAT|O_RDWR, 0777);
    if(fd==-1)
    {
        perror("Error opening file");
        return 1;
    }

    char buf[100];
    int rdlen, wrlen;
    while(1)
    {
        rdlen = read(0, buf, 100);
        if(rdlen==-1)
        {
            perror("Error reading file");
            return -1;
        }
        int flg = strncmp(buf, "end", rdlen-1);
        if(flg==0)
        {
            break;
        }
        wrlen = write(fd, buf, rdlen);
        if(wrlen==-1)
        {
            perror("Error writing to the file");
            return 1;
        }
    }
    close(fd);

    int nfd = open("test.txt", O_RDONLY);
    if(nfd==-1)
    {
        perror("Error opening file");
        return 1;
    }
    while(1)
    {
        rdlen = read(nfd, buf, 100);
        if(rdlen==-1)
        {
            perror("Error reading file");
            return 1;
        }
        if(rdlen==0)
        {
            break;
        }
        write(1, buf, rdlen);
    }
    close(nfd);
    return 0;
}