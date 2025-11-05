#Explain B+tree. write insertion and deletion algorithm in B+tree with neat definition.

#include <stdio.h>

#define MAX 4

struct Leaf{
    int key[MAX];
    int count;
};

void insertLeaf(struct Leaf *L, int k){
    int i=L->count-1;
    while(i>=0 && k < L->key[i]){
        L->key[i+1]=L->key[i];
        i--;
    }
    L->key[i+1]=k;
    L->count++;
}

int main(){
    struct Leaf L;
    L.count=0;

    insertLeaf(&L,20);
    insertLeaf(&L,5);
    insertLeaf(&L,40);
    insertLeaf(&L,10);

    printf("Leaf Node Keys : ");
    for(int i=0;i<L.count;i++) printf("%d ",L.key[i]);
}
