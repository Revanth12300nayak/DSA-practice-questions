# 5*^3 + 2*^2 + 7 polynomial representation using in linked list.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int pow;
    struct node *next;
};

struct node* createPoly() {
    int n, c, p;
    struct node *head = NULL, *temp, *newnode;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter coeff and power: ");
        scanf("%d%d", &c, &p);

        newnode->coeff = c;
        newnode->pow = p;
        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    return head;
}

void display(struct node *head){
    while(head != NULL){
        printf("%dx^%d", head->coeff, head->pow);
        head = head->next;
        if(head != NULL) printf(" + ");
    }
    printf("\n");
}

int main(){
    struct node *poly;
    printf("Enter polynomial:\n");
    poly = createPoly();

    printf("Polynomial is : ");
    display(poly);
    return 0;
}
