#include <stdio.h>

#define TAB_LENGTH 8

int main(void)
{
    int c;
    unsigned int num_of_spaces;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            num_of_spaces = TAB_LENGTH;

            while(num_of_spaces)
            {
                putchar(' ');
                --num_of_spaces;
            }
        } else {
            putchar(c);
        }
    }

    return 0;
} 