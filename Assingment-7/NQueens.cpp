#include<iostream>
using namespace std;
int borard[4][4];

bool isSafe(int row,int col){
    for
}

bool solveRec(int col){
    for(int i=0;i<4;i++){
        if(isSafe(i,col)){
            borard[i][j]=1;
            solveRec(col+1);
        }
        borard[i][j]=0;
    }
}

bool solve(){
    if(solveRec(0)==false){
        cout<<"Not possible";
        return false;
    }
    else{
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<borard[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

int main(){
    cout<<solve();
}