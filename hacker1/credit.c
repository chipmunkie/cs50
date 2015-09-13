#include <stdio.h>
#include <cs50.h>
#include <math.h>

long long int GetCreditNumber()
/*Gets the credit card number from prompt.*/
{   
    long long int number;
    do
    {   
        printf("Type credit card number:");
        number = GetLongLong();
    } while (number < 0);
    return number;
}

int GetNumberOfDigits(long long int credit_card)
/*Gets the credit card's number length.*/
{
    long long int division = 0;
    int digits = 0;
    do
    {
        division = credit_card/10;
        credit_card = division;
        digits++;
    } while (division > 0);
    return digits;
}

int * MakeArray(int digits, long long int credit_card)
/*Separates the credit card number into digits with values 0-9.*/
{
    int* result = calloc(digits, sizeof(int)); 
    long long int division;
    int digit = 0;
    do
    {
        digit = credit_card%10;
        division = credit_card/10;
        result[digits-1] = digit;
        credit_card = division;
        digits--;
    } while(digits>0);
    return result;
}

int GetCheckSum(int digits, int * credit)
/*Gets the credit card number checksum.*/
{
    int i = 0;
    int offset = 0, standard = 0;
    do
    {
        standard += credit[digits-1-i];
        i += 2;
    } while (digits-1-i >= 0);
    i = 0;
    do
    {
        int temp;
        temp = credit[digits-2-i] * 2;
        offset += temp/10 + temp%10;
        i += 2;
    } while(digits-2-i >= 0);
    return standard + offset;
}

int TestCheckSum(int checksum)
/*Tests if checksum is valid.*/
{
    if (checksum%10 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void TestCard(int* credit, int checksum)
/*Tests the card is valid and returns the type.*/
{
    if (checksum == 0)
    {
        if (credit[0] == 4)
        {
            printf("VISA\n");
        }
        if (credit[0] == 3 && (credit[1] == 4 || credit[1] == 7))
        {
            printf("AMEX\n");
        }
        if (credit[0] == 5 && (credit[1] >= 1 && credit[1] <= 5))
        {
            printf("MASTERCARD\n");
        }
        if (credit[0] < 3 || credit[0] > 5)
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

int main(void)
{
    long long int credit_card = GetCreditNumber();
    int digits = GetNumberOfDigits(credit_card);
    int* credit;
    credit = MakeArray(digits,credit_card);
    int checksum = GetCheckSum(digits, credit);
    TestCard(credit, TestCheckSum(checksum));
    free(credit);
}
