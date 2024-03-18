#include <stdio.h>
#include <stdbool.h>
bool searchMatrix(int n, int matrix[][n], int target)
{
    int low = 0, high = n * n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / n, col = mid % n;
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d", &n);
    int target;
    scanf("%d", &target);
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    }
    bool found = searchMatrix(n, matrix, target);
    if (found)
        printf("YES");
    else
        printf("NO");
    return 0;
}
