struct FlowEdge
{
    int v,u;
    ld cap=0 , flow=0;
    FlowEdge(int v , int u , ld cap) : v(v) , u(u) , cap(cap) {}
};

struct Dinic
{
    ld flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int> > adj;
    int n , m=0;
    int s , t;
    vector<int> level , ptr;

    Dinic(int n, int s, int t) : n(n+2), s(s), t(t) {
        adj.resize(n+2);
        level.resize(n+2);
        ptr.resize(n+2);
    }

    void add_edge(int v, int u, ld cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs()
    {
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            for(int id : adj[v])
            {
                if (fabs(edges[id].cap - edges[id].flow ) < eps || level[edges[id].u] != -1) continue;
                level[edges[id].u] = level[v]+1;
                if (edges[id].u == t)
                    return 1;
                q.push(edges[id].u);
            }
        }
        return 0;
    }

    ld dfs(int v , ld mnCap)
    {
        if (v == t)
            return mnCap;

        for(int &cid=ptr[v]; cid < (int)adj[v].size(); cid++)
        {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || fabs(edges[id].cap - edges[id].flow) < eps) continue;
            ld f = dfs(u , min(mnCap , edges[id].cap-edges[id].flow));
            if (f > eps)
            {
                edges[id].flow += f;
                edges[id^1].flow -= f;
                return f;
            }
        }
        return 0;
    }

    ld flow()
    {
        ld res = 0 , f;
        while(1)
        {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            if (!bfs()) break;
            fill(ptr.begin() , ptr.end() , 0);

            while( ( (f = dfs(s , flow_inf)) > eps) )
                res += f;
        }
        return res;
    }
};

