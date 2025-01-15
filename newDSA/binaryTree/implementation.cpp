#include <iostream>
#include<queue>
using namespace std;


class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

// building a tree
Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root= new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter the data for left node of"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for right node of"<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

// levelOrder traversal (BFS)
void levelOrderTraversal(Node* root){
    if(!root){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node*curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int main(){
    Node* root=NULL;
    root=buildTree(root);
    levelOrderTraversal(root);
    return 0;
}