#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
 
const int N = 1000 + 5;
const ll inf = 1e18;
 
ll dp[N][N];
int a[N], best[N][N];
 
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    while(cin >> n){
        cin >> m;
        for(int i = 1; i <= m; i++) cin >> a[i];
        a[m + 1] = n;
        for(int i = 1; i <= m; i++) {
            dp[i][i] = a[i + 1] - a[i - 1];
            best[i][i] = i;
        }
        for(int len = 2; len <= m; len++){
            for(int l = 1, r = len; r <= m; l++, r++){
                dp[l][r] = inf;
                for(int i = best[l][r - 1]; i <= best[l + 1][r]; i++){
                    if(dp[l][r] >= dp[l][i - 1] + dp[i + 1][r] + a[r + 1] - a[l - 1]){
                        dp[l][r] = dp[l][i - 1] + dp[i + 1][r] + a[r + 1] - a[l - 1];
                        best[l][r] = i;
                    }
                }
            }
        }
        cout << dp[1][m] << '\n';
    }
 
    return 0;
}
