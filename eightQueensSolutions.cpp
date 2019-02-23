
#include <iostream>
using namespace std;
int main() {
	
int board[8][8]={0};
int row=0;
int column=0;
int count=1;
	board[0][0]=1;
	
	mc: column++;
		if (column==8)
			goto print;
	row=-1;
	mr: row++;
		if (row==8)
			goto btrack;
	//left
	for (int i=0; i<column; i++){
		if (board[row][i]==1)
			goto mr;
	}
	//up  to left
	for (int i=1; (row-i>=0 && column-i>=0); i++){
		if (board[row-i][column-i]==1)
			goto mr;
	}
	//down to left
	for (int i=1; (row+i<8 && column-i>=0); i++){
		if (board[row+i][column-i]==1)
			goto mr;
	}	
	board[row][column]=1;//if conditions are met, place queen
	goto mc;
	btrack: column--;
		if (column==-1)
			return 0;
		row=0;
		while (board[row][column]!=1)
			row++;
		board[row][column]=0;
		goto mr;
	print: 	
	cout << "Solution: " << count <<  endl;
		for (int i=0; i<8; i++){
			for (int j=0; j<8; j++){
				cout << board[i][j] << ' ';
			}
		cout << endl;
		}
		count++;
		cout << endl;
		goto btrack;
}
		 