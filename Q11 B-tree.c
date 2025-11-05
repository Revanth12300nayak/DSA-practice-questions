# Explain B-tree. write short notes on insertion and deletion operations of B-tree.

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

struct BNode{
    int key[MAX];
    int cnt;
};

void insert(struct BNode *node, int k){
    int i=node->cnt-1;
    while(i>=0 && k < node->key[i]){
        node->key[i+1] = node->key[i];
        i--;
    }
    node->key[i+1] = k;
    node->cnt++;
}

int main(){
    struct BNode node;
    node.cnt = 0;

    insert(&node,30);
    insert(&node,10);
    insert(&node,20);

    printf("Node keys : ");
    for(int i=0;i<node.cnt;i++)
        printf("%d ",node.key[i]);

    return 0;
}
