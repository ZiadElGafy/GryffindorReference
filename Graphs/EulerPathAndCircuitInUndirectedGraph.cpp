// Euler Circuit in directed graph : a path starts from an arbitrarily node and visit each edge exactly once and returns to the same node u started from
// 1- even degree for each node in the graph
// 2- connected component

// Euler path in undirected graph : same as Euler circuit but u do not have to return to the same node u started from
// 1- even degree for each node except 2 nodes exactly 
// start node ----> one of the nodes with odd degree and the other one will be the end node
// 2- connected component 

int n, m, deg[N], vis[N];
vector < pair < int , int > > g[N];
 
vector < int > path;
void Tour(int node)
{
    while(!g[node].empty())
    {
        int nxt = g[node].back().F , edgeidx = g[node].back().S;
        g[node].pop_back();
        if(!vis[edgeidx])
        {
            vis[edgeidx] = 1;
            Tour(nxt);
        }
    }
    path.push_back(node);
}
