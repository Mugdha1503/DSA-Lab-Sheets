#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to calculate the maximum of two numbers
long long max(long long a, long long b)
{
    return (a > b) ? a : b;
}
// Function to multiply two numbers using Karatsuba algorithm
long long karatsuba(const char *num1, const char *num2)
{
    // Convert input strings to long long integers
    long long x = atoll(num1);
    long long y = atoll(num2);
    if (x < 10 || y < 10)
    {
        return x * y;
    }
    // Calculate the size of the numbers
    long long size = max(strlen(num1), strlen(num2));
    // Split the input numbers into two parts
    long long m = ceil(size / 2.0);
    char a[100], b[100], c[100], d[100];
    strncpy(a, num1, m);
    a[m] = '\0';
    strcpy(b, num1 + m);
    strncpy(c, num2, m);
    c[m] = '\0';
    strcpy(d, num2 + m);
    // Recursive steps
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long ad_plus_bc = karatsuba(a, d) + karatsuba(b, c);
    // Combine the results
    return ac * pow(10, 2 * m) + ad_plus_bc * pow(10, m) + bd;
}
int main()
{
    char num1[100], num2[100];
    scanf("%s %s", num1, num2);
    long long result = karatsuba(num1, num2);
    printf("%lld\n", result);
    return 0;
}
