/// understands directed only
/// dist INF: unreachable, dist -INF: reachable by negative cycle
bool bellman(int source){
    for(int i = 1; i <= n; i++)
        dist[i] = (i == source ? 0 : INF);

    int times = n - 1, lastChanged;
    while(times--){
        lastChanged = -1;

        for(int i = 1; i <= n; i++)
            for(auto &j : g[i])
                if(dist[i] + j.S < dist[j.F])
                    dist[j.F] = dist[i] + j.S, lastChanged = j.F;

        if(lastChanged == -1)
            return 0;
    }

    lastChanged = -1;

    // run this part n times to get all nodes reachable by negative cycle
    for(int i = 1; i <= n; i++)
        for(auto &j : g[i])
            if(dist[i] + j.S < dist[j.F])
                dist[j.F] = -INF, lastChanged = j.F;

    return (~lastChanged); /// negative cycle
}
