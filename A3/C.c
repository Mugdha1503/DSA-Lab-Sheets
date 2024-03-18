#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[n];
    scanf(" %[^\n]s", s);

    int start = 0;
    int end = 0;
    while (s[end] != '\0')
    {
        if (s[end] == ' ')
        {
            int l = start;
            int r = end - 1;
            while (l < r)
            {
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                l++;
                r--;
            }
            start = end + 1;
        }
        end++;
    }

    int l = start;
    int r = end - 1;
    while (l < r)
    {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;

        l++;
        r--;
    }
    // Print the modified string
    printf("%s\n", s);
}
