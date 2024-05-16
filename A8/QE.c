#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* subtract(char* num1, char* num2) {
int len1 = strlen(num1);
int len2 = strlen(num2);
int maxlen = (len1 > len2) ? len1 : len2;
char* result = (char*)malloc((maxlen + 1) * sizeof(char));
int carry = 0;
int i = len1 - 1;
int j = len2 - 1;
int k = maxlen;
while (i >= 0) {
int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
int digit2 = (j >= 0) ? (num2[j] - '0') : 0;
int diff = digit1 - digit2 - carry;
if (diff < 0) {
diff += 10;
carry = 1;
} else {
carry = 0;
}
result[--k] = diff + '0';
i--;
j--;
}
while (result[0] == '0' && maxlen > 1) {
for (int x = 0; x < maxlen - 1; x++) {
result[x] = result[x + 1];
}
maxlen--;
}
result[maxlen] = '\0';
return result;
}
int main() {
int n, k;
scanf("%d %d", &n, &k);
char s[100001];
scanf("%s", s);
char temp[100001];
int counter = 0;
int top = -1;
for (int i = 0; i < n; i++) {
while (top >= 0 && s[i] < temp[top]) {
if (counter >= k) {
break;
}
top--;
counter++;
}
temp[++top] = s[i];
}
char ans[100001];
int i = 0;
int j = 0;
while (temp[i] == '0') {
i++;
}
while (i <= top) {
ans[j++] = temp[i++];
}
ans[j] = '\0';
printf("%s\n", subtract(s, ans));
return 0;
}
