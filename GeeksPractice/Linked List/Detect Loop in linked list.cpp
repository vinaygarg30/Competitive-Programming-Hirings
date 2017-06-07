/*
 Author : Vinay Garg
 Description : Detect loop in linked list
*/

#include <bits/stdc++.h>
using namespace std;

int detectloop(Node *list)
{
   struct Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            return 1;
        }
    }
    return 0;
}
