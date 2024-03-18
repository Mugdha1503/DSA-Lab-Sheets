#include<stdio.h>
void add_max_heap(int l[], int s, int k){
    l[s] = k;
    int a = s / 2;
    while(a >= 0 && l[a] < k){
        l[s] = l[a];
        l[a] = k;
        s = a;
        a = s / 2;
    }
}
void add_min_heap(int r[], int s, int k){
    r[s] = k;
    int a = s / 2;
    while(a >= 0 && r[a] > k){
        r[s] = r[a];
        r[a] = k;
        s = a;
        a = s / 2;
    }
}
void maxHeap(int arr[], int i, int s){
    int left = 2 * i + 1, right = 2 * i + 2, largest = i;
    if(left < s && arr[left] > arr[largest])
        largest = left;
    if(right < s && arr[right] > arr[largest])
        largest = right;
    if(largest != i){
        int a = arr[largest];
        arr[largest] = arr[i];
        arr[i] = a;
        maxHeap(arr, largest, s);
    }
}
void minHeap(int arr[], int i, int s){
    int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
    if(left < s && arr[left] < arr[smallest])
        smallest = left;
    if(right < s && arr[right] < arr[smallest])
        smallest = right;
    if(smallest != i){
        int a = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = a;
        minHeap(arr, smallest, s);
    }
}
int main(){
    int q;
    scanf("%d",&q);
    int arr[q][2];
    for(int i = 0; i < q; i++){
        scanf("%d", &arr[i][0]);
        if(arr[i][0] == 1)
            scanf("%d", &arr[i][1]);
        else
            arr[i][1] = 0;
    }
    int l[100], r[100];
    int sz_l = 0, sz_r = 0;
    for(int i = 0; i < q; i++){
        if(arr[i][0] == 1){
            if(sz_l == 0){
                l[sz_l] = arr[i][1];
                sz_l++;
            }
            else if(sz_r == 0){
                if(l[0] > arr[i][1]){
                    r[sz_r] = l[0];
                    l[0] = arr[i][1];
                    sz_r++;
                }
                else{
                    r[sz_r] = arr[i][1];
                    sz_r++;
                }
            }
            else{
                if(sz_l == sz_r){
                    if(r[0] >= arr[i][1]){
                        add_max_heap(l, sz_l, arr[i][1]);
                    }
                    else{
                        add_max_heap(l, sz_r, r[0]);
                        r[0] = arr[i][1];
                        minHeap(r, 0, sz_r);
                    }
                    sz_l++;
                }
                else{
                    if(l[0] <= arr[i][1]){
                        add_min_heap(r, sz_r, arr[i][1]);
                    }
                    else{
                        add_min_heap(r, sz_r, l[0]);
                        l[0] = arr[i][1];
                        maxHeap(l, 0, sz_l);
                    }
                    sz_r++;
                }
            }
        }
        else
            printf("%d\n", l[0]);
    }
}


