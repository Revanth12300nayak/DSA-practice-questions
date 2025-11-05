# Explain heapify algorithm. write a C programe to perform heapify operation in max heap.

#include <stdio.h>

void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    int temp;

    if(left <= n && a[left] > a[largest])
        largest = left;

    if(right <= n && a[right] > a[largest])
        largest = right;

    if(largest != i){
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

int main(){
    int a[50]={0,40,20,30,35,25}; 
    int n=5;


    for(int i=n/2; i>=1; i--)
        heapify(a,n,i);

    printf("After Heapify (Max Heap) : ");
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
}
