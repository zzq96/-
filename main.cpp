#include<iostream>
#include<map>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<functional>
#include<algorithm>
#define FIN freopen("input.txt", "r", stdin);
#define fuck cout<<"fuck"<<endl;
#define mem(x, y) memset(x, y,sizeof(x))
typedef long long LL;
using namespace std;
const int MAX = 5e5 +5;
int n, k;
int num_cnt[MAX * 2];
int arr[MAX];
int main()
{
#ifdef _local
	FIN;
#endif // _local
	while (cin >> n >> k)
	{
		mem(num_cnt, 0);
		int cnt = 0;
		int x = 0;
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (mp.count(x) == 0)
			{
				mp[x] = cnt;
				arr[i] = cnt;
				cnt++;
			}
			else
			{
				arr[i] = mp[x];
			}
		}
		int r = 0;
		num_cnt[arr[0]] ++;
		int ans = 1;
		int now = 1;
		int ans_l = 0;
		int ans_r = 0;
		for (int l = 0; l < n; l++)
		{
			if (l != 0)
			{
				num_cnt[arr[l - 1]] --;
				if (num_cnt[arr[l - 1]] == 0)
					now--;
				if (now > k)
					continue;
			}
			while (r < n - 1)
			{
				r++;
				num_cnt[arr[r]] ++;
				if (num_cnt[arr[r]] == 1)
					now++;
				if (now <= k)
				{

					if (ans < r - l + 1)
					{
						ans = max(ans, r - l + 1);
						ans_l = l;
						ans_r = r;
					}
				}
				else break;
			}
		}
		cout << ans_l +1<<" "<<ans_r+1<< endl;
	}
	return 0;
}

