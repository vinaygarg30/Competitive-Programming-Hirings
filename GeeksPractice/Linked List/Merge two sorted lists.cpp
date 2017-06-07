/*
 Author : Vinay Garg
 Description : Merge two sorted lists
*/

#include <bits/stdc++.h>
using namespace std;
/* Link list Node
struct Node {
    int data;
    Node* next;
}; */

Node* SortedMerge(Node* head1,   Node* head2)
{
    struct Node* result = NULL;
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    if(head1->data < head2->data){
        result = head1;
        result->next = SortedMerge(head1->next,head2);
    }
    else{
        result = head2;
        result->next = SortedMerge(head1,head2->next);
    }
    return result;
}
