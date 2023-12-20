#include<bits/stdc++.h>

using namespace std;


void swap(int *x , int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low;
    for (int j=low;j<high;j++){
        if(ar[j]<=pivot){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[high], &arr[i]);
    return i;
}
void qsort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        qsort(arr, low, pi-1);
        qsort(arr, pi+1, high);
    }
}
int main(){

    int arr[] = {2,7,21,4,6,9,3,4,5,6,7,87,7,7,6,45,43};
    int length = sizeof(arr)/sizeof(arr[0]);
    qsort(arr, 0, length-1);
    for (int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}