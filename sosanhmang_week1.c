#include<stdio.h>

int sosanh(int a[], int b[], int size){
    int i;
    for(i=0; i<size; i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int size;
    int i;
    scanf("%d", &size);
    int a[size], b[size];
    printf("Hay nhap danh sach %d gia tri \n", size);
    for(i=0; i<size; i++){
        scanf("%d", &a[i]);
    }
    printf("Hay nhap danh sach %d gia tri \n", size);
    for(i=0; i<size; i++){
        scanf("%d", &b[i]);
    }
    if(sosanh(a, b, size)==1){
    printf("Mang a va Mang b bang nhau\n");
    }
    if(sosanh(a, b, size)==0){
    printf("Mang a va Mang b khong bang nhau\n");
    }
    return 0;
}