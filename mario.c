#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("the height is:");
    while(true)
    {
    int n = get_int();
    if (n < 0 || n > 23)
    {
        printf("the height should be between 0 and 23");
    }
    else
    {
        int k = 2;
        int space = n;
        for(int i = n; i > 0; i--)
        {
            for(int j = 1;j < space; j++)
            {
                printf(" ");
            }
            space--;
            for(int j = 0; j < k; j++)
            {
                printf("#");
            }
            k++;
            printf("\n");
        }
        break;
    }
    }
}