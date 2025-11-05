# Explain binary search tree (BST) . write a C programe to create BST, insert nodes and perform inorder traversal.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* createNode(int x){
    struct node *t = malloc(sizeof(struct node));
    t->data=x;
    t->left=t->right=NULL;
    return t;
}

struct node* insert(struct node *root,int x){
    if(root==NULL) return createNode(x);

    if(x < root->data) root->left  = insert(root->left,x);
    else if(x > root->data) root->right = insert(root->right,x);

    return root;
}

void inorder(struct node *root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    struct node *root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);

    printf("Inorder Traversal : ");
    inorder(root);
    return 0;
}
