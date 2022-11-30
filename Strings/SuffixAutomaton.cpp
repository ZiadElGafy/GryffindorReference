 
struct SA {
 
    struct node {
        map<int, int> to;
        int link, len, mxlen;
        ll co = 0, co2 = 0;
        bool bad = 0;
 
        node() {
            co = co2 = 0, link = 0, len = 0;
            mxlen = -1e9;
        }
    };
 
    int last, sz;
    vector<node> v;
 
    SA() {
        v = vector<node>(1);
        last = 0, sz = 1;
        v[0].mxlen = 0;
    }
 
    void add_letter(int c, int val, bool bad = 0) {
        int p = last;
        last = sz++;
        v.push_back({});
        v[last].len = v[p].len + 1;
        v[last].co = val;
        v[last].co2 = 1;
        v[last].bad = bad;
        for (; v[p].to[c] == 0; p = v[p].link)
            v[p].to[c] = last;
        if (v[p].to[c] == last) {
            v[last].link = 0;
            return;
        }
        int q = v[p].to[c];
        if (v[q].len == v[p].len + 1) {
            v[last].link = q;
            return;
        }
        int cl = sz++;
        v.push_back(v[q]);
        v.back().co = 0;
        v.back().co2 = 0;
        v.back().len = v[p].len + 1;
        v[last].link = v[q].link = cl;
 
        for (; v[p].to[c] == q; p = v[p].link)
            v[p].to[c] = cl;
    }
 
    void build_co() {
        priority_queue<pair<int, int>> q;
        for (int i = sz - 1; i > 0; i--)
            q.push({v[i].len, i});
        while (q.size()) {
            int i = q.top().second;
            q.pop();
            v[v[i].link].co += v[i].co;
            v[v[i].link].co2 += v[i].co2;
        }
    }
};
 
