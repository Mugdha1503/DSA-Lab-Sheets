#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    while(a>0)
    {
        int current_k=a/(b+1);
        int rem=a%(b+1);
        if(rem>0)
            current_k++;
        a-=current_k;
        while(current_k>0)
        {
            printf("K");
            current_k--;
        }
        if(b>0)  
        {
            printf("O");
            b--;
        }
    }
    return 0;
}

