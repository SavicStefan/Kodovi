typedef long double ldb;
struct line {
	ll k, b;
};

struct CHT {
	vector<line> hull;

	ldb cross(line x, line y) {
		return (ldb)(y.b - x.b) / (x.k - y.k);
	}

	void add_line(line x) {
		while(sz(hull) >= 2 && cross(hull.back(), x) < cross(hull[sz(hull) - 2], hull.back())) {
			hull.pop_back();
		}
		hull.pb(x);
	}

	ll get(int x) {

		auto f = [&] (int id) {
			return hull[id].k * x + hull[id].b;
		};

		int l = 0, r = sz(hull) - 1;
		while(l < r) {
			int mid = (l + r) / 2;
			if(f(mid) > f(mid + 1))l = mid + 1;
			else r = mid;
		}
		return f(l);

	}

};
