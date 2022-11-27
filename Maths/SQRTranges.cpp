int cur = 1;
    while(cur<=x){
        int r = x / (x / cur);
        cout << cur << ' ' << r << endl;
        cur = r + 1;
    }
