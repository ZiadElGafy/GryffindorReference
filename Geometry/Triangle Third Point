/*
        C
        .
       / \
      /   \
     /     \
    /       \
   /         \
A .___________. B

*/

// Given A, B, AC, AB
int triangleThirdPoint(point a, point b, ld ac, ld bc, point &c1, point &c2){
    ld ab = abs(vec(a, b));
    if(ab - (ac + bc) > eps)
        return 0;

    if(fabs(ab - (ac + bc)) < eps)
        return c1 = a + vec(a, b) * (ac / ab), 1;

    ld s = 0, e = 1000, m1, m2;
    point base = a + normalize(vec(a, b)) * ac, mid1, mid2;
    for(int i = 0; i < 200; i++){
        m1 = s + (e - s) / 3;
        m2 = e - (e - s) / 3;

        mid1 = base.rotateAround(a, (m1 / 1001) * pi / 2);
        mid2 = base.rotateAround(a, (m2 / 1001) * pi / 2);

        if(fabs(bc - dist(mid1, b)) < fabs(bc - dist(mid2, b)))
            e = m2;
        else
            s = m1;
    }

    base = base.rotateAround(a, (s / 1001) * pi / 2);
    c1 = base;
    c2 = reflectAroundLine(a, b, c1);
    return 2;
}

// Given A, B, ang(BAC), ang(ABC)
int triangleThirdPoint(point a, point b, ld bac, ld abc, point &c1, point &c2){
    if(bac < eps or pi / 2 - bac < eps)
        return 0;
    if(abc < eps or pi / 2 - abc < eps)
        return 0;

    point bRotated = b.rotateAround(a, bac);
    point aRotated = a.rotateAround(b, 2 * pi - abc);

    // treat as ray ray intersection
    return assert(intersectSegments(a, bRotated, b, aRotated, c1)), 1;
}
