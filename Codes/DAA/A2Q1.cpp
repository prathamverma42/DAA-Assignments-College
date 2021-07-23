#include <bits/stdc++.h>
using namespace std;
vector<int> printMaxActivities(int s[], int f[], int n)
{
    int i, j;
    vector<int> v;
    i = 0;
    v.push_back(i);
    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            v.push_back(j);
            i = j;
        }
    }
    return v;
}
int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);
    vector<int> v = printMaxActivities(s, f, n);
    cout << "Activites selected : " << endl;
    cout << "Index     : ";
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Starting  : ";
    for (auto x : v)
    {
        cout << s[x] << " ";
    }
    cout << endl;
    cout << "Finishing : ";
    for (auto x : v)
    {
        cout << f[x] << " ";
    }
    cout << endl;
    return 0;
}