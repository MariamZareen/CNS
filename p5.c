#include<stdio.h>  
int IP[]={2,6,3,1,4,8,5,7}; 
int inverse[]={4,1,3,5,7,2,8,6}; 
int s0[4][4]={ 
{1,0,3,2},  
{3,2,1,0},  
{0,2,1,3},  
{3,1,3,2}  
}; 
int s1[4][4]={  
{0,1,2,3},  
{2,0,1,3},  
{3,0,1,0},  
{2,1,0,3}  
};  
int inital_perm(int pt){ 
    int res=0; 
    for(int i=0;i<8;i++){ 
        res|=((pt>>(8-IP[i]))&1)<<(7-i); 
    } 
    return res; 
} 
int inverse_inital(int ct){ 
    int res=0; 
    for(int i=0;i<8;i++){ 
        res|=((ct>>(8-inverse[i]))&1)<<(7-i); 
    } 
    return res; 
} 
int main(){ 
    int pt=0b10010111; 
    printf("Plaintext is %x\n",pt); 
    int ct=inital_perm(pt); 
    printf("Cipher text is %x\n",ct); 
    int decrypt=inverse_inital(ct); 
    printf("Decrypted text is %x\n",decrypt); 
    return 0; 
}