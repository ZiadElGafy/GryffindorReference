struct node
{
    ll sum = 0 , lazy = 0;
    node *lf , *rt;
    node()
    {
        lf = rt = NULL;
    }
};


void probagate(node *cur , int st , int en)
{
    if (cur->lazy != 0)
    {
        cur->sum += (en - st + 1) * cur->lazy;

        if (cur->lf == NULL) cur->lf = new node();
        if (cur->rt == NULL) cur->rt = new node();
        cur->lf->lazy += cur->lazy;
        cur->rt->lazy += cur->lazy;
        cur->lazy = 0;
    }
}


void update(node *cur , int st , int en , int l , int r , int val)
{
    if (cur == NULL)
        cur = new node();

    probagate(cur , st , en);
    if (l > en || r < st)
        return;
    if (l <= st && en <= r)
    {
        cur->lazy += 1ll*val;
        probagate(cur , st , en);
    }
    else
    {
        int mid = (st+en)/2;

        if (cur->lf == NULL) cur->lf = new node();
        if (cur->rt == NULL) cur->rt = new node();

        update(cur->lf , st , mid , l , r , val);
        update(cur->rt , mid+1 , en , l , r , val);
        cur->sum = cur->lf->sum + cur->rt->sum;
    }
}


ll query(node *cur , int st , int en , int l , int r)
{
    if (cur == NULL)
        cur = new node();

    probagate(cur , st , en);
    if (l > en || r < st)
        return 0;

    if (l <= st && en <= r)
        return cur->sum;

    int mid = (st+en)/2;

    return query(cur->lf , st , mid , l , r) + query(cur->rt , mid+1 , en , l , r);
}
