#include <bits/stdc++.h>
using namespace std;

static const int INF = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        auto idx = [&](char c) { return c - 'a'; };

        static set<int> op_set[3][3];
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                op_set[x][y].clear();
            }
        }

        for (int i = 1; i <= q; i++) {
            char cx, cy;
            cin >> cx >> cy;
            int x = idx(cx), y = idx(cy);
            if (x != y) {
                op_set[x][y].insert(i);
            }
        }

        string ans = s;

        for (int i = n - 1; i >= 0; i--) {
            int c0 = idx(s[i]);
            int bestTar = c0;

            vector<pair<int,int>> usedOps;

            int useA_one = -1;
            int useA_chain_t1 = -1;
            int useA_chain_t2 = -1;
            int bestA_time = -1;

            if (c0 == 0) {
                bestA_time = 0;
            } else {
                if (!op_set[c0][0].empty()) {
                    auto it = prev(op_set[c0][0].end());
                    useA_one = *it;
                    bestA_time = max(bestA_time, useA_one);
                }
                int midA = 3 - c0 - 0; 
                if (!op_set[midA][0].empty() && !op_set[c0][midA].empty()) {
                    auto it2 = prev(op_set[midA][0].end());
                    int candidate_t2 = *it2;
                    auto it1 = op_set[c0][midA].lower_bound(candidate_t2);
                    if (it1 != op_set[c0][midA].begin()) {
                        --it1;
                        int candidate_t1 = *it1;
                        int chain_time = max(candidate_t1, candidate_t2);
                        if (chain_time > bestA_time) {
                            bestA_time = chain_time;
                            useA_chain_t1 = candidate_t1;
                            useA_chain_t2 = candidate_t2;
                            useA_one = -1;
                        }
                    }
                }
            }

            if (bestA_time >= 0) {
                if (bestA_time == 0) {
                    bestTar = 0;
                } else {
                    if (useA_one != -1 && useA_one == bestA_time) {
                        bestTar = 0;
                        usedOps.emplace_back(c0, 0);
                    } else {
                        bestTar = 0;
                        int midA = 3 - c0 - 0;
                        usedOps.emplace_back(c0, midA);
                        usedOps.emplace_back(midA, 0);
                    }
                }
            }
            else {
                int useB_one = -1;
                int useB_chain_t1 = -1;
                int useB_chain_t2 = -1;
                int bestB_time = -1;

                if (c0 == 1) {
                    bestB_time = 0;
                } else {
                    if (!op_set[c0][1].empty()) {
                        auto it = prev(op_set[c0][1].end());
                        useB_one = *it;
                        bestB_time = max(bestB_time, useB_one);
                    }
                    int midB = 3 - c0 - 1;
                    if (!op_set[midB][1].empty() && !op_set[c0][midB].empty()) {
                        auto it2 = prev(op_set[midB][1].end());
                        int candidate_t2 = *it2;
                        auto it1 = op_set[c0][midB].lower_bound(candidate_t2);
                        if (it1 != op_set[c0][midB].begin()) {
                            --it1;
                            int candidate_t1 = *it1;
                            int chain_time = max(candidate_t1, candidate_t2);
                            if (chain_time > bestB_time) {
                                bestB_time = chain_time;
                                useB_chain_t1 = candidate_t1;
                                useB_chain_t2 = candidate_t2;
                                useB_one = -1;
                            }
                        }
                    }
                }

                if (bestB_time >= 0) {
                    if (bestB_time == 0) {
                        bestTar = 1;
                    } else {
                        if (useB_one != -1 && useB_one == bestB_time) {
                            bestTar = 1;
                            usedOps.emplace_back(c0, 1);
                        } else {
                            bestTar = 1;
                            int midB = 3 - c0 - 1;
                            usedOps.emplace_back(c0, midB);
                            usedOps.emplace_back(midB, 1);
                        }
                    }
                } else {
                    bestTar = c0;
                }
            }

            for (auto &pr : usedOps) {
                int x = pr.first, y = pr.second;
                auto it_del = prev(op_set[x][y].end());
                op_set[x][y].erase(it_del);
            }

            ans[i] = char('a' + bestTar);
        }

        reverse(ans.begin(), ans.end());

        cout << ans << "\n";
    }
    return 0;
}
