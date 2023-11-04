// #include <bits/stdc++.h>
// using namespace std;
// using i64 = int64_t;

// int main() {
//   cin.tie(nullptr)->sync_with_stdio(false);
//   int n, m;
//   cin >> n >> m;
//   vector f(n, vector<vector<int>>(10));
//   for (int i = 0; i < n; i += 1) {
//     string s;
//     cin >> s;
//     for (int j = 0; j < m; j += 1) {
//       if (f[i][s[j] - '0'].size() < n) { f[i][s[j] - '0'].push_back(j); }
//     }
//   }
//   int ans = -1;
//   for (int d = 0; d < 10; d += 1) {
//     bool empty = false;
//     map<int, vector<int>> g;
//     for (int j = 0; j < n; j += 1) {
//       if (f[j][d].empty()) {
//         empty = true;
//         break;
//       }
//       for (int k = 0; k < n; k += 1) {
//         g[f[j][d][k % f[j][d].size()] + k / f[j][d].size() * m].push_back(j);
//       }
//     }
//     int match = 0;
//     vector<int> matched(n, -1);
//     for (auto [x, _] : g) {
//       vector<bool> visited(n);
//       function<bool(int)> dfs = [&](int u) {
//         for (int v : g[u]) {
//           if (not visited[v]) {
//             visited[v] = true;
//             if (matched[v] == -1 or dfs(matched[v])) {
//               matched[v] = u;
//               return true;
//             }
//           }
//         }
//         return false;
//       };
//       match += dfs(x);
//       if (match == n) {
//         if (ans == -1 or x < ans) { ans = x; }
//         break;
//       }
//     }
//   }
//   cout << ans << "\n";
// }