#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


const char delimiter[2] = " ";


int main(int argc, string argv[])
{
    string p = GetString();
    if (strlen(p) < 1)
    { 
        return 1;
    } 
    char* token;
    token = strtok(p, delimiter);
    while (token != NULL)
    {   
        printf("%c", toupper(token[0]));
        token = strtok(NULL, delimiter);
    } 
    printf("\n");
    return 0;
} 
