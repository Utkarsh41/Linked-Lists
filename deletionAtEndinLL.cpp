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

Node *insertBeg(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

Node *deletehead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *temp = head->next;
        delete (head);
        return temp;
    }
}

Node *deleteEnd(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = NULL;
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

int main()
{

    Node *head1 = new Node(5);
    Node *head2 = new Node(7);
    Node *head3 = new Node(9);

    head1->next = head2;
    head2->next = head3;
    head3->next = NULL;

    traversal(head1);

    head1 = insertBeg(head1, 2);
    traversal(head1);

    cout << "Deletion at head\n";
    head1 = deletehead(head1);
    traversal(head1);

    // head1=deletehead(head1);
    // traversal(head1);
    // head1=deletehead(head1);
    // traversal(head1);

    cout << "Deletion at end\n";
    head1 = deleteEnd(head1);
    traversal(head1);

    return 0;
}