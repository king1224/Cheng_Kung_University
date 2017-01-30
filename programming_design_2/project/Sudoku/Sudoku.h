#include <cstdio>

using namespace std;

class Sudoku{
	public:
		Sudoku();
		Sudoku(const int init_map[]);
		void setMap(const int set_map[]);
		int getElement(int index);
		bool isCorrect();
		void outMap();
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int angle);
		void flip(int a);
		void transform();
		static const int sudokuSize = 81;

	private:
		bool checkRow(int row);
		bool checkCol(int col);
		bool checkCell(int cell);
		bool isUnityrow(int row);
		bool isUnitycol(int col);
		bool isUnitycell(int cell);
		bool isUnity();
		bool isOnly();
		bool Dlx(int deep);
		int map[sudokuSize];
		int question_map[sudokuSize];
		int ans_map[sudokuSize];
		int COL[25000],ROW[25000];
		int U[25000],D[25000],L[25000],R[25000];
		int COLNUM[350],ANS[sudokuSize+1];
		struct ii{
			int row;
			int col;
			int num;
		}solve_map[750];
		bool isonly;
};
