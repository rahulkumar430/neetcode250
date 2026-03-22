#include <bits/stdc++.h>
using namespace std;

// DFS Brute Force Approach - Time Complexity: O(n^2 * logn), Space Complexity: O(n^2)
// class Solution {
//    public:
//     void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
//         visited[node] = true;

//         for (int neigh : graph[node]) {
//             if (!visited[neigh]) {
//                 dfs(neigh, graph, visited);
//             }
//         }
//     }

//     bool canTraverseAllPairs(vector<int>& nums) {
//         int n = nums.size();

//         // Step 1: Build graph
//         vector<vector<int>> graph(n);

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (__gcd(nums[i], nums[j]) > 1) {
//                     graph[i].push_back(j);
//                     graph[j].push_back(i);
//                 }
//             }
//         }

//         // Step 2: DFS
//         vector<bool> visited(n, false);
//         dfs(0, graph, visited);

//         // Step 3: Check if all visited
//         for (int i = 0; i < n; i++) {
//             if (!visited[i])
//                 return false;
//         }

//         return true;
//     }
// };

// DSU Class
class DSU {
   public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;

        parent[px] = py;
    }
};

// Optimised DSU + Factorization Approach - Time Complexity: O(n * √m), Space Complexity: O(n), m = largest number in nums
// class Solution {
//    public:
//     // Get prime factors
//     vector<int> getFactors(int num) {
//         vector<int> factors;

//         for (int i = 2; i * i <= num; i++) {
//             if (num % i == 0) {
//                 factors.push_back(i);
//                 while (num % i == 0)
//                     num /= i;
//             }
//         }

//         if (num > 1)
//             factors.push_back(num);

//         return factors;
//     }

//     bool canTraverseAllPairs(vector<int>& nums) {
//         int n = nums.size();

//         DSU dsu(n);
//         // factorMap: factor -> index
//         unordered_map<int, int> factorMap;

//         for (int i = 0; i < n; i++) {
//             vector<int> factors = getFactors(nums[i]);

//             for (int f : factors) {
//                 if (factorMap.count(f)) {
//                     // Unite with existing factor
//                     dsu.unite(i, factorMap[f]);
//                 } else {
//                     // Update factorMap
//                     factorMap[f] = i;
//                 }
//             }
//         }

//         // Check if all belong to same component
//         int root = dsu.find(0);

//         for (int i = 1; i < n; i++) {
//             // if any element is not connected to root, return false
//             if (dsu.find(i) != root)
//                 return false;
//         }

//         return true;
//     }
// };

// Optimal Sieve of Eratosthenes + DSU Approach (You can also use sieve with dfs and bfs)
// Time Complexity: O(m log log m + n log m), Space Complexity: O(n + m), m = largest number in nums
class Solution {
   public:
    // Step 1: Build SPF (Smallest Prime Factor)
    vector<int> buildSPF(int maxVal) {
        vector<int> spf(maxVal + 1);

        for (int i = 0; i <= maxVal; i++)
            spf[i] = i;

        for (int i = 2; i * i <= maxVal; i++) {
            if (spf[i] == i) {
                // Mark all multiples of i as not prime i.e. spf[j] = i (smallest prime factor)
                // i*i, i*(i+1), i*(i+2), ... or i*(i+k) => for i = 2, it will be 2i, 3i, 4i, ...
                // Why start from i * i? => Because Smaller multiples already handled by smaller primes
                for (int j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        return spf;
    }

    // Step 2: Get unique prime factors using SPF
    vector<int> getFactors(int num, vector<int>& spf) {
        vector<int> factors;

        while (num > 1) {
            int prime = spf[num];
            factors.push_back(prime);

            // remove all occurrences of this prime to extract unique prime factors
            // Ex : 12 => 2, 2, 3, 3 => 2, 3
            // So first prime is 2 and we will kepp on dividing 12 with 2 until it divides with 2 more
            // Which will lead to another prime if any, in this case it will be 3
            // In this way, we will get unique prime factors
            while (num % prime == 0) {
                num /= prime;
            }
        }

        return factors;
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();

        // Edge case: if any number is 1 → impossible
        for (int x : nums) {
            if (x == 1) return false;
        }

        int maxVal = *max_element(nums.begin(), nums.end());

        // Step 3: Build SPF
        vector<int> spf = buildSPF(maxVal);

        DSU dsu(n);
        // factorMap: factor -> index
        unordered_map<int, int> factorMap;

        // Step 4: Connect indices via factors
        for (int i = 0; i < n; i++) {
            vector<int> factors = getFactors(nums[i], spf);

            for (int f : factors) {
                if (factorMap.count(f)) {
                    // Unite with existing factor
                    dsu.unite(i, factorMap[f]);
                } else {
                    // Update factorMap
                    factorMap[f] = i;
                }
            }
        }

        // Step 5: Check connectivity
        int root = dsu.find(0);

        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root)
                return false;
        }

        return true;
    }
};

int main() {
    vector<int> nums = {4, 3, 12};

    Solution sol;
    cout << (sol.canTraverseAllPairs(nums) ? "true" : "false") << endl;

    return 0;
}