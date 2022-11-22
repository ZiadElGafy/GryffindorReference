struct sparse{ // 1-based
    int table[N][LOG], logTwo[N];
    
    int merge(int u, int v){
        return min(u, v);
    }
    
    void build(){
        logTwo[1] = 0;
        for(int i = 2; i <= n; i++)
            logTwo[i] = logTwo[i >> 1] + 1;
        
        for(int i = 1; i <= n; i++)
            table[i][0] = a[i];
        
        for(int j = 1; j < LOG; j++)
            for(int i = 1; i + (1 << j) - 1 <= n; i++)
                table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }
    
    int query(int l, int r){
        int len = r - l + 1;
        int power = logTwo[len];
        
        return merge(table[l][power], table[r - (1 << power) + 1][power]);
    }
}st;
