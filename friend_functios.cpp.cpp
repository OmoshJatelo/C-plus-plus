#include <iostream>

using namespace std;
class Time{
private:
	int hours;
	int seconds;
	int minutes;
public:
	void initialize();
	void display();
	friend void sum(Time& t1, Time& t2);

};
void Time::initialize()
{
	cout<<"enter hours"<<endl;
	cin>>hours;
	cout<<"enter minutes"<<endl;
	cin>>minutes;
	cout<<"enter the seconds"<<endl;
	cin>>seconds;

}
void Time::display()
{
	cout<<hours<<"hr(s): "<<minutes<<"mins: "<<seconds<<"secs"<<endl;
}
void sum(Time& t1, Time& t2)
{
	int hrs,secs,mins;
	mins=t1.minutes +t2.minutes+(t1.seconds+t2.seconds)/60;
	secs=(t1.seconds+t2.seconds)%60;
	hrs=t1.hours+t2.hours +mins/60;
	mins%=60;
	cout<<"the total time is"<<endl;
	cout<<hrs<<"hrs: "<<mins<<"mins: "<<secs<<"secs:"<<endl;

}

int main()
{
	Time t1,t2;
	t1.initialize();
	t1.display();
	t2.initialize();
	t2.display();1
	sum(t1,t2);
    cout <<"the conquerer the champion the lion is Jatelo "<< endl;
    return 0;
}
