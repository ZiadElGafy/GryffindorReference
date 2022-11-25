#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
const int N = 1e2+5;

ld eps = 1e-9;
ll n , m , sz , ans;
vector<pair<ll,ll> > v;
ll a[N][N] , D[N][N] , par[N];
ld L[N][N];

ld Det()
{
    ll new_n = n-1; //remove last row and last column
    ld det = 1;
    for (int i=1; i<=new_n; ++i)
    {
        int k = i;
        for (int j=i+1; j<=new_n; ++j)
            if (abs (L[j][i]) > abs (L[k][i]))
                k = j;

        if (abs(L[k][i]) < eps)
        {
            det = 0;
            break;
        }

        swap (L[i], L[k]);
        if (i != k)
            det = -det;
        det *= L[i][i];

        for (int j=i+1; j<=new_n; ++j)
            L[i][j] /= L[i][i];

        for (int j=1; j<=new_n; ++j)
            if (j != i && abs (L[j][i]) > eps)
                for (int k=i+1; k<=new_n; ++k)
                    L[j][k] -= L[i][k] * L[j][i];
    }
    det = round(det);
    return det;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin >> x >> y;
        a[x][y]++ , a[y][x]++; //adj matrix
        D[x][x]++ , D[y][y]++; //degree matrix on diagonals only
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            L[i][j] = D[i][j] - a[i][j];
        }
    }

    cout << abs(Det()) << '\n';

    return 0;
}
