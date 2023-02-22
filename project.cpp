#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

int N, M, sx, sy, ex, ey;
char maze[MAXN][MAXN];
int dist[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return (x >= 1 && x <= N && y >= 1 && y <= M && maze[x][y] != '#' && !visited[x][y]);
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    visited[sx][sy] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;

        if (x == ex && y == ey) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') sx = i, sy = j;
            if (maze[i][j] == 'E') ex = i, ey = j;
            dist[i][j] = INF;
        }
    }

    bfs();

    if (dist[ex][ey] == INF) {
        cout << "No path found\n";
    } else {
        cout << "Shortest distance: " << dist[ex][ey] << '\n';
    }

    return 0;
}
