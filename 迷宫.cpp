#include <iostream>
#include <queue>
using namespace std;

//@file		:迷宫
//@author	:Lvsq
//@time		:2022/3/11 19:14:24

const int MAX = 100;
const int INF = 0x3f3f3f3f;
typedef pair<int, int>P;
char shuru[MAX + 5][MAX + 5];
int n, m;
int sx, sy;//记录起点的位置
int gx, gy;//记录终点的位置
int d[MAX + 5][MAX + 5];//用数组存储起点到某一点的距离
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };//表明每次x和y方向的位移
void bfs()
{
    queue<P> que;//queue<pair<int,int>>que;
    //初始化所有点为INF
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            d[i][j] = INF;
    que.push(P(sx, sy));
    d[sx][sy] = 0;
    while (que.size())
    {
        P p = que.front();
        que.pop();
        int i;
        for (i = 0; i < 4; i++)
        {
            //移动后的坐标
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            //判断是否还可以移动且没有到达过
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && shuru[nx][ny] != '#' && d[nx][ny] == INF)
            {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
                if (nx == gx && ny == gy)
                    break;
            }
        }
        if (i != 4)
            break;
    }
}


int main()
{
    cin >> n >> m;
    //一行一行的输ru
    for (int i = 0; i < n; i++)
        cin >> shuru[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (shuru[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            if (shuru[i][j] == 'G')
            {
                gx = i;
                gy = j;//写成了i。。。这个bug找了半天。。
            }
        }
    }
    bfs();
    cout << d[gx][gy] << endl;
    return 0;
}


/*
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/
/*
5 5
S.###
#.##.
#.##.
...#.
#.#.G
*/   