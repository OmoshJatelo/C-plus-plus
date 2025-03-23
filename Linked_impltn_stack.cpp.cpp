#include <iostream>

using namespace std;
class Node{
public:

	int data;
	Node* next;
};
class Stack{
private:
	Node* top;
public:
	Stack(){top=nullptr;}
	void push(int val);
	void pop();
	void peek();

};
void Stack::push(int val)
{
	Node* temp=new Node;
	temp->data=val;
	temp->next=top;
	top=temp;
	cout<<temp->data<<" has been added to the list"<<endl;

}
void Stack::pop()
{
	if(top==nullptr)
	{
		cout<<"the stack is  empty"<<endl;
		return;
	}
	cout<<top->data<<" has been removed from the stack"<<endl;
	Node* temp=top;
	top=top->next;
	delete temp;
}
void Stack::peek()
{
	if(top==nullptr)
	{
		cout<<"the Stack is empty"<<endl;
		return;
	}
	cout<<"the top element is"<<top->data<<endl;
}
int main()
{
	cout<<"this is a linkedlist implementation of a stack"<<endl;
	Stack s;
	s.push(10);
	s.push(34);
	s.push(78);
	s.pop();
	s.peek();
    cout << "The conquerer the champion the Lion is Jatelo" << endl;
    return 0;
}
