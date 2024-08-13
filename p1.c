//pg1
#include<stdio.h>
#include<string.h>

int plen(char *p){
    int len=0;
    while(p[len]!='\0')
    len++;
    return len;
}
int main(){
    char p[100];
    printf("enter string: ");
    fgets(p,sizeof(p),stdin);
    
  if(p[plen(p)-1]=='\n')
  p[plen(p)-1]='\0';
    
    printf("\nafter performing and op\n");
    for(int i=0; p[i]!='\0'; i++){
        printf("%c = %d", p[i], p[i] & 127);
        printf("\n");
    }
    
    printf("\nafter performing or op\n");
    for(int i=0; p[i]!='\0'; i++){
        printf("%c = %d", p[i], p[i] | 127);
        printf("\n");
    }
    
    printf("\nafter performing xor op\n");
    for(int i=0; p[i]!='\0'; i++){
        printf("%c = %d", p[i], p[i] ^ 127);
        printf("\n");
    }
    
    return 0;
}
