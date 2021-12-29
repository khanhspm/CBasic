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

// Thuat toan sap xep vun dong
// Hàm vun đống cho một đỉnh
void heapify(int a[], int n, int i){  // mảng arr, n - số phần tử, i - đỉnh cần vun đống
    int max =i;    // Lưu vị trí đỉnh max ban đầu
    int l = i*2 +1;   // Vị trí con trái
    int r = l+1;    // Vị trí con phải
    if(l<n && a[l] > a[max]){   // Nếu tồn tại con trái lớn hơn cha, gán max = L
        max = l;
    }
    
    if(r<n && a[r] > a[max]){   // Nếu tồn tại con phải lớn hơn arr[max], gán max = r
        max = r;
    }
    if(max != i){      // Nếu max != i, tức là cha không phải lớn nhất
        int temp = a[i];// Đổi chỗ cho phần tử lớn nhất làm cha
        a[i] = a[max];
        a[max] = temp;   
        heapify(a ,n , max);    // Đệ quy vun các node phía dưới
    }
    
}

// Ham sap xep vun dong
void heapSort(int a[], int n){
    
    // vun dong tu duoi len len de thanh heap
    for(int i = n/2 - 1; i>=0; i--)   // i chạy từ n/2 - 1 về 0 sẽ có n/2 đỉnh nhé!
        heapify(a,n, i);   // Vun từng đỉnh
    
    // Vòng lặp để thực hiện vun đống và lấy phần tử
    for(int j = n-1 ; j>0; j--){   // chạy hết j == 1 sẽ dừng
                // mỗi lần j - 1, tương đương với k xét phần tử cuối 
        int temp = a[0];// đổi chỗ phần tử lớn nhất
        a[0] = a[j];
        a[j] = temp;  
             heapify(a, j, 0);    // vun lại đống, 
    }
}

int main(){
    time_t t1,t2;
    int a[500];
    int n = 500;
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
    heapSort(a, n);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    int durationinseconds = (int) t2 - t1;
    printf("\nThoi gian sap xep chen: t1 = %d (s) \n", (int) t1);
    printf("\nThoi gian sap xep dong: t2 = %d (s) \n", (int) t2);
    printf("\nt2 - t1 = %d (s) \n", durationinseconds);
    return 0;
}
