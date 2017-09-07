/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<set>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
#define sii(a,b) scanf("%d%d",&a,&b)

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define pb push_back
#define pii pair<int,int>
#define mk make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65, 'a'=97 '0'=48


map<ll,bool>visi;
int ar[siz];
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
#define mx 100002
int L[mx],T[mx];
ll dist[mx];
int P[mx][22];
vector<int>g[mx],cost[mx];
char str[101];

void dfs(int from,int u,int dep,ll dst)
{
    T[u]=from;   ///T store parent of child
    L[u]=dep;    /// L store level of node
    dist[u]=dst;

    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v=g[u][i];
        int cst=cost[u][i];

        if(v==from) continue;
        dfs(u,v,dep+1,dst+cst);
    }
}

int lca_query(int N, int p, int q)
{
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;

    }
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];
    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}
void lca_init(int N)
{
    memset (P,-1,sizeof(P));
    int i, j;
    for (i = 0; i < N; i++)
        P[i][0] = T[i];

    for (j = 1; 1 << j < N; j++)
    {
        for (i = 0; i < N; i++)
        {
            if (P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];

            }
        }
    }
    /*
    for(i=0; i<N; i++)
    {
        for(j=0; pow(2,j)<N; j++)
            cout<<P[i][j]<<" ";
        cout<<endl;
    }
    */
}
int two_p(int d)
{
    int log=0;
    while(1)
    {
        int next=log+1;
        if((1<<next)>d)break;
        log++;

    }
    return log;
}
int main()
{
    int i,j,n,k,m,x,y,t,d,lo,hi,r,cs=1;
    si(t);
    while(t--)
    {

        si(n);
        for(i=0; i<n-1; i++)
        {
            si(x),si(y),si(k);
            x--,y--;
            g[x].pb(y);
            cost[x].pb(k);
        }
        dfs(0, 0, 0,0);
        lca_init(n);

        while(1)
        {
            scanf("%s",str);
            if(strcmp(str,"DONE")==0) break;
            else if(strcmp(str,"DIST")==0)
            {
                si(x),si(y);
                x--,y--;
                k=lca_query(n,x,y);
                printf("%lld\n",dist[x]+dist[y]-2*dist[k]);
            }
            else if(strcmp(str,"KTH")==0)
            {
                si(x),si(y),si(d);
                x--,y--,d;
                k=lca_query(n,x,y);
                int log;
                // cout<<"lca="<<k<<endl;

                lo=L[x]-L[k]+1;
                hi=L[y]-L[k]+1;
                //  cout<<"lo=="<<lo<<".."<<hi<<endl;
                if(lo>d)
                {
                    d--;
                    if(d==0)
                    {
                        printf("%d\n",x+1);
                        continue;
                    }
                    log=0;
                    while(1)
                    {
                        log=two_p(d);
                        x=P[x][log];
                        d=d-(1<<log);
                        if(d==0) break;
                    }
                    printf("%d\n",x+1);
                }
                else
                {
                    r=d-lo;
                    d=hi-r-1;
                    if(d==0)
                    {
                        printf("%d\n",y+1);
                        continue;
                    }
                    log=0;
                    while(1)
                    {
                        log=two_p(d);
                        y=P[y][log];
                        d=d-(1<<log);
                        if(d==0) break;
                    }
                    printf("%d\n",y+1);
                }
            }
        }
        for(i=0; i<=n; i++)
            g[i].clear(),cost[i].clear();
        mem(T),mem(L),mem(dist);
    }

    return 0;
}
/*
6
1 2 1
2 4 1
2 5 2
1 3 1
3 6 2

KTH 4 6 4

11

1 3 1
1 2 3
3 4 2
4 6 3
6 7 12
4 5 3
5 8 3
7 9 12
9 10 1
10 11 2







*/

