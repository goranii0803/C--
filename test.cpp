#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int n, m;
int parent[MAXN];
int edge[MAXN][3]; // u, v, w

void init() {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    }

    int ret = 0;
    sort(edge, edge + m, [](const auto& a, const auto& b) {
        return a[2] < b[2];
    });

    for (int i = 0; i < m; i++) {
        if (find(edge[i][0]) != find(edge[i][1])) {
            cout << edge[i][0] << ' ' << edge[i][1] << ' ' << edge[i][2] << endl;
            ret++;
            union_set(edge[i][0], edge[i][1]);
        }
    }

    return 0;
}