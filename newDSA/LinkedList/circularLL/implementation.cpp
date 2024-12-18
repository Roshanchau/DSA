#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    };

    // destructor
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "mem is free with data" << val << endl;
    }
};

/*   Insertion       */
void insertAtHead(Node*& last , int d){
    Node * temp= new Node(d);
    temp->next=last->next;
    last->next=temp;
}

void insertAtTail(Node * &last , int d){
    Node * temp=new Node(d);
    temp->next=last->next;
    last->next=temp;
    last=temp;
}

/*                  deletion        */
void deleteAtPos(Node *& last  ,int pos){
    // deletion at head
    Node * prev=last->next;
    if(pos==1){
        last->next=prev->next;
        prev->next=NULL;
        delete prev;
        return;
    }

    // elsewhere
    int i=1;
    while(i<pos-1){
        prev=prev->next;
        i++;
    }
    Node * curr=prev->next;
    // at last node
    if(curr==last){
        prev->next=curr->next;
        last=prev;
        delete curr;
        return;
    }
    prev->next=curr->next;
    delete curr;
}

void display( Node *&last)
{
    Node *temp = last->next;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=last->next);
    cout << endl;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *last = new Node(30);
    
    // creating a CLL 10 , 20 , 30
    first->next = second;
    second->next = last;
    last->next = first;
    insertAtHead(last , 5);
    insertAtTail(last , 40);
    display( last);
    deleteAtPos(last , 3);
    display( last);
    return 0;
}