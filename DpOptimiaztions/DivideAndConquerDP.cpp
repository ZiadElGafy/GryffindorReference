ll dp[22][N], a[N];
void solve( int k , int l , int r , int optl , int optr)
{
    if ( l > r)
        return;
    ll md = l + r >> 1 , ans = optl, res = 0;
    for ( int j = md ; j >= optl ; j--)
    {
        if(dp[k-1][j] + res < dp[k][md])
        {
            ans = j;
            dp[k][md] = dp[k-1][j] + res;
        }
        res += 1LL * abs(j-md) * a[j];
    }
    solve(k,l,md-1,optl,ans),solve(k,md+1,r,ans,optr);
}
