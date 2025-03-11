#include <iostream>

using namespace std;
//node structure
class Node{
public:
   int data;
   Node* next;
   Node* prev;
public:
    //constructor
    Node(int value){

         data=value;
         next=nullptr;
         prev=nullptr;
    }

};
//the linked list class
class DoublyLinkedList{
private:
    Node* head;
public:
    //constructor
    DoublyLinkedList(){
        head=nullptr;
    }
    void insertAtBegining(int value);
    void insertAtTheEnd(int value);
    void displayFromStart();
    void displayFromEnd();
    void deleteElement(int value);
};
//function definition
void DoublyLinkedList::insertAtBegining(int value)
{
    Node* newNode=new Node(value);
    if(head!=nullptr)//if the list is not empty
    {
        newNode->next=head;//the new nodes next points to the current head
        head->prev=newNode;//the current heads prev points to the new node
    }
    head= newNode;//f the list is empty, the new node becomes the head
}

void DoublyLinkedList::insertAtTheEnd(int value)
{
    Node* newNode=new Node(value);
    if(head==nullptr)
    {
        head=newNode;
        return;
    }
    //if the list is not empty, we traverse the ist untill we get tot the lastnode
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newNode;

    newNode->prev=temp;

}
void DoublyLinkedList::displayFromStart()
{
    if(head==nullptr)
    {
        cout<<"the list is currently empty"<<endl;
        return;
    }
    Node* temp=head;
    cout<<"the lists consists of :"<<"\n";
    while(temp!=nullptr)
    {

        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";

}
void DoublyLinkedList::displayFromEnd()
{
    if(head==nullptr)
    {
        cout<<"the list is empty"<<endl;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    cout<<"the list has the following elements"<<endl;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl;
}
void DoublyLinkedList::deleteElement(int value)
{
    if(head==nullptr)
    {
        cout<<"Oops! The list is currently empty"<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=nullptr&&temp->data!=value)
    {
        temp=temp->next;

    }
    //if the target has not been found
    if(temp==nullptr)
    {
        cout<<"Oops! Target not found in list"<<endl;
        return;
    }
           //if we are deleting the head
    if(temp==head)
    {
        head=head->next;
        if(head!=nullptr)
        {
            head->prev=nullptr;
            delete temp;
        }

        return;
    }
    else
    {
            //if we are not deleting the head
        temp->prev->next=temp->next;
        if(temp->next!=nullptr)//if temp is not at the end of the list
        {
            temp->next->prev=temp->prev;
        }
    }

    delete temp;

}



int main()
{
    DoublyLinkedList dll;
    dll.deleteElement(3);
    cout << "THIS IS JATELO'S MARVELOUS WORK" << endl;
    return 0;
}
