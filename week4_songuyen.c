#include<stdio.h>
#include<stdlib.h>

#define MAX 10


struct Queue{
    int front, last;
    int data[MAX];
    int count;
};
typedef struct Queue que;

void Init(que *q){
    q->front = -1;
    q->last = -1;
    q->count = 0;
}

int Empty(que q){
    if(q.count == 0) return 1;
    return 0;
}

int Full(que q){
    if(q.count == MAX) return 1;
    return 0;
}

void push(que *q, int x){
    if(Full(*q)) printf("Hang doi day!\n");
    else{
        q->data[++q->front] = x;
        q->count ++;
    }
}

int pop(que *q){
    if(Empty(*q)) printf("Hang doi rong!\n");
    else{
        int x;
        x = q->data[q->front];
        for(int i = q->front; i < q->last; i++){
            q->data[i] = q->data[i+1];
        }
        q->last--;
        q->count--;
        return x;
    }
}

void push_y(que *q, int x){
    printf("%d ", q->data[q->front]);
    pop(q);
    push(q,x);
}

void Nhap(que *q){
    int n;
    int x;
    printf("Nhap tong so can nhap\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &x);
        push(q,x);
        if(i>MAX){
            printf("%d ", q->data[q->front]);
            push_y(q,x);
        }
    }
}

int main(){
    que *q;
    Init(q);
    Nhap(q);
    return 0;
}