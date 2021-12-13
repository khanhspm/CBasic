#include<stdio.h>

int count = 0;

#define MAX 100

int search(int a[], int x){
    for(int i = 0; i < MAX; i++){
        a[i] = i+1; 
    }
    int k ;
    int r = MAX;
    while(k < r){
        int mid = (k + r)/2;
        if(a[mid] < x){
            k = mid+1;
            count++;
        }
        else{
            r = mid;
            count++;
        }
        if(a[k] == x){
            return k+1;
            count++;
        }
    }
    return -1;
}

int main(){
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);
    int a[MAX];
    if(search(a,x) > 0){
        printf("%d\n", search(a,x));
        printf("%d ", count);
    }
    else printf("KHONG TIM THAY!");
    return 0;
}