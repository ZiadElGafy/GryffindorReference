using u128 = __uint128_t;

/// return (s * m) % mod
 ll mult(ll s, ll m, ll mod){
      if(!m) return 0;
      ll ret = mult(s, m/2, mod);
      ret = (ret + ret) % mod;
      if(m & 1) ret = (ret + s) % mod;
      return ret;
}
  
ll fp(ll b, ll p, ll mod){
    ll res = 1;
    b %= mod;
    while(p > 0){
        if(p & 1) res = (u128) res * b % mod;
        b = (u128) b * b % mod;
        p >>= 1;
    }
    return res;

}

bool check(ll n, ll a, ll d, ll s){
    ll x = fp(a, d, n);
    if(x == 1 || x == n - 1) return 0;
    for(int r = 1; r < s; r++){
        x = (u128) x * x % n;
        if(x == n - 1) return 0;
    }
    return 1;
}

bool MillerRabin(ll n){
    if(n < 2) return 0;

    int r = 0;
    ll d = n - 1;
    while((d & 1) == 0){
        d >>= 1;
        r++;
    }
    for(ll a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(n == a) return 1;
        if(check(n, a, d, r)) return 0;
    }
    return 1;
}
