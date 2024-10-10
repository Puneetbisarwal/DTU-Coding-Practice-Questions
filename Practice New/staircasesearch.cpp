#include<bits/stdc++.h>
using namespace std;
void readmatrix(int a[][10],int r,int c)
{
    int y=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            a[i][j]=y++;
        }
    }
}
void printmatrix(int **a,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool searchstaircase(int a[][10],int r,int c,int key)
{
    int i=0,j=c-1;
    while(j>=0 && i<r)
    {
        if(a[i][j]==key)
        {
            return true;
        }
        if(a[i][j]<key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}
void spiralprint(int a[][10],int r,int c)
{
    int StartCol=0,Endcol=c-1,StartRow=0,EndRow=r-1;
    while(StartRow <=EndRow && StartCol<=Endcol )
    {
        for(int i=StartCol;i<=Endcol;i++)
        {
            cout<<a[StartRow][i]<<" ";
        }
        StartRow++;
        for(int i=StartRow;i<=EndRow;i++)
        {
            cout<<a[i][Endcol]<<" ";
        }
        Endcol--;
        if(StartRow<EndRow)
        {
        for(int i=Endcol;i>=StartCol;i--)
        {
            cout<<a[EndRow][i]<<" ";
        }
        EndRow--;
        }
        if(StartCol<Endcol)
        {
        for(int i=EndRow;i>=StartRow;i--)
        {
            cout<<a[i][StartCol]<<" ";
        }
        StartCol++;
        }
    }
}
int maxsumsubmatrix(int **a,int row,int col)
{
    int sum=0;
    for(int tl1=0;tl1<row;tl1++)
    {
        for(int tl2=0;tl2<col;tl2++)
        {
            for(int br1=tl1+1;br1<=row;br1++)
            {
                for(int br2=tl2+1;br2<=col;br2++)
                {
                    for(int i=tl1;i<br1;i++)
                    {
                        for(int j=tl2;j<br2;j++)
                        {
                            sum=sum+a[i][j];
                        }
                    }
                }
            }
        }
    }
    return sum;
}
int submatrixsum(int **a,int row,int col)
{
    int sum=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int tl=(i+1)*(j+1);
            int br=(row-i)*(col-j);
            sum=sum+tl*br*a[i][j];
        }
    }
    return sum;
}
void dummymatrix(int **a,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            a[i][j]=a[i][j-1]+a[i][j];
        }
    }
    for(int i=1;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j];
        }
    }
}
void matrixquerysumproblem(vector<pair<int ,int>> & q1 , vector<pair<int,int>> &q2 ,vector<int> &out,int **a,int row,int col)
{
    for(auto i=q1.begin(),j=q2.begin();i!=q1.end(),j!=q2.end();i++,j++)
    {
        out.push_back(a[j->first-1][j->second-1]-a[i->first-2][j->second-1]-a[j->first-1][i->second-2]+a[i->first-2][i->second-2]);
    }
}
void printmatrixquesrysumproblem(vector<int> &v)
{
    for(auto i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
void matrixquerysumprobleminputquery()
{

    cout<<endl;
    cout<<"Enter row and col of matrix "<<endl;
    int row,col;
    int **a=new int*[row];
    for(int i=0;i<row;i++)
    {
        a[i]=new int[col];
    }
    cout<<"Enter elements of matix"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>a[i][j];
        }
    }
    printmatrix(a,row,col);
    cout<<endl;
    cout<<"Enter no. of queries"<<endl;
    int n;
    cin>>n;
    vector<pair<int,int>> q1(10);
    vector<pair<int,int>> q2(10);
    for(int i=0;i<n;i++)
    {
        cout<<" Enter "<<i+1 << "query's first co-ordinate"<<endl;
        int tl1,tl2;
        cin>>tl1>>tl2;
        q1.push_back(make_pair(tl1,tl2));
        cout<<" Enter "<< i+1 << "query's second co-ordinte"<<endl;
        int br1,br2;
        cin>>br1>>br2;
        q2.push_back(make_pair(br1,br2));
    }
    vector<int> v(20);
    dummymatrix(a,row,col);
    printmatrix(a,row,col);
    cout<<endl;
    cout<<"Print dummy matrix"<< endl;
    matrixquerysumproblem(q1,q2,v,a,row,col);
    printmatrixquesrysumproblem(v);
}
int main()
{
    /*int a[10][10];
    int r,c;
    cin>>r>>c;
    readmatrix(a,r,c);
    printmatrix(a,r,c);
    cout<<searchstaircase(a,r,c,12);
    cout<<endl;
    spiralprint(a,r,c);*/
    /*int row,col;
    cin>>row>>col;
    int **arr=new int*[row];
    for(int i=0;i<row;i++)
    {
        arr[i]=new int[col];
    }
    int p=1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            arr[i][j]=p++;
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<maxsumsubmatrix(arr,row,col);
    cout<<endl;
    cout<<submatrixsum(arr,row,col);*/
    matrixquerysumprobleminputquery();
    return 0;
}
