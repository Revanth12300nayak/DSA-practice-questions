#Explain Red Black tree. write insertion and deletion rules of red black tree in students formate.

#include <stdio.h>
#include <stdlib.h>

enum Color {RED, BLACK};

struct node{
    int data;
    enum Color color;
    struct node *left,*right,*parent;
};

struct node *createNode(int data){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->color=RED;
    new->left=new->right=new->parent=NULL;
    return new;
}

void inorder(struct node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d(%s) ",root->data, root->color==RED?"R":"B");
    inorder(root->right);
}

int main(){
    struct node *root=NULL;
    struct node *n1=createNode(10);
    struct node *n2=createNode(20);
    struct node *n3=createNode(30);

    
    root=n1; root->color=BLACK; 
    root->right=n2; n2->parent=root;
    n2->right=n3;  n3->parent=n2; 

    printf("Nodes created (sample demo) :\n");
    inorder(root);
}
