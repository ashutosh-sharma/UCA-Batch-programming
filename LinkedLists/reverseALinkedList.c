/*
Given pointer to the head node of a linked list, the task is to reverse the linked list.

Input:
You need to complete a method reverse() that takes head as argument and returns new head.
There are multiple test cases. For each test case, this method will be called individually.  The first line of input contains number of test cases.  Every test case has two lines, number of nodes first line and data values in next line.

Output:
Reverse the linked list and return head of the modified list.
*/
/*******************************
* try problem on geeksforgeeks : http://practice.geeksforgeeks.org/problems/reverse-a-linked-list
*******************************/

//A function return head of new reversed linkedlist.

Node* reverse(Node *p)
{   
    // to store head of new reversed list
    Node* headNew;
    
    // exiting the recursion when reach at last element in linked list
    if(p->next == NULL)
    {
        // updating headNew when on last element
        headNew = p;
        return headNew;
    }
    
    // headNew will receive the last Node for the first time and then continue it till end
    headNew = reverse(p->next);
    
    //reversing the links of nodes p and q
    Node* q = p -> next;
    q -> next = p;
    p -> next = NULL;
    
    // returning headNew to the main driver function.
    return headNew;
}
