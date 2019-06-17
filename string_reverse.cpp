#include<bits/stdc++.h>
using namespace std;
string rever(char str[])
{
    int i,n;
    string st2;
    n=strlen(str);
    string str2[n];
    int r=0;
    for(i=0; i<n; i++)
    {
        if(str[i]==' ')
        {
            str2[r++]=st2;
            cout<<"Yes"<<endl;
            st2.clear();
        }
        else
            st2+=str[i];
    }
    string ans;
    str2[r++]=st2;
    for(i=r-1; i>=0; i--)
    {
        ans+=str2[i];
        if(i>0) ans+=' ';
    }
    cout<<ans<<endl;
    return ans;

}
int main()
{
    char st[100000];
    gets(st);
    rever(st);
}
