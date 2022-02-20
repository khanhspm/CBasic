#include<stdio.h>
#include<stdlib.h>

void main(){
    FILE *fp;
    fp = fopen("TudienAnh-Viet.txt", "w");
    if(fp == NULL) exit(1);
    fprintf(fp, "school\ttruong hoc\n");
    fprintf(fp, "i\ttoi\n");
    fprintf(fp, "you\tban\n");
    fprintf(fp, "very\tnhieu\n");
    fprintf(fp, "computer\tmay tinh\n");
    fprintf(fp, "tree\tcay\n");
    fprintf(fp, "stone\tda\n");
    fprintf(fp, "and\tva\n");
    fclose(fp);
}