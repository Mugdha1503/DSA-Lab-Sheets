#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
// Function to count the number of set bits (1s) in the binary representation
int countSetBits(mpz_t num)
{
    int count = 0;
    // Convert the mpz_t number to a string in binary representation
    char *binaryStr = mpz_get_str(NULL, 2, num);
    // Count the number of '1's in the binary string
    for (int i = 0; binaryStr[i] != '\0'; ++i)
    {
        if (binaryStr[i] == '1')
        {
            ++count;
        }
    }
    // Free the memory allocated by mpz_get_str
    free(binaryStr);
    return count;
}
int main()
{
    mpz_t number;
    mpz_init(number);
    gmp_scanf("%Zd", number);
    // Check if the number is non-negative
    if (mpz_sgn(number) < 0)
    {
        printf("Please enter a non-negative integer.\n");
    }
    else
    {
        // Count the number of set bits in the binary representation
        int result = countSetBits(number);
        // Output the result
        printf("%d\n", result);
    }
    // Clear allocated resources
    mpz_clear(number);
    return 0;
}
