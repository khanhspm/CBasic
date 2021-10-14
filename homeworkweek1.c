#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    FILE *p;
    char a[128];
    p = fopen("D:\\Cbasic\\homework_week1.txt", "r");
    if(p == NULL){
      printf("Error!");   
      exit(1);             
    }
    int i = 1;
    while (fgets(a, 128, p) != NULL)
    {
        
        printf("%d %s",i, a);
        i++;
    }
    fclose(p);
    return 0;
}