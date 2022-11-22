struct DSU{
    int par[N], sz[N];
 
    void init(int n){
        for(int i = 1; i <= n; i++)
            par[i] = i, sz[i] = 1;
    }
 
    int findPar(int v){
        return (par[v] == v ? v : par[v] = findPar(par[v]));
    }
 
    void join(int u, int v){
        u = findPar(u), v = findPar(v);
 
        if(u == v)
            return;
 
        if(sz[u] < sz[v])
            swap(u, v);
 
        par[v] = u;
        sz[u] += sz[v];
    }
}dsu;
