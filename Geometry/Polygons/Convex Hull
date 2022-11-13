point cntr;

bool sortCCW(point a, point b){
    a = a - cntr;
    b = b - cntr;
    if(dcmp(cross(a, b), 0) == 0){
        if(dcmp(a.Y, b.Y) != 0){
            return a.Y < b.Y;
        }
        return a.X < b.X;
    }
    return cross(a, b) >= eps;
}

bool cmp(point a, point b){
    if(dcmp(a.X, b.X) != 0)
        return a.X < b.X;
    return a.Y < b.Y;
}

vector<point> convexHull(vector<point> points){
    sort(points.begin(), points.end(), cmp);

    /// remove duplicate points
    vector<point> p;
    p.push_back(points[0]);

    for(int i = 1; i < (int) points.size(); i++){
        if(same(points[i], points[i - 1]))
            continue;

        p.push_back(points[i]);
    }

    if(p.size() <= 1)
        return p;

    for(int i = 1; i < (int) p.size(); i++){
        if(p[i].Y < p[0].Y)
            swap(p[i], p[0]);
        else if(dcmp(p[i].Y, p[0].Y) == 0 and p[i].X < p[0].X)
            swap(p[i], p[0]);
    }

    cntr = p[0];
    sort(p.begin() + 1, p.end(), sortCCW);
    vector<point> ch;
    p.push_back(p[0]);

    for(int i = 0; i < p.size(); i++){
        while(ch.size() > 1){
            auto cur = ch.back(), prv = ch[ch.size() - 2];

            if(cross(prv - cur, p[i] - cur) <= 0)
                break;

            ch.pop_back();
        }
        ch.push_back(p[i]);
    }
    ch.pop_back();

    /// ch is convex hull with collinear points
    /// removing collinear points

    vector<point> finalCH = {ch[0]};

    for(int i = 1; i + 1 < ch.size(); i++)
        if(!areCollinear(ch[i - 1], ch[i], ch[i + 1]))
            finalCH.push_back(ch[i]);

    finalCH.push_back(ch.back());
    return finalCH;
}
