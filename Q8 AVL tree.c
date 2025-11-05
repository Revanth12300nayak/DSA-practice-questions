# Explain AVL tree . write a C programe to perform insertion and deletion in AVL tree.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data,height;
    struct node *left,*right;
};

int height(struct node *n){
    if(n==NULL) return 0;
    return n->height;
}

int max(int a,int b){ return (a>b)?a:b; }

struct node* createNode(int x){
    struct node *t = malloc(sizeof(struct node));
    t->data=x;
    t->left=t->right=NULL;
    t->height=1;
    return t;
}

struct node* rightRotate(struct node *y){
    struct node *x=y->left;
    struct node *T=x->right;

    x->right=y;
    y->left=T;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return x;
}

struct node* leftRotate(struct node *x){
    struct node *y=x->right;
    struct node *T=y->left;

    y->left=x;
    x->right=T;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

int getBalance(struct node *n){
    if(n==NULL) return 0;
    return height(n->left)-height(n->right);
}

struct node* insert(struct node* root,int key){
    if(root==NULL) return createNode(key);

    if(key<root->data) root->left=insert(root->left,key);
    else if(key>root->data) root->right=insert(root->right,key);
    else return root;

    root->height=1+max(height(root->left),height(root->right));
    int bf=getBalance(root);

    if(bf>1 && key<root->left->data) return rightRotate(root);
    if(bf<-1 && key>root->right->data) return leftRotate(root);
    if(bf>1 && key>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(bf<-1 && key<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

struct node* minValueNode(struct node* n){
    while(n->left) n=n->left;
    return n;
}

struct node* delete(struct node* root,int key){
    if(root==NULL) return root;

    if(key<root->data) root->left=delete(root->left,key);
    else if(key>root->data) root->right=delete(root->right,key);
    else{
        if(root->left==NULL || root->right==NULL){
            struct node *temp=root->left?root->left:root->right;
            if(temp==NULL){
                temp=root;
                root=NULL;
            }else *root=*temp;
            free(temp);
        }else{
            struct node *temp=minValueNode(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }

    if(root==NULL) return root;

    root->height=1+max(height(root->left),height(root->right));
    int bf=getBalance(root);

    if(bf>1 && getBalance(root->left)>=0) return rightRotate(root);
    if(bf>1 && getBalance(root->left)<0){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(bf<-1 && getBalance(root->right)<=0) return leftRotate(root);
    if(bf<-1 && getBalance(root->right)>0){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
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

    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,10);

    printf("Inorder AVL : ");
    inorder(root);

    root=delete(root,20);
    printf("\nAfter deletion : ");
    inorder(root);
}
