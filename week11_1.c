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

void swap(danhba *a, danhba *b)
{
    danhba t = *a;
    *a = *b;
    *b = t;
}

int phandoan(DANHBA q, int low, int high){
    danhba p = q[high];
    int left = low;
    int right = high - 1;
    while(1){
        while(left <= right && strcmp(q[left].ten, p.ten) < 0) left++;
        while(right >= left && strcmp(q[right].ten, p.ten) > 0) right--;
        if(left >= right) break;
        swap(&q[left], &q[right]);
        left++;
        right--;       
    }
    swap(&q[left], &q[high]);
    return left;
}

void sxnhanh(DANHBA q, int low, int high){
    if(low < high){
        int d = phandoan(q, low, high);
        sxnhanh(q, low, d-1);
        sxnhanh(q, d+1, high);
    }
}


void xuattt(DANHBA p, int n){
    printf("%s\t %11s\t %11s\n", "Ten", "So dien thoai", "Email");
    for(int i = 0; i < n; i++){
        printf("%s\t %11s\t %11s\n", p[i].ten, p[i].sdt, p[i].email);
    }
}

int main(){
    FILE *fp, *fq;
    fp = fopen("D:\\Cbasic\\danhba1.txt", "w");
    if(fp == NULL){
        printf("ERROL !");
        exit(1);
    }
    DANHBA p;
    int n = 10;
    p = (DANHBA)malloc(n*sizeof(danhba));
    if(p == NULL) return 0;
    nhaptt(p, n);
    sxnhanh(p, 0, n-1);
    fprintf(fp, "%s\t %11s\t %11s\n", "Ten", "So dien thoai", "Email");
    for(int i = 0; i < n; i++){
        fprintf(fp, "%s\t %11s\t %11s\n", p[i].ten, p[i].sdt, p[i].email);
    }
    fclose(fp);
    xuattt(p,n);
    return 0;
}