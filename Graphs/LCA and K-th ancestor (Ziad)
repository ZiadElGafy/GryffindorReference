int n, q, anc[N][LOG], in[N], out[N], timer, depth[N];
vector<vector<int>> g;

void dfs(int node, int par, int dep){
    depth[node] = dep;

    in[node] = timer++;

    anc[node][0] = par;

    for(int k = 1; k < LOG; k++)
        anc[node][k] = anc[anc[node][k - 1]][k - 1];

    for(auto i : g[node])
        dfs(i, node, dep + 1);

    out[node] = timer++;
}

bool isChildOf(int x, int y){ // X is in the subtree of Y
    return in[y] <= in[x] and out[x] <= out[y];
}


int LCA(int x, int y){
    if(isChildOf(x, y))
        return y;
    if(isChildOf(y, x))
        return x;

    if(depth[x] < depth[y])
        swap(x, y);

    for(int k = LOG - 1; k >= 0; k--)
        if(!isChildOf(y, anc[x][k]))
            x = anc[x][k];

    return anc[x][0];
}

bool mnwr(int msk, int bit){
    return (msk >> bit) & 1;
}

int kthAncestor(int node, int k){
    for(int j = LOG - 1; j >= 0; j--)
        if(mnwr(k, j))
            node = anc[node][j];

    return node;
}
