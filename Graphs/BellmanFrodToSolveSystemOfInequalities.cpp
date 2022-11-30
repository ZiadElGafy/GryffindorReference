#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ld long double
#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 3e5+10 ,M = 3e5+10 ,mod = 1e9+7;
const ll inf = LLONG_MAX;

int n, ID;
vector < pair < ll , ll > > g[N], ranges;
map < ll , ll > id, rev;
ll dist[N];

bool check( int k)
{
    for ( int i = 0 ; i <= ID ; i++)
        g[i].clear(),dist[i] = 0;

    for ( int i = 0 ; i < n ; i++)
    {
        int u = id[ranges[i].F], v = id[ranges[i].S];
        // sum[v] - sum[u-1] <= k
        g[v].emplace_back(u-1,k);
        // sum[v] - sum[u-1] >= 1
        g[u-1].emplace_back(v,-1);
    }

    for ( int i = 1 ; i <= ID ; i++)
    {
        // sum[i] - sum[i-1] <= 1
        g[i].emplace_back(i-1,1);
        // sum[i] - sum[i-1] >= 0
        g[i-1].emplace_back(i,0);
    }

    bool any;
    for ( int i = 0 ; i < ID ; i++)
    {
        any = false;
        for( int u = 0 ; u <= ID ; u++)
        {
            for(auto v : g[u])
            {
                int nxt = v.F, c = v.S;
                if(dist[nxt] > dist[u] + c)
                    dist[nxt] = dist[u] + c,any = true;
            }
        }
    }
    return !any;
}

void testCase() {

    cin >> n;
    set < ll > points;

    for ( int i = 0 ; i < n ; i++)
    {
        ll l , r ;
        cin >> l >> r;
        ranges.emplace_back(l,r);
        points.insert(l);
        points.insert(r);
    }

    for(auto p : points)
        id[p] = ++ID, rev[ID] = p;

    int st = 0, en = n;
    while(st <= en)
    {
        int md = st + en >> 1 ;
        if(check(md))
            en = md-1;
        else
            st = md+1;
    }
    check(en+1);
    vector < ll > ans;
    for (int i = 1 ; i <= ID ; i++)
    {
        if(dist[i] != dist[i-1])
            ans.push_back(rev[i]);
    }
    cout << ans.size() << '\n';
    for(auto j : ans)
        cout << j << ' ';
    cout << '\n';
}

int32_t main() {
    Tsetso
    int tc = 1;
//    cin >> tc;
    while(tc--)
        testCase();
}
