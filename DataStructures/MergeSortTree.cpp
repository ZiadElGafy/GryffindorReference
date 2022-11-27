struct mergeSortTree{
    vector<vector<int>> tree;

    mergeSortTree(int sz){
        tree.assign(4 * sz, {});
    }

    vector<int> merge(vector<int> &u, vector<int> &v){
        vector<int> ret;
        int i = 0, j = 0;

        while(i < u.size() and j < v.size()){
            if(u[i] <= v[j])
                ret.push_back(u[i++]);
            else
                ret.push_back(v[j++]);
        }

        while(i < u.size())
            ret.push_back(u[i++]);

        while(j < v.size())
            ret.push_back(v[j++]);

        return ret;
    }

    void build(int node, int start, int end){
        if(start == end)
            return tree[node] = a[start], void();

        int m = (start + end) >> 1;
        build(2 * node, start, m);
        build(2 * node + 1, m + 1, end);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int left, int right){
        if(start > right or end < left)
            return 0;

        if(left <= start and end <= right){
            return ();
        }

        int m = (start + end) >> 1;
        return query(2 * node, start, m, left, right) + query(2 * node + 1, m + 1, end, left, right);
    }
};
