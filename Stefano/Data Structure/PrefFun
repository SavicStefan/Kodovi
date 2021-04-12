vector<int> prefix_function(string a) {
	int N = sz(a);
	vector<int> pi(N);
	pi[0] = 0;
	ff(i,1,N - 1) {
		int j = pi[i - 1];
		while(j > 0 && a[i] != a[j])j = pi[j - 1];
		if(a[i] == a[j])j += 1;
		pi[i] = j;
	}
	return pi;
}
