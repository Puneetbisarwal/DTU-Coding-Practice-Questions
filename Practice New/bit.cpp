
#include <iostream>
using namespace std;

// Returns a number which has same bit
// count as n and has only first and last
// bits as set.
int takeLandFsetbits(int n)
{
    // set all the bit of the number
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    // Adding one to n now unsets
    // all bits and moves MSB to
    // one place. Now we shift
    // the number by 1 and add 1.
    return ((n + 1) >> 1) + 1;
}

int toggleFandLbits(int n)
{
    // if number is 1
    if (n == 1)
        return 0;

    // take XOR with first and
    // last set bit number
    return n ^ takeLandFsetbits(n);
}
int replacebit(int n)
{
    int a=n,count=0;
    while(a)
    {
        count++;
        a=a>>1;
    }
    cout<<"count = "<<count<<endl;
    a=1<<(count-1);
    cout<<" a = "<<a<<endl;
    a=a|1;
    return n^a;
}
// Driver code
int main()
{
    int n = -9;
    cout << toggleFandLbits(n)<<endl;
    cout<<replacebit(n);
    return 0;
}
