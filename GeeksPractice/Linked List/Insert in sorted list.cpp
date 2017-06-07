/*
 Author : Vinay Garg
 Description : Insert in sorted list
*/

#include <bits/stdc++.h>
using namespace std;

/*
structure of the node of the list is as
struct node
{
	int data;
	struct node* next;
};
*/
void sortedInsert(struct node** head_ref, int data)
{
    struct node* current;
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {

        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else{
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
