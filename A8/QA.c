#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 1000000
#define MAX_SIZE 100
bool isValid(char s[]) {
    char stack[MAX_SIZE];
    int top = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if (top == -1) {
                return false;
            }
            char ch = stack[top--];
            if ((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[') || (s[i] == '}' && ch == '{')) {
                continue;
            } else 
                return false;
        }
    }
    return top == -1;
}
int main() {
    char s[SIZE];
    scanf(" %[^\n]s",s);
    if (isValid(s)) {
        printf("YES\n");
  } else 
        printf("NO\n");
    return 0;
}

