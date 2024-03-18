#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100000
typedef struct {
    int value;
    int count;
    int first_index;
} Element;
Element arr[MAX_N];
int n;
int compare(const void* a, const void* b) {
    Element* elementA = (Element*)a;
    Element* elementB = (Element*)b;
    if (elementA->count != elementB->count)
        return elementA->count - elementB->count;
    else
        return elementA->first_index - elementB->first_index;
}
void sort_elements() {
    qsort(arr, n, sizeof(Element), compare);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        arr[value - 1].value = value;
        arr[value - 1].count++;
        if (arr[value - 1].count == 1)
            arr[value - 1].first_index = i;
    }
    sort_elements();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < arr[i].count; j++)
            printf("%d ", arr[i].value);
    printf("\n");
    return 0;
}
