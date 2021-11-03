#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *insertAtPosition(Node *head, int val, int pos)
{
    Node *temp = new Node(val);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for (int i = 1; i <= pos - 2 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node *insertBeg(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    return newNode;
}
Node *insertEnd(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
        return newNode;

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;

    return head;
}

void traversal(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int searchInLL(Node *head, int key)
{
    int pos = 1;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == key)
            return pos;

        else
        {
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}
int searchRec(Node *head, int key)
{
    if (head == NULL)
        return -1;

    if (head->data == key)
        return 1;

    else
    {
        int res = searchRec(head->next, key);
        if (res == -1)
            return -1;
        else
            return res + 1;
    }
}
int main()
{

    Node *head1 = new Node(5);
    Node *head2 = new Node(7);
    Node *head3 = new Node(9);

    head1->next = head2;
    head2->next = head3;
    head3->next = NULL;

    traversal(head1);

    // cout << "Insertion at head\n";
    // head1 = insertBeg(head1, 2);
    // traversal(head1);

    cout << "Insertion at end\n";
    head1 = insertEnd(head1, 92);
    traversal(head1);

    // cout << "Insertion at position\n";
    // head1 = insertAtPosition(head1, 52, 3);
    // traversal(head1);
    cout << "Searching...in linked lsit\n";
    cout << "Element found at " << searchInLL(head1, 192) << endl;

    cout << "Recursive search\nFound at index: ";
    cout << searchRec(head1, 92);

    return 0;
}