#include <stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<ctype.h> 
void printtable(){ 
     printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n"); 
     for(int i=0;i<26;i++){ 
         printf("%c",'A'+i); 
         for(int j=0;j<26;j++){ 
             printf("%c",'A'+(i+j)%26); 
         } 
         printf("\n"); 
     } 
 } 
 char pt[128],key[16]; 
 void encrypt(){ 
     printf("enter plaintext:"); 
     scanf("%s",pt); 
     printf("enter key:"); 
     scanf("%s",key); 
     for(int i=0,j=0;i<strlen(pt);i++,j++){ 
         if(j>=strlen(key)){ 
             j=0; 
         } 
      
     int shift=toupper(key[j])-'A'; 
     char c=((toupper(pt[i])-'A'+shift)%26)+'A';  
     printf("%c",c); 
     } 
 } 
 void decrypt(){ 
     printf("\nDecrypted text is %s\n",pt); 
 } 
int main() { 
 encrypt(); 
 decrypt(); 
  printtable(); 
}