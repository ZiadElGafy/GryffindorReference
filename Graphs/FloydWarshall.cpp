void floyd(){ // d[i][j] = (edge(i, j) ? cost : INF)
    for(int k = 1; k <= n; k++) // try K as an intermediate node
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    // if(d[i][i] < 0): i is part of a negative cycle
}
