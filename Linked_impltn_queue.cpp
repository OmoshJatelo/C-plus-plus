# include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

};
class Queue{
    private:
    Node* front;
    Node* rear;
    public:
    Queue(){front=rear=nullptr;}
    void enqueue(int);
    void dequeue();
    void peek(); 
    bool queueIsEmpty();
};
void Queue::enqueue(int value)
{
    Node* temp=new Node;
    temp->data=value;
    temp->next=nullptr;
    if(rear==nullptr)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    cout<<rear->data<<" has been enqueued"<<endl;

}
void Queue::dequeue()
{
    if(front==nullptr)
    {
        cout<<"there is nothing in the queue"<<endl;
        return;
    }
    Node* temp=front;
    front=front->next;
    if(front==nullptr)//if we are dequeuing the last node then we updte rear to nullptr
    {
        rear=nullptr;
    }
    cout<<temp->data<<" has been dequeued"<<endl;
    delete temp;
}
void Queue::peek()
{
    if(front==nullptr)
    {
        cout<<"the queue is empty"<<endl;
        return;
    }
    cout<<"the element at the fron of the queue is "<<front->data<<endl;
}
bool Queue::queueIsEmpty()
{
    return (front==nullptr)?true:false;
}

int main()
{
    Queue q;
    cout<<"The queue is empty?: "<<q.queueIsEmpty()<<endl;
    q.peek();
    q.enqueue(7);
    q.enqueue(12);
    q.enqueue(3);
    q.dequeue();
    q.peek();
    cout<<"The queue is empty?: "<<q.queueIsEmpty()<<endl;
    return  0;
}