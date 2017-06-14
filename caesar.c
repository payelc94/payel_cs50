#include <cs50.h>
#include<stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error in given input!!\n");
        return 1;
    }
    else
    {
        int c;
        int k = atoi(argv[1]);
        
        if(k<0)
        {
            printf("enter a positive number");
            return 0;
        }
        printf("plaintext: ");
        string plaintext=get_string();
        printf("ciphertext: ");
        
        for(int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isalpha(plaintext[i]) && isupper(plaintext[i]))
            {
                c = (plaintext[i] - 65 + k) % 26;
                printf("%c", c + 65);
            }
            else if (isalpha(plaintext[i]) && islower(plaintext[i]))
            {
                c = (plaintext[i] - 97 + k) % 26;
                printf("%c", c + 97);
            }
            else
                printf("%c",plaintext[i]);
        }
        printf("\n");
        return 0;
    }
}