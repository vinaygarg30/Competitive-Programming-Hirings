/*
 Author : Vinay Garg
 Description : Delete without head pointer
*/

#include <bits/stdc++.h>
using namespace std;
/*struct Node
{
    int data;
    Node* next;
}*/

void deleteNode(Node *node)
{
   struct Node *temp = node->next;
   node->data    = temp->data;
   node->next    = temp->next;
   free(temp);
}
