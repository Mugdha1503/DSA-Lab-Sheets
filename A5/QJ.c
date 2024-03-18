#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node* prev;
    struct node* next;
};
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    struct node* first = NULL;
    struct node* last;
    struct node* temp;
    for(int i = 0; i < n; i++){
        if(first == NULL){
            first = (struct node *)malloc(sizeof(struct node));
            temp = first;
            first -> prev = NULL;
        }
        else{
            temp -> next = (struct node *)malloc(sizeof(struct node));
            struct node* p = temp;
            temp = temp -> next;
            temp -> prev = p;
        }
        scanf("%d", &(temp -> v));
    }
    temp -> next = NULL;
    last = temp;
    temp = first;
    int arr[q], val[q];
    int j = 0;
    for(int i = 0; i < q; i++){
        scanf("%d", &arr[i]);
        if(arr[i] == 2 || arr[i] == 3){
            scanf("%d", &val[j]);
            j++;
        }
    }
    j = 0;
    printf("\n");
    for(int i = 0; i < q; i++){
        if(arr[i] == 1){
            printf("%d\n", temp -> v);
        }
        else if(arr[i] == 2){
            struct node* t = temp -> next;
            temp -> next = (struct node *)malloc(sizeof(struct node));
            (temp -> next) -> next = t;
            if(t != NULL)
                t -> prev = temp -> next;
            (temp -> next) -> prev = temp;
            (temp -> next) -> v = val[j];
            j++;
        }
        else if(arr[i] == 3){
            last -> next = (struct node *)malloc(sizeof(struct node));
            (last -> next) -> v = val[j];
            (last -> next) -> prev = last;
            last = last -> next;
            last -> next = NULL;
            j++;
        }
        else if(arr[i] == 4 && temp -> next != NULL){
            temp = temp -> next;           
        }
        else if(arr[i] == 5 && temp -> prev != NULL){
            temp = temp -> prev;
        }
        else if(arr[i] == 6){
            if(temp -> next == NULL && temp != first){
                (temp -> prev) -> next = NULL;
                struct node* t = temp;
                temp = first;
                free(t); 
            }
            else if(temp -> next != NULL){
                struct node* t = temp;
                temp = temp -> next;
                temp -> prev = t -> prev;
                if(t == first)
                    first = temp;
                else
                    (t -> prev) -> next = temp;
                free(t);
            }
        }
    }    
}

