#include <iostream>
#include <vector>
void Dfs(std::vector<std::vector<int>>& graph, int n, std::vector<int>& colors) {
    colors[n] = 1;
    for (int i = 0; i < graph[n].size(); ++i) {
        int ch = graph[n][i];
        if (colors[ch] == 0) {
            Dfs(graph, ch, colors);
        }
    }
    colors[n] = 2;
}
int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    std::vector<int> colors(n, 0);
    for (int i = 0; i < m; ++i) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int comp = 0;
    for (int i = 0; i < graph.size(); ++i) {
        if (colors[i] == 0) {
            Dfs(graph, i, colors);
            comp++;
        }
    }
    comp--;
    std::cout << comp;
}
