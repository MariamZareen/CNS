#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char pt[100];

void encry(char *pt,int rail){
printf("\nenter pt: ");
scanf("%[^\n]",pt);
printf("enter no. of rails: ");
scanf("%d",&rail);

int i,j=0,count=0,code[100][1000];
int len=strlen(pt);
for(int i=0;i<rail;i++){
    for(int j=0;j<len;j++){
        code[i][j]=0;
    }
}

j=0;
while(j<len){
    if(count%2==0){
        for(int i=0;i<rail;i++){
            if(j<len)
           code[i][j]=(int)pt[j];
            j++;
        }
    }else{
       for(int i=rail-2;i>0;i--){
            if(j<len)
            code[i][j]=(int)pt[j];

           j++;
        }
    }
    count++;
}
printf("\nrailfence pattern: \n");
for(int i=0;i<rail;i++){
    for(int j=0;j<len;j++){
        if(code[i][j]!=0)
        printf("%c",code[i][j]);
        else{
printf(" ");
        }
    }
    printf("\n");
}
printf("\nencrypted msg: ");
for(int i=0;i<rail;i++){
    for(int j=0;j<len;j++){
        if(code[i][j]!=0)
        printf("%c",(char)code[i][j]);      
    }  
}
}

void decry(){
    printf("\ndecrypted txt: %s",pt);
}

int main(){
    int rail=0;
    encry(pt,rail);
    decry();
    return 0;
}
