#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define FIN freopen("input.txt", "r", stdin);
#define fuck cout<<"fuck"<<endl;
#define mem(x, y) memset(x, y,sizeof(x))
typedef long long LL;
using namespace std;
const int MAX = 40 + 5;

class Solution {
public:
    double x, y;
    double eps = 1e-7;
    double getMinDistSum(vector<vector<int>>& positions) {
        
        return threefenx(0, 100, positions); 
    }
    double threefenx(double minx, double maxx, vector<vector<int>> &positions)
    {
        int cnt = 100;
        double lsum, rsum;
        while(abs(minx -maxx) > eps)
        {
            double l = (minx * 2 + maxx)/3;
            double r = (minx + maxx* 2)/3;
            lsum = threefeny(l, 0, 100, positions);
            rsum = threefeny(r, 0, 100, positions);
            if(lsum > rsum)
            minx = l;
            else 
            maxx = r;
        }
    return lsum;
    }
    double threefeny(double x, double miny, double maxy, vector<vector<int>>&positions)
    {
        int cnt = 100;
        double lsum, rsum;
        while(abs(miny -maxy) > eps)
        {
            double l = (miny * 2 + maxy)/3;
            double r = (miny + maxy* 2)/3;
            lsum = getDistSum(x, l, positions);
            rsum =getDistSum(x, r, positions);
            if(lsum > rsum)
            miny = l;
            else 
            maxy = r;
        }
        return lsum;
    }
    double getDistSum(double x, double y, vector<vector<int>>&positions)
    {
        double sum = 0;
        for(int i = 0; i< positions.size();i++)
        {
            sum += sqrt((positions[i][0] - x)*(positions[i][0] - x) + (positions[i][1] - y)*(positions[i][1] - y));
        }
        return sum;
    }
};
