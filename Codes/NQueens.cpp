#include<bits/stdc++.h>
using namespace std;

bool isSafe(int arr[4][4], int row , int col){
	
	//vertically up
	int r=row-1;
	int c=col;
	while(r>=0){
		if(arr[r][c]){
			return false;
		}
		r--;
	}
	
	//horizontally left
	r=row;
	c=col-1;
	while(c>=0){
		if(arr[r][c]){
			return false;
		}
		c--;
	}
	
	//diagonally left
	r=row-1;
	c=col-1;
	while(r>=0 && c>=0){
		if(arr[r][c]){
			return false;
		}
		r--;
		c--;
	}
	
	//diagonally right
	r=row-1;
	c=col+1;
	while((r>=0) && (c < arr[0][4].length())){
		if(arr[r][c]){
			return false;
		}
		r--;
		c++;
	}
	return true;
}

void NQueens(int board[4][4], int row, int col, int tq, int qpsf, string ans){
	
	if(qpsf==tq){
		cout<<ans<<endl;
		return;
	}
	if(col==board[0].length){
		row++;
		col=0;
	}
	if(row==board.length){
		return;
	}
	
	if(isSafe(arr,row,col)){
		arr[row][col]=1;
		NQueens(arr,row,col+1,4,tq+1,"["+row+","+col+"]");
		arr[row][col]=0;
	}
	
	NQueen(board,row,col+1,tq,qpsf,ans);
}

int main(){
	int boolean[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			boolean[i][j]=0;
		}
	}
	//NQueens(int arr[][], int row, int col, int tq, int qpsf, string ans);
	string ans="";
	void NQueens(boolean,0,0,4,0,ans);
}
