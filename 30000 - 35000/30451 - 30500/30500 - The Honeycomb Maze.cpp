#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, m, k, p, q;
int ans = 0;

void dfs(int x, int y, int steps, vector<vector<char>>& grid, vector<vector<int>> visited)
{
    // check if it is outside graph
    if(x < 0 || x >= n || y < 0 || y >= m) return;

    // check if grid is non traversable
    else if(grid[x][y] == '*') return;

    // check if we reached source
    else if(x == p && y == q)
    {
        if(steps >= k) {ans = 1; return;}
        else return;
    }

    else if(visited[x][y] == 1) return;

    // cout << x << ' ' << y << ' ' << steps << '\n';

    visited[x][y] = 1;
    steps += 1;
    dfs(x+1, y, steps, grid, visited);
    dfs(x-1, y, steps, grid, visited);
    dfs(x, y+1, steps, grid, visited);
    dfs(x, y-1, steps, grid, visited);
}

int main()
{
    cin >> n >> m >> k >> p >> q;
    --p, --q;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];

    visited[p][q] = 1;
    int steps = 0;


    dfs(p+1, q, steps+1, grid, visited);
    dfs(p-1, q, steps+1, grid, visited);
    dfs(p, q+1, steps+1, grid, visited);
    dfs(p, q-1, steps+1, grid, visited);

    cout << ((ans == 1) ? "YES" : "NO") << '\n';

    return 0;
}
