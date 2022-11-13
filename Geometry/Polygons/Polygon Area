ld polygonArea(vector<point> &p){ /// polygon has to be in ccw or cw
    int n = p.size();
    p.push_back(p[0]);
    ld ret = 0;

    for(int i = 0; i < n; i++)
        ret += cross(p[i], p[i + 1]);

    p.pop_back();

    return fabs(ret / 2.0);
}
