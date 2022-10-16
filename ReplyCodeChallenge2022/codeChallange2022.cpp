#include<iostream>
#include<vector>
#include <stack>
using namespace std;

class Pair
{
public:
	int row;
	int col;
	bool visited;
	bool deadCell;
	Pair()
	{
		row = -1;
		col = -1;
		visited = false;
		deadCell = false;
	}
};
void popit(vector <pair<int, int>> &v,int row,int col)
{
	for (int i = 0; i < v.size(); i++)
	{
		if(v[i].first ==row && v[i].second == col)
			v.erase(v.begin() + i);
	}
}
pair<int,string> moveToThisM(Pair start,Pair destination,int size,char matrix[90][90], vector <pair<int, int>>& v)
{
	stack<Pair> stack_, istack_;
	bool dead_end = 0;
	int row = start.row;
	int col = start.col;
	Pair** cell = new Pair *[size];
	for (int i = 0; i < size; i++)
	{
		cell[i] = new Pair[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cell[i][j].row = i;
			cell[i][j].col = j;
		}
	}
	cell[row][col].visited = 1;
	stack_.push(cell[row][col]);
	while (1)
	{
		dead_end = 0;
		int c1 = col + 1, c2 = col - 1, r1 = row + 1, r2 = row - 1;
		if (row != destination.row || col != destination.col)
		{
			if (c1 < size && cell[row][c1].visited != 1 && matrix[row][c1] == 'M')
			{
				if (matrix[row][c1] != 'I')
					cell[row][c1].visited = 1;
				col = c1;
				stack_.push(cell[row][col]);
				if (matrix[row][col] == 'M' && row != destination.row || col != destination.col)
					popit(v, row, col);
				else if (matrix[row][col] == 'M' && row == destination.row && col == destination.col)
					break;
			}
			else if (r2 >= 0 && cell[r2][col].visited != 1 && (matrix[r2][col] == 'M'))
			{
				if (matrix[r2][col] != 'I')
					cell[r2][col].visited = 1;
				row = row - 1;
				stack_.push(cell[row][col]);
				if (matrix[row][col] == 'M' && row != destination.row || col != destination.col)
					popit(v, row, col);
				else if (matrix[row][col] == 'M' && row == destination.row && col == destination.col)
					break;
			}
			else if (r1 < size && cell[r1][col].visited != 1 && (matrix[r1][col] == 'M'))
			{
				if (matrix[r1][col] != 'I')
					cell[r1][col].visited = 1;
				row = r1;
				stack_.push(cell[row][col]);
				if (matrix[row][col] == 'M' && row != destination.row || col != destination.col)
					popit(v, row, col);
				else if (matrix[row][col] == 'M' && row == destination.row && col == destination.col)
					break;
			}
			else if (c2 >= 0 && cell[row][c2].visited != 1 && (matrix[row][c2] == 'M'))
			{
				if (matrix[row][c2] != 'I')
					cell[row][c2].visited = 1;
				col = c2;
				stack_.push(cell[row][col]);
				if (matrix[row][col] == 'M' && row != destination.row || col != destination.col)
					popit(v, row, col);
				else if (matrix[row][col] == 'M' && row == destination.row && col == destination.col)
					break;
			}
			else if (c1 < size && cell[row][c1].visited != 1 && matrix[row][c1] == '*')
			{
				if (matrix[row][c1] != 'I')
					cell[row][c1].visited = 1;
				col = c1;
				stack_.push(cell[row][col]);
				if (matrix[row][col] == 'M' && row != destination.row || col != destination.col)
					popit(v, row, col);
				else if (matrix[row][col] == 'M' && row == destination.row && col == destination.col)
					break;
			}
			else if (r2 >= 0 && cell[r2][col].visited != 1 && matrix[r2][col] == '*')
			{
				if (matrix[r2][col] != 'I')
					cell[r2][col].visited = 1;
				row = row - 1;
				stack_.push(cell[row][col]);
				if (matrix[row][col] == 'M' && row != destination.row || col != destination.col)
					popit(v, row, col);
				else if (matrix[row][col] == 'M' && row == destination.row && col == destination.col)
					break;
			}
			//check all of above for adjacent LOWER cell
			else if (r1 < size && cell[r1][col].visited != 1 && matrix[r1][col] == '*')
			{
				if (matrix[r1][col] != 'I')
					cell[r1][col].visited = 1;
				row = r1;
				stack_.push(cell[row][col]);
				if (matrix[row][col] == 'M' && row != destination.row || col != destination.col)
					popit(v, row, col);
				else if (matrix[row][col] == 'M' && row == destination.row && col == destination.col)
					break;
			}
			//check all of above for adjacent RIGHT cell
			else if (c2 >= 0 && cell[row][c2].visited != 1 && matrix[row][c2] == '*')
			{
				if (matrix[row][c2] != 'I')
					cell[row][c2].visited = 1;
				col = c2;
				stack_.push(cell[row][col]);
				if (matrix[row][col] == 'M' && row != destination.row || col != destination.col)
					popit(v, row, col);
				else if (matrix[row][col] == 'M' && row == destination.row && col == destination.col)
					break;
			}
			//if mouse can't move in any of above four directions dead end is reached
			else
				dead_end = 1;
		}
		//if dead end is reached start marking cells as deadcells and pop from stack until we 
		//reach a cell from where path exists in any direction.
		if (dead_end && !(stack_.empty()))
		{
			cell[row][col].deadCell = 1;
			if (!(stack_.empty()))
				stack_.pop();
			if (!(stack_.empty()))
			{
				Pair poped = stack_.top();
				row = poped.row;
				col = poped.col;
			}
		}
		//if deadend is reached and stack is empty means no more path exist in any direction so no path found
		if (dead_end && (stack_.empty()))
		{
			return { -1, "" };
		}
	}
	//to display in start to end order pop all pairs of cells and insert in other stack
	while (!(stack_.empty()))
	{
		istack_.push(stack_.top());
		stack_.pop();
	}
	string str;
	//display path coordinates from mouse ton destination
	while (!(istack_.empty()))
	{
		int a = istack_.top().row, b= istack_.top().col;
		istack_.pop();
		if (!(istack_.empty()))
		{
			if (istack_.top().row > a)
				str += "D";
			else if (istack_.top().col > b)
				str += "R";
			else if (istack_.top().row < a)
				str += "U";
			else
				str += "L";
		}
	}
	return { 0, str };
}
int main()
{
	int t;
	cin >> t;
	vector<string> strr;
	while (t--)
	{
		int floors, levels, maxSteps;
		cin >> floors >> levels >> maxSteps;
		string pat = "";
		for (int i = 0; i < floors; i++)
		{
			int thisFloor, legthOfChess, MonsterLevel;
			cin >> thisFloor >> legthOfChess >> MonsterLevel;
			char floor[90][90];
			vector < pair<int, int>> v;
			Pair start,destination;
			for (int i = 0; i < legthOfChess; i++)
			{
				for (int j = 0; j < legthOfChess; j++)
				{
					cin >> floor[i][j];
					if (floor[i][j] == 'M')
						v.push_back({ i,j });
					if (floor[i][j] == 'I')
						start.row = i, start.col = j;
					if (floor[i][j] == 'O')
						destination.row = i, destination.col = j;
				}
			}
			v.push_back({ destination.row,destination.col });
			
			Pair end; 
			end.row = v[0].first, end.col = v[0].second;
			for (int i = 0; i < v.size(); )
			{
				pair<int, string> path = moveToThisM(start, end,legthOfChess,floor,v);
				pat += path.second;
				start.row = end.row, start.col = end.col;
				i++;
				if (i >= v.size())
					break;
				end.row = v[i].first, end.col = v[i].second;
				floor[start.row][start.col] = 'I';
				if(end.row == destination.row && end.col == destination.col)
					floor[destination.row][destination.col] = 'M';
			}
		}
		strr.push_back(pat); 
	}
	for (int i = 0; i < strr.size(); i++)
	{
		cout << "Case #" << i + 1 << ": " << strr[i] << endl;
	}
	return 0;
}
/*
1
1 65 582
0 7 3
M M M * M M M
M * * M M * O
M M M M * * M
M M M M M M M
M M * M * * M
* I M * M M M
M * M M M * *
1 5 1
M M * * M
* M * * I
M M M M *
M O * * M
M * M * M
2 6 2
* M * * I M
* * * * M *
M * * * * M
* * M * * M
M M M O * *
* * M * M M
3 11 2
* * * M * M M M * * M
M * M M * M M * * * M
* M * M M M * * M M M
M M * M M * M * M * M
* M M M * * * M M M *
M * * M * * * M * * *
M I M M M M M M M M *
M M M M M O * * * M M
* * * * * M * * * * M
* M M * * M * M M M M
M * M M M M M M * M M
4 14 3
M M M M M M M M M M M M M M
M * M M M M M M M M M M M M
M M M M M M M M M M M M M M
* M M * M M * M M M * * M M
M M M M M M M M M I M M M M
M M M M M M M M M M M M M M
M M M M M M M M M M M M M M
M M M M M M M M M M M * M M
M M M M M M M M M M M M M M
M M M M M M M M M M M M M M
M M M M M M M M M M M O M M
M * M M M M M M M M M M M M
M M M M M M M M M M M M M M
M M M M M M M M M M M M M M
5 11 2
M M M * M M M * M M M
M M M M M M M M M M M
M M M M M M M M M M M
* M M M M M * M M M M
M M * * M M * M M M *
* M M M M M M * * M *
M M * M M I M M M * *
M M M * M M M M M M M
M * M * M M M M M M M
M M M M * M M M M M M
M M O M M M M * M M M
6 7 3
M * M * * M M
* * M * * M M
* M * * M M *
* * * * * * M
* * M * * M M
* * O M M I *
* M * * * M M
7 6 4
M O M M M M
M M M M M M
M M M M M M
M M M M M M
M M M M M M
M I M M M M
8 13 4
M M * M * * M * M * * * M
* O * * * M * * M * * M M
M M * * M M * * M * M * *
* * M M M M M * * M * M M
* M M * M * * M M M * M *
* * * M * M M * M M * * *
M * * * * * M * M I M M *
M * * * * M * * * M * M *
* M M M M M * * * * * M *
* M * M * M M * M M * M *
* * * * * * * M * M M * *
M M * M * * * M M M * * *
* M M M * * * * M M * * M
9 12 5
* M M M * M M M M M M *
M * * M M * * * M M M M
M M M M M M O M M M M M
M M M M M M M M M M M M
M M M M M * M * * M M M
M * M M M M M * M M * M
M M M M M M M M M * M M
* * M * * M M M M I M M
M M M M * M M M M M M M
M * M M M * * * M * * M
* M * M M M M M * * M M
* M M M M M M M * * M M
10 10 2
* * * M * * * * * *
* * * * M * * * * M
* * * * * M M M * *
* * * M * * O * * *
M M * * * * * M * I
* * * * * M * M * *
* M * M * * * * * *
* M * * M * * * M *
* * * * M * * * * *
* M * * * * * * M M
6 50 199
0 7 2
M M * * * * M
M * * * * * *
* * M M I * *
* * M * O * *
* M M M * M *
* * * * M M *
* * * * M * *
1 5 3
M M * * M
M M * M M
M M M M M
O M M M I
M M * M M
2 6 5
M * M M M M
O M M M M M
M M M M * M
M * M M M M
M M M * M M
M M M I * M
3 4 4
M M M M
M M M M
M O M I
M * M M
4 14 2
M M M * M * M M M M M M * M
* M M M * * M M M M * M M M
M * * M * M M M M M M * M M
* M M M M O M M M M M M * *
M * M M * M M M * M M M M M
* M M M M M M M M M M M * M
* * M M M * M M M * M M * *
* M * M M M M * M M M M * M
M M M M M M * M M * * M * *
M M M M M M * M M * M * M M
M M M * M M M M M M M M M *
M I * M * M * M M M M * M *
M M M * M M * M M M M M M *
* * M M M M * M M M M M M M
5 11 4
M M M M M M M M M M M
M M M M M M M M M M M
M M M M M M M M M M M
M M M M M M M M M M M
M M M M M M M M M M M
M M M M M M M M M M M
M M M M M M M M M M M
M M M M M M M M M M M
M M M M M M M M M M M
M M M M M M O M M M M
M M M M M M I M M M M
13 65 930
0 11 2
M M * M * M M M * M M
M M M M M M M M * M M
* M M M M * M * M M M
* M * * M M * M M * *
M M M M M M M M M M *
* M M M M * * O M M M
M * * M * M M M M M M
M M M * M * M M * M M
M M M M M M M M M * M
M M M M M M M M I M M
M M M M M * M M * M M
1 10 4
M M M M M M M * M M
M * M M * M M O M M
* M M M M * M M M M
* * M M M * * M M M
M M M * M * M M M M
M M * M * M M M M M
M M M M M M M M * M
M M * M M M M M M *
M * * I M * * M M M
M M M * M M M M M M
2 7 2
* * M * M * M
M M M M * * *
* O * * M M M
M M M M * * *
* * * M M * *
* M M * M M I
* * M * M M M
3 10 4
M M * * * M * M * *
* * * * * * * * * *
* * M * M M * * * *
* M * * * M * M * *
M M * * * M * M * M
M M * M * * * * * M
M * * * * * * * M M
* * * M M * * * * O
* M M * M M M I M *
* * * * * * M * M *
4 11 1
M M M * M M * M M * *
M * M M M * * * M M *
M M M M * M * * M M M
* M * * M * M M M M M
M * * * * * M M I * *
* O M * M M * * M * *
* * * M * M * * M M M
* * M * M M M * M * *
M M M M M * * * * * *
* * M * M * M * M M *
M M M * * * * M M * M
5 8 1
M M M M M M M M
M M M M * M M M
M M M M I * M M
M M * * M * M *
M M M * M M M M
M M M M M M M M
* * M M M M O *
M M M * M M M M
6 5 1
M * M M *
O * * I *
* M * * *
* M * * M
M * M * M
7 9 5
* M M * * * * * *
* M * * * * * M M
* * * * * * * * *
* M M M * M * * *
M * * * I M * * *
M * * * M * * M *
* * M M * * * M M
M * * * * M M * *
* M M * * O * * M
8 6 3
* I * * * *
M M M M M *
M * * * * M
M * * M * M
M * * * M M
M * * O * *
9 10 1
M * * * * M * * * M
O * * * M M M * * *
* M * * * M * * * M
M M M M M M M M * *
M M * * * * M * * M
M M * M * * * M * *
M * * M M M M I * *
* M * * M * M M * M
M M M M * * * * * M
* M * * M M * * * *
10 13 5
M * M M * M * * M * M * *
M * * M M * * * * M M * *
* * M * M M M * M M * M M
* * * M * M M M M M * * *
M * M * M * M M M M M M *
M M M M * M M * * M M M *
M M * M * M * * M M * * *
M M M * M M M M M M M * M
M M * M M * * M * * * * M
M O * M M M * * M M * M M
M * M * M M M M * M * M *
* * I M * M M M M M M M M
* M M M * M M * M * M M M
11 7 4
M * M M M * M
M M M * M M M
M M O M M M M
M * M M * I M
M M M M M M M
M * * M M M M
M M M * M * M
12 12 2
M M M M M M * M M * M *
M M M * * M M M M M M M
* M M M M M M M * M * M
* M M M M M * M M M M M
M M M M M * M * M M M *
M M * M M M M * M I M *
M M M M M M M M M O M M
M M M M * M M M M M M M
* M M M M M * M M M M M
M M M * M M M M * M M M
M M M M M M M M M M M *
* M M M * M M M M M M M

*/