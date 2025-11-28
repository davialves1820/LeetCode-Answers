class Solution {
public:

    int n, k;
    vector<vector<int>> g;
    vector<int> values;
    int components = 0;

    int dfs(int u, int parent) {
        int rem = ((values[u] % k) + k) % k; // Resto positivo

        for (int v : g[u]) {
            if (v == parent) continue;
            int child_rem = dfs(v, u);
            if (child_rem == 0) {
                // O subtree do filho é divisível por k -> podemos cortar aqui
                components++;
            } else {
                rem = (rem + child_rem) % k;
            }
        }
        return rem;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->n = n;
        this->k = k;
        this->values = values;
        components = 0;
        g.assign(n, {});

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        // Rodar DFS uma vez a partir da raiz (0 é OK porque é uma árvore conexa)
        int total_rem = dfs(0, -1);

        // Se a soma total for divisível por k, a raiz forma um componente válido
        if (total_rem == 0){ 
            components++;
    	}

        return components;
    }
};
