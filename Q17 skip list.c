#Explain search, insertion and deletion operations in skip list. write sample c programe.

#include <stdio.h>
#include <stdlib.h>

#define MAXLVL 3

struct node{
    int key;
    struct node *next[MAXLVL];
};

struct node* newNode(int key){
    struct node n = (struct node)malloc(sizeof(struct node));
    n->key=key;
    for(int i=0;i<MAXLVL;i++) n->next[i]=NULL;
    return n;
}

void insert(struct node *head,int key){
    struct node *update[MAXLVL];
    struct node *curr=head;

    for(int lvl=MAXLVL-1;lvl>=0;lvl--){
        while(curr->next[lvl] && curr->next[lvl]->key < key)
            curr=curr->next[lvl];
        update[lvl]=curr;
    }

    struct node *n = newNode(key);
    for(int lvl=0;lvl<MAXLVL;lvl++){
        n->next[lvl]=update[lvl]->next[lvl];
        update[lvl]->next[lvl]=n;
    }
}

int search(struct node *head,int key){
    struct node* curr=head;
    for(int lvl=MAXLVL-1;lvl>=0;lvl--){
        while(curr->next[lvl] && curr->next[lvl]->key < key)
            curr=curr->next[lvl];
    }
    curr=curr->next[0];
    return(curr && curr->key==key);
}

int main(){
    struct node *head=newNode(-1);

    insert(head,10);
    insert(head,30);
    insert(head,20);

    printf("Search 20 → %s\n", search(head,20)?"Found":"Not Found");
}
