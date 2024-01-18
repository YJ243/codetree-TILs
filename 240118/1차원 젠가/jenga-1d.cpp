#include <iostream>
#define MAX_N 100

using namespace std;
int n;
int arr[MAX_N];
int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	int arrLastIdx = n-1;

	for(int i=0; i<2; i++){
		int s, e;
		cin >> s >> e;
		s--; e--;
		// s부터 e까지 블럭 빼기
		for(int j=s; j<=e; j++)
			arr[j] = 0;
		// 옮길 블럭
		int temp[arrLastIdx+1];
		int curTempIdx = arrLastIdx;
		for(int j=arrLastIdx; j>=0; j--){
			if(arr[j] != 0){
				temp[curTempIdx] = arr[j];
				curTempIdx--;
			}
		}
		// 원래 배열로 옮기기
		for(int j=curTempIdx+1; j<=arrLastIdx; j++){
			arr[j-curTempIdx-1] = temp[j];
		}
		arrLastIdx = arrLastIdx-curTempIdx-1;

	}
	// 출력:
	cout << arrLastIdx+1 << '\n';
	for(int i=0; i<=arrLastIdx; i++)
		cout << arr[i] << '\n';

	return 0;
}