#include<stdio.h>

void repeatTriangle(int n, char ch){
    if(n<1) return;
    for(int i = 1; i <= n; i++){
        printf("%c ", ch);
    }
    printf("\n");
    repeatTriangle(n-1, ch);
}

int main(){
    int n;
    char ch;
    printf("Nhap n: ");
    scanf("%d", &n);
    fflush(stdin);
    printf("Nhap ki tu: ");
    scanf("%c", &ch);
    printf("\n");
    repeatTriangle(n, ch);
    return 0;
}