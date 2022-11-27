// UNTESTED
bool isSimplePolygon(vector<point> &p){ /// Edges don't intersect
    int n = p.size();
    p.push_back(p[0]);
    point intersect;

    for(int i = 0; i < n; i++)
        for(int j = i + 2; j < n; j++)                 /// last and first edge are consecutive
            if(intersectSegments(p[i], p[i + 1], p[j], p[j + 1], intersect) and (i > 0 or j != n - 1))
                return p.pop_back(), 0;

    return p.pop_back(), 1;
}
