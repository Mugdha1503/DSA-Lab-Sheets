#include <stdio.h>
void printSpiral(int n)
{
    int matrix[n][n];
    int top = 0, left = 0, bottom = n - 1, right = n - 1;
    int cnt = 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            matrix[top][i] = cnt++;
        top++;
        for (int i = top; i <= bottom; i++)
            matrix[i][right] = cnt++;
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                matrix[bottom][i] = cnt++;
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                matrix[i][left] = cnt++;
            left++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    printSpiral(n);
    return 0;
}
