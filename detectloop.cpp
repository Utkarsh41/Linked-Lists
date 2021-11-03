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

void traversal(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
bool isLoop(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
int main()
{

    Node *head1 = new Node(5);
    Node *head2 = new Node(7);
    Node *head3 = new Node(9);
    Node *head4 = new Node(22);

    head1->next = head2;
    head2->next = head3;
    head3->next = NULL;
    // head3->next = head4;
    // head4=head2;

    // cout<<isLoop(head1);
    if (isLoop(head1))
    {
        cout << "Loop detected\n";
    }

    else
        cout << "No loop found\n";
    // traversal(head1);

    return 0;
}