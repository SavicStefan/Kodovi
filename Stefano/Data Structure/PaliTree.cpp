struct palindrome_tree {
	int N; // trenutna duzina stringa
	int idx; // trenutni broj noda
	int last; // poslednji broj noda
	int son[maxn][26]; // insertinion link
	int fail[maxn]; // suffix link
	int len[maxn]; // duzina palindroma u nodu
	int a[maxn]; // string

	// ovo jos ne znam sta predstavlja ali ima vremena
	int cnt[maxn];
	int num[maxn];
	int anc[maxn][26];

	int newnode(int X) {
		memset(son[idx], 0, sizeof (son[idx]));
		cnt[idx] = 0;
		num[idx] = 0;
		len[idx] = X;
		return idx++;
	}

	void init() {
		idx = 0;
		newnode(0);
		newnode(-1);
		last = 0;
		N = 0;
		a[N] = -1;
		fail[0] = 1;
	}

	int get_fail(int X) {
		while(a[N - len[X] - 1] != a[N]) {
			X = fail[X];
		}
		return X;
	}

	void add(int c) {
		c -= 'a';
		a[++N] = c;

		int cur = get_fail(last); // nadjem onaj najduzi sufiks
		if (!son[cur][c]) { // ako nikad pre nije bio
			int now = newnode(len[cur] + 2); // stavi novi node
			fail[now] = son[get_fail(fail[cur])][c]; // samo idem jos dalje i trazim max palindrom koji je suffix od trenutnog palindroma
			son[cur][c] = now; // stavi link sa tog sufiksa
			num[now] = num[fail[now]] + 1; // gledam na koliko nacina mogu da dobijem novi palindrom
		}

		last = son[cur][c]; // samo stavim koji je zadnji node
		cnt[last]++;
	}

	void count() {
		for (int i = 0; i < idx; ++i) {
			anc[i][0] = fail[i];
		}
		for (int j = 1; j < 26; ++j) {
			for (int i = 0; i < idx; ++i) {
				anc[i][j] = anc[anc[i][j - 1]][j - 1];
			}
		}
	}

	int get(int v, int w) {
		if (len[v] <= w) {
			return len[v];
		}
		for (int i = 26 - 1; ~i; --i) {
			if (len[anc[v][i]] > w) {
				v = anc[v][i];
			}
		}
		return max(len[fail[v]], 0);
	}

	int koliko() {
		int kol = 0;
		ff(i,0,idx)kol += num[i];
		return kol;
	}

} pt;
