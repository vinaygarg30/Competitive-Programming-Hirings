/*
 Author : Vinay Garg
 Description : Reverse of Linked List
*/

#include <bits/stdc++.h>
using namespace std;


/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/

// Should reverse list and return new head.
Node* reverse(Node *head)
{
    struct Node* prev   = NULL;
    struct Node* current = head;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
