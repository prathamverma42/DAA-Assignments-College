#include<bits/stdc++.h>
using namespace std;

int knapsack_01(int W,int w[],int val[],int n)
{
    if(n==0 || W==0) 
        return 0;
    
    if(w[n-1]>W) 
        return knapsack_01(W,w,val,n-1);
    else
        return max(knapsack_01(W,w,val,n-1),(val[n-1]+knapsack_01(W-w[n-1],w,val,n-1)));
}

int knapsack_01_tabular(int W,int w[],int val[],int n)
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    
    for(int i=0;i<=W;i++)
    dp[0][i]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(w[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-w[i-1]]);
            }
        }
    }

    // To print the dp array

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=W;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[n][W];
}

//     0   1   2   3   4   
// 0   0   0   0   0   0   
// 1   0   60  60  60  60
// 2   0   60  100 160 160
// 3   0   60  100 160 180

int main()
{
    int n=3;
    int w[]={1,2,3};
    int val[]={60,100,120};
    int W=4;
    cout<<knapsack_01_tabular(W,w,val,n);
    cout<<knapsack_01_tabular(W,w,val,n);
}
