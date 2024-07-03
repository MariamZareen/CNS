#include<stdio.h>  
#include<string.h>  
#include<ctype.h>  
  
int main(){  
    unsigned int a[3][3]={{2,7,8},{8,4,13},{15,17,6}};  
    unsigned int b[3][3]={{3,2,9},{7,6,8},{16,17,20}};  
    int i,j,t=0;  
    unsigned int c[20],d[20];  
    char msg[20];  
      
    printf("\n Enter the plain text(in capitals):");  
    scanf("%s",msg);  
    for(i=0;i<3;i++){  
        c[i]=toupper(msg[i])-65;  
        printf("%d",c[i]);  
    }  
 
    for(i=0;i<3;i++){  
        t=0;  
        for(j=0;j<3;j++){  
            t+=(a[i][j]*c[j]);  
        }  
        d[i]=t%26;  
    }  
      
    printf("\n Encrypted Cipher text is:");  
    for(i=0;i<3;i++){  
        printf("%c",d[i]+65);  
    }  
      
  
    for(i=0;i<3;i++){  
        t=0;  
        for(j=0;j<3;j++){  
            t+=(b[i][j]*d[j]);  
        }  
        c[i]=t%26;  
    }  
      
    printf("\n Decrypted cipher text is:");  
    for(i=0;i<3;i++){  
        printf("%c",c[i]+65);  
    }  
    return 0;  
}  