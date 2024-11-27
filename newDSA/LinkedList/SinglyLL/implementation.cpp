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
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"mem is free with data"<<val <<endl;
    }
};

/*       INSERTION          */

// insertion at head
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// insertion at tail
void insertAttail(Node *&tail , int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

// insertion at middle or any position.
void insertAtmiddle(Node* &tail , Node *&head , int pos , int d){

    if(pos==1){
        insertAtHead(head , d);
        return;
    }

    Node *temp=head;
    int cnt=1;
    while(cnt< pos-1){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAttail(tail , d);
        return;
    }

    Node * newNode= new Node(d);
    newNode->next=temp->next;
    temp->next=newNode;
}


/*            DELETION         */


// delete node at a position-
void deletePos(Node * &head , int pos){
    Node *curr= head;
    Node* prev=NULL;

    if(pos==1){
        head=head->next;
        curr->next=NULL;
        delete curr;
        return;
    }
    int cnt=1;


    while(cnt<pos){
        if(curr->next==NULL){
            prev->next=NULL;
            delete curr;
            return;
        }
       prev=curr;
       curr=curr->next;
        cnt++; 
    }

    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}

// traverse.
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *head = node1;
    Node *tail=node1;
    display(head);


    insertAttail(tail, 12);
    display(head);
    insertAttail(tail, 15);
    display(head);
    insertAttail(tail, 20);
    display(head);
    insertAttail(tail, 30);
    display(head);
    insertAtmiddle(tail , head, 4, 17);
    display(head);
    insertAtmiddle(tail , head, 1, 5);
    display(head);
    insertAtmiddle(tail , head, 8, 35);
    display(head);

    deletePos(head, 1);
    display(head);
    deletePos(head, 4);
    display(head);
    deletePos(head, 6);
    display(head);
    return 0;
}