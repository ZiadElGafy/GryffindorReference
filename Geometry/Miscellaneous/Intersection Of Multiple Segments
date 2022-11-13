int ccw(point a, point b, point c){
    point v1(b - a), v2(c - a);
    ld t = cross(v1, v2);

    if(t > eps)

        return 1;
    if(t < -eps)
        return -1;
    if(v1.X * v2.X < -eps or v1.Y * v2.Y < -eps)
        return -1;
    if(abs(v1) * abs(v1) < abs(v2) * abs(v2) - eps)
        return 1;
    return 0;
}


bool intersect(point p1, point p2, point p3, point p4){
    /// special case handling if a segment is just a point
    bool x = same(p1, p2), y = same(p3, p4);
    if(x and y)
        return same(p1, p3);
    if(x)
        return ccw(p3, p4, p1) == 0;
    if(y)
        return ccw(p1, p2, p3) == 0;

    return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 and
           ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

bool operator <(point &a, point &b) {
    if (dcmp(a.X, b.X) != 0)
        return dcmp(a.X, b.X) < 0;

    return dcmp(a.Y, b.Y) < 0;
}

struct Segment{
    point p, q;
    int idx;

    Segment() {idx = -1;}

    Segment(point a, point b, int i){
        if(b < a)
            swap(a, b);
        p = a, q = b, idx = i;
    }

    ld CY(int x) const {
        if(dcmp(p.X, q.X) == 0)
            return p.Y;

        ld t = 1.0 * (x - p.X) / (q.X - p.X);
        return p.Y + (q.Y - p.Y) * t;
    }

    bool operator<(const Segment &rhs) const {
        if(same(p, rhs.p) and same(q, rhs.q))
            return 0;

        int maxX = max(p.X, rhs.p.X);
        int yc = dcmp(CY(maxX), rhs.CY(maxX));

        if(yc == 0)
            return idx < rhs.idx;

        return yc < 0;
    }
};

/// assigning a value to event types to be able to compare later
int ENTRY = 1, EXIT = -1;
const int MAX_SEGMENTS = 5e4 + 9;
const int MAX_EVENTS = MAX_SEGMENTS * 2;

struct Event{
    point p;
    int type, segmentIdx;

    /// smaller X first. If tied: ENTRY event first. Last on smaller Y
    bool operator<(const Event &rhs) const {
        if (dcmp(p.X, rhs.p.X) != 0)
            return dcmp(p.X, rhs.p.X) < 0;

        if (type != rhs.type)
            return type > rhs.type;

        return dcmp(p.Y, rhs.p.Y) < 0;
    }
};

int n;
Segment segments[MAX_SEGMENTS];
Event events[MAX_EVENTS];
set<Segment> sweepSet;
#define ITER set<Segment>::iterator

bool intersectSeg(ITER seg1Iter, ITER seg2Iter){
    if(seg1Iter == sweepSet.end() or seg2Iter == sweepSet.end())
        return 0;

    return intersect(seg1Iter->p, seg1Iter->q, seg2Iter->p, seg2Iter->q);
}

ITER after(ITER cur){
    return cur == sweepSet.end() ? sweepSet.end() : ++cur;
}

ITER before(ITER cur){
    return cur == sweepSet.begin() ? sweepSet.end() : --cur;
}

void foundIntersection(int i, int j, set<pair<int, int>> &ret){
    if(i > j)
        swap(i, j);

    ret.insert({i + 1, j + 1});
}

/// returns set of pairs on indices (1 based) of lines that intersect
/// To change what it does modify function foundIntersection
set<pair<int, int>> BentleyOttmannLineSweep(){ /// O( (k + n) log n)
    set<pair<int, int>> ret;

    /// prepare events
    for(int i = 0; i < n; i++){
        events[2 * i] = {segments[i].p, ENTRY, i};
        events[2 * i + 1] = {segments[i].q, EXIT, i};
    }

    sort(events, events + 2 * n);

    for(int i = 0; i < 2 * n; i++){
        if(events[i].type == ENTRY){
            auto status = sweepSet.insert(segments[events[i].segmentIdx]);
            ITER cur = status.first, below = before(cur), above = after(cur);

            if(!status.second){ /// This exact same segment appeared before
                /// this considers duplicate segments to intersect
                foundIntersection(cur->idx, events[i].segmentIdx, ret);
            }
            else{
                if(intersectSeg(cur, above))
                    foundIntersection(cur->idx, above->idx, ret);
                if(intersectSeg(cur, below))
                    foundIntersection(cur->idx, below->idx, ret);
            }
        }
        else{
            ITER cur = sweepSet.find(segments[events[i].segmentIdx]);

            if(cur == sweepSet.end())
                continue; // duplicate

            ITER below = before(cur), above = after(cur);

            if(intersectSeg(above, below))
                foundIntersection(above->idx, below->idx, ret);

            sweepSet.erase(cur);
        }
    }

    return ret;
}

void doWork(){
    cin >> n;

    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        point p1 = point(x, y);
        cin >> x >> y;
        point p2 = point(x, y);

        segments[i] = Segment(p1, p2, i);
    }

    set<pair<int, int>> ans = BentleyOttmannLineSweep();
}
