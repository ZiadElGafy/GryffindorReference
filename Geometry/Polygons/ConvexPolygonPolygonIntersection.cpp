vector<point> convexPolygonPolygonIntersection(vector<point>& p, vector<point>& q){ // both CCW
    vector<point> ret = q;
    for (int i = 0; i < p.size(); i++) {
        int j = (i + 1) % p.size();
        vector<point> temp = polygonCut(ret, p[i], p[j]);
        ret = temp;
        if(ret.empty())
            return {};
    }
    return ret;
}
