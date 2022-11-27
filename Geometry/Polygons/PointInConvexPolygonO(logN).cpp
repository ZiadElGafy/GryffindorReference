const int PolygonCnt = 1 + 3;

bool lexComp(const point &a, const point &b){
    return a.X < b.X or (dcmp(a.X, b.X) == 0 and a.Y < b.Y);
}

int sign(ld val){
    return (val > eps ? 1 : (val < -eps ? -1 : 0));
}

bool pointInTriangle(point a, point b, point c, point pt){
    ld s1 = abs(cross(vec(a, b), vec(a, c)));
    ld s2 = abs(cross(vec(pt, a), vec(pt, b))) + abs(cross(vec(pt, b), vec(pt, c))) + abs(cross(vec(pt, c), vec(pt, a)));
    return dcmp(s1, s2) == 0;
}

bool isPointOnSegment(point a, point b, point c){
    ld acb = abs(a - b), ac = abs(a - c), cb = abs(b - c);
    return dcmp(acb - (ac + cb), 0) == 0;
}

vector<point> seq[PolygonCnt];
point translation[PolygonCnt], polygonStart[PolygonCnt], polygonEnd[PolygonCnt];
int num[PolygonCnt];

/// todo: call pre
/// give polygon to answer queries on
void pre(vector<point> &points, int idx){
    num[idx] = points.size();
    int pos = 0;

    for(int i = 1; i < num[idx]; i++)
        if(lexComp(points[i], points[pos]))
            pos = i;

    rotate(points.begin(), points.begin() + pos, points.end());
    num[idx]--;
    seq[idx].resize(num[idx]);

    for (int i = 0; i < num[idx]; i++)
        seq[idx][i] = points[i + 1] - points[0];

    translation[idx] = points[0];

    polygonStart[idx] = points[0];
    polygonEnd[idx] = points.back();
}

bool pointInConvexPolygon(point pt, int idx){ // inside or on
    if(seq[idx].size() == 1)
        return isPointOnSegment(polygonStart[idx], polygonEnd[idx], pt);

    pt = pt - translation[idx];

    if(dcmp(cross(seq[idx][0], pt), 1) != 0 and
       sign(cross(seq[idx][0], pt)) != sign(cross(seq[idx][0], seq[idx][num[idx] - 1])))
        return 0;

    if(dcmp(cross(seq[idx][num[idx] - 1], pt), 0) != 0 and
       sign(cross(seq[idx][num[idx] - 1], pt)) != sign(cross(seq[idx][num[idx] - 1], seq[idx][0])))
        return 0;

    if(dcmp(cross(seq[idx][0], pt), 0) == 0)
        return dcmp(dot(seq[idx][0], seq[idx][0]), dot(pt, pt)) != -1;

    int l = 0, r = num[idx] - 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        int pos = mid;

        if(dcmp(cross(seq[idx][pos], pt), 0) != -1)
            l = mid;
        else
            r = mid;
    }

    int pos = l;
    return pointInTriangle(seq[idx][pos], seq[idx][pos + 1], point(0, 0), pt);
}

bool pointOnPolygon(vector<point> &p, point pt){
    int sz = p.size(), s, e, before = -1, after = -1, m;

    s = 1, e = sz - 1;
    while(s <= e){
        m = (s + e) >> 1;

        if(cross(vec(p[0], p[m]), vec(p[0], pt)) >= 0)
            before = m, s = m + 1;
        else
            e = m - 1;
    }

    s = 1, e = sz - 1;
    while(s <= e){
        m = (s + e) >> 1;

        if(cross(vec(p[0], pt), vec(p[0], p[m])) >= 0)
            after = m, e = m - 1;
        else
            s = m + 1;
    }

    if(before == -1 or after == -1)
        return 0;

    if(before == after){
        if(before == 1 or before == sz -1)
            return isPointOnSegment(p[0], p[before], pt);
        else
            return abs(p[before] - pt) < eps;
    }

    return isPointOnSegment(p[before], p[after], pt);
}
