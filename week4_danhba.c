#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Diachi{
    char ten[100];
    char sdt[20];
    char email[100];
};
typedef struct Diachi diachi;

struct stack{
    int Top;
    diachi Data[MAX];
};
typedef struct stack Stack;

void Init(Stack *S){
    (*S).Top = 0;
}

int Empty(Stack *S){
    return (*S).Top == 1;
}

int Full(Stack *S){
    return (*S).Top == MAX;
}

void Push(Stack *S, diachi x){
    if(Full(S)){
        (*S).Data[(*S).Top] = x;
        (*S).Top ++;
    }
}

diachi Pop(Stack *S){
    if(!Empty(S)){
        (*S).Top --;
        return (*S).Data[(*S).Top];
    }
}

void Input(Stack *S){
    int n;
    diachi x;
    do{
        printf("Nhap so dia chi :");
        scanf("%d", &n);
    }while(n>MAX || n < 1);
    for(int i = 0; i < n; i++){
        printf("Nhap dia chi thu %d\n", i+1);
        fflush(stdin);
        printf("Ten: ");
        gets(x.ten);
        printf("SDT: ");
        gets(x.sdt);
        printf("Email: ");
        gets(x.email);
        Push(S,x);
    }
}

void Output(Stack *S){
    for(int i = (*S).Top -1; i >= 0; i--){
        printf("%s\t %s\t %s\t", (*S).Data[i].ten, (*S).Data[i].sdt, (*S).Data[i].email);
    }
}

int main(){
    Stack *S;
    Init(S);
    Input(S);
    Output(S);
    int lua_chon;
    printf("Menu\n");
    printf("\n1: Kiem tra danh sach rong");
    printf("\n2: Kiem tra danh sach day");
    printf("\n3: Them dia chi vao danh sach");
    printf("\n4: Xoa dia chi trong danh sach");
    printf("\n5: Xuat danh sach");
    printf("\n6: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
        switch (lua_chon)
        {
            case 1:
            {
                if (Empty(S)) printf("Danh sach rong !");
                else printf ("Danh sach khong rong !");
                break;
            }
            case 2:
            {
                if (Full(S)) printf("Danh sach day !");
                else printf ("Danh sach chua day !");
                break;
            }
            case 3:
            {
                diachi x;
                printf ("Nhap thong tin dia chi can chen\n");
                fflush(stdin);
                printf("Ten: ");
                gets(x.ten);
                printf("SDT: ");
                gets(x.sdt);
                printf("Email: ");
                gets(x.email);
                Push(S,x);
                break;
            }
            case 4:
            {
                Pop(S);
                break;
            }
            case 5: 
            {
                Output(S);
                break;
            }
            case 6: break;
        }
    }while (lua_chon !=6);
    return 0;
}