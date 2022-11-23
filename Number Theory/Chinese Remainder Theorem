/// calculate each two congruences then solve with next: sol(sol(sol(1, 2), 3), 4)
 
/// T = x mod N                  -> T = N * k + x
/// T = y mod M                  -> T = M * p + y
/// N * k + x = M * p + y        -> N * k - M * p = y - x (LDE)
ll CRT(vector<ll> &rems, vector<ll> &mods){
    ll prevRem = rems[0], prevMod = mods[0]; /// first congruence
 
    for(int i = 1; i < rems.size(); i++){
        ll x, y, c = rems[i] - prevRem;
 
        if(c % __gcd(prevMod, -mods[i])) /// LDE can't be solved (no answer to system of congruences)
            return -1;
 
        ll g = eGCD(prevMod, -mods[i], x, y);
        x *= c / g;
 
        prevRem += prevMod * x;
        prevMod = prevMod / g * mods[i];
        prevRem = ((prevRem % prevMod) + prevMod) % prevMod;
    }
 
    return prevRem;
}
