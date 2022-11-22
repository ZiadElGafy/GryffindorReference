struct query{
    int L, R, idx;

    query(int l, int r, int i){
        L = l;
        R = r;
        idx = i;
    }
};

bool cmp(query& a, query& b){
    if(a.L / B == b.L / B)
        return a.R < b.R;
    return a.L < b.L;
}

int n, a[N], q;
vector<query> queries;

void add(int i){
    
}

void remove(int i){
    
}

int solve(){
    
}

vector<int> moAlgorithm(){
    vector<int> answers(q);
    sort(queries.begin(), queries.end(), cmp);

    int lastL = 1, lastR = 0;

    for(auto& i : queries){
        int L = i.L, R = i.R, idx = i.idx;

        while(lastL > L)
            add(--lastL);
        while(lastR < R)
            add(++lastR);
        while(lastL < L)
            remove(lastL++);
        while(lastR > R)
            remove(lastR--);

        answers[idx] = solve();
    }

    return answers;
}
