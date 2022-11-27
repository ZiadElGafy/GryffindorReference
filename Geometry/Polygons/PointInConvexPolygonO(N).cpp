bool isInsideConvexPolygon(vector<point> &p, point c){
    int n = p.size();
    bool right = 0, left = 0, on = 0;

    for(int i = 0; i < n; i++){
        point side = vec(p[i], p[(i + 1) % n]), line = vec(p[i], c);

        if(cross(side, line) < -eps)
            right = 1;
        else if(cross(side, line) > eps)
            left = 1;
        else
            on = 1;
    }

    return !(right and left);
}
