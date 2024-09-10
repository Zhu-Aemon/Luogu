#include<iostream>
#include<algorithm>

using namespace std;

int n,m,map[205][205],f[205][205][205],x,y,v;

void P1004()
{
    cin >> n;
    m = n;
    for (;;) {
        int x, y, v;
        cin >> x >> y >> v;
        if (x == 0 && y == 0 && v == 0) {
            break;
        }
        map[x][y] = v;
    }
    for(int k = 1; k <= m + n; k++)
        for(int i = 1; i <= min(k,n); i++)
            for(int j = 1; j <= min(k,n); j++)
            {
                f[k][i][j] = max({f[k - 1][i][j],f[k - 1][i - 1][j],f[k - 1][i][j - 1],f[k - 1][i - 1][j - 1]}) + map[k - i + 1][i] + map[k - j + 1][j];
                if(i == j) f[k][i][j] -= map[k - i + 1][i];
            }

    f[n + m][n][n] = max({f[n + m - 1][n][n - 1],f[n + m - 1][n - 1][n],f[n + m - 1][n][n],f[n + m - 1][n - 1][n - 1]});
    printf("%d\n",f[n + m][n][n]);
}