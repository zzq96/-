#include<iostream>
#include<stdio.h>
#include<algorithm>
#define FIN freopen("input.txt", "r", stdin);
#define fuck cout<<"fuck"<<endl;
#define mem(x, y) memset(x, y,sizeof(x))
typedef long long LL;
using namespace std;
const int MAX = 40 + 5;
LL dp[MAX][3];
int shu[MAX];
int ans[MAX];
int n = 0, k = 0;
bool finish;
int icnt = 0;
int dfs(int len, int res, bool isin, int limit)
{
	if (res == 1)
	{
		finish = true;
		return 0;
	}
	if ((limit == 2 && len == 0) || len == -1)
	{
		return 1;
	}
	if(dp[len][limit] != -1 && isin == false)
		return dp[len][limit];
	int c = 0;
	int cnt = 1;
	for (int i = ((len == icnt - 1) ? 1 : 0); i <= (limit == 1 && len == 0 ? shu[len] : 9); i++)
	{
		ans[len] = i;
		if (limit == 0 ||(limit ==1 &&i < shu[len]))
			c = dfs(len - 1, res - cnt, false, 0);
		else if (limit == 1 && i == shu[len])
			c = dfs(len - 1, res - cnt, false, 1);
		else if (limit == 2 || (limit == 1 &&  i > shu[len]))
			c = dfs(len - 1, res - cnt, false, 2);

		if (cnt + c >= res)
		{
			if (limit == 0 ||(limit ==1 &&i < shu[len]))
				c = dfs(len - 1, res - cnt, true, 0);
			else if (limit == 1 && i == shu[len])
				c = dfs(len - 1, res - cnt, true, 1);
			else if (limit == 2|| (limit == 1 &&  i > shu[len]))
				c = dfs(len - 1, res - cnt, true, 2);
		}
		cnt += c;
		if (finish == true)
			return 0;
		ans[len] = -1;
	}
	return dp[len][limit] = cnt;
}
int findKthNumber(int n, int k)
{
	int ans2 = 0;
		k +=1;
		finish = false;
		mem(dp, -1);
		mem(ans, -1);
		icnt = 0;
		while (n)
		{
			shu[icnt++] = n % 10;
			n /= 10;
		}

		dfs(icnt - 1, k, true, 1);
		for (int i = icnt - 1; i >= 0; i--)
			if (ans[i] != -1)
				ans2 *= 10, ans2 += ans[i];

				return ans2;
}
int main()
{
#ifdef _local
	FIN;
#endif // _local
	while(cin >> n >> k)
	{
		cout << findKthNumber(n, k) << endl;
	}
	return 0;
}