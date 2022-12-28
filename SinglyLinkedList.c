#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

//Defining Head Node
struct node *head = NULL;

//Function Definition
void InsertBeg(int);
void InsertEnd(int);
void InsertBefore(int , int);
void InsertAfter(int , int);
void DeleteBeg();
void DeleteEnd();
void DeleteNode(int);
void DeleteAfter(int);
void Display();

int main()
{
    InsertEnd(50);
    InsertBeg(20);
    InsertBeg(10);
    InsertEnd(60);
    InsertBefore(30, 50);
    InsertAfter(40, 30);
    Display();
    printf("\n");

    DeleteBeg();
    DeleteEnd();
    DeleteNode(30);
    DeleteAfter(40);
    Display();

    return 0;
}

void Display()
{
    struct node *temp;
    temp = head;
    if(head == NULL)
    return;
    while(temp != NULL)
    {
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
}

void InsertBeg(int data)
{
    struct node *new_n;
    new_n = malloc(sizeof(struct node));
    new_n -> data = data;
    if(head == NULL)
    {
        new_n -> next = NULL;
    }
    else
    {
        new_n -> next = head;
    }
    head = new_n;
}

void InsertEnd(int data)
{
    struct node *new_n, *temp; 
    new_n = malloc(sizeof(struct node));
    new_n -> data = data;
    new_n -> next = NULL;
    if(head == NULL)
    {
        head = new_n;
    }
    else
    {
        temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = new_n;
    }
}

void InsertBefore(int data, int num)
{
    if(head == NULL)
    return;

    struct node *new_n, *temp, *ptr;
    temp = head;
    new_n = malloc(sizeof(struct node));
    new_n -> data = data;
    while(temp -> data != num)
    {
        ptr = temp;
        temp = temp -> next;
    }
    ptr -> next = new_n;
    new_n -> next = temp;
}

void InsertAfter(int data, int num)
{
    if(head == NULL)
    return;

    struct node *new_n, *temp;
    temp = head;
    new_n = malloc(sizeof(struct node));
    new_n -> data = data;
    while(temp -> data != num)
    {
        temp = temp -> next;
    }
    new_n -> next = temp -> next;
    temp -> next = new_n;
}

void DeleteBeg()
{
    if(head == NULL)
    return;

    struct node *temp;
    temp = head;
    head = head -> next;
    free(temp);
}

void DeleteEnd()
{
    if(head == NULL)
    return;

    struct node *temp, *ptr;
    temp = head;
    while(temp -> next != NULL)
    {
        ptr = temp;
        temp = temp -> next;
    }
    ptr -> next = NULL;
    free(temp);
}

void DeleteNode(int num)
{
    if(head == NULL)
    return;

    struct node *temp, *ptr;
    temp = head;
    while(temp -> data != num)
    {
        ptr = temp;
        temp = temp -> next;
    }
    ptr -> next = temp -> next;
    free(temp);
}

void DeleteAfter(int num)
{
    if(head == NULL)
    return;

    struct node *ptr, *temp;
    temp = head;
    while(ptr -> data != num)
    {
        ptr = temp;
        temp = temp -> next;
    }
    ptr -> next = temp -> next;
    free(temp);
}