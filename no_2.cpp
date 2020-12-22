#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    node *next;
}*head=NULL, *tail=NULL;

node *createNode(int num){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->num=num;
    newNode->next=NULL;
    return newNode;
}

void pushTail(int num){
    node *temp=createNode(num);
    if(!head){
        head=tail=temp;
    } else {
        tail->next=temp;
        tail=temp;
    }
}

int checkCycle(){
    node *slow=head, *fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return 1;
        }
    }
    return 0;
}

int main(){
    pushTail(20);
    pushTail(40);
    pushTail(60);
    pushTail(80);
    pushTail(100);
    head->next->next->next->next->next=head;
    checkCycle();

    if(checkCycle()){
        puts("Cycle");
    } else {
        puts("No Cycle");
    }
    return 0;
}
