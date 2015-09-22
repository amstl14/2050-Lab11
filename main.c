#include <string.h>
#include <stdio.h>
#include "parser.h"

#define MAX_LINE 250

/****************************************************************************
 
                                MAIN FUNCTION
 
 
 ****************************************************************************/



int main(int argc,char** argv) {
 
    if(argc != 2){
        printf("Use: ./lab11 <file.txt>\n");
    }
    
    FILE* fp = fopen(argv[1],"r");
    
    if(fp == NULL){
        
        printf("Failed to open the selected file.\n");
        return 0;
    }
    
    char buff[MAX_LINE+1];
    
    while(fgets(buff,MAX_LINE,fp)){
        
        if(buff[strlen(buff)-1] == '\n'){
            buff[strlen(buff)-1] = '\0';
        }
        
        char* token = strtok(buff," \n\r\t");
        while(token != NULL){
            
            if(is_phone_number(token))
            {
                printf("\nPhone Number: %s",token);
            }
            else if(is_date(token)){
                printf("    Date: %s",token);
            }
            else if(looks_like_name(token)){
                
                char* nextName = strtok(NULL," \n\r\t");
                
                if(looks_like_name(nextName)){
                    printf("Name:%s %s\n",nextName,token);
                }
                else token = nextName;
            }
            
            else if(is_email(token)){
                printf("\nEmail: %s\n",token);
            }
            
            token = strtok(NULL," \n\r\t");
        }
        
    }
    
    fclose(fp);
    return 0;
}