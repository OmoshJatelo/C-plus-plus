#include <iostream>
#define MAX 10

using namespace std;

class Queue{
 private:
    int front,rear;
    int arr[MAX];
 public:
    Queue(){front=rear=-1;}
    void enqueue(int val);
    void dequeue();
    void peek();
};
void Queue::enqueue(int val)
{
   if(front==-1)
   {
    front=0;
   }
   if(rear>MAX-1)
   {
    cout<<"the queue is full, it can only contain a maximum of "<<MAX<<" elements"<<endl;
    return;
   }
   arr[++rear]=val;
   cout<<val<<" enqueued"<<endl;
}
void Queue::dequeue()
{
    if(front==-1||front>rear)
    {
        cout<<"there is nothing in the queue"<<endl;
        return;
    }
    cout<<arr[front++]<<" has been dequeued"<<endl;
}
void Queue::peek()
{
    if(front==-1)
    {
        cout<<"there is nothing in the queue"<<endl;
        return;
    }
    cout<<"the telement on the top is "<<arr[front]<<endl;
}


int main()
{
    Queue q;
    q.peek();
    q.dequeue();
    q.enqueue(6);
    q.enqueue(5);
    q.peek();
    q.dequeue();
    cout << "The conquererr the Champion the lion is Jatelo" << endl;
    return 0;
}
