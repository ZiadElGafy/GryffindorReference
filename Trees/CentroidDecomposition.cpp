const int N = 2e5+10, M = 23, inf = 1e6, mod = 1e9+7 , b = 29 , b2 = 31;
int n, k , sz[N], cpar[N],vis[N];
vector < int > g[N];
void init()
{
    for ( int i = 1;  i <= n ;i++)
        g[i].clear();
}
int dfs_sz( int node , int par)
{
    sz[node] = 1;
    for(auto ch : g[node])
    {
        if(ch == par || vis[ch])
            continue;
        sz[node] += dfs_sz(ch,node);
    }
    return sz[node];
}
 
int dfs_centroid( int node , int par , int tot)
{
    for(auto ch : g[node])
    {
        if(ch == par || vis[ch])
            continue;
        if(sz[ch] > tot / 2)
            return dfs_centroid(ch,node,tot);
    }
    return node;
}
int cnt[N];
ll ans;
vector < int > pool;
void dfs_collect( int node , int par , int cur)
{
    pool.push_back(cur);
    for(auto ch : g[node])
    {
        if(ch == par || vis[ch])
            continue;
        dfs_collect(ch,node,cur+1);
    }
}
void build( int node , int par)
{
    int tot = dfs_sz(node,par);
    int centroid = dfs_centroid(node , par, tot);
    if(par == -1)
        par = centroid;
    cpar[centroid] = par;
    vis[centroid] = 1;
    cnt[0] = 1;
    for(auto ch : g[centroid])
    {
        if(vis[ch])
            continue;
        pool.clear();
        dfs_collect(ch, centroid,1);
        for(auto j : pool)
            if(k >= j)
                ans += cnt[k-j];
        for(auto j : pool)
            cnt[j]++;
    }
    for ( int i = 0 ; i < tot ; i++)
        cnt[i] = 0;
    for(auto ch : g[centroid])
       if(!vis[ch])
            build(ch,centroid);
}
