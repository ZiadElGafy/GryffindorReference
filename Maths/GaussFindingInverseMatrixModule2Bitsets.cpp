vector< bitset<N> > a(N) , ans(N);
 
bool gauss()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            if (a[j][i])
            {
                swap(a[i],a[j]);
                swap(ans[i] , ans[j]);
                break;
            }
            if (j==n) return 0;
        }
 
        for(int j=1; j<=n; j++)
        {
            if (i != j && a[j][i])
            {
                a[j] ^= a[i];
                ans[j] ^= ans[i];
            }
        }
    }
    return 1;
}
