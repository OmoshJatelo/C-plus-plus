#include<iostream>
using namespace std;

//node structure and initialization
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=right=nullptr;
    }
};

// a function to append a new node into the tree
Node* insert(Node* root,int value)
{
    //if the root is empty, we crete anew node
    if(root==nullptr){
        return new Node(value);
    }    
    //inserting at the left if value is less than the data in the root
    if(value<root->data){
        root->left=insert(root->left,value);
    } 
    //inserting at the right if the value is greater than the data in the root
    else {
        root->right=insert(root->right,value);
    }  
    return root;
}

//preorder traversal of the tree
void preorder(Node* root)
{
    if(root!=nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    
}
// inorder traversal
void inorder(Node* root)
{
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<' ';
        inorder(root->right);
    }
}
//postorder traversal of the tree
void postorder(Node* root)
{
    if(root!=nullptr){
        preorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

}


int main()
{
    Node* root=nullptr;
    preorder(root);
    root=insert(root,50);
    insert(root,30);
    insert(root,50);
    insert(root,80);
    insert(root,99);
    cout<<"preorder traversal"<<endl;
    preorder(root);
    cout<<"inorder traversal"<<endl;
    inorder(root);
    cout<<"postorder traversal"<<endl;
    postorder(root);
    return 0;
}
