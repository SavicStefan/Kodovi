int pref[maxn];
int sufi[maxn];
void divi(int l, int r, vector<array<int,3>> upit) {
    if(!sz(upit) || l > r)return;

    if(l == r) {
        for(auto c : upit)res[c[2]] = niz[l];
        return;
    }

    int mid = (l + r) / 2;
    sufi[mid] = niz[mid];
    fb(i,mid - 1, l)sufi[i] = cmb(sufi[i + 1], niz[i]);

    pref[mid + 1] = niz[mid + 1];
    ff(i,mid + 2, r)pref[i] = cmb(pref[i - 1], niz[i]);

    vector<array<int,3>> todo[2];
    for(auto c : upit) {
        int L = c[0];
        int R = c[1];
        int id = c[2];

        if(L <= mid && mid < R)res[id] = cmb(sufi[L], pref[R]);
        else todo[L > mid].pb(c);

    }

    divi(l, mid, todo[0]);
    divi(mid + 1, r, todo[1]);

}
