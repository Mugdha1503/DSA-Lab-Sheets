#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node* prev;
    struct node* next;
};
struct node* insert_front(struct node* f, int v){
    f -> prev = (struct node *)malloc(sizeof(struct node));
    f -> prev -> next = f;
    f = f -> prev;
    f -> val = v;
    return f;
}
struct node* insert_end(struct node* e, int v){
    e -> next = (struct node *)malloc(sizeof(struct node));
    e -> next -> prev = e;
    e = e -> next;
    e -> val = v;
    return e;
}
struct node* delete_front(struct node* f){
    if(f -> next == NULL){
        free(f);
        return NULL;
    }
    f = f -> next;
    free(f -> prev);
    f -> prev = NULL;
    return f;
}
struct node* delete_end(struct node* e){
    if(e -> prev == NULL){
        free(e);
        return NULL;
    }
    e = e -> prev;
    free(e -> next);
    e -> next = NULL;
    return e;
}
void print_forward(struct node* f){
    if(f == NULL)
        printf("-1");
    else{
        while(f != NULL){
            printf("%d ", (f -> val));
            f = f -> next;
        }
    }
    printf("\n");
}
void print_backward(struct node* e){
    if(e == NULL)
        printf("-1");
    else{
        while(e != NULL){
            printf("%d ", (e -> val));
            e = e -> prev;
        }
    }
    printf("\n");
}
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    struct node* last = NULL;
    struct node* first = NULL;
    struct node* temp;
    for(int i = 0; i < n; i++){
        if(first == NULL){
            temp = (struct node *)malloc(sizeof(struct node));
            first = temp;
            first -> prev = NULL;
        }
        else{
            temp -> next = (struct node *)malloc(sizeof(struct node));
            (temp -> next) -> prev = temp;
            temp = temp -> next;
        }
        scanf("%d", &(temp -> val));
    }
    temp -> next = NULL;
    last = temp;
    int arr[q], val[q];
    int j = 0;
    for(int i = 0; i < q; i++){
        scanf("%d", &arr[i]);
        if(arr[i] == 1 || arr[i] == 2){
            scanf("%d", &val[j]);
            j++;
        }
    }
    j = 0;
    for(int i = 0; i < q; i++){
        if(arr[i] == 1 || arr[i] == 2){
            if(first == NULL || last == NULL){
                first = (struct node *)malloc(sizeof(struct node));
                first -> val = val[j];
                last = first;
                first -> prev = NULL;
                first -> next = NULL;
            }
            else if(arr[i] == 1)
                first = insert_front(first, val[j]);
            else
                last = insert_end(last, val[j]);
            j++;
        }
        else if(arr[i] == 3 && first != NULL){
            first = delete_front(first);
            if(first == NULL)
                last =NULL;
        }
        else if(arr[i] == 4 && last != NULL){
            last = delete_end(last);
            if(last == NULL)
                first = NULL;
        }
        else if(arr[i] == 5){
                print_forward(first);
        }
        else
            print_backward(last);
    }
}

