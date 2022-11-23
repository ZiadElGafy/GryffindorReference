void move1step(ll &a, ll &b, ll q){
    ll next = a - q * b;
    a = b;
    b = next;
}

ll eGCD(ll r0, ll r1, ll &x0, ll &y0){
    if(r0 < 0){
        ll ret = eGCD(-r0, r1, x0, y0);
        x0 *= -1;
        return ret;
    }

    if(r1 < 0){
        ll ret = eGCD(r0, -r1, x0, y0);
        y0 *= -1;
        return ret;
    }

    ll q, x1, y1;
    x0 = y1 = 1;
    x1 = y0 = 0;

    while(r1){
        q = r0 / r1;
        move1step(r0, r1, q);
        move1step(x0, x1, q);
        move1step(y0, y1, q);
    }

    return r0;
}

/*
aX + bY = g
aXt + bYt = c = gt

t = c / g
x *= t, y *= t
xUnit = b / g, yUnit = a / g;
*/

// if you want to use with Y pass: (y, x, yUnit, xUnit, bar, orEqual)

void raiseXOverBar(ll &x, ll &y, ll &xUnit, ll &yUnit, ll bar, bool orEqual){
    if(x > bar or (x == bar and orEqual))
        return;

    ll shift = (bar - x + xUnit - orEqual) / xUnit;
    x += shift * xUnit;
    y -= shift * yUnit;
}

void lowerXUnderBar(ll &x, ll &y, ll &xUnit, ll &yUnit, ll bar, bool orEqual){
    if(x < bar or (x == bar and orEqual))
        return;

    ll shift = (x - bar + xUnit - orEqual) / xUnit;
    x -= shift * xUnit;
    y += shift * yUnit;
}

void minXOverBar(ll &x, ll &y, ll &xUnit, ll &yUnit, ll bar, bool orEqual){
    if(x < bar or (x == bar and !orEqual)){
        ll shift = (bar - x + xUnit - orEqual) / xUnit;
        x += shift * xUnit;
        y -= shift * yUnit;
    }
    else{
        ll shift = (x - bar - !orEqual) / xUnit;
        x -= shift * xUnit;
        y += shift * yUnit;
    }
}

void maxXUnderBar(ll &x, ll &y, ll &xUnit, ll &yUnit, ll bar, bool orEqual){
    if(x < bar or (x == bar and orEqual)){
        ll shift = (bar - x - !orEqual) / xUnit;
        x += shift * xUnit;
        y -= shift * yUnit;
    }
    else{
        ll shift = (x - bar + xUnit - orEqual) / xUnit;
        x -= shift * xUnit;
        y += shift * yUnit;
    }
}
