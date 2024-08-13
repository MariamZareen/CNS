//pg5
#include<stdio.h>
#include<string.h>
int result[2];
int to_digit(int a, int b)
{
    int output;
    if(a==1 && b==1)  output = 3;
    if(a==0 && b==1)  output = 1;
    if(a==1 && b==0)  output = 2;   
    if(a==0 && b==0)  output = 0;
    return output;
}
void to_binary(int num)
{
    if(num == 3) {
            result[0] = 1;
            result[1] = 1;
    }
     else if(num == 1) {
        result[0] = 0;
        result[1] = 1;
    }
    else if(num == 2) {
        result[0] = 1;
        result[1] = 0;
    }
    else if(num == 0) {
            result[0] = 0;
            result[1] = 0;
    }
}
void main()
{
    int i,j,index;
    int s0=0,s1=0,row=0, col=0;
    int s0_binary[2], s1_binary[2];
    int pt[8];

    int k1[8]={1,0,1,0,0,1,0,0};
    int k2[8]={0,1,0,0,0,0,1,1};  
    int ip[8]={2,6,3,1,4,8,5,7},ep[8]={4,1,2,3,2,3,4,1},p4[4]={2,4,3,1},ipinverse[8]={4,1,3,5,7,2,8,6};
    int s_matrix0[4][4] = { {1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2} };
    int s_matrix1[4][4] = { {0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3} };
    
    int after_ip[8], after_ep[8], after_p4[4];
    int S[4], S1[4];
    int left_after_ip[4], right_after_ip[4];
    int left_after_one[4], right_after_one[4];
    int after_ip_inverse[8];
    int after_one[8], after_two[8];

    printf("\n---->Enter the 8-bit plaintext : ");
    for(i=0; i<8; i++)
        scanf("%d",&pt[i]);

    for(i=0; i<8; i++) {
        index = ip[i];
        after_ip[i] = pt[index - 1];
    }
   
    for(j=0; j<4; j++)
        left_after_ip[j] = after_ip[j];

    for(j=0; j<4; j++)
        right_after_ip[j] = after_ip[j+4];

    for(i=0; i<4; i++) {
        index = ep[i];
        after_ep[i] = right_after_ip[index - 1];
    }

    for(i=4; i<8; i++) {
        index = ep[i];
        after_ep[i] = right_after_ip[index - 1];
    }
   
    for(i=0; i<8; i++)
        k1[i] = k1[i] ^ after_ep[i];
  
//left part of key1
    row = to_digit(k1[0],k1[3]);
    col = to_digit(k1[1],k1[2]);
    s0 = s_matrix0[row][col];

    to_binary(s0);
    for(j=0; j<2; j++)
        s0_binary[j] = result[j];
       
//right part of key1
    row = to_digit(k1[4],k1[7]);
    col = to_digit(k1[5],k1[6]);

    s1 = s_matrix1[row][col];

    to_binary(s1);
    for(j=0; j<2; j++)
        s1_binary[j] = result[j];

    for(j=0; j<2; j++)
        S[j] = s0_binary[j];

    for(i=0,j=2; i<2,j<4; i++,j++)
        S[j] = s1_binary[i];

    for(i=0; i<4; i++) {
        index = p4[i];
        after_p4[i] = S[index - 1];
    }

    for(i=0; i<4; i++)
        after_p4[i] = after_p4[i] ^ left_after_ip[i];

    for(i=0; i<4; i++)
        after_one[i] = right_after_ip[i];

    for(i=0,j=4; i<4,j<8; i++,j++)
        after_one[j] = after_p4[i];

//same after ep
    for(j=0; j<4; j++)
        left_after_one[j] = after_one[j];

    for(j=0; j<4; j++)
        right_after_one[j] = after_one[j+4];

    for(i=0; i<4; i++) {
        index = ep[i];
        after_ep[i] = right_after_one[index - 1];
    }

    for(i=4; i<8; i++) {
        index = ep[i];
        after_ep[i] = right_after_one[index - 1];
    }
   
    for(i=0; i<8; i++)
        k2[i] = k2[i] ^ after_ep[i];

    row = to_digit(k2[0],k2[3]);
    col = to_digit(k2[1],k2[2]);
    s0 = s_matrix0[row][col];
    to_binary(s0);

    for(j=0; j<2; j++)
        s0_binary[j] = result[j];

    row = to_digit(k2[4],k2[7]);
    col = to_digit(k2[5],k2[6]);
    s1 = s_matrix1[row][col];
    to_binary(s1);

    for(j=0; j<2; j++)
        s1_binary[j] = result[j];

    for(j=0; j<2; j++)
        S1[j] = s0_binary[j];

    for(i=0,j=2; i<2,j<4; i++,j++)
        S1[j] = s1_binary[i];

    for(i=0; i<4; i++) {
        index = p4[i];
        after_p4[i] = S1[index - 1];
    }

    for(i=0; i<4; i++)
        after_p4[i] = after_p4[i] ^ left_after_one[i];

    for(i=0; i<4; i++)
        after_two[i] = after_p4[i];

    for(i=0,j=4; i<4,j<8; i++,j++)
        after_two[j] = right_after_one[i];

    for(i=0; i<8; i++)
    {
        index = ipinverse[i];
        after_ip_inverse[i] = after_two[index - 1];
    }   
    printf("\n\n--->8-bit Ciphertext will be= ");
    for(i=0; i<8; i++)
        printf("%d ", after_ip_inverse[i]);
}
