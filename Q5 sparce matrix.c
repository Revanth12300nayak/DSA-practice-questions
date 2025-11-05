# Explain multi linked representation of sparse matrix and write a C programe to represent sparse matrix using multi linked lists.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int row, col, val;
    struct node *right;
    struct node *down;
};

int main(){
    int r,c,i,j,a[10][10];
    printf("Enter rows & columns : ");
    scanf("%d%d",&r,&c);

    printf("Enter matrix elements :\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }

    struct node *head=NULL, *temp=NULL;

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j] != 0){
                struct node *newnode = malloc(sizeof(struct node));
                newnode->row = i;
                newnode->col = j;
                newnode->val = a[i][j];
                newnode->right = NULL;
                newnode->down  = NULL;

                if(head == NULL){
                    head = newnode;
                    temp = newnode;
                }
                else{
                    temp->right = newnode;
                    temp = newnode;
                }
            }
        }
    }

    printf("\nNon-zero elements (row col value) :\n");
    temp = head;
    while(temp){
        printf("(%d %d %d)\n",temp->row,temp->col,temp->val);
        temp=temp->right;
    }

    return 0;
}
