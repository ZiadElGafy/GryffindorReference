bool cmpX(pair<point, int> &a, pair<point, int> &b){
    if(a.first.X != b.first.X)
        return a.first.X < b.first.X;

    if(a.first.Y != b.first.Y)
        return a.first.Y < b.first.Y;

    return a.second < b.second;
}

struct cmpY{
    bool operator()(const pair<point, int> &a, const pair<point, int> &b) const {
        if(a.first.Y != b.first.Y)
            return a.first.Y < b.first.Y;

        if(a.first.X != b.first.X)
            return a.first.X < b.first.X;

        return a.second < b.second;
    }
};

///                          point, idx
void closestPair(vector<pair<point, int>> &v){
    if(v.size() < 2)
        return;

    ld d = abs(vec(v[1].first, v[0].first));
    int idx1 = 0, idx2 = 1;
    sort(v.begin(), v.end(), cmpX);
    set<pair<point, int>, cmpY> st;
    int left = 0, n = v.size();

    for(int i = 0; i < n; i++){
        while(left < i and v[i].first.X - v[left].first.X > d)
            st.erase(st.find(v[left++]));

        pair<point, int> tmp = {point(-(1e9 + 5), v[i].first.Y - d), 0};

        auto it = st.lower_bound(tmp);

        for(; it != st.end() and v[i].first.Y + d >= (*it).first.Y; it++){
            ld dist = abs((v[i].first - (*it).first));
            if(dist < d){
                d = dist;
                idx1 = v[i].second;
                idx2 = (*it).second;
            }
        }

        st.insert(v[i]);
    }

    if(idx1 > idx2)
        swap(idx1, idx2);

    // indices of points from input (0 based)
    cout << idx1 << " " << idx2 << " " << fixed << setprecision(6) << d << '\n';
}
