#include <string.h>
#include <stdio.h>

void table()
{
    printf("  ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    printf("----------------------------\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%c", 'A' + i);
        printf("|");
        for (int j = 0; j < 26; j++)
        {
            printf("%c", 'A' + (i + j) % 26);
        }
        printf("\n");
    }
}

char pt[128], key[16], e1[128];
void encry()
{
    printf("\nenter pt: ");
    fgets(pt, sizeof(pt), stdin);
    //pt[strcspn(pt, "\n")] = 0;
    if(pt[strlen(pt)-1]=='\n')
    pt[strlen(pt)-1]='\0';

    printf("\nenter key: ");
    scanf("%s", key);

    for (int i = 0, j = 0; i < strlen(pt); i++)
    {

        if (pt[i] == ' ')
        {
            e1[i] = ' ';
            continue;
        }

        if (j >= strlen(key))
            j = 0;

        int shift = toupper(key[j]) - 'A';
        char c;
        if (isupper(pt[i]))
        {
            c = ((pt[i] - 'A' + shift) % 26) + 'A';
        }
        else
        {
            c = ((pt[i] - 'a' + shift) % 26) + 'a';
        }
        e1[i] = c;
        j++;
    }
    e1[strlen(pt)] = '\0';
    printf("\nencry txt: %s", e1);
}

void decry()
{
    char d1[128];
    for (int i = 0, j = 0; i < strlen(e1); i++)
    {

        if (e1[i] == ' ')
        {
            d1[i] = ' ';
            continue;
        }
        if (j >= strlen(key))
            j = 0;

        int shift = toupper(key[j]) - 'A';
        char c;
        if (isupper(e1[i]))
        {
            c = ((e1[i] - 'A' - shift + 26) % 26) + 'A';
        }
        else
        {
            c = ((e1[i] - 'a' - shift + 26) % 26) + 'a';
        }
        d1[i] = c;
        j++;
    }
    d1[strlen(e1)] = '\0';
    printf("\ndecry txt: %s", d1);
}

int main()
{
    table();
    encry();
    decry();
    return 0;
}
