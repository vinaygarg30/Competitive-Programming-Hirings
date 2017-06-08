/*
 Author : Vinay Garg
 Description : Intersection of two linked list
*/

#include <bits/stdc++.h>
using namespace std;

/* The structure of the Linked list Node is as follows:
struct Node {
    int val;
    struct Node* next;
}; */

void intersection(Node **head1, Node **head2,Node **head3)
{
  *head3 = NULL;
  struct Node** lastPtrRef = &(*head3);

  while ((*head1)!=NULL && (*head2)!=NULL)
  {
    if ((*head1)->val == (*head2)->val)
    {
      push(lastPtrRef, (*head1)->val);
      lastPtrRef = &((*lastPtrRef)->next);
      (*head1) = (*head1)->next;
      (*head2) = (*head2)->next;
    }
    else if ((*head1)->val < (*head2)->val)
      (*head1)=(*head1)->next;
    else
      (*head2)=(*head2)->next;
  }
}
