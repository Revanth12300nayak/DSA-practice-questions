# Explain min heap and max heap. write a C programe to represent max heap and min heap using arrays.

#include <stdio.h>

int maxHeap[50], minHeap[50];
int maxSize=0, minSize=0;

void insertMax(int x){     
    int i = ++maxSize;
    while(i>1 && x > maxHeap[i/2]){
        maxHeap[i]=maxHeap[i/2];
        i/=2;
    }
    maxHeap[i]=x;
}

void insertMin(int x){     
    int i = ++minSize;
    while(i>1 && x < minHeap[i/2]){
        minHeap[i]=minHeap[i/2];
        i/=2;
    }
    minHeap[i]=x;
}

void display(int h[], int size){
    for(int i=1;i<=size;i++) printf("%d ",h[i]);
    printf("\n");
}

int main(){
    insertMax(50);
    insertMax(30);
    insertMax(40);
    insertMax(10);

    insertMin(50);
    insertMin(30);
    insertMin(40);
    insertMin(10);

    printf("Max Heap Representation : ");
    display(maxHeap,maxSize);

    printf("Min Heap Representation : ");
    display(minHeap,minSize);

    return 0;
}
