point polygonCentroid(vector<point> &p){
    int n = p.size();
    p.push_back(p[0]);
    ld x = 0, y = 0, signedArea = 0;

    for(int i = 0; i < n; i++){
        ld crossProduct = cross(p[i], p[i + 1]);
        signedArea += crossProduct;
        x += (p[i].X + p[i + 1].X) * crossProduct;
        y += (p[i].Y + p[i + 1].Y) * crossProduct;
    }

    p.pop_back();

    if(dcmp(signedArea, 0) == 0) // it's a line not a polygon
        return (p[0] + p.back()) * (ld)0.5;

    signedArea /= 2;
    x /= 6 * signedArea;
    y /= 6 * signedArea;

    if(dcmp(x, 0) == 0)
        x = 0;
    if(dcmp(y, 0) == 0)
        y = 0;

    return point(x, y);
}
