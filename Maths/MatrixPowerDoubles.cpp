#define matrix vector < vector < ld > >
 
 
matrix mul( matrix &a , matrix &b)
{
    int n = a.size() , k = a[0].size();
    int k2 = b.size() , m = b[0].size();
    assert( k == k2);
    matrix ret(n,  vector <ld > (m,0));
    for ( int i = 0 ; i < n ; i++)
        for ( int j =  0 ; j < m ; j++)
            for ( int k3 = 0 ; k3 < k2 ; k3++)
                ret[i][j] += a[i][k3] * b[k3][j];
    return ret;
}
 
matrix fp( matrix &b , int p)
{
    if(p == 1)
        return b;
    auto ret = fp(b, p >> 1);
    ret = mul(ret ,ret);
    if(p&1)
        ret = mul(ret,b);
    return ret;
}
