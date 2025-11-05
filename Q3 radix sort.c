# explain radixsort using linked list and write a C programme to impliment radix sort using linked lists.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *bucket[10], *bucketEnd[10];

void insert(int index, int value){
    struct node newnode = (struct node)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
if(bucket[index]==NULL){
        bucket[index]=bucketEnd[index]=newnode;
    }else{
        bucketEnd[index]->next=newnode;
        bucketEnd[index]=newnode;
    }
}
void collect(struct node **head){
    struct node *p=NULL;
    for(int i=0;i<10;i++){
        if(bucket[i]!=NULL){
            if(*head==NULL){
                *head=bucket[i];
                p=bucketEnd[i];
            }
            else{
                p->next=bucket[i];
                p=bucketEnd[i];
            }
        }
        bucket[i]=bucketEnd[i]=NULL;
    }
}

int maxDigit(int a[],int n){
    int max=a[0];
    for(int i=1;i<n;i++) if(a[i]>max) max=a[i];
    int d=0;
    while(max){ d++; max/=10; }
    return d;
}

void radixSort(int a[],int n){
    struct node *head=NULL,*temp;
    for(int i=0;i<n;i++){
        temp=malloc(sizeof(struct node));
        temp->data=a[i];
        temp->next=head;
        head=temp;
    }

    int digits=maxDigit(a,n);
    int exp=1;

    while(digits--){
        temp=head;
        while(temp){
            insert((temp->data/exp)%10,temp->data);
            temp=temp->next;
        }
        head=NULL;
        collect(&head);
        exp*=10;
    }

    temp=head;
    int i=0;
    while(temp){
        a[i++]=temp->data;
        temp=temp->next;
    }
}

int main(){
    int a[]={170,45,75,90,802,24,2,66};
    int n=8;

    radialSort(a,n);

    printf("Sorted : ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}
