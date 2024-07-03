#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
char str[100]; 
void encrypt(char *str,int rails){ 
    printf("enter message:"); 
    scanf(" %[^\n]", str);  
    printf("enter no of rails:"); 
    scanf("%d",&rails); 
    int i,j=0,len,count=0,code[100][1000]; 
    len=strlen(str); 
    for(int i=0;i<rails;i++){ 
        for(int j=0;j<len;j++){ 
            code[i][j]=0; 
        } 
    } 
    while(j<len){ 
        if(count%2==0){ 
            for( i=0;i<rails;i++){ 
                if(j<len){ 
                    code[i][j]=(int)str[j]; 
                } 
                j++; 
            } 
            } 
            else{ 
                for(i=rails-2;i>0;i--){ 
                    if(j<len){ 
                    code[i][j]=(int)str[j]; 
                } 
                j++; 
                } 
            } 
            count++; 
        } 
        printf("Railfence pattern\n"); 
        for(int i=0;i<rails;i++){ 
            for(int j=0;j<len;j++){ 
                if(code[i][j]!=0){ 
                    printf("%c",code[i][j]); 
                } 
                else{ 
                    printf(" "); 
                } 
            } 
            printf("\n"); 
        } 
        printf("Encrypted text:"); 
        for(int i=0;i<rails;i++){ 
            for(int j=0;j<len;j++){ 
                if(code[i][j]!=0){ 
                    printf("%c",(char)code[i][j]); 
                } 
            } 
        } 
        printf("\n"); 
    } 
void decrypt(){ 
    printf("Decrypted text:%s",str); 
} 
int main(){ 
    int rails; 
    encrypt(str,rails); 
    decrypt(); 
} 