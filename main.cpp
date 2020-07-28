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
int jc[20];
void jiecheng()
{
	jc[0] = 1;
	jc[1] = 1;
	for (int i = 2; i <= 10; i++)
		jc[i] = jc[i - 1] * i;
}
int cantor(int x)
{
	vector<int> arr;
	while (x)
	{
		arr.push_back(x % 10);
		x /= 10;
	}
	reverse(arr.begin(), arr.end());
	int num = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		int cnt = 0;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] > arr[j])
				cnt++;
		}
		num += cnt * jc[arr.size() - i - 1];
	}
	return num + 1;
}
vector<int> inv_cantor(int x)
{
	x--;
	vector<int> ans;
	vector<int> arr;
	for (int i = 0; i < 5; i++)
		arr.push_back(i + 1);
	for (int i = 4; i >= 0; i--)
	{
		int shang = x / jc[i];
		x = x % jc[i];
		ans.push_back(arr[shang]);
		arr.erase(arr.begin()+shang);
	}
	return ans;
}
int main()
{
	jiecheng();
#ifdef _local
	FIN;
#endif // _local
	int x;
	while (cin >> x)
	{
		cout << x << endl;
		int ans = 0;
		ans  =cantor(x);
		cout << ans << endl;
		vector<int>  anss;
		anss = inv_cantor(ans);
		for (auto i : anss)
			cout << i;
		cout << endl << endl;
	}
	return 0;
}

