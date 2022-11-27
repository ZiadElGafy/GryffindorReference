bool isInsidePolygon(vector<point> &p, point c){ // concave or convex O(n)
    int n = p.size(), wn = 0;

    if(n < 3)
        return 0;

    p.push_back(p[0]);

    for(int i = 0; i < n; i++){
        point cur = p[i], next = p[i + 1];

        if(isPointOnSegment(cur, next, c)) /// point is on polygon edge
            return p.pop_back(), 1;

        if(cur.Y <= c.Y)
            wn += (next.Y > c.Y and cross(vec(cur, next), vec(cur, c)) > eps);
        else
            wn -= (next.Y <= c.Y and cross(vec(cur, next), vec(cur, c)) < -eps);
    }

    p.pop_back();

    return wn;
}
