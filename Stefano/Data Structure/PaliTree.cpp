struct palindrom_tree {
    int N;
    int idx;
    int last;
    int a[maxn];
    int len[maxn];
    int num[maxn];
    int fail[maxn];
    int son[maxn][26];
    int anc[maxn][26];

    int new_node(int X) {
        memset(son[idx], 0, sizeof(son[idx]));
        len[idx] = X;
        num[idx] = 0;
        return idx++;
    }

    void init() {
        N = 0;
        last = 0;
        idx = 0;
        new_node(0);
        new_node(-1);
        a[N] = -1;
        fail[0] = 1;
    }

    int get_fail(int X) {
        while(a[N - len[X] - 1] != a[N])X = fail[X];
        return X;
    }

    void add(int X) {
        X -= 'a';
        a[++N] = X;

        int cur = get_fail(last);
        if(!son[cur][X]) {
            int nw = new_node(len[cur] + 2);
            fail[nw] = son[get_fail(fail[cur])][X];
            num[nw] = num[fail[nw]] + 1;
            son[cur][X] = nw;
        }

        last = son[cur][X];
    }

    void init_anc() {
        ff(i,0,idx - 1)anc[i][0] = fail[i];
        ff(j,1,25) {
            ff(i,0,idx - 1)anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }

    int get(int v, int w) {
        if(len[v] <= w)return len[v];
        fb(i,25,0) {
            if(len[anc[v][i]] > w) {
                v = anc[v][i];
            }
        }
        return max(0, len[fail[v]]);
    }

} P;
