int idx = 0;
bool kraj[maxn];
int lipa[maxn][26];
void add(string a) {
	int N = sz(a);
	int tr = 0;
	ff(i,0,N - 1) {
		if(!lipa[tr][a[i] - 'a'])lipa[tr][a[i] - 'a'] = ++idx;
		tr = lipa[tr][a[i] - 'a'];
	}
	kraj[tr] = 1;
}

bool kve(string a) {
	int N = sz(a);
	int tr = 0;
	ff(i,0,N - 1) {
		if(!lipa[tr][a[i] - 'a'])return 0;
		tr = lipa[tr][a[i] - 'a'];
	}
	return kraj[tr];
}
