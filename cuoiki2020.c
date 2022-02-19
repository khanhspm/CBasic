#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Solieu{
    char Diadiem[40];
    int Gio;
    int Phut;
};
typedef struct Solieu solieu;

struct Node{
    solieu data;
    struct Node *next;
};
typedef struct Node* node;

//Kiểm tra danh sách rỗng
int Empty(node list){
    return list == NULL;
}

//Chèn node mới vào đầu danh sách
void addnew(node* head, solieu x){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    if(Empty(*head)){
        *head = p;
    }
}

// Thêm node
void add(node* head, solieu x){
    if(Empty(*head)){
        addnew(head, x);
    }else{
        struct Node* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}

// Tìm kiếm theo địa điểm
void searchdd(node head, char diadiem[]){
    int a = 0;
    if(Empty(head)){
        printf("Khong co so lieu!\n");
        return;
    }else{
        struct Node* p = head;
        while(p != NULL){
            if(strcmp(diadiem, p->data.Diadiem) == 0){
                printf("%50s%10d%10d\n", p->data.Diadiem, p->data.Gio, p->data.Phut);
                a++;
            }
            p = p->next;
        }
    }
    if(a == 0) printf("Ban chua toi dia diem nay trong ngay!\n");
}

// Tìm kiếm theo thời gian
void searchtg(node head, int gio, int phut){
    int b = 0;
    if(Empty(head)){
        printf("Khong co so lieu!\n");
        return;
    }else{
        struct Node* p = head;
        while(p != NULL){
            if(gio == p->data.Gio && phut == p->data.Phut){
                printf("%50s\n", p->data.Diadiem);
                b++;
            }
            p = p->next;
        }
    }
    if(b == 0) printf("KHONG tim thay lich su di chuyen\n");
}

// Truy vết
void truy_vet(node head, char diadiem[], int gio, int phut){
    int c = 0;
    if(Empty(head)){
        printf("Khong co du lieu!\n");
        return;
    }else{
        struct Node* p = head;
        while(p != NULL){
            if(strcmp(diadiem, p->data.Diadiem) == 0){
                if(gio < p->data.Gio){
                    printf("Ban co kha nang bi lay Covid, can khai bao y te ngay lap tuc!\n");
                    c++;
                }
                else if(gio == p->data.Gio){
                    if(phut <= p->data.Phut){
                        printf("Ban co kha nang bi lay Covid, can khai bao y te ngay lap tuc!\n");
                        c++;
                    }
                }
            }
            p = p->next;
        }
    }
    if(c == 0) printf("Lich su di chuyen cua ban OK!\n");
}

// Đưa ra màn hình
void show(const node head){
    const struct Node* p = head;
    while(p != NULL){
        printf("%50s%10d%10d\n", p->data.Diadiem, p->data.Gio, p->data.Phut);
        p = p->next;
    }
}

void main(){
    node l = NULL;
    FILE *fp1, *fp2;
    int lua_chon_1;

    // Ghi dữ liệu vào FILE
    fp1 = fopen("COVID19.txt", "w");
    if(fp1 == NULL) exit(1);
    fprintf(fp1, "Nha_rieng 0 0\n");
    fprintf(fp1, "C1_BKHN 8 15\n");
    fprintf(fp1, "Highland_coffee_BK 8 47\n");
    fprintf(fp1, "B1_BKHN 9 12\n");
    fprintf(fp1, "Nha_an_1-5 11 57\n");
    fprintf(fp1, "Hoi_truong_C2 15 25\n");
    fclose(fp1);

    fp2 = fopen("COVID19.txt", "r");
    if(fp2 == NULL) exit(1);
    solieu x;
    while(fscanf(fp2, "%s %d %d\n", x.Diadiem, &x.Gio, &x.Phut) != EOF){
        printf("%50s%10d%10d\n", x.Diadiem, x.Gio, x.Phut);
        add(&l, x);
    }
    fclose(fp2);
    do{
        printf("============================================================\n\n");
        printf("CHUONG TRINH TRUY VET COVID19\n");
        printf("1. Nap file log lich su di chuyen\n");
        printf("2. Tim kiem lich su di chuyen theo dia diem\n");
        printf("3. Tim kiem lich su di chuyen theo thoi gian\n");
        printf("4. Kiem tra truy vet moi nhat\n");
        printf("5. Thoat\n");
        printf("============================================================\n\n");

        printf("Ban chon: ");
        scanf("%d", &lua_chon_1);

        switch(lua_chon_1){
            case 2:{
                char diadiem[40];
                scanf("%s", diadiem);
                searchdd(l, diadiem);
            }
            case 3:{
                int gio = -1;
                int phut = -1;
                do{
                    printf("Nhap gio: ");
                    scanf("%d", &gio);
                    printf("Nhap phut: ");
                    scanf("%d", &phut);
                    if(gio >= 0 && gio < 24 && phut >= 0 && phut < 60) break;
                }while(1);
                searchtg(l, gio, phut);
            }
            case 4:{
                char diadiemCovid[40];
                int gioCovid = -1;
                int phutCovid = -1;
                printf("Dia diem: ");
                scanf("%s", diadiemCovid);
                do{
                    printf("Nhap gio: ");
                    scanf("%d", &gioCovid);
                    printf("Nhap phut: ");
                    scanf("%d", &phutCovid);
                    if(gioCovid >= 0 && gioCovid < 24 && phutCovid >= 0 && phutCovid < 60) break;
                }while(1);
                truy_vet(l, diadiemCovid, gioCovid, phutCovid);
            }
            case 5: break;
        }
    }while(lua_chon_1 != 5);
    
}