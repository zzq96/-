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
const int MAX = 1e3 +5;
struct edge
{
	int nxt;
	int to;
	int p;
	int d;
}E[MAX * 111];
int head[MAX], rear = 0;
int S = 0, T = 0;
void edge_init()
{
	mem(head, -1);
	rear = 0;
}
void edge_add(int a, int b, int d, int p)
{
	E[rear].nxt = head[a];
	E[rear].p = p;
	E[rear].d = d;
	E[rear].to = b;
	head[a] = rear++;
}
struct Node
{
	Node(int d, int p, int node):d(d), p(p), node(node){}
	int d;
	int p;
	int node;
	bool operator <(const Node &x)const {
		if (d != x.d)
			return d < x.d;
		return p < x.p;
	}
	bool operator >(const Node &x)const {
		if (d != x.d)
			return d > x.d;
		return p > x.p;
	}
};

int Dis[MAX], P[MAX];
void dijkstra(int& ans_d, int& ans_p)
{
	mem(Dis, 0x3f);
	mem(P, 0x3f);
	Dis[S] = 0;
	P[S] = 0;
	priority_queue<Node, vector<Node>, greater<Node> > Q;
	Q.push(Node(0, 0, S));
	while (!Q.empty())
	{
		Node tmp = Q.top();
		Q.pop();
		int dis = tmp.d;
		int p = tmp.p;
		int node = tmp.node;
		for (int i = head[node]; ~i; i = E[i].nxt)
		{
			int to = E[i].to;
			if (Dis[to] > Dis[node] + E[i].d)
			{
				Dis[to] = Dis[node] + E[i].d;
				P[to] = P[node] + E[i].p;
			}
			else if (Dis[to] == Dis[node] + E[i].d && P[to] > P[node] + E[i].p)
			{
				P[to] = P[node] + E[i].p;
			}
			else {
				continue;
			}
			Q.push(Node(Dis[to], P[to], to));
		}
	}
	ans_d = Dis[T];
	ans_p = P[T];
}
int main()
{
#ifdef _local
	FIN;
#endif // _local

	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0)
			break;
		edge_init();
		int a = 0, b = 0, d = 0, p = 0;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d %d", &a, &b, &d, &p);
			edge_add(a, b, d, p);
			edge_add(b, a, d, p);
		}
		cin >> S >> T;
		int ans_d, ans_p;
		dijkstra(ans_d, ans_p);
		cout << ans_d << " " << ans_p << endl;

	}
	return 0;
}

