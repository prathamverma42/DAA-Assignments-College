#include<iostream>
using namespace std;

int lcs(string s1, string s2, int m, int n){

    if(m==0 || n==0){
        return 0;
    }
    // cout<<m<<" "<<n<<" ";
    // for(int i=0;i<m;i++){
    //     cout<<s1[i];
    // }
    // cout<<" ";
    // for(int i=0;i<n;i++){
    //     cout<<s2[i];
    // }
    // cout<<endl;
    if(s1[m-1]==s2[n-1]){
        return 1 + lcs(s1,s2,m-1,n-1); 
    }else{
        return max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
    }
}

int lcs_tabulation(string s1,string s2, int m, int n){
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    
    for(int i=0;i<=n;i++)
        dp[0][i]=0;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    // To print the dp array

    //  for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[m][n];
}
int memo[11][11];
int lcs_memoization(string s1,string s2, int m, int n){

    if(m==0 || n==0){
        memo[m][n]=0;
        return memo[m][n];
    }

    if(memo[m][n]!=-1){
        return memo[m][n];
    }
    else{
        if(s1[m-1]==s2[n-1]){
            return 1+ lcs_memoization(s1,s2,m-1,n-1);
        }else{
            return max(lcs_memoization(s1,s2,m-1,n),lcs_memoization(s1,s2,m,n-1));
        }
    }
}
    

// ABC MSA
// AB MSA
// A MSA
// A MS 
// A M 
// AB MS 
// A MS
// A M 
// AB M 
// A M

int main(){
    // string s1="AATAC";
    // string s2="AACAC";
    // string s1="ABCDGH";
    // string s2="AEDFHR";    
    string s1="AGGTAB";
    string s2="GXTXAYB";
    cout<<"Recursion: "<<lcs(s1,s2,s1.length(),s2.length())<<endl;
    cout<<"Tabulation: "<<lcs_tabulation(s1,s2,s1.length(),s2.length())<<endl;
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            memo[i][j]=-1;
        }
    }
    cout<<"Memoization: "<<lcs_memoization(s1,s2,s1.length(),s2.length());
}