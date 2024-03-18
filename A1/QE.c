#include <stdio.h>
#include <gmp.h>
int main()
{
    mpz_t N, M, passcode;
    mpz_init(N);
    mpz_init(M);
    mpz_init(passcode);
    gmp_scanf("%Zd", N);
    gmp_scanf("%Zd", M);
    // Check if N and M are non-negative
    if (mpz_sgn(N) < 0 || mpz_sgn(M) <= 0)
    {
        printf("N should be non-negative and M should be positive.\n");
    }
    else
    {
        // Compute passcode (modular multiplicative inverse of N modulo M)
        mpz_invert(passcode, N, M);
        mpz_out_str(stdout, 10, passcode);
    }
    // Clear allocated resources
    mpz_clear(N);
    mpz_clear(M);
    mpz_clear(passcode);
    return 0;
}
