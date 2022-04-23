
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_valid(long input);
const char *card_brand(long input);

int main(void)
{
    long card = get_long("Number:\n");
    if (is_valid(card))
    {
        printf("%s\n", card_brand(card));
    }
    else
    {
        printf("INVALID\n");
    }
}

const char *card_brand(long input)
{
    char str[256];
    sprintf(str, "%ld", input);
    int second = (int)str[1] - 48;
    if (str[0] == '4')
    {
        return "VISA";
    }
    else if (str[0] == '5' && (second > 0 && second < 6))
    {
        return "MASTERCARD";
    }
    else if (str[0] == '3' && (second == 4 || second == 7))
    {
        return "AMEX";
    }
    else
    {
        return "INVALID";
    }
}

bool is_valid(long input)
{
    char str[256];
    sprintf(str, "%ld", input);

    int len = strlen(str);

    if (len > 16 || len < 13)
    {
        printf("INVALID\n");
        exit(0);
    }
    int products = 0;
    int sums = 0;
    int i = len - 2;
    char results[5];
    while (i >= 0)
    {
        int temp = 2 * ((int)str[i] - 48);
        sprintf(results, "%i", temp);
        int j = 0;
        while (j < strlen(results))
        {
            products += (int)results[j] - 48;
            j ++;
        }
        i -= 2;
    }
    int j = len - 1;
    while (j >= 0)
    {
        int temp = (int)str[j] - 48;
        sums += temp;
        j -= 2;
    }
    return (((sums + products) % 10) == 0);
}
//still not ready
long get_long(char *input)
{
    do
    {
        scanf("insert a long number: %lld", input);
        long output = (long)input;
        if ((long)output != NULL)
        {
            break;
            return output;
        }
    } while (true);
    
    
}