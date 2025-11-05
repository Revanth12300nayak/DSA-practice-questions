# What is splay tree? Explain its working  and write small c programe exmaple with small code.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* newNode(int x){
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data=x; t->left=t->right=NULL;
    return t;
}

struct node* rightRotate(struct node* x){
    struct node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

struct node* leftRotate(struct node* x){
    struct node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

struct node* splay(struct node* root, int key){
    if(root==NULL || root->data==key) return root;

    if(key < root->data && root->left){
        if(key < root->left->data)
            root->left->left = splay(root->left->left,key);
        root = rightRotate(root);
    }

    else if(key > root->data && root->right){
        if(key > root->right->data)
            root->right->right = splay(root->right->right,key);
        root = leftRotate(root);
    }

    return root;
}

int main(){
    struct node *root = newNode(30);
    root->left=newNode(20);
    root->left->left=newNode(10);

    root = splay(root,10); 

    printf("Root after splay = %d",root->data);
}
