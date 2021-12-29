#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

int phandoan(char c[], int low, int high){
    char p = c[high];
    int left = low;
    int right = high - 1;
    while(1){
        while(left <= right && c[left] < p) left++;
        while(right >= left && c[right] > p) right--;
        if(left >= right) break;
        swap(&c[left], &c[right]);
        left++;
        right--;
    }
    swap(&c[left], &c[high]);
    return left;
}

void sxnhanh(char c[], int low, int high){
    if(low < high){
        int pi = phandoan(c, low, high);
        sxnhanh(c, low, pi - 1);
        sxnhanh(c, pi+1, high);
    }
}

int main(){
    char ch;
    char c[100];
    int n = 100;
    int i = 0;
    FILE *fp;
    fp = fopen("D:\\Cbasic\\week11_kitu.txt", "r");
    if(fp == NULL){
        printf("Errol !");
        exit(1);
    }
    while((ch = fgetc(fp)) != EOF && i < n){
        printf("%c", ch);
        c[i] = ch;
        i++;
    }
    fclose(fp);
    sxnhanh(c, 0, n-1);
    printf("\n\n\nSau khi sap xep ki tu:\n%s", c);
    return 0;

}