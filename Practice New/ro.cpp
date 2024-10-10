#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    vector<string> vect={"this","bat","cat","dog"};
    		for(int i=0;i<vect.size();i++)
        {
            for(int j=vect[i].length();j>0;j--)
            {
                cout<<vect[i].substr(0,j)<<",";
            }
        }
	return 0;
}
