bool isRectangle(vector<point> &v){
    vector<ld> distances;

    for(int j = 1; j < 4; j++)
        distances.push_back(abs(vec(v[0], v[j])));

    sort(distances.begin(), distances.end());

    ld width = distances[0], length = distances[1], diagonal = distances[2];

    bool fail = 0;

    for(int i = 0; i < 4; i++){
        int w = 1, l = 1, d = 1;

        for(int j = 0; j < 4; j++){
            if(i == j)
                continue;

            ld dist = abs(vec(v[i], v[j]));

            if(abs(dist - width) < eps and w)
                w--;
            else if(abs(dist - length) < eps and l)
                l--;
            else if(abs(dist - diagonal) < eps)
                d--;
        }

        fail |= (w or l or d);
    }

    return !fail;
}
