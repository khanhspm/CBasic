#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Diachi{
    char ten[50];
    char sdt[20];
    char email[50];
};
typedef struct Diachi diachi;

void Input(diachi a[], int n){
    for(int i = 0; i < n; i++){
        printf("Nhap thong tin cua nguoi thu %d\n", i+1);
        fflush(stdin);
        printf("Ten: ");
        gets(a[i].ten);
        printf("So dien thoai: ");
        gets(a[i].sdt);
        printf("Email: ");
        gets(a[i].email);
    }
}

void Search(diachi a[], char x[50],int n){
    printf("Nhap ten can tim kiem: ");
    fflush(stdin);
    gets(x);
    for(int i = 0; i < n; i++){
        if(strcmp(a[i].ten, x) == 0){
            printf("Ten: %s\n", a[i].ten);
            printf("So dien thoai: %s\n", a[i].sdt);
            printf("Email: %s\n", a[i].email);
        }
    }
}

int main(){
    int n;
    char x[50];
    printf("Nhap tong so nguoi can nhap thong tin!\n");
    scanf("%d", &n);
    diachi a[100];
    Input(a,n);
    Search(a,x,n);
    return 0;
}