int numberOfLatticePointsOnSegment(point a, point b){
    int x1 = a.X, y1 = a.Y, x2 = b.X, y2 = b.Y;

    int dx = abs(x1 - x2), dy = abs(y1 - y2);

    if(dx == 0)
        return dy + 1;
    if(dy == 0)
        return dx + 1;

    int g = __gcd(dx, dy);
    int xUnit = dx / g, yUnit = dy / g;

    return min(dx / xUnit, dy / yUnit) + 1;
}

ll numberOfBoundaryPoints(vector<point> &p){
    int n = p.size();
    p.push_back(p[0]);
    ll ret = 0;

    for(int i = 0; i < n; i++){
        if(same(p[i], p[i + 1])) /// duplicate points
            continue;

        ret += numberOfLatticePointsOnSegment(p[i], p[i + 1]) - 1;
    }

    p.pop_back();
    return ret;
}

ll numberOfInternalPoints(vector<point>& p){
    /// internal = (2 * area - boundary + 2) / 2
    ll area = 2LL * polygonArea(p);
    return (area - numberOfBoundaryPoints(p) + 2) / 2;
}
