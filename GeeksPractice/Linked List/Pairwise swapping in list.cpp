/*
 Author : Vinay Garg
 Description : Pairwise swapping in linked list
*/


/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as
  struct node
  {
     int data;
     struct node *next;
  }
*/
#include <bits/stdc++.h>
using namespace std;
void pairWiseSwap(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        swap(&temp->data, &temp->next->data);
        temp = temp->next->next;
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
