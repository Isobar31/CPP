#include <iostream>

using namespace std;

struct milk
{
    int x, y, a, b, c, d;
    double answer, f, e;

};
int main()
{
milk clients;
    cout<<"input x "<<endl;
    cin>>clients.x;
    cout<<" input y "<<endl;
    cin>>clients.y;
    a = clients.x + clients.y;
    b = clients.x - clients.y;
    c = clients.y - clients.x;
    d = clients.x * clients.y;
    e = clients.x/clients.y;
    f = clients.y/clients.x;
    cout<<"x + y = "<< a<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"x - y = "<<b<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"y - x = "<<c<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"x * y = "<< d<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"x/y = "<< e<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"y/x = "<< f<<endl;
    cout<<"=================================================================="<<endl;
    cout<<"=================================================================="<<endl;



    return 0;
}
