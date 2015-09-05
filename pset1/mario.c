#include <stdio.h>
#include <cs50.h>

int ReadHeight()
    /*Retrieves the pyramid height from prompt.
     *
     * The reader has 5 retries to give a correct height for the pyramid,
     * a positive integer lower than 24.
     *
     * Returns an integer.*/
{
    int retry_counter = 5;
    int height;
    do
    {
        printf("\nHeight:");
        height = GetInt();
        if (height < 0 || height > 23)
        {
            retry_counter--;
            printf("Number of retries left: %d \n", retry_counter);
        }
    } while ((height < 0 || height > 23) && retry_counter > 0);
    if (height > 0 && height < 24)
    {
        return height;
    }
    else 
    {
        return 0;
    }
}

int main(void)
    /*Prints the pyramid on the screen.*/
{
    int i, height, empty_space;
    int hash_counter = 2;
    int height_counter;
    height = ReadHeight();
    empty_space = height - 1;
    hash_counter = 2;
    height_counter = 0;
    while (height_counter < height)
    {
        for(i = 0; i < empty_space; i++)
        {
            printf(" ");
        }
        for(i = 0; i < hash_counter; i++)
        {
            printf("#");
        }
        printf("\n");
        empty_space = empty_space - 1;
        hash_counter++;
        height_counter++;
    }

}
