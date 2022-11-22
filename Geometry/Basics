#define ld long double
#define pi acos(-1)
const ld eps = 1e-8;
//#define point complex<ld>
//#define dot(a, b) ((conj(a) * (b)).real())
//#define cross(a, b) ((conj(a) * (b)).imag())
//#define vec(a, b) (point)(b - a)
//#define same(a, b) (dot(vec(a, b), vec(a, b)) < eps)
//#define X real()
//#define Y imag()

using pType = long double;
struct point{
    pType X, Y;
    ld angle;

    point(){
        X = Y = angle = 0;
    };

    point(pType x, pType y){
        X = x, Y = y;

        if(Y == 0)
            angle = (X < 0 ? pi : 0);
        else if(X == 0)
            angle = (Y < 0 ? 3 * pi / 2 : pi / 2);

        angle = atan2(Y, X);
        if(X > 0 and Y > 0)
            ;
        else if(X < 0 and Y > 0)
            angle = pi - angle;
        else if(X < 0 and Y < 0)
            angle = pi + angle;
        else
            angle = 2 * pi - angle;
    }

    const point operator*(const ld &factor) const{
        return point(X * factor, Y * factor);
    }

    const point operator/(const ld &factor) const {
        assert(fabs(factor) > eps);
        return point(X / factor, Y / factor);
    }

    const point operator-(const point &other) const {
        return point(X - other.X, Y - other.Y);
    }

    const point operator+(const point &other) const {
        return point(X + other.X, Y + other.Y);
    }

    static point pol(ld mag, ld dir){
        return point(mag * cos(dir), mag * sin(dir));
    }

    point rotateAround(point pivot, ld ang){
        point ret(X, Y);
        ld s = sin(ang), c = cos(ang), x, y;
        ret.X -= pivot.X;
        ret.Y -= pivot.Y;
        x = ret.X * c - ret.Y * s + pivot.X;
        y = ret.X * s + ret.Y * c + pivot.Y;
        return point(x, y);
    }

    friend ostream &operator<<(ostream &out, const point &p){
        out << '{' << p.X << ", " << p.Y << '}';
        return out;
    }
};

point vec(point a, point b){
    return b - a;
}

pType cross(point a, point b){
    return a.X * b.Y - a.Y * b.X;
}

pType dot(point a, point b){
    return a.X * b.X + a.Y * b.Y;
}

ld abs(point a){
    return sqrt(a.X * a.X + a.Y * a.Y);
}

pType abs2(point a){
    return a.X * a.X + a.Y * a.Y;
}

ld dist(point a, point b){
    return sqrt(fabs(a.X - b.X) * fabs(a.X - b.X) + fabs(a.Y - b.Y) * fabs(a.Y - b.Y));
}

pType dist2(point a, point b){
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

ld fixAngle(ld a){
    return (a > 1 ? 1 : ((a < -1) ? -1 : a));
}

ld angleO(point a, point O, point b){ /// angle(aOb)
    assert(dist(a, O) > eps and dist(b, O) > eps); // nan
    point v1 = (a - O), v2 = (b - O);
    return acos(fixAngle(dot(v1, v2) / (abs(v1) * abs(v2))));
}

bool same(point a, point b){
    return dot(vec(a, b), vec(a, b)) == 0;
}

point normalize(point a){
    return a / abs(a);
}

// angle between [0, pi]
ld angleBetween(point a, point b){
    return acos(dot(a, b) / (abs(a) * abs(b)));
}

int dcmp(const ld &a, const ld &b){
    if(fabs(a - b) < eps)
        return 0;

    return (a > b ? 1 : -1);
}
