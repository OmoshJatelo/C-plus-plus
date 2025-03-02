#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Node{
    int data;
    Node* next_node;
};

//FUNCTION TO INSERT A NEW NODE TO THE LIST
void insert_new_node(Node*& head, int value){
    //create a new node and assign it a new noe pointer
    Node* newNode=new Node;
    //use the new node pointer to initialialize the data to value and the pointer to the next node to nullptr
    newNode->data=value;
    newNode->next_node=nullptr;
    //check if e]head is empty
    if(head==nullptr){
        head=newNode;
        return; //exit the function
    }
    /*if head is not empty,we traverse the list untill the pointer to the next node points to nullptr, indicating end
     of the list. then asign head to the new node created*/
    Node* temp=head;
    while(temp->next_node!=nullptr){
        temp=temp->next_node;
    }
    temp->next_node=newNode;

}

//FUCTION TO DISPLAY THE DATA IN THE LIST
void display_list(Node* head){
    Node* temp=head;
    if (temp==nullptr){
        cout<<"The list is empty"<<endl;
        return;
    }

    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next_node;//move to the next node
    }

    cout<<"NULL"<<endl;
}

//FUNCTION TO DELETE AN ELEMENT FROM THE LIST
void delete_list_element(Node*& head, int value){
    if(head==nullptr){
        cout<<"The list is currently empty";
        return;

    }

    if(head->data==value){
       Node* temp=head;
       head=head->next_node;//move head to the next node
       delete temp;//delete the old head
       cout<<value<<" deleted successfully from the list"<<endl;
       cout<<"the list now has: ";
       display_list( head);
       return;

    }
    //ELSE WE NOW TRAVERSE THE LIST UNTILL WE FIND THE TARGET VALUE
    Node* temp=head;
    while(temp->next_node!=nullptr&& temp->next_node->data!=value){
        temp=temp->next_node;
    }
    if(temp->next_node==nullptr){
        cout<<"Oops! "<<value<<" has not been found in the list"<<endl;
        return;

    }


    //otherwise it meas that the value has been found in the next node
    Node* nodeToDelete=temp->next_node;
    temp->next_node=temp->next_node->next_node;//skip over the node

    delete nodeToDelete;
    cout<<value<<" has been deleted successfully"<<endl;
    cout<<"the list now has: ";
    display_list(head);
    return;



}
int main(){
    int number,to_remove;
    Node* head=nullptr;
    srand(time(0));
    cout<<"many random numbers do you want to generate: ";
    cin>>number;
    for(int i=0;i<number;i++){
        int rand_num=rand()%150;
        insert_new_node(head,rand_num);
    }
    cout<<"these are the numbers generated:"<<endl;
    display_list(head);
    cout<< "which of the numbers do you want to delete from the list:"<<endl;
    cin>>to_remove;
    delete_list_element(head,to_remove);

    return 0;
}
