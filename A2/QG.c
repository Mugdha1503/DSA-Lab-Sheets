#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    long long maxSum=0; long long sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>maxSum)
        maxSum=sum;
        if(sum<0){
            sum=0;
        } 
    } 
    printf("%lld",maxSum);
    return 0;
}



