#include <bits/stdc++.h>
using namespace std;
bool sortBySec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second > b.second);
}
void jobSeq(vector<pair<int, int>> v, vector<pair<int, int>> v1, int n)
{
    sort(v.begin(), v.end(), sortBySec);
    sort(v1.begin(), v1.end(), sortBySec);
    int ans[n];
    bool slot[n] = {false};
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, v[i].first) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                ans[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    cout << "Seq is : " << endl;
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
            cout << "Job " << v1[ans[i]].first << endl;
    }
}
int main()
{
    vector<pair<int, int>> v;
    vector<pair<int, int>> v1;
    v.emplace_back(2, 100);
    v.emplace_back(1, 19);
    v.emplace_back(2, 27);
    v.emplace_back(1, 25);
    v.emplace_back(3, 15);

    v1.emplace_back(0, 100);
    v1.emplace_back(1, 19);
    v1.emplace_back(2, 27);
    v1.emplace_back(3, 25);
    v1.emplace_back(4, 15);
    int n = v.size();
    jobSeq(v, v1, n);
    return 0;
}