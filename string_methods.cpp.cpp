#include <iostream>
#include <string>

using namespace std;

int main()

{
    string name;
    int name_length;
    cout<<"whats your name:?";
    getline(cin>>ws,name);
    while(name.empty())
    {
        cout<<"you did not enter your name. please do so";
        getline(cin>>ws,name);
    }
    name_length=name.length();
    name_length>=15?cout<<"your name is very long.It has "<<name_length<<" characters"<<endl:cout<<"your name is not very long. it has "<<name_length<<"charcters"<<endl;


    name.find("t")?cout<<"the letter 't' is the character number "<<name.find("t")+1<<" in your name"<<endl: cout<<"the letter 't' has not been found in your name."<<endl;

    cout<<"the first character in your name is "<<name.at(0)<<" and the last character is "<<name.length()-1<<endl;
    cout << "Your new name is "<<name.append("@gmail.com") << endl;
    cout<<"Or you can still use "<<name.insert(0,"@")<<endl;
    return 0;
}
