#include<stdio.h>
#include<stdlib.h>

struct Thongtinsinhvien{
    char id[10];
    char name[100];
    int grade;
};
typedef struct Thongtinsinhvien ttsv;

struct Node{
    ttsv data;
    struct Node* next;
};
typedef struct Node* node;

//Kiem tra danh sach rong
int Empty(node l){
    return l == NULL;
}

//In ra man hinh
void show(const node head){
    const struct Node* p = head;
    while(p != NULL){
        printf("%10s ", p->data.name);
        printf("%10s ", p->data.id);
        printf("%4d ", p->data.grade);
        printf("\n");
        p = p->next;
    }
}

//Chen vao dau danh sach 
void addnew(node* head, ttsv data){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    if(Empty(*head)){
        *head = p;
    }else{
        p->next = *head;
        *head = p;
    }
}

// Them vao cuoi danh sach
void addTail(node* head, ttsv data){
    if(Empty(*head)){
        addnew(head, data);
    }else{
        struct Node* x = *head;
        while(x->next != NULL){
            x = x->next;
        }
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
        p->data = data;
        p->next = NULL;
        x->next = p;
    }
}

//Tim sinh vien co ID can tim
int findsv(const node l, const ttsv x){
    const struct Node* p = l;
    while(p != NULL){
        if(p->data.id == x.id){
            return 1;
        }
        p= p->next;
    }
    return 0;
}

//Change grade
int changegrade(node* l, const ttsv x, const ttsv y){
    struct Node* p = *l;
    int coutupdate = 0;
    while(p != NULL){
        if(p->data.id == x.id){
            p->data = y;
            coutupdate++;
        }
        p = p->next;
    }
    return coutupdate;
}

//xoa node head
void removeh(node* head){
    if(Empty(*head)){
        printf("Danh sach rong!\n");
    }else{
        struct Node* p = *head;
        (*head) = (*head)->next;
        free(p);
        printf("Xoa thanh cong!\n");
    }
}

//Xoa sinh vien co id can xoa
void removeX(node* head, const ttsv x){
    void removeh(node*);
    if((*head)->data.id == x.id){
        removeh(head);
    }else{
        struct Node* p = *head;
        struct Node* pre = *head;
        while(p->data.id != x.id){
            pre = p;
            p = p->next;
        }
        if(p==NULL){
            printf("Khong ton tai id: %s\n", x.id);
        }else{
            pre->next = p->next;
            p->next = NULL;
            free(p);
            printf("Xoa thanh cong\n");
        }
    }
}

int main(){
    node a = NULL;
    int n;
    printf("Tong so sinh vien can nhap: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        ttsv data;
        fflush(stdin);
        printf("Ten: ");
        gets(data.name);
        printf("id: ");
        gets(data.id);
        printf("Diem: ");
        scanf("%d", &data.grade);
        addTail(&a, data);
    }
    show(a);
    /*int b;
    do{
    printf("1. Them vao cuoi danh sach\n");
    printf("2. Tim sinh vien theo ID\n");
    printf("3. Doi diem\n");
    printf("4. Xoa sinh vien theo ID\n");
    printf("0. Thoat\n");
    scanf("%d", &b);
    switch(b){
        case 1:
            ttsv data1;
            printf("Nhap thong tin sinh vien can them\n");
            fflush(stdin);
            printf("Ten: ");
            gets(data1.name);
            printf("ID: ");
            gets(data1.id);
            printf("Diem: ");
            scanf("%d", &data1.grade);
            addTail(&a, data1);
        case 0:
            break;
    }
    }while(b!=0); */
    return 0;
}