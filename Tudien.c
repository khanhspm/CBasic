#include <stdlib.h>
#include <stdio.h>  
#include<string.h>
#include<limits.h>

void search(char s1[], char s2[]){
   int n = 0;
   int m = 0;
   int times = 0;
   // bien luu giu do dai cua chuoi can tim kiem
   int len = strlen(s2);
 
   while(s1[n] != '\0') {
 
      if(s1[n] == s2[m]) {    // neu ky tu dau tien la giong nhau
 
         // tiep tuc tim kiem
         while(s1[n] == s2[m]  && s1[n] !='\0') {
            n++;
            m++;
         }
 
         // Neu day ky tu nay co do dai bang chuoi tim kiem
         if(m == len && (s1[n] == ' ' || s1[n] == '\0')) {
 
            // Chuc mung ban da tim ra chuoi can tim
            times++;
         }
      } else {   // Neu ky tu dau tien khong giong nhau
         while(s1[n] != ' ') {    //bo qua, tiep tuc tim kiem tu tiep theo
            n++;
            if(s1[n] == '\0')
            break;
         }
      }
         
      n++;
      m=0;  // reset bien dem.
   }
 
   if(times > 0) {
      printf("%s\n", s1);
   }
}

struct tex{
  char d[50];
};

int main(){
  FILE *fp;
  char a[50];
  struct tex k[50];
  int i = 0;
  char txt[50];
  fp = fopen("Tudien.txt", "r");
  if(fp == NULL){
    return -1;
  }
   char b[50];
  fflush(stdin);
  gets(b);
  while(fgets(a, 50,fp) != NULL){
    sscanf(a, "%[^,]", txt);
    for(int j = 0; j< sizeof(k[i].d) / sizeof(k[i].d[0]); j++){
      k[i].d[j] = txt[j];
    }
    search(b, k[i].d);
    i++;
  }
  fclose(fp);

  return 0;
}