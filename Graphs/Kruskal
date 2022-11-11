ll kruskal(){
    vector<pair<int, pair<int, int>>> edges, takenEdges;
    dsu.init(n);
    ll cost = 0;
    
    
    for(int i = 1; i <= n; i++)
        for(auto &j : g[i])
            edges.push_back({j.S, {i, j.F}});

    sort(edges.begin(), edges.end());

    for(auto &e : edges){
        int u = e.S.F, v = e.S.S, c = e.F;

        if(dsu.findPar(u) != dsu.findPar(v)){
            cost += c;
            takenEdges.push_back(e);
            dsu.join(u, v);
        }
    }

    return cost;
}
