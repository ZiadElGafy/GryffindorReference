// gets polygon LEFT of line
vector<point> polygonCut(vector<point> &p, point a, point b){
    vector<point> ret;

    for (int i = 0; i < p.size(); i++) {
        int j = (i + 1) % p.size();
        bool in1 = cross(vec(a,b),vec(a,p[i])) > eps;
        bool in2 = cross(vec(a,b),vec(a,p[j])) > eps;

        if(in1)
            ret.push_back(p[i]);

        if(in1 ^ in2) {
            point r;
            intersectSegments(a, b, p[i], p[j], r); // LINE - Segment
            ret.push_back(r);
        }
    }

    return ret;
}
