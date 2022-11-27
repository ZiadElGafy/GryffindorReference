// Euler Circuit in directed graph : a path starts from an arbitrarily node and visit each edge exactly once and returns to the same node u started from
// 1- in degree = out degree for each node in the graph
// 2- connected component

// Euler path in direected graph : same as Euler circuit but u do not have to return to the same node u started from
// 1- in degree = out degree for each node except 2 nodes exactly 
// start node ----> out degree == in degree + 1 
// end node ----> in degree == out degree + 1 
// 2- connected component 

int n, m, in[N], out[N], vis[N];
vector < pair < int , int > > g[N];
 
vector < int > path;
void Tour(int node)
{
    while(!g[node].empty())
    {
        int nxt = g[node].back().F;
        g[node].pop_back();
        Tour(nxt);
    }
    path.push_back(node);
}
