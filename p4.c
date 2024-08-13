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
void processMsg(int mode, int mat[][3], char msg[], int size) {
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
    int size, mat[3][3];
    char msg[100], encMsg[100], decMsg[100];

    printf("Enter matrix size (2 or 3): ");
    scanf("%d", &size);

    printf("Enter key matrix elements:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Enter the message: ");
    scanf("%s", msg);
    strcpy(encMsg, msg);
   
    processMsg(1, mat, encMsg, size);
    printf("Encrypted message: %s\n", encMsg);


    printf("Decrypted message: %s\n", msg);

    return 0;
}
