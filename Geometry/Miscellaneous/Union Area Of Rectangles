struct Event{
    int idx, type;
    Event(){}
    Event(int i, int t) : idx(i), type(t) {}
};

const int ENTRY = 0, EXIT = 1;
point rects[N][2];
bool inActiveSet[N];
Event eventsVertical[2 * N], eventsHorizontal[2 * N];

bool cmpX(Event &a, Event &b){
    return rects[a.idx][a.type].X < rects[b.idx][b.type].X;
}

bool cmpY(Event &a, Event &b){
    return rects[a.idx][a.type].Y < rects[b.idx][b.type].Y;
}

ll n, eventsCnt;

ll rectangleUnion(){
    ll area = 0;

    sort(eventsVertical, eventsVertical + eventsCnt, cmpY);
    sort(eventsHorizontal, eventsHorizontal + eventsCnt, cmpX);

    inActiveSet[eventsVertical[0].idx] = 1;

    for(int v = 1; v < eventsCnt; v++){ // vertical sweep: line is vertical
        Event cur = eventsVertical[v], prev = eventsVertical[v - 1];
        int cnt = 0, firstRect, deltaX, deltaY;

        if((deltaX = rects[cur.idx][cur.type].X - rects[prev.idx][prev.type].X) == 0)
            continue;

        for(int h = 0; h < eventsCnt; h++){ // horizontal sweep: line is horizontal
            if(inActiveSet[eventsHorizontal[h].idx]){
                if(eventsHorizontal[h].type == ENTRY){
                    if(cnt++ == 0)
                        firstRect = h;
                }
                else if(--cnt == 0){
                    deltaY = rects[eventsHorizontal[h].idx][EXIT].Y - rects[eventsHorizontal[firstRect].idx][ENTRY].Y;
                    area += deltaX * deltaY;
                }
            }
        }

        inActiveSet[cur.idx] = (cur.type == ENTRY);
    }

    return area;
}

void doWork(){
    cin >> n;

    for(int i = 0, x, y; i < n; i++){ // rect is 2 points : (bottom left, top right)
        cin >> x >> y;
        rects[i][0] = point(x, y);

        cin >> x >> y;
        rects[i][1] = point(x, y);

        eventsVertical[eventsCnt] = Event(i, ENTRY);
        eventsVertical[eventsCnt + 1] = Event(i, EXIT);

        eventsHorizontal[eventsCnt] = Event(i, ENTRY);
        eventsHorizontal[eventsCnt + 1] = Event(i, EXIT);

        eventsCnt += 2;
    }

    cout << rectangleUnion();
}
