#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

/****************************************************************************
 
                       IS PHONE NUMBER FUNCTION
 
 
 ****************************************************************************/


int is_phone_number(char* word){
    if(strlen(word)!=14){
        return 0;
    }
    else if(*word!='('||*(word+4)!=')'||*(word+5)!='-'||*(word+9)!='-'){
        return 0;
    }
    int i;
    for(i=0;i<14;i++){
        if(i==0||i==4||i==5||i==9){
            continue;
    }
    else if(*(word+i)>57||*(word+i)<48){
        return 0;
    }
    }
    return 1;
}

/****************************************************************************
 
                            IS DATE FUNCTION
 
 
 ****************************************************************************/


int is_date(char* word){
    int validDays[]={31,28,31,30,31,30,31,31,30,31};
    int i=1;
    //if the length is not 10
    if(strlen(word)!=10){
        return 0;
    }
        else if(*(word+2)!='/'||*(word+5)!='/'){
            return 0;
    }
    char* month=malloc(sizeof(char)*3);
    *month=*(word);
    *(month+1)=*(word+1);
    int Newmonth=atoi(month);
    if(Newmonth<1||Newmonth>12){
        return 0;
    }
    char* day=malloc(sizeof(char)*3);
    *day=*(word+3);
    *(day+1)=*(word+4);
    int Newday=atoi(day);
    if(Newday>validDays[Newmonth-1]){
        return 0;
    }
    return 1;
}

/****************************************************************************
 
                         LOOKS LIKE NAME FUNCTION
 
 
 ****************************************************************************/


int looks_like_name(const char* word){
    int i;
    if(*word<65||*word>90){
        return 0;
    }
    else if(strlen(word)<=1){ //ASCII
        return 0;
    }
    for(i=1;i<strlen(word);i++){
        if(*(word+i)<97||*(word+i)>122){
            return 0;
        }
    }
    return 1;
}

/****************************************************************************
 
                                IS EMAIL FUNCTION
 
 
 ****************************************************************************/

int is_email(char* word){
    int length=strlen(word);
    int temp=0;
    if(*(word+length-4)!='.'||*(word+length-3)!='c'||*(word+length-2)!='o'||*(word+length-1)!='m'){
        return 0;
    }
    int i;
    for(i=0;i<length-4;i++){
        if(*(word+i)=='@'){
            temp=1;
            continue;
        }
        else if((*(word+i)>90&&*(word+i)<97)||*(word+i)>122||(*(word+i)>57&&*(word+i)<65)||*(word+i)<48){
                return 0;
        }
    }
    if(temp==0){
        return 0;
    }
    return 1;
}