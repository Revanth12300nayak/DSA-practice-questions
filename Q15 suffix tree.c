#Define suffix tree. Expalin insertion & deletion operations of suffix tree in DSA. write simple C representation demonstration programe.

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *child[26];
};

struct node* createNode(){
    struct node n = (struct node)malloc(sizeof(struct node));
    for(int i=0;i<26;i++) n->child[i]=NULL;
    return n;
}

void insertSuffix(struct node *root, char *s){
    struct node *curr=root;
    for(int i=0;s[i];i++){
        int idx = s[i]-'a';
        if(curr->child[idx]==NULL)
            curr->child[idx]=createNode();
        curr=curr->child[idx];
    }
}

int main(){
    char str[]="banana";
    struct node *root = createNode();

    for(int i=0;str[i];i++)
        insertSuffix(root,&str[i]);

    printf("Suffix tree insertion done for string = %s\n",str);
    return 0;
}
