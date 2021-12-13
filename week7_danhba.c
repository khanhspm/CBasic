#include<stdio.h>
#include<string.h>

enum {SUCCESS, FAIL, MAX_ELEMENT = 100};

typedef struct phoneaddress_t{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

int BinarySearch(phoneaddress A[], char name[], int N){
    int Low, Mid, High;
    Low = 0;
    High = N-1;
    while(Low <= High){
        Mid = (Low + High) / 2;
        if(strcmp(A[Mid].name, name) < 0){
            Low = Mid + 1;
        }
        else if(strcmp(A[Mid].name, name) > 0){
            High = Mid - 1;
        }
        else return Mid;
    }
    return -1;
}

int main(){
    FILE *fp;
    FILE *fpout;
    phoneaddress phonearr[MAX_ELEMENT];
    int i, n, irc;
    char name[20];
    int reval = SUCCESS;

    printf("Ban muon nhap bao nhieu nguoi?\n");
    scanf("%d", &n);
    if((fp = fopen("phonebook.dat","rb")) == NULL){
        printf("Khong mo duoc!\n");
        reval = FAIL;
    } 
    irc = fread(phonearr, sizeof(phoneaddress), n, fp);
    printf("%d\n",irc); fclose(fp);
    if(irc < 0){
        printf("khong the doc file!\n");
        return -1;
    }
    printf("Nhap ten ban muon tim kiem: ");
    fflush(stdin);
    gets(name);
    irc = BinarySearch(phonearr, name, n);
    if(irc < 0){
        printf("Nguoi dung khong ton tai!\n");
        return -1;
    }

    if((fpout = fopen("result.txt", "w")) == NULL){
        printf("Co the tao file de ghi.\n");
        reval = FAIL;
    }
    else{
        fprintf(fpout, "%s co dia chi email la %s va so dien thoai la %s\n", phonearr[i].name, phonearr[i].email, phonearr[i].tel);
    }
    fclose(fpout);
    return reval;
}
