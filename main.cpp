#include<iostream>
#include<queue>
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#define FIN freopen("input.txt", "r", stdin);
#define fuck cout<<"fuck"<<endl;
#define mem(x, y) memset(x, y,sizeof(x))
typedef long long LL;
using namespace std;
const int MAX = 1e2 +5;
int dis[MAX][MAX];
int N, M;
void floyd()
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				dis[i][j] = min(dis[i][j], (i > k?dis[i][k]:dis[k][i]) + (k>j?dis[k][j]:dis[j][k]));
			}
		}
	}
}
int main()
{
#ifdef _local
	FIN;
#endif // _local
	while (cin >> N >> M)
	{
		mem(dis, 0x3f);
		for (int i = 0; i < N; i++)
			dis[i][i] = 1;
		int a =0, b = 0;
		for (int i = 0; i < M; i++)
		{
			scanf("%d %d", &a, &b);
			if (a < b)
				swap(a, b);
			dis[a][b] = 1;
		}
		floyd();
		bool isok = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < i; j++)
				if (dis[i][j] > 7)
					isok = false;
		cout << (isok ? "Yes" : "No") << endl;
	}
	return 0;
}

