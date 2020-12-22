#include <stdio.h>
#include <stdlib.h>

struct Data1
{
    int num1;
    Data1* next1;
}*head1 = NULL, *tail1 = NULL;

struct Data
{
    int num2;
    Data* next;
}*head = NULL, *tail = NULL;

struct Data1* initialize(int num2)
{
    struct Data1* newData = (Data1*)malloc(sizeof(Data1));

    newData->num1 = num2;
    newData->next1 = NULL;

    return newData;
}

struct Data* createNode(int num2)
{
    struct Data* newNode = (Data*)malloc(sizeof(Data));
    
    newNode->num2 = num2;
    newNode->next = NULL;

    return newNode;
}

void pushHead(int num2)
{
    struct Data* newNode = createNode(num2);

    if (!head ) head = tail = newNode;
    else 
    {
        newNode->next  = head;
        head =  newNode;
    }
}

void pushTail(int num2)
{
    struct Data* newNode = createNode(num2);

    if (!head) head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void pushMid(int num2)
{
    struct Data* newNode = createNode(num2);
    if (!head) head = tail = newNode;
    else if (newNode->num2 < head->num2) pushHead(num2);
    else if (newNode->num2 > tail->num2 ) pushTail(num2);
    else
    {
        struct Data *current = head;
        while (current)
        {
            if (newNode->num2 < current->next->num2) break;
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }   
}

void pushTail1(int num2)
{
    struct Data1* newData = initialize(num2);
    if (!head1) head1 = tail1 = newData;
    else
    {
        tail1->next1 = newData;
        tail1 = newData;
    }
}

void print1()
{
    struct Data* current = head;
    while (current)
    {
        printf("%d ", current->num2);
        current = current->next;
    }
    puts("");
}

void print2()
{
    struct Data1* current = head1;
    while (current)
    {
        printf("%d ", current->num1);
        current = current->next1;
    }
    puts("");
}

void popHead()
{
    if (!head1) return;
    else 
    {
        struct Data1* current = head1;
        head1 = head1->next1;
        free(current);
        current = NULL;
    }
}

void merge()
{
    struct Data1* current = head1;
    while(current)
    {
        pushMid(current->num1);
        current=  current->next1;
        popHead();
    }
}

int main()
{
    pushTail1(20);
    pushTail1(40);
    pushTail1(60);
    print2();
    pushTail(30);
    pushTail(50);
    pushTail(90);
    print1();
    merge();
    print1();


    return 0;
}
