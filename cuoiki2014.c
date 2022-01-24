#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Định nghĩa node
struct node{
    char Username[20], Password[20];
    float diem;
    struct node *left, *right;
};

// Thêm tài khoản 
struct node * Them_tk(struct node *root, char username[], char password[], float diem){
    if(root == NULL){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        strcpy(temp->Username, username);
        strcpy(temp->Password, password);
        temp->diem = diem;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if(strcmp(username, root->Username) <= 0){
        root->left = Them_tk(root->left, username, password, diem);
    }else{
        root->right = Them_tk(root->right, username, password, diem);
    }
    return root;
}

// In ra danh sách 
void hien_thi_danh_sach(struct node *root){
    if(root == NULL){
        return;
    }
    hien_thi_danh_sach(root->left);
    printf("%20s\t%20s\t%5.2f\n", root->Username, root->Password, root->diem);
    hien_thi_danh_sach(root->right);
}

// Node có tên nhỏ nhất theo a&b
struct node* tim_kiem_username_min(struct node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

// Xóa tài khoản
struct node* xoa_tk(struct node *root, char u[]){
    if(root == NULL){
        return root;
    }
    else if(strcmp(u, root->Username) < 0){
        root->left = xoa_tk(root->left, u);
    }
    else if(strcmp(u, root->Username) > 0){
        root->right = xoa_tk(root->right, u);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            struct node *temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
        }
        else if(root->right == NULL){
            struct node *temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }
        else{
            struct node *temp = root;
            root->left = tim_kiem_username_min(root);
            root->left->right = root->right;
            root = root->left;
            strcpy(temp->Username, root->Username);
            strcpy(temp->Password, root->Password);
            temp->diem = root->diem;
            free(temp);
            temp = NULL;
        }
        return root;
    }
    return root;
}

// Tìm kiếm trả về giá trị để so sánh
int tim_kiem(struct node *root, char username[], char password[]){
    if(root->left == NULL && root->right == NULL && strcmp(root->Username, username) != 0){
        return 0;
    }
    if(strcmp(root->Username, username) > 0){
        tim_kiem(root->left, username, password);
    }
    else if(strcmp(root->Username, username) < 0){
        tim_kiem(root->right, username, password);
    }
    else if(strcmp(root->Username, username) == 0){
        if(strcmp(root->Password, password) == 0){
            return 1;
        }
        else return 0;
    }
}

// Tìm kiếm để in ra thông tin điểm
void xem_diem(struct node *root, char username[]){
    if(strcmp(root->Username, username) > 0){
        xem_diem(root->left, username);
    }
    else if(strcmp(root->Username, username) < 0){
        xem_diem(root->right, username);
    }
    else if(strcmp(root->Username, username) == 0){
        printf("Diem cua ban la: %.2f\n", root->diem);
    }
}

// Thay đổi password
void thay_doi_pass(struct node *root, char username[], char new_password[]){
    if(strcmp(root->Username, username) > 0){
        thay_doi_pass(root->left, username, new_password);
    }
    else if(strcmp(root->Username, username) < 0){
        thay_doi_pass(root->right, username, new_password);
    }
    else if(strcmp(root->Username, username) == 0){
        strcpy(root->Password, new_password);
        printf("Doi mat khau thanh cong!\n");
    }
}

// Ghi lại file
void ghi_lai_file(struct node *root, FILE *fp){
    if(root == NULL){
        return;
    }
    fprintf(fp,"%s\t%s\t%f\n", root->Username, root->Password, root->diem);
    ghi_lai_file(root->left, fp);
    ghi_lai_file(root->right, fp);
}

void main(){
    struct node *root = NULL;
    int lua_chon_1, lua_chon_2, lua_chon_3;
    FILE *fp1, *fp2, *fp3;
    char username[20];
    char password[20];
    int a, b, c;
    float d;

/*
    // Ghi dữ liệu vào File sinhvien.txt để có dữ liệu ban đầu
    fp1 = fopen("sinhvien.txt", "w");
    if(fp1 == NULL) exit(1);
    fprintf(fp1, "Admin\tAdmin12\t0\n");
    fprintf(fp1, "khanhcs\tmvk652002\t9.5\n");
    fprintf(fp1, "hieucs\thieuanlon\t8\n");
    fprintf(fp1, "quancs\tquankkk\t8.5\n");
    fclose(fp1);
*/

    // Lấy dữ liệu ra và tạo thành cây
    fp2 = fopen("sinhvien.txt", "r");
    if(fp2 == NULL) exit(1);
    do{
        fscanf(fp2, "%s", username);
        a = fgetc(fp2);
        fscanf(fp2, "%s", password);
        b = fgetc(fp2);
        fscanf(fp2, "%f", &d);
        c = fgetc(fp2);
        if(c == EOF){
            break;
        }
        // Tạo cây
        root = Them_tk(root, username, password, d);
    }while(!feof(fp2));
    fclose(fp2);


    do{
        printf("\n\n--------------------------Menu--------------------------------\n");
        printf("1. Dang nhap\n");
        printf("2. Thoat\n");
        printf("\nChon chuc nang: ");
        scanf("%d", &lua_chon_1);
        printf("\n\n");
        switch(lua_chon_1){
            case 1:{
                int dem = 0;
                lua_chon_2 = 0;
                lua_chon_3 = 0;
                do{
                    if(dem == 3) break;
                    if(lua_chon_2 == 4) break;
                    if(lua_chon_3 == 3) break;
                    printf("Username: ");
                    fflush(stdin);
                    gets(username);
                    printf("Password: ");
                    gets(password);
                    int tk = tim_kiem(root, username, password);
                    if(tk == 1){
                        printf("Dang nhap thanh cong\n");

                        // Nếu tên đăng nhập là Admin
                        if(strcmp(username, "Admin") == 0){
                            do{
                                printf("\n\n--------------------------Menu--------------------------------\n");
                                printf("1. Them sinh vien\n");
                                printf("2. In ra danh sach sinh vien\n");
                                printf("3. Xoa sinh vien\n");
                                printf("4. Thoat\n");
                                printf("\nChon chuc nang: ");
                                scanf("%d", &lua_chon_2);
                                printf("\n\n");
                                switch(lua_chon_2){
                                    case 1:{
                                        char new_username[20];
                                        char new_password[20];
                                        float new_diem;
                                        printf("Username: ");
                                        fflush(stdin);
                                        gets(new_username);
                                        printf("Password: ");
                                        gets(new_password);
                                        printf("Diem: ");
                                        scanf("%f", &new_diem);
                                        root = Them_tk(root, new_username, new_password, new_diem);
                                        break;
                                    }
                                    case 2:{
                                        hien_thi_danh_sach(root);
                                        break;
                                    }
                                    case 3:{
                                        char xoa_username[20];
                                        printf("Username can xoa: ");
                                        fflush(stdin);
                                        gets(xoa_username);
                                        xoa_tk(root, xoa_username);
                                        break;
                                    }
                                    case 4: break;
                                }
                            }while(lua_chon_2 != 4);
                        }

                        // Nếu là người dùng
                        else{
                            do{
                                printf("\n\n--------------------------Menu--------------------------------\n");
                                printf("1. Xem diem\n");
                                printf("2. Thay doi mat khau\n");
                                printf("3. Thoat\n");
                                printf("\nChon chuc nang: ");
                                scanf("%d", &lua_chon_3);
                                printf("\n\n");
                                switch(lua_chon_3){
                                    case 1:{
                                        xem_diem(root, username);
                                        break;
                                    }
                                    case 2:{
                                        char s1[20], s2[20];
                                        int xet = 0;
                                        do{
                                            printf("Nhap mat khau moi: ");
                                            fflush(stdin);
                                            gets(s1);
                                            printf("Nhap lai mat khau moi: ");
                                            gets(s2);
                                            if(strcmp(s1, s2) == 0){
                                                thay_doi_pass(root, username, s1);
                                                xet = 1;
                                                break;
                                            }
                                            else if(strcmp(s1, s2) != 0){
                                                printf("Xac nhan lai mat khau moi khong dung!\n");
                                            }
                                        }while(xet == 0);
                                    }
                                }
                            }while(lua_chon_3 != 3);
                        }
                    }
                    if(tk == 0){
                        printf("Sai tai khoan hoac mat khau!\n");
                        dem++;
                    }
                }while(dem!=3);
            }
            case 2:{
                int xoa_file_cu;
                xoa_file_cu = remove("sinhvien.txt");
                if(xoa_file_cu == 0){
                    fp3 = fopen("sinhvien.txt", "w");
                    ghi_lai_file(root, fp3);
                    fclose(fp3);
                }
                break;
                exit(1);
            }
        }
    }while(lua_chon_1 != 2);
}