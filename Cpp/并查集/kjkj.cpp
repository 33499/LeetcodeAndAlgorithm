#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MAXN 1005
typedef long long ll;
int fa[MAXN],rank_node[MAXN];
ll x[MAXN],y[MAXN],z[MAXN];
using namespace std;

// 判断两个圆是否相切，相交
inline bool is_next(ll x1,ll y1,ll z1,ll x2,ll y2,ll z2,ll r)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2) <= 4*r*r;
}

//初始化 
inline void init(int n)
{
    
    for(int i = 1; i <= n; ++i)
    {
        rank_node[i] = 1;
        fa[i] = i;     
    }
}
//查找根节点
int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

//合并集合
inline void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if(rank_node[x] <= rank_node[y])
        fa[x] = y;
    else 
        fa[y] = x;
    if(rank_node[x] == rank_node[y] && x != y)
        rank_node[y]++;
}

int main()
{
    int T,n,h;
    ll r;
    scanf("%d",&T);
    for(int i = 0; i < T; ++i)
    {
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(z,0,sizeof(z));
        scanf("%d%d%lld",&n,&h,&r);
        init(n);
        fa[1001] = 1001; // 用1001代表底部节点
        fa[1002] = 1002; // 用1002代表顶部元素
        for(int i= 1; i<=n; i++)
        {
            scanf("%lld%lld%lld",x+i,y+i,z+i);
        }

        for(int i = 1; i <= n; i++)
        {
            if(z[i] <= r)
                merge(i,1001); //与底部接触的空洞与底部结合
            if(z[i] >= h-r)
                merge(i,1002); //与底部接触的空洞与底部结合
        }
        for(int i = 1; i <= n; ++i)
            for(int j = i+1; j <= n; j++)
                {
                    if(is_next(x[i],y[i],z[i],x[j],y[j],z[j],r))
                        merge(i,j); //遍历所有空洞，合并相交和相切的球
                }
        printf("%s",find(1001) == find(1002) ? "yes" : "no");
    }
    return 0;
}