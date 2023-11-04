#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator> //for std::istream_iterator 
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M;
	std::cin >> N >> M;
	vector <vector<int>> Sarray;
	for (int i = 0; i < N; i++)
	{
		vector <int> v(N);
		for (int j = 0; j < N; j++)
		{
			cin >> v[j];
		}
		Sarray.push_back(v);
	}



	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Sarray[i][j];
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}