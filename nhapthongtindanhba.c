#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct Danhba{
    char ten[20];
    char sdt[12];
    char email[30];
};
typedef struct Danhba danhba;
typedef struct Danhba *DANHBA;


void nhaptt(DANHBA p, int n){
    for(int i = 0; i < n; i++){
        printf("Ten: ");
        fflush(stdin);
        gets(p[i].ten);
        printf("So dien thoai: ");
        gets(p[i].sdt);
        printf("Email: ");
        gets(p[i].email);
        printf("\n");
    }
}

void xuattt(DANHBA p, int n){
    printf("%s\t %11s\t %11s\n", "Ten", "So dien thoai", "Email");
    for(int i = 0; i < n; i++){
        printf("%s\t %11s\t %11s\n", p[i].ten, p[i].sdt, p[i].email);
    }
}

int main(){
    FILE *fp;
    fp = fopen("D:\\Cbasic\\danhba.txt", "w");
    if(fp == NULL){
        printf("ERROL !");
        exit(1);
    }
    DANHBA p;
    int n = 20;
    p = (DANHBA)malloc(n*sizeof(danhba));
    if(p == NULL) return 0;
    nhaptt(p, n);
    fprintf(fp, "%s\t %11s\t %11s\n", "Ten", "So dien thoai", "Email");
    for(int i = 0; i < n; i++){
        fprintf(fp, "%s\t %11s\t %11s\n", p[i].ten, p[i].sdt, p[i].email);
    }
    fclose(fp);
    xuattt(p, n);
    return 0;
}