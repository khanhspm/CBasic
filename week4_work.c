#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Work{
    char time[10];
    char place[100];
    char people[100];
    char des[100];
};
typedef struct Work work;

struct Node{
    work data;
    struct Node* next;
};
typedef struct Node node;

struct Queue{
    node* front, *last;
    int count;
};
typedef struct Queue que;

void Init(que *q){
    q->front = q->last = NULL;
    q->count = 0; 
}

int Empty(que q){
    if(q.count == 0) return 1;
    return 0;
}

node *Makenode(work x){
    node *p = (node*)malloc(sizeof(node));
    p->next = NULL;
    p->data = x;
    return p;
}

void push(que *q, work x){
    node *p = Makenode(x);
    if(Empty(*q)){
        q->front = q->last = p;
    }
    else{
        q->last->next = p;
        q->last = p;
    }
    q->count++;
}

void pop(que *q){
    if(Empty(*q)){
        printf("Danh sach rong!\n");
    }
    else{
        work x = q->front->data;
        if(q->count == 1) Init(q);
        else q->front = q->front->next;
        q->count--;
    }
}

void Input(que *q){
    int i = 0;
    int n;
    work x;
    printf("Nhap tong so phan tu can nhap ban dau\n");
    scanf("%d", &n);
    do{
        printf("Nhap phan tu thu %d: ", i+1);
        printf("Time: ");
        fflush(stdin);
        gets(x.time);
        printf("Place: ");
        gets(x.place);
        printf("People: ");
        gets(x.people);
        printf("Description: ");
        gets(x.des);
        push(q,x);
        i++;
    }while(i==n);
}

void Output(que q){
    node *p = q.front;
    while(p != NULL){
        printf("%s\t %s\t %s\t %s\n", p->data.time, p->data.place, p->data.people, p->data.des);
        p = p->next;
    }
}

int main(){
    que *q;
    Init(q);
    Input(q);
    Output(*q);
    int lua_chon;
    do{
        printf("1. Them vao danh sach\n");
        printf("2. Xoa ");
        printf("3. Xuat danh sach\n");
        printf("0. Thoat\n");
        scanf("%d", &lua_chon);
        switch(lua_chon){
            case 1:{
                work x;
                printf("Nhap thong tin can chen\n");
                fflush(stdin);
                printf("Time: ");
                gets(x.time);
                printf("Place: ");
                gets(x.place);
                printf("People: ");
                gets(x.people);
                printf("Description: ");
                gets(x.des);
                push(q,x);
                break;
            }
            case 2:{
                pop(q);
                break;
            }
            case 3:{
                Output(*q);
                break;
            }
        }
    }while(lua_chon != 0);
    return 0;
}