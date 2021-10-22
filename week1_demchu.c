#include<stdio.h>
#include<string.h>

int main(){
    char s[100];
    gets(s);
    char c[100];
    char A = 'A';
    char a = 'a';
    int i, j;
    int x[100] = {0};
    for(i=0; i <26; i++){
       c[i] = A;
       A++;
    }
    for(i=26; i<51; i++){
       c[i] = a;
       a++;
    }
    
    for(j=0; j<=strlen(s); j++){
       for(i=0; i<51; i++){
           if(s[j]==c[i]){
               x[i]++;
           }
        }
    }
    for(i=0; i<51; i++){
        if(x[i]>0){
            printf("The letter '%c' appears %d time(s).\n", c[i], x[i]);
        }
    }
    return 0;
}