int n2;
vector < pair < int , int > > g2[N];
 
void addEdge( int u , int v , int w)
{
    g2[u].emplace_back(v,w);
}
 
int tree[N<<2], lazy[N<<2];
 
void propagate( int node , int l , int r )
{
    if(lazy[node] == -1)
        return ;
    tree[node] = lazy[node];
    if( l != r)
        lazy[node<<1] = lazy[node<<1|1] = lazy[node];
    lazy[node] = -1;
}
 
void update( int node , int l , int r,  int s , int e , int val)
{
    propagate(node,l,r);
    if( l  > e || r < s)
        return ;
    if( l >= s and r <= e)
    {
        lazy[node] = val;
        propagate(node,l,r);
        return;
    }
    int md = l + r >> 1 ;
    update(node<<1,l,md,s,e,val), update(node<<1|1,md+1,r,s,e,val);
    tree[node] = min(tree[node<<1],tree[node<<1|1]);
}
 
int parent[N], depth[N], heavy[N], val[N];
int q, pos[N], cur_pos, head[N];
 
int dfs2 ( int node)
{
    int size = 1 , max_c_size = 0;
    for(auto ch : g2[node])
    {
        if(ch.F == parent[node])
            continue;
        parent[ch.F] = node;
        val[ch.F] = ch.S;
        depth[ch.F] = depth[node] + 1;
        int c_size = dfs2(ch.F);
        size += c_size;
        if(c_size > max_c_size)
            max_c_size = c_size , heavy[node] = ch.F;
    }
    return size;
}
 
void decompose( int node , int h)
{
    head[node] = h, pos[node] = ++cur_pos;
    update(1,1,n2,pos[node],pos[node],val[node]);
    if(heavy[node])
        decompose(heavy[node],h);
    for(auto ch : g2[node])
    {
        if(ch.F == parent[node] || ch.F == heavy[node])
            continue;
        decompose(ch.F,ch.F);
    }
}
 
void solve ( int a , int b)
{
    while(head[a] != head[b])
    {
        if(depth[head[a]] < depth[head[b]])
            swap(a,b);
        update(1,1,n2,pos[head[a]],pos[a],1e9);
        a = parent[head[a]];
    }
    if(depth[a] < depth[b])
        swap(a,b);
 
    if(pos[b] < pos[a])
        update(1,1,n2,pos[b]+1,pos[a],1e9);
}
