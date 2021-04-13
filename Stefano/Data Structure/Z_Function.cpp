vector<int> z_function(string a) {
	int N = sz(a);
	vector<int> z(N);
	int L = 0, R = -1;
	ff(i,0,N - 1) {
		int j = (i > R ? 0 : min(z[i - L], R - i + 1));
		while(i + j < N && a[i + j] == a[j])j += 1;
		z[i] = j--;
		if(i + j > R) {
			R = i + j;
			L = i;
		}
	}
	return z;
}
