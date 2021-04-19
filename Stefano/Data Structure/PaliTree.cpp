struct palindrom_tree {
    int N;
    int idx;
    int last;
    int a[maxn];
    int len[maxn];
    int num[maxn];
    int fali[maxn];
    int son[maxn][26];

    int new_node(int X) {
        memset(son[idx], 0, sizeof(son[idx]));
        len[idx] = X;
        num[idx] = 0;
        return idx++;
    }

    void init() {
        idx = 0;
        new_node(0);
        new_node(-1);
        last = 0;
        N = 0;
        a[N] = -1;
        fali[0] = 1;
    }

    int get_fali(int X) {
        while(a[N - len[X] - 1] != a[N])X = fali[X];
        return X;
    }

    void add(int X) {
        X -= 'a';
        a[++N] = X;

        int cur = get_fali(last);
        if(!son[cur][X]) {
            int nw = new_node(len[cur] + 2);
            fali[nw] = son[get_fali(fali[cur])][X];
            son[cur][X] = nw;
            num[nw] = num[fali[nw]] + 1;
        }

        last = son[cur][X];

    }
    
};
