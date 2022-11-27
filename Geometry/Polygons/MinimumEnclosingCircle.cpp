// equation of circle: (x - h)^2 + (y - k)^2 = r^2
struct circle{
    ld h, k, r;

    circle() {}
    circle(ld h, ld k, ld r) : h(h), k(k), r(fabs(r)) {}

    // Circle with the line segment ab as a diameter.
    circle(const point &a, const point &b) {
        h = (a.X + b.X) / 2.0;
        k = (a.Y + b.Y) / 2.0;
        r = abs(point(a.X - h, a.Y - k));
    }

    // Circumcircle of three points.
    circle(const point &a, const point &b, const point &c) {
        ld an = abs2(point(b.X - c.X, b.Y - c.Y));
        ld bn = abs2(point(a.X - c.X, a.Y - c.Y));
        ld cn = abs2(point(a.X - b.X, a.Y - b.Y));
        ld wa = an * (bn + cn - an);
        ld wb = bn * (an + cn - bn);
        ld wc = cn * (an + bn - cn);
        ld w = wa + wb + wc;

        if(fabs(w) < eps)
            throw std::runtime_error("No circumcircle from collinear points.");

        h = (wa*a.X + wb*b.X + wc*c.X)/w;
        k = (wa*a.Y + wb*b.Y + wc*c.Y)/w;
        r = abs(point(a.X - h, a.Y - k));
    }

    bool contains(const point &p) const {
        return r * r - abs2(point(p.X - h, p.Y - k)) > -eps;
    }
};

circle minimumEnclosingCircle(vector<point> v){ // send by reference if you don't care if shuffled
    if (v.empty())
        return circle(0, 0, 0);

    if (v.size() == 1)
        return circle(v.back().X, v.back().Y, 0);

    std::random_shuffle(v.begin(), v.end());
    circle res(v[0], v[1]);

    for (vector<point>::iterator i = v.begin() + 2; i != v.end(); i++){
        if(res.contains(*i))
            continue;

        res = circle(v[0], *i);
        for (vector<point>::iterator j = v.begin() + 1; j != i; j++){
            if(res.contains(*j))
                continue;

            res = circle(*i, *j);

            for(vector<point>::iterator k = v.begin(); k != j; k++)
                if(!res.contains(*k))
                    res = circle(*i, *j, *k);
        }
    }

    return res;
}
