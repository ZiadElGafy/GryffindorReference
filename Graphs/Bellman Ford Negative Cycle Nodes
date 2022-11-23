/// understands directed only
/// dist INF: unreachable, -INF: reachable by negative cycle
bool bellman(int source){
    for(int i = 1; i <= n; i++)
        dist[i] = (i == source ? 0 : INF), pre[i] = -1;

    int times = n - 1, lastChanged;
    while(times--){
        lastChanged = -1;

        for(int i = 1; i <= n; i++){
            for(auto &j : g[i]){
                if(dist[i] + j.S < dist[j.F]){
                    dist[j.F] = dist[i] + j.S, pre[j.F] = i;
                    lastChanged = j.F;
                    pre[j.F] = i;
                }
            }
        }

        if(lastChanged == -1)
            return 0;
    }

    lastChanged = -1;

    for(int i = 1; i <= n; i++)
        for(auto &j : g[i])
            if(dist[i] + j.S < dist[j.F])
                dist[j.F] = -INF, lastChanged = j.F;

    if(lastChanged == -1)
        return 0;

    int cur = lastChanged;
    for(int i = 0; i < n; i++)
        cur = pre[cur];

    int temp = cur;

    vector<int> cycleNodes;

    do{
        cycleNodes.push_back(cur);
        cur = pre[cur];
    }while(cur != temp);

    reverse(cycleNodes.begin(), cycleNodes.end());

    cout << "Negative cycle: ";
    for(auto &i : cycleNodes)
        cout << i << ' ';

    return 1; /// negative cycle
}
