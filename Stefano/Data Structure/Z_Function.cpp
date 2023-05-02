vector<int> z_function(const string& a) {
    int N = sz(a); vector<int> z(N); int L = 0, R = 0;
    for (int i = 1; i < N; ++i) {
        int j = (i >= R ? 0 : min(z[i - L], R - i));
        while (i + j < N && a[i + j] == a[j])j += 1;
        z[i] = j;
        if (i + j > R) {
            L = i;
            R = i + j;
        }
    }
    return z;
}
