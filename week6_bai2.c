#include<stdio.h>

#define MAX 10

int xet(int x, int a[]){
    for(int i = 0; i < MAX; i++){
        if(x == a[i]) return i+1;
    }
    return 0;
}

int main(){
    int n=MAX;
    int a[n];
    printf("Nhap 11 so nguyen\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int x;
    scanf("%d", &x);
    printf("%d", xet(x,a));
    return 0;
}