#include<iostream>
#include<stdio.h>
#include<algorithm>
#define FIN freopen("input.txt", "r", stdin);
#define fuck cout<<"fuck"<<endl;
#define mem(x, y) memset(x, y,sizeof(x))
typedef long long LL;
using namespace std;
const int MAX = 40 + 5;
LL dp[MAX][2][2];
int shu[MAX];

LL dfs(int len, bool is4, bool state, bool limit)
{
	if (len == -1)
		return state;

	//如果被记忆化搜索过了，就直接返回
	if (limit == false && dp[len][is4][state] != -1)
		return dp[len][is4][state];
	
	LL cnt = 0;
	for (int i = 0; i <= (limit ? shu[len] : 9); i++)
	{
		cnt += dfs(len - 1, i==4, (is4 && i ==9) || state, limit && i == shu[len]);
	}
	if (limit == false)
		dp[len][is4][state] = cnt;
	return cnt;
}
int main()
{
#ifdef _local
	FIN;
#endif // _local
	int n = 0;
	cin >> n;
	while(n--)
	{
		LL N = 0;
		scanf("%lld", &N);
		mem(dp, -1);
		int cnt = 0;
		while (N)
		{
			shu[cnt++] = N % 10;
			N /= 10;
		}
		cout << dfs(cnt - 1, false,false, true) << endl;
	}
	return 0;
}