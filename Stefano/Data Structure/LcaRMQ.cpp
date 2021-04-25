vector<int> euler;

int d[maxn];
int in[maxn];
ll dist[maxn];
void dfs(int v, int p) {
    in[v] = sz(euler);
    euler.pb(v);
    for(auto c : g[v]) {
        int u = c.fi;
        int w = c.se;
        if(u != p) {
            d[u] = d[v] + 1;
            dist[u] = dist[v] + w;
            dfs(u, v);
            euler.pb(v);
        }
    }
}

int cmb(int X, int Y) {
    return (d[X] > d[Y] ? Y : X);
}

int sp[10 * maxn][20];
void init_sp() {
    int N = sz(euler);
    ff(i,0,N - 1)sp[i][0] = euler[i];
    ff(j,1,19) {
        for(int i = 0; i + (1 << j) - 1 < N; i++) {
            sp[i][j] = cmb(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int rmq(int l, int r) {
    int x = 31 - __builtin_clz(r - l + 1);
    return cmb(sp[l][x], sp[r - (1 << x) + 1][x]);
}

int lca(int x, int y) {
    x = in[x], y = in[y];
    if(x > y)swap(x, y);
    return rmq(x, y);
}
