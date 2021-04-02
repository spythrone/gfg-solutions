#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

Node* sortedMerge(Node* head1, Node* head2)  
{
    struct Node *curr1 = head1;    
    struct Node *prev1 = nullptr;    
    struct Node *hd1 = curr1;    
    struct Node *curr2 = head2;    
    struct Node *prev2 = nullptr;
    struct Node *hd2 = curr2;
    while(curr1 != nullptr && curr2 != nullptr){
        if(curr1->data > curr2->data){
            while(curr1 != nullptr && curr2 != nullptr && curr1->data >= curr2->data){
                prev2 = curr2;
                curr2 = curr2->next;
            }
            prev2->next = curr1;
        }
        else{
            while(curr1 != nullptr && curr2 != nullptr && curr2->data >= curr1->data){
                prev1 = curr1;
                curr1 = curr1->next;
            }
            prev1->next = curr2;
        } 
    }
    if(hd1->data > hd2->data)
        return hd2;
    return hd1;
}