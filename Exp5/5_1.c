#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCOUNT 100
#define MAXLENGTH 51



int main()
{
    char buf[MAXLENGTH];    //用来存储读进来的字符串
    char longest[MAXLENGTH] = { '\0' };    //用来保存最长的字符串
    const char* target = "******";
    int cnt = 0;
    printf("Please enter strings: \n");
    for(cnt = 0; cnt < MAXCOUNT; ++cnt){
        gets(buf);
        if( strcmp(buf, target) == 0 )  //如果读到******，就不再读了，跳出循环
        {
            break;
        }
        if(strlen(buf) > strlen(longest)){
            strcpy(longest, buf);
        }
    }

    printf("%s\n", longest);


    return 0;
}

unsigned int myStrlen(char * str){
    char * p = str;
    for(p = str; *p != '\0'; ++p);
    return (unsigned int)(p - str);
}