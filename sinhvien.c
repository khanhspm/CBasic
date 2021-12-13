#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct tagSINHVIEN {
    int ID;
    char Hoten[35];
    float diem;
}SINHVIEN, *PSINHVIEN;
 
typedef struct tagNODE {
    SINHVIEN Data;
    struct tagNODE* Next;
}NODE, *PNODE;
 
typedef struct tagLIST {
    NODE* Dau;
    NODE* Cuoi;
}LISTSV, *PLIST;
 
//Khoi tao NODE
NODE* KhoitaoNode()
{
    NODE* x = (NODE*)malloc(sizeof(NODE));
    if(x == NULL)
    {
        printf("\n Bo nho khong du ");
        return 0;
    }
    x->Next = NULL;
    return x;
}
 
//Khoi tao danh sach LISTSV
void KhoitaoList(LISTSV* x)
{
    x->Dau = NULL;
    x->Cuoi=NULL;
}
 
//Nhap thong tin sinh vien
void Nhap (NODE* x)
{
    char tg[25];
    int a, d, m, y;
    float t, c;
    printf("\nNhap ID: ");
    scanf("%d", &a);
    x->Data.ID = a;
    fflush(stdin);
    printf("Nhap ten Sinh Vien: ");
    gets(tg);
    strcpy(x->Data.Hoten,tg);
    fflush(stdin);
    do
    {
        printf("Nhap Diem: ");
        scanf("%f", &c);
    }while(c < 0 || c > 10);
    x->Data.diem = c;
    fflush(stdin);
    x->Next = NULL;
}

//Sap xep theo ten

//in sinh vien
void InSV(NODE* p)
{
    printf("\nID: %d",p->Data.ID);
    printf("\tTen: %s",p->Data.Hoten);
    printf("\tDiem: %.2f\n", p->Data.diem);
}
 
// in danh sach SINHVIEN
void InDanhSach(LISTSV x)
{
    NODE *p;
    p = x.Dau;
    while(p != NULL)
    {
        InSV(p);
        p = p->Next;
    }
}
 
//Them mot NODE vao Cuoi danh sach
void ThemCuoi(LISTSV* x, NODE* t)
{
    if(x->Dau == NULL)
    {
        x->Dau = t;
    }
   else
   {
       x->Cuoi->Next = t;
   }
   x->Cuoi = t;
}
 
// Them mot sinh vien vao cuoi danh sach
int NhapSV(LISTSV* x)
{
    NODE* a = KhoitaoNode();
    Nhap(a);
    ThemCuoi(x,a);
    return 0;
}
 
//Tim kiem theo ID
void TimKiemID(LISTSV x , int n)
{
    NODE *p;
    p = x.Dau;
    while(p != NULL)
    {
        if(p->Data.ID == n)
        {
            InSV(p);
        }else   printf("\n ID sinh vien khong ton tai!\n");
        p = p->Next;
    }
}

//Tim kiem theo ten
void TimKiemten(LISTSV x, char n[]){
	NODE *p;
	p = x.Dau;
	while(p != NULL){
		if(strcmp(p->Data.Hoten, n) == 0){
			InSV(p);
		}else{
			printf("\n Ten sinh vien can tim khong ton tai!");
		}
		p = p->Next;
	}
}

//Xoa 1 Sinh Vien bat ki theo ID
int XoaSVID(LISTSV *x , int n)
{
    NODE *p = x->Dau;
    NODE *q = NULL;
    while(p != NULL)
    {
        if(p->Data.ID == n)
            break;
        q = p;
        p = p->Next;
    }
    if(p == NULL) return 0;
    if(q != NULL)
    {

        x->Dau = q;
        q->Next = p->Next;
        free(p);
    }
    else
    {
        x->Dau = p->Next;
        if(x->Dau == NULL)
        {
            x->Cuoi = NULL;
        }
    }
    return 1;
}

//Xoa 1 Sinh Vien bat ki theo ten
int XoaSVten(LISTSV *x , char n[])
{
    NODE *p = x->Dau;
    NODE *q = NULL;
    while(p != NULL)
    {
        if(strcmp(p->Data.Hoten, n) == 0)
            break;
        q = p;
        p = p->Next;
    }
    if(p == NULL) return 0;
    if(q != NULL)
    {

        x->Dau = q;
        q->Next = p->Next;
        free(p);
    }
    else
    {
        x->Dau = p->Next;
        if(x->Dau == NULL)
        {
            x->Cuoi = NULL;
        }
    }
    return 1;
}
 
//Giai phong bo nho
void giaiphong(LISTSV *x)
{
    NODE *p = x->Dau;
    NODE *a;
   while( p->Next != NULL)
    {
        a = p;
        p = p->Next;
        free(a);
    }
}

//Ham Tao Danh Sach Tuy chon
int Menu()
{
    int a;
    int Ma;
	char name[20], m[20];
    LISTSV x;
    KhoitaoList(&x);
    do
    {
        printf("\n Ban chon 1,2,3,4,,5,0");
        printf("\n\nNhap so can chon roi bam enter");
        printf("\n\n\n 1 - Nhap danh sach Sinh Vien");
        printf("\n 2 - Liet ke danh sach Sinh Vien");
        printf("\n 3 - Tim kiem Sinh vien theo ID");
        printf("\n 4 - Xoa Sinh Vien theo ID");
		printf("\n 5 - Tim kiem Sinh Vien theo ten");
        printf("\n 0 - Thoat\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                {
                    int n;
                    printf("\nNhap so luong Sinh vien : ");
                    scanf("%d",&n);
                    for(int i = 1; i <= n ;i++)
                    {
                        printf("\nNhap thong tin sinh vien thu: %d \n",i);
                        NhapSV(&x);
                    }
                    break;
                }
            case 2:
                {
                    InDanhSach(x);
                    break;
                }
            case 3:
                {
                    fflush(stdin);
                    printf("\nNhap ID Sinh Vien can tim:");
                    scanf("%d",&Ma);
                    TimKiemID(x ,Ma);
                    break;
                }  
            case 4:
                {
                    fflush(stdin);
                    printf("\nNhap ID Sinh Vien Xoa: ");
                    scanf("%d",&Ma);
                    fflush(stdin);
                    XoaSVID(&x ,Ma);
                    break;
                }
            case 5:
                {
                    fflush(stdin);
                    printf("\nNhap ten Sinh Vien can tim: ");
                    gets(name);
                    TimKiemten(x ,name);
                    break;
                }
            case 6:
                {
                    fflush(stdin);
                    printf("\nNhap ten Sinh Vien Xoa: ");
                    gets(m);
                    fflush(stdin);
                    XoaSVten(&x ,m);
                    break;
                }
            case 0:
                {
                    break;
                }
            default: printf("\nBan chon sai vui long chon lai!");
        }
    }while(a != 0);
    giaiphong(&x);
    return 1;
}
int main()
{
    Menu();
    return 0;
}