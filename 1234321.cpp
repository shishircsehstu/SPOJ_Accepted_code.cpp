#include<bits/stdc++.h>
using namespace std;
int cal(int n)
{
    int n2,i;
    n2=2*n-1;
    int st=1;
    bool flag=0;
    while(n2--)
    {

        if(st<n&&flag==0)
        {
            cout<<st;
            st++;
        }
        else if(st==n&&flag==0)
        {
            cout<<st;
            flag =1;
            st--;
        }
        else
        {
            cout<<st;
            st--;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    cal(n);
}
