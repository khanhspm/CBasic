#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define FULL 20

struct Ram{
    char cpu[3];
    int capacity;
};
typedef struct Ram ram;

struct Node{
    ram data;
    struct Node *next;
};
typedef struct Node node;

struct Queue{
    int count;
    node *front;
    node *rear;
};
typedef struct Queue queue;

void Init(queue *q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int Empty(queue *q){
    return (q->rear == NULL);
}

void Enqueue(queue *q, ram x){
    if(q->count < FULL){
        node *tmp;
        tmp = malloc(sizeof(node));
        tmp->data = x;
        tmp->next = NULL;
        if(!Empty(q)){
            q->rear->next = tmp;
            q->rear = tmp;
        }else{
            q->front = q->rear = tmp;
        }
        q->count++;
    }else{
        printf("Danh sach day, khong them duoc!\n");
    }
}

void Display(node *head){
    if(head == NULL){
        return;
    }else{
        printf("%s\t%d\n", head->data.cpu, head->data.capacity);
        Display(head->next);
    }
}

int nn = 0;
void SearchNAME(node *head, char name[]){
    if(head == NULL){
        return;
    }else{
        if(strcmp(name, head->data.cpu) == 0){
            printf("%s\t%d\n", head->data.cpu, head->data.capacity);
            nn++;
        }
        SearchNAME(head->next, name);
    }
}

int mm = 0;
void SearchCAPA(node *head, int a){
    if(head == NULL){
        return;
    }else{
        if(a == head->data.capacity){
            printf("%s\t%d\n", head->data.cpu, head->data.capacity);
            mm++;
        }
        SearchCAPA(head->next, a);
    }
}

void main(){
    int lua_chon;
    int b = 0;
    queue *q;
    q = malloc(sizeof(node));
    Init(q);
    ram x;
    FILE *fp1, *fp2;
    do{
        printf("=================================================\n");
        printf("1. Load Data Files\n");
        printf("2. Update CPU info\n");
        printf("3. Update RAM info\n");
        printf("4. Search\n");
        printf("5. Quit\n");
        printf("=================================================\n\n"); 
        printf("Ban chon: ");
        scanf("%d", &lua_chon);
        switch(lua_chon){
            case 1:{
                char filename[50];
                int a;
                printf("Nhap ten file: ");
                scanf("%s", filename);
                fp1 = fopen(filename, "r");
                if(fp1 == NULL){
                    printf("FILE khong ton tai!\n");
                    break;
                }
                fscanf(fp1, "%d\n", &a);
                b += a;
                while(fscanf(fp1, "%s %d\n", x.cpu, &x.capacity) != EOF){
                    Enqueue(q, x);
                }
                printf("%d\n", b);
                Display(q->front);
                break;
            }
            case 4:{
                char sss[5];
                scanf("%s", sss);
                int size = strlen(sss);
                if(size > 1){
                    SearchNAME(q->front, sss);
                    if(nn == 0) printf("Gia tri tim kiem khong hop le!\n");
                    break;
                }else if(size == 1){
                    int capa = atoi(sss);
                    SearchCAPA(q->front, capa);
                    if(mm == 0) printf("Gia tri tim kiem khong hop le!\n");
                    break;
                }
            }
            case 5: break;
        }
    }while(lua_chon != 5);
}