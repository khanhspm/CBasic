#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Danhsach{
	char ten[100];
	char sdt[20];
	char email[100];
	struct Danhsach *next;
}; 
typedef struct Danhsach danhsach;

typedef struct {
	char ten[100];
	char sdt[20];
	char email[100];
}data;

danhsach *f, *l;
void add(void){
	danhsach *p;
	int c = 0;
    int n;
    printf("Tong so nguoi can nhap: ");
    scanf("%d", &n);
	do{
		p = (danhsach *)malloc(sizeof(danhsach));
		p->next = NULL;
		fflush(stdin);
		printf("Nhap ten: ");
		gets(p->ten);
		printf("Nhap sdt: ");
		gets(p->sdt);
		printf("Nhap email: ");
		gets(p->email);
		if(f == NULL){
			f = p;
			l = p;
		}
		else {
			l->next = p;
			l = p;
		}
        c++;
	}while(c<n);
}

void duyet(void){
	danhsach *p;
	int i = 0;
	if(f==NULL){
		printf("Danh sach rong\n");
	} 
	else{
		p = f;
		while(p!=NULL){
			i++;
			printf("%d ten: %s\t sdt: %s\t email: %s\n", i, p->ten, p->sdt, p->email);
			p = p->next;
		}
	}
}

void sapxep(){
	
}

void main(){
	int a;
	do{
		printf("1. Nhap dia chi\n");
	    printf("2. Duyet va in ra danh sach\n");
	    printf("0. De thoat\n");
		printf("Ban chon: ");
		scanf("%d", &a);
		switch(a){
		case 1: add(); break;
		case 2: duyet(); break;
		case 0: break;
	    }
	}while(a!=0);
}