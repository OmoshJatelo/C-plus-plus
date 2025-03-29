#include<iostream>
using namespace std;

//NODE STRUCTURE AND INITIALIZATION
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=right=nullptr;
    }
};

// A FUCTION TO APPEND A NEW NODE INTO THE TREE
Node* insert(Node* root,int value)
{
    //if there is no node yet, we crete anew node
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

//PREORDER TRAVERSAL OF THE TREE
void preorder(Node* root)
{
    if(root!=nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }    
}
// INORDER TRAVERSAL OF THE TREE                
void inorder(Node* root)
{
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<' ';
        inorder(root->right);
    }
    /*else{
        cout<<"the tree is empty or we have reached the end"<<endl;
    }*/
}
//POSTORDER TRAVERSAL OF THE TREE
void postorder(Node* root)
{
    if(root!=nullptr){
        preorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

}
//FUNCTION TO FIND THE SMALLEST NODE
Node* findSmallest(Node* node)
{
    Node* current=node;
    while(current &&current->left!=nullptr){//while
        current=current->left;// move to the left to find the smallest node
    }
    return current;
}
//DELETING A NODE FROM THE TREE

Node* deleteNode(Node* root, int value)
{
    if(root==nullptr){//base case:when the root is empty(or the target has not been found)
        cout<<"The  target has not been found in the tree"<<endl;
        return root;
    }
    if(value<root->data){//if the target is less than the value at the current root, we go to the left
        deleteNode(root->left,value);
    }
    else if(value>root->data){//if the trget is greater than the one at the current root, we go to the right
        deleteNode(root->right,value);
    }
    else{// the target ha sbeen found
        //case 1:  target node has no child
        if(root->left==nullptr&& root->right==nullptr){
            delete root;
            return nullptr;
        }
        //case 2: the target- node has only one child
        else if(root->left==nullptr){
            Node* temp=root->right;
            delete root;
            return temp;// replace with the right child
        }
        else if(root->right==nullptr){
            Node* temp=root->left;
            delete root;
            return temp;// replace with the left child
        }
        //case 3: the node has two children
        /*in this case we find the inorder successor of the node(the smallest node
        to the right subtree)*/
        else{
            Node* temp=findSmallest(root->right);// find the inorder successor
            root->data=temp->data;//copy to the successor's value tot he root
            root->right=deleteNode(root->right,temp->data);//delete the successor
        }
    }
    return root;

}

//MAIN PROGRAM
int main()                 
{
    Node* root=nullptr;
    preorder(root);
    inorder(root);
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
    deleteNode(root,50);
    inorder(root);
    return 0;
}
