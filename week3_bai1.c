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
	int c;
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
		printf("Nhan 1 de tiep tuc add, 0 de dung!\n");
		scanf("%d", &c);
	}while(c==1);
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

void xoa(void){
	danhsach *p, *q;
	char t[100];
	int x = 0;
	fflush(stdin);
	printf("Nhap ten can xoa: ");
	gets(t);
	p = f;
	if(p!=NULL){
		while(p!=NULL & x==0){
			if(strcmp(p->ten, t)==0){
				x = 1;
			}
			else{
				q = p;
				p = p->next;
			}
			if(x==1){
				if(p==f){
					f = p->next;
				}
				else{
					q->next = p->next;
				}
				if(p->next ==NULL){
					l = q;
				}
				free(p);
				printf("Da xoa thanh cong!\n");
			}
		}
	}
}

void main(){
	int a;
	do{
		printf("1. Them vao 1 dia chi vao vi tri cuoi cung\n");
	    printf("2. Duyet va in ra danh sach\n");
	    printf("3. Xoa dia chi nguoi dung theo ten\n");
	    printf("0. De thoat\n");
		printf("Ban chon: ");
		scanf("%d", &a);
		switch(a){
		case 1: add(); break;
		case 2: duyet(); break;
		case 3: xoa(); break;
		case 0: break;
	    }   
	}while(a!=0);
}




