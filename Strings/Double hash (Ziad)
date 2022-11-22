/// DON'T FORGET TO CALL PRE()!
const int b1 = 29, b2 = 37;
 
int mul(int a, int b){
    return 1LL * a * b % mod;
}
 
int add(int a, int b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (a + b) % mod;
}
 
int fp(int b, int p){
    if (b == 1 or p == 0)
        return 1;
    if (p == 1)
        return b;
 
    ll hp = fp(b, p >> 1);
    ll ans = hp * hp % mod;
 
    if (p % 2)
        (ans *= b) %= mod;
 
    return ans;
}
 
int modInv(int x){
    return fp(x, mod - 2);
}
 
int pw1[N], invP1[N];
int pw2[N], invP2[N];
 
void pre(){
    pw1[0] = invP1[0] = 1;
    int baseInverse1 = modInv(b1);
 
    pw2[0] = invP2[0] = 1;
    int baseInverse2 = modInv(b2);
 
    for(int i = 1; i < N; i++){
        pw1[i] = mul(pw1[i - 1], b1);
        invP1[i] = mul(invP1[i - 1], baseInverse1);
 
        pw2[i] = mul(pw2[i - 1], b2);
        invP2[i] = mul(invP2[i - 1], baseInverse2);
    }
}
 
struct Hash{
    vector<pair<int, int>> prefixHash, revHash;
    int sz;
 
    Hash():sz(0){}
 
    Hash(string s){
        sz = s.size();
        prefixHash.assign(sz, {0, 0});
        revHash.assign(sz, {0, 0});
 
        for(int i = 0; i < sz; i++){
            prefixHash[i].first = mul(s[i] - 'A' + 1, pw1[i]);
            prefixHash[i].second = mul(s[i] - 'A' + 1, pw2[i]);
 
            if(i > 0){
                prefixHash[i].first = add(prefixHash[i].first, prefixHash[i - 1].first);
                prefixHash[i].second = add(prefixHash[i].second, prefixHash[i - 1].second);
            }
        }
 
        reverse(s.begin(), s.end());
 
        for(int i = 0; i < sz; i++){
            revHash[i].first = mul(s[i] - 'A' + 1, pw1[i]);
            revHash[i].second = mul(s[i] - 'A' + 1, pw2[i]);
 
            if(i > 0){
                revHash[i].first = add(revHash[i].first, revHash[i - 1].first);
                revHash[i].second = add(revHash[i].second, revHash[i - 1].second);
            }
        }
    }
 
    pair<int, int> getHashValue(){
        return prefixHash.back();
    }
 
    pair<int, int> getRangeHashValue(int l, int r){
        return {mul(add(prefixHash[r].first, -(l ? prefixHash[l - 1].first: 0)), invP1[l]),
                mul(add(prefixHash[r].second, -(l ? prefixHash[l - 1].second: 0)), invP2[l])};
    }
 
    pair<int, int> getRevHashValue(int pl, int pr){//	if rangeHash(i, j) == revHash(i, j) --> substr(i, j) is a palindrome
        int l = sz - pr - 1;
        int r = sz - pl - 1;
 
        return {mul(add(revHash[r].first, -(l ? revHash[l - 1].first: 0)), invP1[l]),
                mul(add(revHash[r].second, -(l ? revHash[l - 1].second: 0)), invP2[l])};
    }
};
