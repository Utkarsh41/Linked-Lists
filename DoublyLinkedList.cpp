#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

Node *insertionAtBeg(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;

    if (head != NULL)
    {
        head->prev = temp;
    }
    return temp;
}
Node *deleteEnd(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete (head);
        return NULL;
    }

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->prev->next = NULL;
    delete curr;
    return head;
}
Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        delete (head);
        return NULL;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;

        delete temp;
        return head;
    }
}

Node *insertEnd(Node *head, int val)
{
    cout << "INSERTION AT END" << endl;

    Node *temp = new Node(val);

    if (head == NULL)
    {
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;

    return head;
}

Node *reverseDLL(Node *head)
{
    cout << "REVERSAL" << endl;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}
void traversal(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(20);
    Node *head2 = new Node(30);
    Node *head3 = new Node(40);
    Node *head4 = new Node(50);

    head->next = head2;
    head2->prev = head;

    head2->next = head3;
    head3->prev = head2;

    head3->next = head4;
    head4->prev = head3;

    head4->next = NULL;
    head->prev = NULL;

    traversal(head);

    head = insertionAtBeg(head, 99);
    head = insertionAtBeg(head, 98);
    traversal(head);

    head = insertEnd(head, 97);
    traversal(head);

    head = reverseDLL(head);
    traversal(head);

    head = deleteHead(head);
    traversal(head);

    head = deleteEnd(head);
    traversal(head);

    return 0;
}