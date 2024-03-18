#include <stdio.h>
#define MAX 1005
// Function to find the length of a string
int findLength(char num[]) {
    int length = 0;
    while (num[length] != '\0') {
        length++;
    }
    return length;
}
// Function to multiply two numbers represented as strings
void multiply(char num1[], char num2[], char result[]) {
    int len1 = findLength(num1);
    int len2 = findLength(num2);
    int res[MAX * 2] = {0};
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            int product = digit1 * digit2 + res[i + j + 1];
            res[i + j] += product / 10;
            res[i + j + 1] = product % 10;
        }
    }
    int i = 0;
    while (i < len1 + len2 - 1 && res[i] == 0) {
        i++;
    }
    int index = 0;
    while (i < len1 + len2) {
        result[index++] = res[i] + '0';
        i++;
    }
    result[index] = '\0';
}
int main() {
    char num1[MAX], num2[MAX], result[MAX * 2];
    scanf("%s", num1);
    scanf("%s", num2);
    multiply(num1, num2, result);
    printf("%s\n", result);
    return 0;
}
