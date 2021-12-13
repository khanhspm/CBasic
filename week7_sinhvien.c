#include<stdio.h>
#include<string.h>

typedef struct sinhvien{
    char id[10];
    char ten[20];
    float diem;
}sv;

void nhap(sv x){
    printf("Nhap ID: ");
    fflush(stdin);
    gets(x.id);
    printf("Nhap ten: ");
    gets(x.ten);
    printf("Nhap diem: ");
    scanf("%f", &x.diem);
}

void nhapsv(sv x[], int n){
    for(int i = 0; i < n; i++){
        nhap(x[i]);
    }
}

void xuat(sv x){
    printf("ID: %s\t Ten: %s\t Diem: %.2f\n");
}
void xuatsv(sv x[], int n){
    for(int i = 0; i < n; i++){
        xuat(x[i]);
    }
}

void sapxepten(sv x[], int n){
    sv tmp;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(strcmp(x[i].ten, x[j].ten) < 0){
                tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
        }
    }
}

void sapxepdiem(sv x[], int n){
    sv tmp;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(x[i].diem > x[j].diem){
                tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
        }
    }
}

int timkiemdiem(sv x[],float a, int n){
    int low, mid, high;
    low = 0; high = n-1;
    while(low <= high){
        mid = (low + high) / 2;
        if(x[mid].diem < a){
            low = mid +1;
        }
        else if(x[mid].diem > a){
            high = mid - 1;
        }
        else return mid;
    }
    return -1;
}

int main(){
    int n;
    sv x[100];
    int luachon;
    do{
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. In danh sach sinh vien\n");
        printf("3. Tim kiem theo diem\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &luachon);
        switch(luachon){
            case 1:{
                printf("Tong so sinh vien can nhap: ");
                scanf("%d", &n);
                nhapsv(x,n);
               
                break;
            }
            case 2:{
                xuatsv(x, n);
                break;
            }
            case 3:{
                float a;
                printf("Nhap diem ban muon tim: ");
                scanf("%f", &a);
                timkiemdiem(x, a, n);
                if(timkiemdiem(x, a, n) != -1){
                    xuat(x[timkiemdiem(x, a, n)]);
                }
                else printf("Khong tim thay!");
                break;
            }
        }
    }while(luachon != 0);
    return 0;
}