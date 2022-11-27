//A X = B , find X with mod
ll inv(ll x, ll MOD) { return fp(x, MOD - 2); }
//Last col of matrix (a) is the results of the system
vector<ll> gauss(vector<vector<ll> > &a, ll MOD)
{
    int n = a.size(), m = a[0].size() - 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= m; j++)
            a[i][j] = (a[i][j] % MOD + MOD) % MOD;

    vector<int> where(m, -1);
    for(int col = 0, row = 0; col < m && row < n; col++)
    {
        int sel = row;
        for(int i = row; i < n; i++)
            if(a[i][col] > a[sel][col])
                sel = i;

        if(a[sel][col] == 0) { where[col] = -1; continue;
        }

        for(int i = col; i <= m; i++)
            swap(a[sel][i], a[row][i]);
        where[col] = row;

        ll c_inv = inv(a[row][col], MOD);
        for(int i = 0; i < n; i++)
            if(i != row)
            {
                if(a[i][col] == 0) continue;
                ll c = (a[i][col] * c_inv) % MOD;
                for(int j = 0; j <= m; j++)
                    a[i][j] = (a[i][j] - c * a[row][j] % MOD + MOD) % MOD;
            }

        row++;
    }
    vector<ll> ans(m, 0);
    ll result = 1;
    // for counting rank, take the count of where[i]==-1
    for(int i = 0; i < m; i++)
        if(where[i] != -1) ans[i] = (a[where[i]][m] * inv(a[where[i]][i], MOD)) % MOD;
        else result = (result * MOD) % mod;
    // This is validity check probably.May not be needed
    for(int i = 0; i < n; i++)
    {
        ll sum = a[i][m] % MOD;
        for(int j = 0; j < m; j++)
            sum = (sum + MOD - (ans[j] * a[i][j]) % MOD) % MOD;

        if(sum != 0) return vector<ll>(); //Has No Sol
    }
    
	// Has at least one sol
    return ans;
}
