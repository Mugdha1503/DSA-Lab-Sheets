#include <stdio.h>
#include <string.h>
void less_than_thousand(int num, char *result)
{
    const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if (num < 10)
        strcat(result, ones[num]);
    else if (num >= 11 && num <= 19)
        strcat(result, teens[num - 10]);
    else if (num < 100)
    {
        strcat(result, tens[num / 10]);
        if (num % 10 != 0)
        {
            strcat(result, " ");
            strcat(result, ones[num % 10]);
        }
    }
    else
    {
        strcat(result, ones[num / 100]);
        strcat(result, " hundred");
        if (num % 100 != 0)
        {
            strcat(result, " ");
            less_than_thousand(num % 100, result);
        }
    }
}
void number_to_words(long long num, char *result)
{
    if (num == 0)
    {
        strcat(result, "zero");
        return;
    }
    if (num >= 1000000000)
    {
        less_than_thousand(num / 1000000000, result);
        strcat(result, " billion ");
        num %= 1000000000;
    }
    if (num >= 1000000)
    {
        less_than_thousand(num / 1000000, result);
        strcat(result, " million ");
        num %= 1000000;
    }
    if (num >= 1000)
    {
        less_than_thousand(num / 1000, result);
        strcat(result, " thousand ");
        num %= 1000;
    }
    if (num > 0)
        less_than_thousand(num, result);
}
int main()
{
    long long n;
    scanf("%lld", &n);
    char result[1000] = "";
    number_to_words(n, result);
    printf("%s\n", result);
    return 0;
}
