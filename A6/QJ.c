#include <stdio.h>
struct Slot {
    int start;
    int end;
};
int main() {
    int n;
    scanf("%d", &n);
    struct Slot slots[n];
    for (int i = 0; i < n; i++) 
        scanf("%d %d", &slots[i].start, &slots[i].end);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (slots[i].start > slots[j].start) {
                struct Slot temp = slots[i];
                slots[i] = slots[j];
                slots[j] = temp;
            }
        }
    }
    int mergedIndex = 0;
    for (int i = 1; i < n; i++) {
        if (slots[mergedIndex].end >= slots[i].start) {
            slots[mergedIndex].end = (slots[i].end > slots[mergedIndex].end) ? slots[i].end : slots[mergedIndex].end;
        } else {
            mergedIndex++;
            slots[mergedIndex] = slots[i];
        }
    }
    printf("%d\n", mergedIndex + 1);
    for (int i = 0; i <= mergedIndex; i++) 
        printf("%d %d\n", slots[i].start, slots[i].end);
    return 0;
}


