#Explain multi precision arithmetic using linked list and write a C program to add two big integers using linked list.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int digit;
    struct node *next;
};

struct node* insert_front(struct node *head,int d){
    struct node *t = malloc(sizeof(struct node));
    t->digit = d;
    t->next = head;
    return t;
}

struct node* readNumber(){
    char s[500];
    printf("Enter big integer : ");
    scanf("%s",s);

    struct node *head=NULL;
    for(int i=0;s[i]!='\0';i++){      
        head = insert_front(head, s[i]-'0');
    }
    return head;
}

struct node* add(struct node* a, struct node* b){
    struct node *res=NULL;
    int carry=0,sum;

    while(a || b || carry){
        sum = carry;
        if(a){ sum+=a->digit; a=a->next; }
        if(b){ sum+=b->digit; b=b->next; }
        carry = sum/10;
        res = insert_front(res, sum%10);
    }
    return res;
}

void display(struct node *p){
    while(p){
        printf("%d",p->digit);
        p=p->next;
    }
    printf("\n");
}

int main(){
    struct node *n1,*n2,*ans;
    n1 = readNumber();
    n2 = readNumber();

    ans = add(n1,n2);

    printf("Result = ");
    display(ans);

    return 0;
}
