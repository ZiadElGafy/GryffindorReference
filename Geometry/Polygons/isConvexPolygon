bool isConvexPolygon(vector<point> &p){
    int n = p.size();

    p.push_back(p[0]);
    p.push_back(p[1]);

    bool pos = 0, neg = 0;

    for(int i = 0; i < n; i++){
        ld crossProduct = cross((p[i + 1] - p[i]), (p[i + 2] - p[i]));

        pos |= (crossProduct > eps);
        neg |= (crossProduct < -eps);
    }

    p.pop_back();
    p.pop_back();

    return !(pos and neg);  /// duplicate points will fail this function
}
