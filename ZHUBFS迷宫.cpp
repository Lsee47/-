#include<iostream>
#include<stdlib.h>
using namespace std;

//@file		:ZHUBFS迷宫
//@author	:Lvsq
//@time		:2022/3/22 16:49:35

const int N = 110;//地图最大范围
int dx[4] = { -1,0,1,0 };//x移动范围
int dy[4] = { 0,1,0,-1 };//y移动范围
int q[100000];//数组队列
int front = 0;//队列首指针
int rear = 0;//队列尾指针

int BFS(int map[N][N], int vis[N][N], int dist[N][N], int n, int m, int sx, int sy) {
	front = rear = 0;//清空队列
	q[rear++] = sx;
	q[rear++] = sy;//起点入队
	dist[sx][sy] = 0;
	vis[sx][sy] = 1;
	//队列非空
	while (front<rear) {
		int x = q[front++];
		int y = q[front++];
		for (int i = 0; i < 4; i++) {
			//周围的点
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] == 1 || map[nx][ny] == 1) {
				continue;
			}
			if (map[nx][ny] == 4) {
				return dist[x][y] + 1;
			}
			q[rear++] = nx;
			q[rear++] = ny;
			vis[nx][ny] = 1;
			dist[nx][ny] = dist[x][y] + 1;
		}
	}
	return -1;
}
int main() {
	int n, m, sx, sy;
	while (scanf("%d %d",&n,&m)!=EOF)
	{
		int map[N][N], dist[N][N], vis[N][N]={{0}};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 3) {
					sx = i; 
					sy = j;
				}
			}
		}
		int ans = BFS(map, vis, dist, n, m, sx, sy);
		if (ans == -1) {
			printf("unreachable\n");
		}
		else {
			printf("%d\n", ans);
		}
	}

	system("pause");
	return 0;
}