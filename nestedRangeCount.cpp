#include <bits/stdc++.h>
using namespace std;

class seg_tree {
private:
    vector<int> s_tree;
    int n;
    int f(int node, int node_low, int node_high, int q_low, int q_high) {
        if (q_low <= node_low && node_high <= q_high) {
            return s_tree[node];
        }
        if (node_high < q_low || q_high < node_low) {
            return 0;
        }
        int last_in_left = (node_low + node_high) / 2;
        return f(2*node, node_low, last_in_left, q_low, q_high)
             + f(2*node + 1, last_in_left + 1, node_high, q_low, q_high);
    }
    
public:
    seg_tree(int size) {
        n = size;
        while (__builtin_popcount(n) != 1) {
            n++;
        }
        s_tree.resize(2 * n);
    }

    int query(int low, int high) {
        return f(1, 0, n - 1, low, high);
    }

    void update(int i, int v) {
        s_tree[n + i] += v;
        for (int j = (n + i)/2; j >= 1; j /= 2) {
            s_tree[j] = s_tree[2 * j] + s_tree[2 * j + 1];
        }
        return;
    }
};

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> ranges (n);
    vector<int> ans1 (n);
    vector<int> ans2 (n);
    vector<int> bounds;
    unordered_map<int, int> compress;
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].first.first >> ranges[i].first.second;
        bounds.push_back(ranges[i].first.first);
        bounds.push_back(ranges[i].first.second);
        ranges[i].second = i;
    }
    sort(bounds.begin(), bounds.end());

    int N = 1;
    for (int &bound: bounds) {
        if (compress[bound] == 0) {
            compress[bound] = N++;
        }
    }
    sort(ranges.begin(), ranges.end(), [] (auto &a, auto &b) {
        if (a.first.first == b.first.first) return a.first.second > b.first.second;
        return a.first.first < b.first.first;
    });
    seg_tree tree =seg_tree(N);
    for (auto &range: ranges) {
        // is there something that covers me
        ans2[range.second] = tree.query(compress[range.first.second], N);
        tree.update(compress[range.first.second], 1);
    }

    sort(ranges.begin(), ranges.end(), [] (auto &a, auto &b) {
        if (a.first.second == b.first.second) return a.first.first > b.first.first;
        return a.first.second < b.first.second;
    });
    seg_tree ntree = seg_tree(N);
    for (auto &range: ranges) {
        ans1[range.second] = ntree.query(compress[range.first.first], compress[range.first.second]);
        ntree.update(compress[range.first.first], 1);
    }
    for (int &i: ans1) {
        cout << i << ' ';
    }
    cout << '\n';
    for (int &i: ans2) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}