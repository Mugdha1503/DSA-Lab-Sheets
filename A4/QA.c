#include <stdio.h>
void numtoword(int num)
{
    switch (num/100)
    {
        case 1 : printf("one "); break;
        case 2 : printf("two "); break;
        case 3 : printf("three "); break;
        case 4 : printf("four "); break;
        case 5 : printf("five "); break;
        case 6 : printf("six "); break;
        case 7 : printf("seven "); break;
        case 8 : printf("eight "); break;
        case 9 : printf("nine "); break;
        case 0 : break;
    }
    if (num/100 != 0){ printf("hundred ");}
    num = num%100 ;
    switch(num/10)
    {
        case 1 : 
        {
            switch (num%10)
            {
                case 1 : printf("eleven "); break;
                case 2 : printf("twelve "); break;
                case 3 : printf("thirteen "); break;
                case 4 : printf("fourteen "); break;
                case 5 : printf("fifteen "); break;
                case 6 : printf("sixteen "); break;
                case 7 : printf("seventeen "); break;
                case 8 : printf("eighteen "); break;
                case 9 : printf("nineteen "); break;
                case 0 : printf("ten ");break;
            }
        }break;
        case 2 : printf("twenty "); break;
        case 3 : printf("thirty "); break;
        case 4 : printf("forty "); break;
        case 5 : printf("fifty "); break;
        case 6 : printf("sixty "); break;
        case 7 : printf("seventy "); break;
        case 8 : printf("eighty "); break;
        case 9 : printf("ninety "); break;
        case 0 : break;
    }
    if (num/10 != 1)
    {
        switch (num%10)
        {
            case 1 : printf("one "); break;
            case 2 : printf("two "); break;
            case 3 : printf("three "); break;
            case 4 : printf("four "); break;
            case 5 : printf("five "); break;
            case 6 : printf("six "); break;
            case 7 : printf("seven "); break;
            case 8 : printf("eight "); break;
            case 9 : printf("nine "); break;
            case 0 : break;
        }
    }
}
void splitnum(int n)
{
    int num;
    num = n/1000000000 ;
    n=n%1000000000 ;
    if (num!=0)
    {
        numtoword(num);
        printf("billion ");
    }
    num = n/1000000 ;
    n=n%1000000 ;
    if (num!=0)
    {
        numtoword(num);
        printf("million ");
    }
    num = n/1000 ;
    n=n%1000 ;
    if (num!=0)
    {
        numtoword(num);
        printf("thousand ");
    }
    numtoword(n);
}
int main()
{
    int n;
    scanf("%d",&n);
    splitnum(n) ;
    return 0;
}
