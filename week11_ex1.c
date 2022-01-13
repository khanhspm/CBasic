#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include<string.h>

int bb[52];

int check(int r){
        for(int i = i; i < 52; i++){
                if(r == bb[i]) return r;
        }
        return 0;
}

int random(){
        int r = 1 + rand() % (52);
        if(check(r) == 0) return r;
        else random();
}

void tronbai(){
        for(int i = 0; i < 52; ++i){
                bb[i] = random();
                printf("%d ", bb[i]);
        }
}

void chiabai(int a[], int b[], int c[], int d[]){
        for(int i = 0; i < 52; i+=4){
                a[i] = bb[i];
                b[i] = bb[i+1];
                c[i] = bb[i+2];
                d[i] = bb[i+3];
        }
}

void in(int x[]){
        for(int i = 0; i < 13; i++){
                printf("%d ", x[i]);
        }
        printf("\n");
}

// 1 -> 13 : Bích  -> B
// 14 -> 26 : Cơ   -> C
// 27 -> 39: Chuồn  -> Ch
// 40-> 52: Rô     -> R

int main(){
        int a[13], b[13], c[13], d[13];
        random();
        tronbai();
        chiabai(a, b, c, d);
        in(b);
        return 0;
}