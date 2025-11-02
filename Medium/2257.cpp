class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Marcar guardas e paredes
        for (auto &g : guards) {
            grid[g[0]][g[1]] = 2; // guarda
        }

        for (auto &w : walls) {
            grid[w[0]][w[1]] = 1; // parede
        }
        
        // Direções: cima, direita, baixo, esquerda
        vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        
        // Para cada guarda, espalhar visão
        for (auto &g : guards) {
            int x = g[0], y = g[1];

            for (auto &d : dirs) {
                int i = x + d.first;
                int j = y + d.second;
                
                while (i >= 0 && i < m && j >= 0 && j < n) {
                    if (grid[i][j] == 1 || grid[i][j] == 2) {
                        break; // parede ou guarda bloqueia
                    }

                    if (grid[i][j] == 0) { 
                        grid[i][j] = 3; // marca como vigiada
                    }

                    i += d.first;
                    j += d.second;
                }
            }
        }

        // Contar células desocupadas (0) não vigiadas
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) count++;
            }
        }

        return count;
    }

};
