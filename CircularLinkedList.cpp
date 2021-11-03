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

Node *InsertHead(Node *head, int x)
{

    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
    }
    else
    {
        Node *curr = head;

        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
    }
    return temp;
}
Node *deleteEnd(Node *head)
{
    Node *curr = head;
    while (curr->next->next != head)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = head;
    delete (temp);
    return head;
}
Node *InsertEnd(Node *head, int x)
{

    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        Node *curr = head;

        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
    }
    return head;
}

void traversal(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *p = head;
    do
    {
        cout << head->data << " ";
        head = head->next;
    } while (p != head);

    cout << endl;
}

Node *deleteAthead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = head->next;
    delete head;

    return curr->next;
}

Node*insertAfterk(Node*head,int k,int val){
    Node*newNode=new Node(val);
    Node*curr=head;
    do{
        if(curr->data==k || curr==NULL){
            break;
        }
        curr=curr->next;
    }while(curr!=head);

    if(curr==NULL or curr->data!=k){
        cout<<"No data found"<<endl;
    }
    else
    {
        newNode->next=curr->next;
        curr->next=newNode;
    }
    return head;

}
Node *deleteAtKpos(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    if (pos == 1)
    {
        delete head;
    }
    Node *curr = head;
    for (int i = 0; i < pos - 2; i++)
    {
        curr = curr->next;
    }

    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;

    return head;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(25);
    head->next->next = new Node(52);
    head->next->next->next = new Node(26);
    head->next->next->next->next = head;

    traversal(head);

    head = InsertHead(head, 999);
    // traversal(head);
    head = InsertEnd(head, 859);
    traversal(head);

    // head = deleteAthead(head);
    // traversal(head);

    // head = deleteAtKpos(head, 3);
    // traversal(head);

    // head = deleteEnd(head);
    // traversal(head);


    head = insertAfterk(head,26,2);
    traversal(head);

    return 0;
}