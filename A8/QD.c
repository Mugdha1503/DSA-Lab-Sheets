#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;
void init(Stack *s) {
    s->top = -1;
}
void push(Stack *s, int value) {
    s->data[++s->top] = value;
}
int pop(Stack *s) {
    return s->data[s->top--];
}
int top(Stack *s) {
    return s->data[s->top];
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
int largestRectangleArea(int histo[], int n) {
    Stack st;
    init(&st);
    int maxA = 0;
    for (int i = 0; i <= n; i++) {
        while (!isEmpty(&st) && (i == n || histo[top(&st)] >= histo[i])) {
            int height = histo[top(&st)];
            pop(&st);
            int width;
            if (isEmpty(&st))
                width = i;
            else
                width = i - top(&st) - 1;
            maxA = width * height > maxA ? width * height : maxA;
        }
        push(&st, i);
    }
    return maxA;
} 
int main() {
    int n;
    scanf("%d",&n);
    int histo[n];
    for(int i=0;i<n;i++)
    scanf("%d",&histo[i]);
    printf("%d\n", largestRectangleArea(histo, n));
    return 0;
}

