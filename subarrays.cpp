#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

#include<string.h>
#include<math.h>
#define N 20
#define MAX (1+(1<<6))
int tree[1000001];
int lazy[MAX];
void build_tree(int node, int s, int e, int id, int value)
{
    if(id < s || id > e || s > e) return;
    if(s == e)
    {
        tree[node] = value;
        return;
    }
    build_tree( node*2,s,(s+e)/2,id,value);
    build_tree(node*2+1,(s+e)/2+1,e,id,value);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

int query_tree(int node, int a, int b, int i, int j)
{
    int q1,q2,res;
    if(a > b || a > j || b < i) return -1;

    if(a >= i && b <= j)
        return tree[node];

    q1 = query_tree(node*2, a, (a+b)/2, i, j);
    q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
    res  = max(q1,q2);
    return res;
}

int main()
{
    int i,j,n,x,y,m,t,cs=1;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        build_tree(1, 0, n-1,i,x);
    }
    scanf("%d",&x);
    y=n-x+1;
    m=0;
    x=x-1;
    for(i=1; i<=y; i++)
    {
        printf("%d",query_tree(1, 0, n-1, m++, x++));
        if(i<y)
            printf(" ");
    }
    // printf("%d\n",query_tree(1, 0, n-1, x-1, y-1));
}
