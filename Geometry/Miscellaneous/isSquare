bool isSquare(vector<point> &v){
    vector<ld> distances;

    for(int j = 1; j < 4; j++)
        distances.push_back(abs(vec(v[0], v[j])));

    sort(distances.begin(), distances.end());
    ld side = distances[0], diagonal = distances[2];

    if(abs(distances[1] - distances[0]) > eps)
        return 0;

    bool fail = 0;

    for(int i = 0; i < 4; i++){
        int s = 2, d = 1;

        for(int j = 0; j < 4; j++){
            if(i == j)
                continue;

            ld dist = abs(vec(v[i], v[j]));

            if(abs(dist - side) < eps)
                s--;
            else if(abs(dist - diagonal) < eps)
                d--;
        }

        fail |= (s or d);
    }

    return !fail;
}
