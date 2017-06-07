/*
 Author : Vinay Garg
 Description : Remove duplicates using hashing
*/

/*
The structure of linked list is given as:
struct Node
{
int data;
Node* next;
};
*/
#include <bits/stdc++.h>
using namespace std;
Node *removeDuplicates(Node *root)
{
    unordered_set<int> seen;
    struct Node *curr = root;
    struct Node *prev = NULL;
    while (curr != NULL)
    {
        if (seen.find(curr->data) != seen.end())
        {
           prev->next = curr->next;
           delete (curr);
        }
        else
        {
           seen.insert(curr->data);
           prev = curr;
        }
        curr = prev->next;
    }
    return root;
}
