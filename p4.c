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



#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 26

// Convert character to index (A=0, B=1, ...)
int charToIndex(char c) {
    return toupper(c) - 'A';
}

// Convert index back to character
char indexToChar(int idx) {
    return (idx % N) + 'A';
}

// Multiply matrix by vector (mod N)
void matVecMult(int mat[][3], int vec[], int res[], int size) {
    for (int i = 0; i < size; i++) {
        res[i] = 0;
        for (int j = 0; j < size; j++) {
            res[i] = (res[i] + (mat[i][j] * vec[j])) % N;
        }
    }
}

// Process message (encrypt/decrypt based on mode)
void processMsg(int mat[][3], char msg[], int size) {
    int len = strlen(msg);

    for (int i = 0; i < len; i += size) {
        int vec[3] = {0};
        int res[3] = {0};

        for (int j = 0; j < size; j++) {
            if (i + j < len) {
                vec[j] = charToIndex(msg[i + j]);
            }
        }

        matVecMult(mat, vec, res, size);

        for (int j = 0; j < size; j++) {
            if (i + j < len) {
                msg[i + j] = indexToChar(res[j]);
            }
        }
    }
}

int main() {
    int size, mat[3][3], invMat[3][3];
    char msg[100], encMsg[100], decMsg[100];

    printf("Enter matrix size (2 or 3): ");
    scanf("%d", &size);

    printf("Enter key matrix elements:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // For simplicity, we're directly entering the inverse matrix here.
    // In a real application, you'd calculate the inverse of the matrix.
    printf("Enter inverse key matrix elements:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &invMat[i][j]);
        }
    }

    printf("Enter the message: ");
    scanf("%s", msg);
    strcpy(encMsg, msg);

    // Encrypt the message
    processMsg(mat, encMsg, size);
    printf("Encrypted message: %s\n", encMsg);

    // Decrypt the message
    strcpy(decMsg, encMsg);
    processMsg(invMat, decMsg, size);
    printf("Decrypted message: %s\n", decMsg);

    return 0;
}
