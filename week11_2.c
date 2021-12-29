#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void sxchen(int a[], int n){
    int i, key, j;
    for(i = 1; i < n; i++){
        key = a[i];
        j = i-1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
 
int partition (int a[], int low, int high)
{
    int pivot = a[high];    // pivot
    int left = low;
    int right = high - 1;
    while(1){
        while(left <= right && a[left] < pivot) left++;
        while(right >= left && a[right] > pivot) right--;
        if (left >= right) break;
        swap(&a[left], &a[right]);
        left++;
        right--;
    }
    swap(&a[left], &a[high]);
    return left;
}
 
/* Hàm thực hiện giải thuật quick sort */
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(a, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main(){
    time_t t1,t2;
    int a[20];
    int n = 20;
    for(int i = 0; i < n; i++){
        a[i] = rand();
    }
    time(&t1);
    sxchen(a, n);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    time(&t2);
    quickSort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    int durationinseconds = (int) t2 - t1;
    printf("\nThoi gian sap xep chen: t1 = %d (s) \n", (int) t1);
    printf("\nThoi gian sap xep nhanh: t2 = %d (s) \n", (int) t2);
    printf("\nt2 - t1 = %d (s) \n", durationinseconds);
    return 0;
}
