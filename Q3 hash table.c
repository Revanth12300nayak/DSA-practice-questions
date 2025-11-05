#example hash table using linked list (separate chaining) and write a C programe to impliment insert & search operations in hash table using linked list.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node{
    int data;
    struct node *next;
};

struct node *ht[SIZE] = {NULL};

int hashFunction(int key){
    return key % SIZE;
}

void insert(int key){
    int index = hashFunction(key);
    struct node newnode = (struct node)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->next = ht[index];
    ht[index] = newnode;
}

int search(int key){
    int index = hashFunction(key);
    struct node *temp = ht[index];
    while(temp){
        if(temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

void display(){
    for(int i=0;i<SIZE;i++){
        printf("%d -> ",i);
        struct node *temp = ht[i];
        while(temp){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    insert(23);
    insert(56);
    insert(13);
    insert(43);
    insert(33);

    display();

    if(search(43)) printf("Element found\n");
    else printf("Element not found\n");

    return 0;
}
