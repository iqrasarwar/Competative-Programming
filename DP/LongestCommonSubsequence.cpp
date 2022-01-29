class Solution {
public:
    
int LCS(int arr[1002][1002], int x , int y)
{
   
	for (int i = 2; i < x; i++)
	{
		for (int j = 2; j < y; j++)
		{
			if (arr[i][0] != arr[0][j])
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			else
				arr[i][j] = arr[i - 1][j - 1] + 1;
		}
	}
    int max = 0;
	for (int i = 2; i < x+2; i++)
	{
		for (int j = 2; j < y+2; j++)
		{
			if (max < arr[i][j]) max = arr[i][j];
            cout << arr[i][j] << "\t";

		}
	}
    return max;
}
    int longestCommonSubsequence(string text1, string text2) {
        int x, y;
        int arr[1002][1002];
         for (int i = 0; i < 1002; i++)
		{
			for (int j = 0; j < 1002; j++)
			{
				arr[i][j] = 0;
			}
		}
	string a, b;
	a=text1; b= text2;
	x = a.length();
	y = b.length();
	for (int i = 2; i < x+2; i++)
	{
		arr[i][0] = a[i-2];
		arr[i][1] = 0;
	}
	for (int i = 2; i < y+2; i++)
	{
		arr[0][i] = b[i-2];
		arr[1][i] = 0;
	}
	return LCS(arr,x+2,y+2);
    }
};
//const int n = 1000;
//const int m = 1000;
//int arr[n][m];
//
//void LCS(int arr[n][m], int x , int y)
//{
//	for (int i = 2; i < x; i++)
//	{
//		for (int j = 2; j < y; j++)
//		{
//			if (arr[i][0] != arr[0][j])
//				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
//			else
//				arr[i][j] = arr[i - 1][j - 1] + 1;
//		}
//	}
//}
//int main()
//{
//	int x, y;
//	string a, b;
//	cin >> a >> b;
//	x = a.length();
//	y = b.length();
//	for (int i = 2; i < x+2; i++)
//	{
//		arr[i][0] = a[i-2];
//		arr[i][1] = 0;
//	}
//	for (int i = 2; i < y+2; i++)
//	{
//		arr[0][i] = b[i-2];
//		arr[1][i] = 0;
//	}
//	for (int i = 0; i < x + 2; i++)
//	{
//		for (int j = 0; j < y + 2; j++)
//		{
//			cout << arr[i][j] << "\t";
//		}
//		cout << endl;
//	}
//	LCS(arr,x+2,y+2);
//	
//}
