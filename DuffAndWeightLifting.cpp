#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define pb push_back
#define mp make_pair
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a;
    cin >> n;
    bitset<1000001> st;
    while (n--) {
        cin >> a;
        while (st[a]) {
            st[a] = false;
            a++;
        }
        st[a] = true;
    }
    cout << st.count() << endl;
    
    return 0;
}
 