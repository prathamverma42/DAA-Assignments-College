#include <bits/stdc++.h>
using namespace std;
bool vwratio(const pair<double, double> &a, const pair<double, double> &b)
{
    double r1 = a.first / a.second;
    double r2 = b.first / b.second;
    return r1 > r2;
}
double knapSack(int w, vector<pair<double, double>> v, int n)
{
    sort(v.begin(), v.end(), vwratio);
    double sum = 0;
    double final = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + v[i].second <= w)
        {
            sum = sum + v[i].second;
            final = final + v[i].first;
        }
        else
        {
            double remaining = w - sum;
            final = final + (v[i].first * (remaining / v[i].second));
            break;
        }
    }
    return final;
}
int main()
{
    int w = 50;
    vector<pair<double, double>> v;
    v.emplace_back(60, 10);
    v.emplace_back(100, 20);
    v.emplace_back(120, 30);

    int n = v.size();
    cout << "Max profit is : " << knapSack(w, v, n);
    return 0;
}