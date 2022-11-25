int n , m , k , sz[N] , col[N] , bad[N];
pair<int,int> par[N];
map<int,vector< pair<int,int> > > mp[N];
stack<pair<int,int> > sml , lar;

pair<int,int> findPar(int node)
{
    if (node != par[node].f)
    {
        int parity = par[node].s;
        pair<int,int> pr = findPar(par[node].f);
        return {pr.f , parity^pr.s};
    }
    else return par[node];
}

bool mergeCom(int node , int node2 , bool roll)
{
    pair<int,int> led = findPar(node) , led2 = findPar(node2);

    if (led.f == led2.f)
    {

        if (led.s == led2.s) return 0;
        return 1;
    }
    else
    {
        if (sz[led.f] < sz[led2.f]) swap(led,led2);

        if (roll)
        {
            sml.push({led2.f , 0});
            lar.push({led.f , sz[led.f]});
        }

        par[led2.f] = {led.f , led.s^led2.s^1};
        sz[led.f] += sz[led2.f];

        return 1;
    }
}

void roll_back()
{
    while(sml.size())
    {
        int nodeSml = sml.top().f , nodeLar = lar.top().f;
        par[nodeSml] = {nodeSml , 0};
        sz[nodeLar] = lar.top().s;
        sml.pop();
        lar.pop();
    }
}
