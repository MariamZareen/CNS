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





#include<stdio.h>
#include<string.h>
int res[2];
    int p4[]={2,4,3,1};
    int ep[]={4,1,2,3,2,3,4,1};
    int s0_mat[][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3}, {3,1,3,2}};
    int s1_mat[][4]={{0,1,2,3},{2,0,1,3}, {3,0,1,0}, {2,1,0,3}};

int toInt(int a,int b){
   if(a==0 && b==0) return 0;
   if(a==0 && b==1) return 1;
   if(a==1 && b==0) return 2;
   return 3;
}
void toBinary(int n){
   if(n==0) {
      res[0]=0;
      res[1]=0;
   }else if(n==1){
      res[0]=0;
      res[1]=1;
   }else if(n==2){
      res[0]=1;
      res[1]=0;
   }else{
     res[0]=1;
     res[1]=1;
   }
}
void s_round(int left_half[],int right_half[],int key[]){
    int after_ep[8];
    int row,col,s0,s1;
    for(int i=0;i<4;i++){
        int idx=ep[i];
        after_ep[i]=right_half[idx-1];
    }
    for(int i=4;i<8;i++){
        int idx=ep[i];
        after_ep[i]=right_half[idx-1];
    }

    for(int i=0;i<8;i++){
        after_ep[i]^=key[i];
    }
    int s[4];
    row=toInt(after_ep[0],after_ep[3]);
    col=toInt(after_ep[1],after_ep[2]);
    s0=s0_mat[row][col];
    toBinary(s0);

    s[0]=res[0];
    s[1]=res[1];

    row=toInt(after_ep[4],after_ep[7]);
    col=toInt(after_ep[5],after_ep[6]);
    s1=s1_mat[row][col];
    toBinary(s1);

    s[2]=res[0];
    s[3]=res[1];
    
    int after_p4[4];
    for(int i=0;i<4;i++){
        int idx=p4[i];
        after_p4[i]=s[idx-1];
    }

    for(int i=0;i<4;i++){
        left_half[i] ^=after_p4[i];
    }

}
void main(){
    char pt[8],ct[8];
    int ip[]= {2,6,3,1,4,8,5,7};
    int ip_inverse[]={4,1,3,5,7,2,8,6};
    int k1[]={1,0,1,0,0,1,0,0};
    int k2[]={0,1,0,0,0,0,1,1};


    printf("Enter 8 bit plain text: ");
    for(int i=0;i<8;i++)
    scanf("%d",&pt[i]);

    int after_ip[8], left_half[4],right_half[4];
    for(int i=0;i<8;i++){
        int idx=ip[i];
        after_ip[i]=pt[idx-1];
    }
    for(int i=0;i<4;i++){
        left_half[i]=after_ip[i];
    }
    for(int i=0;i<4;i++){
        right_half[i]=after_ip[i+4];
    }

    s_round(left_half,right_half,k1);

    //swap left and right half
    for(int i=0;i<4;i++){
        int temp=left_half[i];
        left_half[i]=right_half[i];
        right_half[i]=temp;
    }
    s_round(left_half,right_half,k2);

     //combine 2 half
     int after_two[8];
     for(int i=0;i<4;i++){
        after_two[i]=left_half[i];
     }
     for(int i=0;i<4;i++){
        after_two[i+4]=right_half[i];
     }


    // int after_ip_inverse[8];
    //applying ip inverse
    for(int i=0;i<8;i++){
       int idx=ip_inverse[i];
        ct[i]=after_two[idx-1];
    }
     printf("The cipher text is : \n");
     for(int i=0;i<8;i++){
        printf("%d",ct[i]);
     }

}

