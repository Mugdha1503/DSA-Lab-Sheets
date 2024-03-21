#include <stdio.h>
int find(char s[], int l, int r, int n, int len)
{
    while (l >= 0 && r < n && s[l] == s[r])
    {
        if ((r - l + 1) > len)
        {
            len = r - l + 1;
        }
        l--;
        r++;
    }
    return len;
}
int main()
{
    int n;
    scanf("%d", &n);
    char s[n];
    scanf(" %[^\n]s", s);
    int len = 0;
    int l, r;
    for (int i = 0; i < n; i++)
    {
        // for odd sized substrings
        l = i;
        r = i;
        len = find(s, l, r, n, len);

        // for even sized substrings
        l = i;
        r = i + 1;
        len = find(s, l, r, n, len);
    }
    printf("%d", len);
}
