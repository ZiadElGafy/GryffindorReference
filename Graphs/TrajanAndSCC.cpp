pair<int, int> pr(int a, int b){
    return {min(a, b), max(a, b)};
}

int n, m, scc[N], lowLink[N], timer[N], compID, curTimer;
vector<int> g[N], comps[N];
set<pair<int, int>> bridges;
set<int> artPoints;
bool inStack[N];
stack<int> stk;

void tarjan(int node, int par){
    timer[node] = lowLink[node] = ++curTimer;
    stk.push(node);
    inStack[node] = 1;
    int newChildren = 0;

    for(auto &i : g[node]){
        if(i == par)
            continue;

        if(!timer[i]){
            tarjan(i, node);
            lowLink[node] = min(lowLink[node], lowLink[i]);
            newChildren++;

            if(lowLink[i] == timer[i])
                bridges.insert(pr(node, i));

            if(lowLink[i] >= timer[node])
                artPoints.insert(node);
        }
        else if(inStack[i])
            lowLink[node] = min(lowLink[node], timer[i]);
    }

    if(par == node and newChildren <= 1)
        artPoints.erase(node);

    if(lowLink[node] == timer[node]){
        compID++;

        while(1){
            int cur = stk.top();
            stk.pop();
            inStack[cur] = 0;
            scc[cur] = compID;
            comps[compID].push_back(cur);

            if(cur == node)
                break;
        }
    }
}
