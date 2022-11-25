//Kuhn algo

const int N = 1e2+5;
int n,m;
int matchTo[N];
vector<int> adj[N];
bool vis[N];

bool dfs(int node)
{
    if (vis[node]) return 0;
    vis[node] = 1;
    for(auto ch : adj[node])
    {
        if (!matchTo[ch] || dfs(matchTo[ch]))
        {
            matchTo[ch] = node;
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y); //from left to right , y bigger than n
    }

    int match=0;
    for(int i=1; i<=n; i++)
    {
        memset(vis , 0 , sizeof(vis));
        match += dfs(i);
    }

    cout << match << '\n';

    return 0;
}
