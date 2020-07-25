#include<iostream>
#include<stdio.h>
#include<algorithm>
#define FIN freopen("input.txt", "r", stdin);
#define fuck cout<<"fuck"<<endl;
#define mem(x, y) memset(x, y,sizeof(x))
typedef long long LL;
using namespace std;
const int MAX = 40 + 5;
LL dp[MAX];
int shu[MAX];
int ans[MAX];
int n = 0, k = 0; 
bool finish;
int dfs(int len, int res, bool isin, bool allzero,  bool limit)
{
	if (len == -1)
	{
		if (res == 1 && isin==false)
			finish = true;
		return 1;
	}

	if (limit == false && dp[len] != -1 && isin==false)
		return dp[len];

	int cnt = 0;
	int c = 0;
	for (int i = 0; i <= (limit ? shu[len] : 9); i++)
	{
		ans[len] = i;
		c = dfs(len - 1, res - cnt, false, allzero && i==0, limit && i == shu[len]);
		if(cnt + c>=res)
			dfs(len - 1, res - cnt, true, allzero && i==0, limit && i == shu[len]);
		cnt += c;

		if (finish) return 0;
	}
	return  limit ? cnt : dp[len] = cnt;
}
int main()
{
#ifdef _local
	FIN;
#endif // _local
	while(cin >> n >> k)
	{
		k += 1;
		finish = false;
		mem(dp, -1);
		int cnt = 0;
		while (n)
		{
			shu[cnt++] = n % 10;
			n /= 10;
		}

		dfs(cnt - 1, k, true, true, true);
		for (int i = cnt -1; i >= 0; i--)
			printf("%d", ans[i]);
		cout << endl;
	}
	return 0;
}