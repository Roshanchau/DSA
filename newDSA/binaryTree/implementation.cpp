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

// insertion in binary tree.
Node* insertNode(Node * root , int data){

    if( root==NULL){
        root=new Node(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node * curr= q.front();
        q.pop();


        // first insert in the left
        if(curr->left!=NULL){
            q.push(curr->left);
        }else{
            curr->left= new Node(data);
            return root;
        }

        // insertion in right node
        if(curr->right!=NULL){
            q.push(curr->right);
        }else{
            curr->right= new Node(data);
            return root;
        }
    }
}

void deleteDeepest(Node * root , Node * dnode){

    cout<<"inside deepest"<<endl;
    queue<Node*> q;
    q.push(root);

    Node* curr;

    while(!q.empty()){
        curr=q.front();
        q.pop();


        if(curr==dnode){
            curr=NULL;
            delete dnode;
            return;
        }
        // deletion from right
        if(curr->right){
            if(curr->right==dnode){
                curr->right=NULL;
                delete dnode;
                return;
            }
            q.push(curr->right);
        }


        // then left
        if(curr->left){
            if(curr->left==dnode){
                curr->left=NULL;
                delete dnode;
                return;
            }
            q.push(curr->left);
        }
    }
}


// deletion 
Node * deletion( Node * root , int key){
    cout<<"inside deletion"<<endl;
    if(root==NULL){
        return NULL;
    }

    if(root->left==NULL && root->right==NULL){
        if(root->data==key){
            return NULL;
        }
        else{
            return root;
        }
    }

    queue<Node*> q;
    q.push(root);

    Node* curr;
    Node* keyNode=NULL;
    while(!q.empty()){
        curr=q.front();
        q.pop();

        if(curr->data==key){
            keyNode=curr;
        }

        if(curr->left){
            q.push(curr->left);
        }

        if(curr->right){
            q.push(curr->right);
        }
    }

    if(keyNode!=NULL){
        // get the deepest node data.
        int x=curr->data;

        // replase the keynode with the deepest node data cuz we cannot just delete the keynode data.
        keyNode->data=x;

        deleteDeepest(root, curr);
    }
    return root;
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
    root= insertNode(root, 7);
    levelOrderTraversal(root);
    root=deletion(root , 2);
    cout<<"after deletion"<<endl;
    levelOrderTraversal(root);
    return 0;
}