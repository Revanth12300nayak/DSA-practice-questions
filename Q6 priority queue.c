# Define priority queue. Explain its implimentation using heap and write a C programe to insert & delete elements in priority queue using max heap.

#include <stdio.h>

int heap[50];
int size = 0;

void insert(int x){
    int i = ++size;
    while(i > 1 && x > heap[i/2]){   // compare with parent
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = x;
}

int delete(){
    int root = heap[1];
    int last = heap[size--];
    int i = 1, child;

    while(i*2 <= size){
        child = i*2;
        if(child+1 <= size && heap[child+1] > heap[child]) child++;

        if(last >= heap[child]) break;

        heap[i] = heap[child];
        i = child;
    }
    heap[i] = last;
    return root;
}

void display(){
    for(int i=1;i<=size;i++) printf("%d ",heap[i]);
    printf("\n");
}

int main(){
    insert(40);
    insert(50);
    insert(20);
    insert(60);
    insert(10);

    printf("Heap elements : ");
    display();

    printf("Deleted highest priority = %d\n",delete());

    printf("After deletion heap : ");
    display();

    return 0;
}
