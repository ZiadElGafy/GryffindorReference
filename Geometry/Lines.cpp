bool intersectSegments(point a, point b, point c, point d, point &intersect){
    ld d1 = cross(vec(b, a), vec(c, d)), d2 = cross(vec(c, a), vec(c, d)), d3 = cross(vec(b, a), vec(c, a));

    if (fabs(d1) < eps)
        return 0; /// parllel or identical

    ld t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;

    /// segment: [0, 1]
    /// ray: [0, INF]
    /// line: [-INF, INF]

    /// make sure that eps is not too accurate
    if(t1 < -eps or t1 > 1 + eps or t2 < -eps or t2 > 1 + eps)
        return 0;

    return 1;
}

point ProjectPointSegment(point a, point b, point p){
    ld r = dot(p - a, b - a) / dot(b - a, b - a);
    if(r < 0)
        return a;
    if(r > 1)
        return b;
    return a + (b - a) * r ;
}

point ProjectPointLine(point a, point b, point p){
    return a + (b - a) * 1.0 * dot(p - a, b - a) / dot(b - a, b - a);
}

ld distToSegment(point s, point e, point c){
    point v1 = e - s, v2 = c - s;
    ld d1 = dot(v1, v2), d2 = dot(v1, v1);

    if(d1 <= 0)
        return abs(c - s);

    if(d2 <= d1)
        return abs(c - e);

    ld t = d1/d2;
    return abs(c - (s + v1 * t));
}

ld distSegmentSegment(point a, point b, point x, point y){
    ld s = 0, e = 1000, m1, m2;
    point pm1, pm2;
 
    for(int i = 0; i < 200; i++){
        m1 = s + (e - s) / 3;
        m2 = e - (e - s) / 3;
 
        pm1 = a + (b - a) * (m1 / 1000);
        pm2 = a + (b - a) * (m2 / 1000);
 
        if(distToSegment(x, y, pm1) <= distToSegment(x, y, pm2))
            e = m2;
        else
            s = m1;
    }
 
    pm1 = a + (b - a) * (s / 1000);
 
    return distToSegment(x, y, pm1);
}

bool areCollinear(point a, point b, point c){
    return fabs( cross(b-a, c-a) ) < eps;
}

bool isPointOnSegment(point a, point b, point c){
    ld acb = abs(a - b), ac = abs(a - c), cb = abs(b - c);
    return dcmp(acb - (ac + cb), 0) == 0;
}

bool isPointOnRay(point p0, point p1, point p2){
    if(abs(p2-p0) < eps) return true;
    return same( normalize(p1-p0), normalize(p2-p0) );
}

point reflectAroundLine(point a, point b, point p){
    //(proj-p) *2 + p
    return ProjectPointLine(a, b, p) * 2 - p;
}
