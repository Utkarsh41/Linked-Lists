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

Node *revreseLinkedList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
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

int main()
{

    Node *head1 = new Node(5);
    Node *head2 = new Node(7);
    Node *head3 = new Node(9);

    head1->next = head2;
    head2->next = head3;
    head3->next = NULL;

    traversal(head1);

    cout << "Insertion at head\n";
    head1 = insertBeg(head1, 2);
    head1 = insertBeg(head1, 22);
    head1 = insertBeg(head1, 36);

    traversal(head1);

    cout << "Reversing linked list\n";
    head1 = revreseLinkedList(head1);
    traversal(head1);

    return 0;
}