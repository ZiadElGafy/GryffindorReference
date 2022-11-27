point cntr;

bool cmp(point a, point b){
    if(a.X != b.X)
        return a.X < b.X;
    return a.Y < b.Y;
}

bool sortCCW(point a, point b){
    a = a - cntr;
    b = b - cntr;
    if(cross(a, b) == 0){
        if(a.Y != b.Y)
            return a.Y < b.Y;

        return a.X < b.X;
    }
    return cross(a, b) > 0;
}

void sortPolygonCCW(vector<point> &p){
    sort(p.begin(), p.end(), cmp);

    for(int i = 1; i < (int) p.size(); i++){
        if(p[i].Y < p[0].Y)
            swap(p[i], p[0]);
        else if(p[i].Y == p[0].Y && p[i].X < p[0].X)
            swap(p[i], p[0]);
    }

    cntr = p[0];
    sort(p.begin() + 1, p.end(), sortCCW);
}
