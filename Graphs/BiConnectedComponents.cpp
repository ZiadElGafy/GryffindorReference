// Bi-Connected Components

int n, m, lo[N], timer[N], curTimer;
vector<int> g[N];
bool inStack[N], isArt[N];
stack<int> stk;
stack<pair<int, int>> taken;
 
 
void tarjan(int node, int par){
    timer[node] = lo[node] = ++curTimer;
    inStack[node] = 1;
    stk.push(node);
    int newChildren = 0;
 
    for(auto &i : g[node]){
        if(i == par)
            continue;
 
        if(!timer[i]){
            taken.push({node, i});
 
            tarjan(i, node);
            lo[node] = min(lo[node], lo[i]);
            newChildren++;
 
            if(lo[i] >= timer[node]){
                isArt[node] = 1;
                
                set<int> BCC;
                while(taken.top().F != node or taken.top().S != i){
                    BCC.insert(taken.top().F);
                    BCC.insert(taken.top().S);
                    taken.pop();
                }
                BCC.insert(taken.top().F);
                BCC.insert(taken.top().S);
                taken.pop();
            }
        }
        else if(inStack[i])
            lo[node] = min(lo[node], timer[i]);
    }
 
    if(par == node and newChildren <= 1)
        isArt[node] = 0;
 
    // assign SCC
    if(lo[node] == timer[node]){
        while(1){
            int cur = stk.top();
            stk.pop();
            inStack[cur] = 0;
 
            if(cur == node)
                break;
        }
    }
}
