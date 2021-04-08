typedef long double ldb;
struct line {
	ll px, py;
};

// za min
struct CHT {
	vector<line> hull;

	ldb cross(line x, line y) {
		return ((ldb)(x.py - y.py) / (y.px - x.px));
	}

	// < - opadajuce, > - rastuce
	void add_line(ll x, ll y) {
		while(sz(hull) >= 2 && cross(hull.back(), {x, y}) < cross(hull[sz(hull) - 2], hull.back())) {
			hull.pop_back();
		}
		hull.pb({x, y});
	}

	ll kwe(ll x) {

		auto f = [&] (int id) {
			return hull[id].px * x + hull[id].py;
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
