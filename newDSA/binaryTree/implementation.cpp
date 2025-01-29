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
    q.push(NULL);
    while(!q.empty()){
        Node*curr=q.front();
        q.pop();
        if(curr==NULL){
            // one level of tree is complete
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
        }
    }
}

// inOrder Traversal
void inOrder(Node * root){
    if(root==NULL){
        return;
    }
    inOrder( root->left);

    cout<<root->data<<" ";

    inOrder(root->right);
}

// preOrder Traversal
void preOrder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";

    preOrder(root->left);

    preOrder(root->right);
}

// postOrder Traversal
void postOrder(Node* root){
    if(root==NULL){
        return;
    }

    postOrder(root->left);

    postOrder(root->right);

    cout<<root->data<<" ";
}

// height of the tree
int height(Node * root){
    if(root==NULL){
        return -1;
    }

    int lheight= height(root->left);
    int rheight= height(root->right);

    return max(lheight , rheight)+1;
}

int main(){
    // Node* root=NULL;
    // root=buildTree(root);
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right= new Node(6);
    levelOrderTraversal(root);
    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    cout<<"height->"<<height(root)<<endl;
    return 0;
}