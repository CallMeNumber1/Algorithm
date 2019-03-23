#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 105
char map[MAX][MAX];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0,-1, 1, 1, -1};
int main() {
	int n, m;
	int cnt = 0;
	while (cin >> n >> m) {
		if (n == 0 || m == 0) break;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                map[i][j] = '.';
            }
        }
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == '*') continue;
				int ans = 0;
				for (int k = 0; k < 8; k++) {
					if (map[i + dx[k]][j + dy[k]] == '*') ans++;
				}
				map[i][j] = ans + '0';
			}
		}
		if (cnt > 0) cout << endl;
		cnt++;
		printf("Field #%d:\n", cnt);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
		
	}	
	return 0;
}