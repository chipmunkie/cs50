include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

const int upper = 65;
const int lower = 97;

int CalculateKey(int key)
{
    if (key >= 65 && key <= 90)
    {
        return key - upper;
    }
    else
    {
        if (key >= 97 &&  key <= 122)
        {
            return key - lower;
        }
        else
        {
            return key;
        }
    }
}

bool IsChar(int key)
{
    if (key >= 65 && key <= 90)
    {
        return true;
    }
    else
    {
        if (key >= 97 && key <= 122)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

int main(int argc, string argv[])
{
    char* keyword;
    if (argc == 2)
    {
        keyword = (char *) malloc(strlen(argv[1]));
        strcpy(keyword, argv[1]);
        for (int i = 0, n = strlen(keyword); i < n; i++)
        {
            if (IsChar(keyword[i]) == false)
            {
                printf("Keyword must be only A-Z and a-z");
                return 1;
            }
        }
    }
    else
    {
        printf("No keyword given.\n");
        return 1;
    }
    string p = GetString();
    int j = 0;
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (IsChar(p[i]) == true)
        {
            if (p[i] >= 65 && p[i] <= 90)
            {
                p[i] = ((p[i] - upper) + CalculateKey(keyword[j])) % 26 + upper;
            }
            if (p[i] >= 97 &&  p[i] <= 122)
            {
                p[i] = ((p[i] - lower) + CalculateKey(keyword[j])) % 26 + lower;
            }
            if (j == strlen(keyword) -1)
            {
                j = 0;
            }
            else
            {
                j++;
            }
        }
    }
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        printf("%c", p[i]);
    }
    printf("\n");
    return 0;
}
