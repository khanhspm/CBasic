#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char FC[10];
    int diem;
    struct node *left, *right;
};

// Thêm node
struct node * them_node(struct node *root, char FC[], int diem){
    if(root == NULL){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        strcpy(temp->FC, FC);
        temp->diem = diem;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if(strcmp(FC, root->FC) == 0) return root;
    else if(strcmp(FC, root->FC) < 0){
        root->left = them_node(root->left, FC, diem);
    }else{
        root->right = them_node(root->right, FC, diem);
    }
    return root;
}

// Node có tên nhỏ nhất
struct node* FC_min(struct node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

// Tìm kiếm
int tim_kiem(struct node *root, char fc[]){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL && strcmp(root->FC, fc) != 0){
        return 0;
    }
    if(strcmp(root->FC, fc) > 0){
        tim_kiem(root->left, fc);
    }
    else if(strcmp(root->FC, fc) < 0){
        tim_kiem(root->right, fc);
    }
    else if(strcmp(root->FC, fc) == 0){
        return 1;
    }
}

// Thay đổi điểm
void thay_doi_diem(struct node *root, char fc[], int d){
    if(strcmp(root->FC, fc) > 0){
        tim_kiem(root->left, fc);
    }
    else if(strcmp(root->FC, fc) < 0){
        tim_kiem(root->right, fc);
    }
    else if(strcmp(root->FC, fc) == 0){
        root->diem = d;
    }
}

// Hiển thị kết quả theo thứ tự tăng dần của mã đội bóng
void ket_qua(struct node *root){
    if(root == NULL){
        return;
    }
    ket_qua(root->left);
    printf("%s\t%d\n", root->FC, root->diem);
    ket_qua(root->right);
}

void main(){
    struct node *root = NULL;
    FILE *fp1, *fp2;
    char t1[10], t2[10];
    int s1, s2;
    int p1 = 0, p2 = 0;
    fp1 = fopen("BongDa.txt", "w");
    if(fp1 == NULL) exit(1);
    // Tạo dữ liệu cho file BongDa.txt
    fprintf(fp1, "FC01\tFC02\t4\t0\n");
    fprintf(fp1, "FC01\tFC03\t2\t0\n");
    fprintf(fp1, "FC01\tFC04\t0\t0\n");
    fprintf(fp1, "FC02\tFC03\t2\t0\n");
    fprintf(fp1, "FC04\tFC02\t0\t0\n");
    fprintf(fp1, "FC03\tFC04\t0\t4\n");
    fclose(fp1);
    fp2 = fopen("BongDa.txt", "r");
    if(fp2 == NULL) exit(0);
    // Đọc dữ liệu từ file BongDa.txt và lưu vào cây
    do{
        fscanf(fp2, "%s", t1);
        int x = fgetc(fp2);
        fscanf(fp2, "%s", t2);
        int y = fgetc(fp2);
        fscanf(fp2, "%d", &s1);
        int z = fgetc(fp2);
        fscanf(fp2, "%d", &s2);
        int w = fgetc(fp2);
        if(w == EOF){
            break;
        }
        printf("%s\t%s\t%d\t%d\n", t1, t2, s1, s2);

        // Tạo cây
        int tk1 = tim_kiem(root, t1);
        int tk2 = tim_kiem(root, t2);

        if(tk1 == 0){
            if(s1 > s2){
                root = them_node(root, t1, 3);
            }
            if(s1 == s2){
                root = them_node(root, t1, 1);
            }
            if(s1 < s2){
                root = them_node(root, t1, 0);
            }
        }
        if(tk2 == 0){
            if(s1 > s2){
                root = them_node(root, t2, 0);
            }
            if(s1 == s2){
                root = them_node(root, t2, 1);
            }
            if(s1 < s2){
                root = them_node(root, t2, 3);
            }
        }
        if(tk1 == 1){
            if(s1 > s2){
                thay_doi_diem(root, t1, root->diem + 3);
            }
            if(s1 == s2){
                thay_doi_diem(root, t1, root->diem +1);
            }
        }
        if(tk2 == 1){
            if(s1 < s2){
                thay_doi_diem(root, t2, root->diem + 3);
            }
            if(s1 == s2){
                thay_doi_diem(root, t2, root->diem +1);
            }
        }
    }while(!feof(fp2));
    ket_qua(root);
}