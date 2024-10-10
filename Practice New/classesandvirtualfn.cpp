#include<bits/stdc++.h>
using namespace std;
class base
{
    public:
    void show()
    {
        cout<<"base show() fn "<<endl;
    }
    void dis()
    {
        cout<<"base dis() fn "<<endl;
    }
};
class derived : public base
{
    public:
    void show()
    {
        cout<<"derived class show() fn "<<endl;
    }
    void dis()
    {
        cout<<" derived class dis () fn "<<endl;
    }
};

int main()
{
    base *b;
    derived d;
    b=&d;
    b->show();
    return 0;
}
