#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    char s[n];
    scanf(" %[^\n]s", s);
    int len = 0;
    int l = 0, r = 0;
    int visited[256] = {0};
    while (r < n)
    {
        if (visited[s[r]] == 1)
        {
            while (visited[s[r]] == 1)
            {
                visited[s[l]] = 0;
                l++;
            }
        }
        visited[s[r]] = 1;
        len = (r - l + 1) > len ? (r - l + 1) : len;
        r++;
    }
    printf("%d", len);
}