#include <stdio.h>
int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    int a[N], ans[Q];
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < Q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        int sum = 0;
        for (int i = l - 1; i < r; i++)
            sum += a[i];
        ans[i] = sum;
    }
    for (int i = 0; i < Q; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
