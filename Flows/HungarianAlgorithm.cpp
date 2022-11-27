//Hungarian Algorithm for min cost bipartite matching, works also with negative costs
//All the nodes on the left should have an edge with all the nodes on the right (complete graph)
//a[1][1] represents the cost of the edge between node 1 in the left and node 1 in the right
//One based and every row should be matched with exactly one column

int hung()
{
    vector<int> u (n+1), v (m+1), p (m+1), way (m+1); //n is the nodes on the left (rows), m in the nodes on right (columns)
    for (int i=1; i<=n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv (m+1, INF);
        vector<char> used (m+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0],  delta = INF,  j1;
            for (int j=1; j<=m; ++j)
                if (!used[j]) {
                    int cur = a[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=m; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    vector<int> ans (n+1);
    for (int j=1; j<=m; ++j)
        ans[p[j]] = j; //ans[p[j]] represents that j-th column is matched with p[j]-th row

    int cost = -v[0]; //min cost 
    return cost;
}
