#include<iostream>
using namespace std;

class Coordinate
{
    private:
    int x,y;
    
    public:
    Coordinate(int a=0,int b=0)
    {
        x=a;
        y=b;
    }
    //binary oprerator overloading
    Coordinate operator +( const Coordinate& p){
        return Coordinate (x+p.x,y+p.y);
    }
    void display(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }   
};

class Unary
{
    private:
    int number;
    public:
    Unary(int a)
    {
        number=a;
    }
     Unary operator ++(){
        return Unary (number+=10);
        
     }
     void display();


};

void Unary::display()
{
    cout<<number<<endl;
}

int main()
{
    
    Coordinate p(4,6),q(3,2),r ;
    r=p+q;
    r.display();
    Unary u(5);
    u=++u;
    u.display();

    return 0;
}
