#include <stdio.h>
#include <string.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
char* lcmStrings(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int l = lcm(len_a, len_b);
    char* result = malloc(l + 1);
    int i;
    if (strcmp(a, b) == 0) {
        strcpy(result, a);
        return result;
    }
    int repeats_a = l / len_a;
    int repeats_b = l / len_b;
    char* pattern_a = malloc(l + 1);
    char* pattern_b = malloc(l + 1);
    for (i = 0; i < repeats_a; i++) {
        strcat(pattern_a, a);
    }
    for (i = 0; i < repeats_b; i++) {
        strcat(pattern_b, b);
    }
    if (strcmp(pattern_a, pattern_b) == 0) {
        strcpy(result, pattern_a);
        free(pattern_a);
        free(pattern_b);
        return result;
    }
    free(pattern_a);
    free(pattern_b);
    strcpy(result, "-1");
    return result;
}
int main() {
    char a[1000001], b[1000001];
        scanf("%s %s", a, b);
    char* result = lcmStrings(a, b);
    printf("%s\n", result);
    return 0;
}



