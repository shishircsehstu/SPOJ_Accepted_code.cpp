/******************************************************************
 *                   BISMIintAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
#include<bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)

#define sii(a,b) scanf("%d%d",&a,&b)

#define pt(a) printf("%d\n",a)
#define PLN(a) printf("%I64d\n",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second

#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 3000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
#define mod 100000009
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

using namespace std;

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]= {1,1,2,2,-1,-1,-2,-2}; /*knight move*/
//int dy[]= {2,-2,1,-1,2,-2,1,-1}; /*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48


//upper bound and lower bound

#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())
//S.insert(lower_bound(S.begin( ),S.end( ),x),x); //S is vector

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
/* -a%b---------
ll  Mod(ll  a,ll  b)
{
    ll  c = a % b;
    return (c < 0) ? c + b : c;
}
/*
ll  power(ll num,ll p)
{
    int i;
    ll sum=1;
    for(i=1; i<=p; i++)
        sum*=num;
    return sum;
}
*/
int dis[1004][1005];
char str[1001][1001];
int vis[1001][1001][4];
int row,col,ro2,co2;
void bfs(int sx,int sy)
{
    int x,y,i,dir;
    vis[sx][sy][1]=1;
    vis[sx][sy][2]=1;
    vis[sx][sy][3]=1;
    vis[sx][sy][4]=1;
    dis[sx][sy]=1;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        x=top.ff;
        y=top.ss;
        if(x==ro2 and y==co2) break;
        //  cout<<x<<"   "<<y<<endl;
        // cout<<"dis="<<dis[x][y]<<endl;
        dir=1;
        //right
        for(i=y+1; i<=col; i++)
        {
            if(str[x][i]=='X') break;
            if(vis[x][i][dir]==1) break;
            if(dis[x][i]==0)
            {
                dis[x][i]=dis[x][y]+1;
                vis[x][i][dir]=1;
                // cout<<x<<" one "<<i<<endl;
                q.push(pii(x,i));
            }
        }
        //left
        for(i=y-1; i>=1; i--)
        {
            if(str[x][i]=='X') break;
            if(vis[x][i][dir]==1) break;
            if(dis[x][i]==0)
            {
                dis[x][i]=dis[x][y]+1;
                vis[x][i][dir]=1;
                // cout<<x<<" 4th "<<i<<endl;
                q.push(pii(x,i));
            }
        }
        dir++;
        //cout<<endl;
        //down
        for(i=x+1; i<=row; i++)
        {
            if(str[i][y]=='X') break;
            if(vis[i][y][dir]==1) break;
            if(dis[i][y]==0)
            {
                dis[i][y]=dis[x][y]+1;
                vis[i][y][dir]=1;
                // cout<<i<<" 2nd "<<y<<endl;
                q.push(pii(i,y));
            }
        }
        // cout<<endl;
        //up
        // dir++;
        for(i=x-1; i>=1; i--)
        {
            if(str[i][y]=='X') break;
            if(vis[i][y][dir]==1) break;
            if(dis[i][y]==0)
            {
                dis[i][y]=dis[x][y]+1;
                vis[i][y][dir]=1;
                // cout<<i<<" 3rd "<<y<<endl;
                q.push(pii(i,y));
            }
        }

        //  cout<<endl;
        // dir++;
        //right up
        int yy;
        yy=y;
        dir++;
        for(i=x-1; i>=1; i--)
        {
            yy++;
            if(yy>col) break;
            if(str[i][yy]=='X') break;
            if(vis[i][yy][dir]==1) break;
            if(dis[i][yy]==0)
            {
                dis[i][yy]=dis[x][y]+1;
                vis[i][yy][dir]=1;
                q.push(pii(i,yy));
                // cout<<i<<" 5th "<<yy<<endl;
            }
        }
        yy=y;
        //left down
        // dir++;
        for(i=x+1; i<=row; i++)
        {
            yy--;
            if(yy<=0) break;
            if(str[i][yy]=='X') break;
            if(vis[i][yy][dir]==1) break;
            if(dis[i][yy]==0)
            {
                dis[i][yy]=dis[x][y]+1;
                vis[i][yy][dir]=1;
                q.push(pii(i,yy));
                // cout<<i<<" 7th "<<yy<<endl;
            }
        }

        int xx;
        xx=x;
        yy=y;
        //right down
        // cout<<endl;
        dir++;
        for(i=xx+1; i<=row; i++)
        {
            yy++;
            if(yy>col) break;
            if(str[i][yy]=='X') break;
            if(vis[i][yy][dir]==1) break;
            if(dis[i][yy]==0)
            {
                dis[i][yy]=dis[x][y]+1;
                vis[i][yy][dir]=1;
                q.push(pii(i,yy));
                //  cout<<i<<" 6th "<<yy<<endl;
            }
        }
        yy=y;
        //left up
        for(i=x-1; i>=1; i--)
        {
            yy--;
            if(yy<=0) break;
            if(str[i][yy]=='X') break;
            if(vis[i][yy][dir]==1) break;
            if(dis[i][yy]==0)
            {
                dis[i][yy]=dis[x][y]+1;
                vis[i][yy][dir]=1;
                q.push(pii(i,yy));
                // cout<<i<<" 8th "<<yy<<endl;
            }
        }
    }
}
char ch;
int main()
{
    int x,ro1,co1,i,j,t;
    char c1,c2;
    si(t);
    while(t--)
    {
        mem(dis);
        mem(vis);
        si(row),si(col);
        for(i=1; i<=row; i++)
        {
            for(j=1; j<=col; j++)
            {
                scanf(" %c",&ch);
                if(ch=='S')
                {
                    ro1=i;
                    co1=j;
                }
                else if(ch=='F')
                {
                    ro2=i;
                    co2=j;
                }
                str[i][j]=ch;
            }
        }
        bfs(ro1,co1);
        printf("%d\n",dis[ro2][co2]-1);
    }
    return 0;
}
/*
1
5 5
S....
.....
.....
.....
....F
*/
