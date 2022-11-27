#define matrix vector<vector<int>>
const ll mod2 = 1ll * mod * mod;
 
int add(int a, int b){
    return (a + b) % mod;
}
 int mul(int a, int b){
    return 1ll * a * b % mod;
}
 
matrix mul(matrix &a, matrix &b){
    int n = a.size(), k = a[0].size();
    int k2 = b.size(), m = b[0].size();
    assert(k == k2);
    matrix ret(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ll tmp = 0;
            for(int k = 0; k < k2; k++){
                tmp += 1ll * a[i][k] * b[k][j];
                while(tmp >= mod2) tmp -= mod2;
            }
            ret[i][j] = tmp % mod;
        }
    }
    return ret;
}
 
matrix I(int n){
    matrix ret(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) ret[i][i] = 1;
    return ret;
}
 
matrix fp(matrix &b, ll p){
    if(p == 0) return I(b.size());
    auto ret = fp(b, p >> 1);
    ret = mul(ret, ret);
    if(p & 1) ret = mul(ret, b);
    return ret;
}
