vector < ll > basis;
void init()
{
    basis.clear();
}
 
bool insertVector( ll x)
{
    for(auto cur : basis)
        x = min(x , cur ^ x);
    if(x)
        basis.push_back(x);
    return x == 0;
}
