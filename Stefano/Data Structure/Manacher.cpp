void manacher(string a){
	int N = sz(a);
	vector<int> d1(N);
	int L = 0, R = -1;
	ff(i,0,N - 1){
		int j = (i > R ? 1 : min(d1[L + R - i], R - i + 1));
		while(i >= j && i + j < N && a[i - j] == a[i + j])j += 1;
		d1[i] = j--;
		if(i + j > R){
			L = i - j;
			R = i + j;
		}
	}
	
	vector<int> d2(N);
	L = 0, R = -1;
	ff(i,0,N - 1){
		int j = (i > R ? 0 : min(d2[L + R - i + 1], R - i + 1));
		while(i > j && i + j < N && a[i - j - 1] == a[i + j])j += 1;
		d2[i] = j--;
		if(i + j > R){
			L = i - j - 1;
			R = i + j;
		}
	}
	
}
