#include<iostream>
using namespace std;
void print(string s,int k){
	if(k==0)
	return;
	cout<<s;
	print(s,k-1);
}
void sum(int arr[],int index,int size,int sums){
	if(index==size){
		cout<<sums;
		return;
	}
	sums+=arr[index];
	sum(arr,index+1,size,sums);
}
int main(){
	string s="Pratham ";
	print(s,5);
	int arr[]={1,2,3,14};
	sum(arr,0,4,0);
}

