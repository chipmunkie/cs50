#include <stdio.h>
#include <cs50.h>
#include <math.h>

const int quarter = 25;
const int dime = 10;
const int penny = 5;
const int nickel = 1;
const int coins[4] = {quarter, dime, penny, nickel};

float ReadChange()
{
    float change;
    do
    {
        printf("How much change is owned?\n");
        change = GetFloat();
    } while (change < 0);
    return change;
}

int ConvertChangeToCents(float change)
{
    return round(change * 100);
}

int GetUnits(int coin, int cents)
{
    int counter = 0;
    do
    {
        cents = cents - coin;
        counter++;

    } while (cents >= coin);
    return counter;
}


int GetCoinUnits(int coin, int cents)
{
    int units;
    if (cents < coin)
    {
        return 0;
    }
    else 
    {
        units = GetUnits(coin,cents);
    }
    return units;
}

int GetRest(int coin, int units, int cents)
{
    return cents - (coin * units);
}

int main(void)
{
    int sum = 0;
    float change = ReadChange();
    int cents = ConvertChangeToCents(change);
    int coin_units[4];
    for (int i = 0; i < 4; i++)
    {
        coin_units[i] = GetCoinUnits(coins[i], cents);
        cents = GetRest(coins[i], coin_units[i], cents);
    }
    for (int i = 0; i < 4; i++)
    {
        sum = sum + coin_units[i];
    }
    printf("%i\n", sum);

}
