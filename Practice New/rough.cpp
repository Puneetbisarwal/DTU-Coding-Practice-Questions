#include<bits/stdc++.h>
using namespace std;
int main()
{    set<int> s;
    s.insert(1);
    s.insert(6);
    s.insert(4);
    s.insert(19);
    s.insert(1);
    s.insert(19);
    s.insert(2);
    for(auto i=s.begin();i!=s.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    auto it=s.lower_bound();
    cout<<*it;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
struct Compare
{
    bool operator()(pi const & a, pi const & b)
    {
         if(a.second < b.second)
         {
            return true;
         }
         else if(a.second > b.second)
         {
             return false;
         }
         else
         {
             if(a.first > b.first)
             {
                 return true;
             }
             return false;
         }
    }
};
int main()
{
    priority_queue<pi , vector<pi>, Compare>q;
    q.push({1, 5});
    q.push({5, 15});
    q.push({7, 15});
    q.push({10, 2});
    q.push({1, 10});
    cout<<q.top().first<<" "<<q.top().second<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int>s;
    pair<set<int>::iterator, bool> ret;
    s.insert(1);
    s.insert(5);
    s.insert(10);
    s.insert(3);
    ret = s.insert(10);
    cout<<ret.second<<endl;
    return 0;
}
