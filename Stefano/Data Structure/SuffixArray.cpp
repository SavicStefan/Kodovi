vector<int> SuffixArray(string a){
    int N = sz(a); vector<int> sa(N), isa(N);
    iota(all(sa), 0); sort(all(sa), [&](int x, int y){ return a[x] < a[y]; });
    ff(i,1,N - 1){
        int x = sa[i], y = sa[i - 1];
        isa[x] = i > 1 && a[x] == a[y] ? isa[y] : i;
    }
    for(int len = 1; len < N; len *= 2){
        vector<int> s(sa), is(isa), pos(N); iota(all(pos), 0);
        ff(i,0,N - 1){
            int x = s[i] - len;
            if(x >= 0)sa[pos[isa[x]]++] = x;
        }
        ff(i,1,N - 1){
            int x = sa[i], y = sa[i - 1];
            isa[x] = is[x] == is[y] && is[x + len] == is[y + len] ? isa[y] : i;
        }
    }
    return sa;
}

vector<int> LCP(string a, vector<int> sa){
    int N = sz(sa); vector<int> lcp(N), pos(N);
    ff(i,0,N - 1)pos[sa[i]] = i;
    int k = 0;
    ff(i,0,N - 2){
        int pi = pos[i];
        int j = sa[pi - 1];
        while(i + k < N && j + k < N && a[i + k] == a[j + k])k += 1;
        lcp[pi] = k; k = max(k - 1, 0);
    }
    return lcp;
}
