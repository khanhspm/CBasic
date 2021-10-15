#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int  main(){
    FILE *p;
    int *x;
    int i, n, v;
    printf("Nhap tong so can nhap\n");
    scanf("%d", &n);
    x = (int *) malloc(n*sizeof(int));
    int sum = 0;
    i = 0;
    while(i < n){
        printf("Nhap so thu %d\n", i+1);
        scanf("%d", &v);
        x[i++] = v; 
        sum += v;
    }
    p = fopen("D:\\Cbasic\\out.txt", "w");
    if(p == NULL){
        printf("Errol!");
        exit(1);
    }
    for(i = n-1; i >= 0; i--){
        fprintf(p, "%d ", x[i]);
    }
    fprintf(p, "%d", sum);
    fclose(p);
    return 0;
}