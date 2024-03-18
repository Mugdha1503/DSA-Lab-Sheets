#include <stdio.h>
int vowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    char s[n];
    scanf(" %[^\n]s", s);
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if (vowel(s[l]) == 0)
            l++;
        if (vowel(s[r]) == 0)
            r--;
        if (vowel(s[l]) == 1 && vowel(s[r]) == 1)
        {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    }
    printf("%s", s);
}