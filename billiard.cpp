#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define pb push_back
#define mp make_pair

template<typename T>
T extgcd(T a, T b, T &x, T &y)
{
    if (a == 0) return x = 0, y = 1, b;
    T p = b / a;
    T g = extgcd(b - p * a, a, y, x);
    x -= p * y;
    return g;
}


template<typename T>
bool find_any_solution(T a, T b, T c, T &x, T &y, T &g)
{
    if (a == 0 && b == 0) /// 0x + 0y = c
    {
        if (c != 0) return false;
        x = y = g = 0;
        return true;
    }

    if (a == 0) /// 0x + by = c
    {
        if (c % b != 0) return false;
        x = 0, y = c / b, g = abs(b);
        return true;
    }

    if (b == 0) /// ax + 0y = c
    {
        if (c % a != 0) return false;
        x = c / a, y = 0, g = abs(a);
        return true;
    }

    /// ax + by = c
    g = extgcd(abs(a), abs(b), x, y);
    if (c % g != 0) return false;

    x *= (a < 0 ? -1 : +1) * c / g;
    y *= (b < 0 ? -1 : +1) * c / g;
    return true;
}

/// Find the next/prev (cnt)-th solution of ax + by = c
template<typename T>
void shift_solution(T & x, T & y, T a, T b, T cnt)
{
    x += cnt * b;
    y -= cnt * a;
}


int main() {
    ll n, m, x, y, vx, vy;
    cin >> m >> n >> x >> y >> vx >> vy;
    // the ball is either moving parallel to the axis or it is moving 45 deg
    // moving horizontal
    if (vx == 0 && vy == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (vy == 0) {
        // the only possible holes are (0/n, y);
        if (y != 0 && y != n) {
            cout << -1 << endl;
            return 0;
        }
        if (vx < 0) {
            cout << 0 << " " << y << endl;
        } else {
            cout << m << " " << y << endl;
        }
        return 0;
    }
    if (vx == 0) {
        if (x != 0 && x != m) {
            cout << - 1 << endl;
            return 0;
        }
        if (vy < 0) {
            cout << x << " " << 0 << endl;
        } else {
            cout << x << " " << n << endl;
        }
        return 0;
    }

    ll a, b, X, Y, g;
    a = x;
    b = y;
    if (vx == 1) {
        a = m - x;
    }
    if (vy == 1) {
        b = n - y;
    }
    ll c = b - a;
    if (find_any_solution(m, n, c, X, Y, g)) {
        if(X<0){
			ll k=(-X-1)/(n/g)+1;
			X=X+k*(n/g);
			Y=Y-k*(m/g);
		}
		else{
			long long k=X/(n/g);
			X=X-k*(n/g);
			Y=Y+k*(m/g);
		}
        Y=-Y;
        cout << ((X%2)^(vx==1))*m << " " << ((Y%2)^(vy==1))*n << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}