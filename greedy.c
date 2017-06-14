#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    float change=0;
    do{
    printf("how much change is owed?\n");

    change = get_float();
    
    }while(change<0);
    
    int c = 0;
    
    float cent = round(change * 100);
    
    while(cent != 0)
    {
        if (cent >= 25)
        {
            cent-=25;
            c++;
        }
        else if (cent >= 10)
            {
            cent-=10;
            c++;
        }
        else if(cent >= 5)
        {
            cent-=5;
            c++;
        }
        else
        {
            cent-=1;
            c++;
        }
    }
    printf("%i\n", c);
}