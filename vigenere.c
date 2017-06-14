
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error in giving input!!\n");
        return 1;
    }
    else
    {
        string key = argv[1];
        int keyLength = strlen(key);
        int j = 0,c=0;
        
        for(int i = 0 ; i < keyLength ; i++)
        {
            if (isalpha(key[i]))
            {
                continue;
            }
            else
            {
                printf("Error in giving input!!\n");
                return 1;
            }
        }
        printf("plaintext: ");
        string plain = get_string();
         
        printf("ciphertext: ");
        for(int i = 0 ; i < strlen(plain); i++)
        {
            int rotate = j % keyLength;
            if (isupper(plain[i]) && isalpha(plain[i]))
            {
                if (isupper(key[rotate]))
                {
                    c = (plain[i] - 65 + key[rotate] - 65) % 26; 
                    printf("%c", c + 65);
                }
                else 
                {
                    c= (plain[i] - 65 + key[rotate] - 97) % 26; 
                    printf("%c", c+ 65);
                }
                j++;
            }
            else if (islower(plain[i]) && isalpha(plain[i]))
            {
                if (isupper(key[rotate]))
                {
                    c= (plain[i] - 97 + key[rotate] - 65) % 26; 
                    printf("%c", c+ 97);
                }
                else 
                {
                    c= (plain[i] - 97 + key[rotate] - 97) % 26; 
                    printf("%c", c+ 97);
                }
                j++;
            }
            else
                printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}