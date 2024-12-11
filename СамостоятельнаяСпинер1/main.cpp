#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

vector<int> findZeros(vector<int>& mesta) 
{
	vector<int> zeros;
	auto item = find(mesta.begin(), mesta.end(), 0);
	while (item != mesta.end())
	{
		zeros.push_back(item - mesta.begin());
		item = find(item + 1, mesta.end(), 0);
	}
	return zeros;
}

int* findIndexes(vector<int>&list)
{
	int maxPair = 0;
	int *properData = new int[2];
	for (int i = 0; i < list.size() - 1; i++)
	{
		if (list[i + 1] - list[i] - 1 > maxPair)
		{
			maxPair = list[i + 1] - list[i] - 1;
			properData[0] = list[i];
			properData[1] = list[i + 1];
		}
	}
	return properData;
}

int findPlaceAmount(vector<int>& mesta, int size, int index, int side) 
{
	int chislo = -1;
	int sum_mest = 0;
	if (side == 1)
	{
		for (int i = index; i < size + 2; i++)
		{
			if (mesta[i] != 0 and chislo == -1)
			{
				chislo = mesta[i];
				sum_mest += 1;
				continue;
			}
			if (mesta[i] != 0 and chislo != -1)
			{
				chislo = mesta[i];
				sum_mest += 1;
				continue;
			}
			if (mesta[i] == 0 and chislo == -1)
			{
				continue;
			}
			if (mesta[i] == 0 and chislo != -1)
			{
				return sum_mest;
			}
		}
	}
	else 
	{
		for (int i = index; i > 0; i--)
		{
			if (mesta[i] != 0 and chislo == -1)
			{
				chislo = mesta[i];
				sum_mest += 1;
				continue;
			}
			if (mesta[i] != 0 and chislo != -1)
			{
				chislo = mesta[i];
				sum_mest += 1;
				continue;
			}
			if (mesta[i] == 0 and chislo == -1)
			{
				continue;
			}
			if (mesta[i] == 0 and chislo != -1)
			{
				return sum_mest;
			}
		}
	}
	return sum_mest;

}


int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251 > nul");
	
	
	//Задание 1
	int A, B, C;
	int N = 1;
	cout << "Введите значение A, B и C: " << endl;
	cin >> A >> B >> C;

	if (A > C or A > 2 * pow(10, 9) or B > 2 * pow(10, 9) or C > 2 * pow(10, 9)  or B <= 0)
	{
		cout << "Неверный ввод" << endl;
		return 0;
	}

	while ((A + B * N) <= C)
	{
		if ((A + B * (N + 1)) > C)
		{
			cout << "Максимальное количество лопастей: " << N << endl;;
			break;
		}
		N += 1;
	} 
	
	//Задание 2
	int M;
	int maxA = -1;
	int maxB = -1;
	cout << "Введите значение M: ";
	cin >> M;
	

	if (M <= 0 or M > 2 * pow(10, 9)) {
		cout << "Неверное значение M" << endl;
		return 0;
	}
	if (M / 3 == 0) {
		cout << 0 << endl << 0 << endl;
		return 0;
	}
	
	for (int i = 0; i <= M / 3; i++) 
	{
		int a = 3 * i;
		for (int j = 0; j <= (M - a) / 4; j++) 
		{
			if (a + 4 * j == M and maxA < i and maxB < j)
			{
				maxA = i;
				maxB = j;
			}
		}
	}
	if (maxA == -1 or maxB == -1) {
		maxA = 0;
		maxB = 0;
	}
	cout << "Количество троек: " << maxA << endl << "Количество четверок: " << maxB; 
	
	

	//Задание 3
	int M, N;
	cout << "Введите значения N, M: " << endl;;
	cin >> N >> M;
	if (N > 75000 or M > 75000) {
		cout << "Неверный ввод" << endl;
		return 0;
	}
	
	
	int sumVert = 0;
	int sumHor = 0;
	for (int x1 = 0; x1 < N; x1++)
	{
		for (int x2 = x1; x2 < N; x2++) //Cчитаем все возможные комбинации прямоугольников по координате x
		{
			sumHor += 1;
		}
	}
	for (int y1 = 0; y1 < M; y1++)
	{
		for (int y2 = y1; y2 < M; y2++) //Считаем все возможные комбинации прямоугольников по координате y
		{
			sumVert += 1;
		}
	}
	cout << sumVert * sumHor;


	//Задание 4
	int N;
	cin >> N;
	if (N > 54 or N < 0) {
		cout << "Неверный ввод";
		return 0;
	}

	vector<int> kupe;
	vector<int> side;
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		int j;
		cin >> j;
		if (j < 37) {
			kupe.push_back(j);
		}
		else {
			side.push_back(j);
		}
	}


	sort(kupe.begin(), kupe.end());
	sort(side.begin(), side.end(), [](const int& a, const int& b) {return a > b; });

	if (kupe.size() < 4 or side.size() < 2) 
	{
		cout << 0;			
		return 0;
	}


	vector<int> freeKupe;
	for (int i = 0; i < kupe.size() - 3; i++)
	{
		int el = kupe[i];
		if ((el - 1) % 4 == 0 and el != 3 and (kupe[i + 3] - el) == 3) 
		{
			switch (el) 
			{
				case 1: 
					freeKupe.push_back(1);
					break;
				default:
					freeKupe.push_back(el / 4 + 1);
			}
		}
	}

	vector<int> freeSide;
	for (int i = 0; i < side.size()-1; i++)
	{
		if (side[i] % 2 == 0 and side[i] - side[i + 1] == 1) 
		{
			freeSide.push_back(28 - side[i]/2);
		}
	} 

	int out = 0;
	int out_max = 0;
	for (int i = 0; i < freeKupe.size(); i++)
	{
		for (int j = 0; j < freeSide.size(); j++)
		{
			int kupI = freeKupe[i];
			int sideJ = freeSide[j];
			if (out == 0 and kupI == sideJ)
			{
				out += 1;
				out_max = max(out, out_max);
				break;
			}

			if (out != 0 and kupI == sideJ and kupI - freeKupe[i - 1] == 1)
			{
				out += 1;
				out_max = max(out, out_max);
				break;
			}

			if (sideJ > kupI)
			{
				out = 0;
				break;
			}
		}
	}

	cout << "Вывод: " << out_max;


	//Задание 5
	int K, N;
	cout << "Значение N и K: " << endl;
	cin >> N >> K;
	if (!(1 <= K and K <= N and N <= pow(10, 18))) {
		return 0;
	}

	
	vector<int> mesta;
	for (int i = 0; i < N + 2; i++)
	{
		mesta.push_back(i); //Записываем номера мест
	}
	mesta[N + 1] = 0; //Боковые места заняты -> Пометим их нулями 

	for (int i = 0; i < K; i++)
	{
		vector<int> zero_pairs = findZeros(mesta);
		int *mestaInfo = findIndexes(zero_pairs);
		int indLeftZero = mestaInfo[0];
		int indRightZero = mestaInfo[1];
		int place_zan = (indLeftZero + indRightZero) / 2;
		mesta[place_zan] = 0;
		if (i + 1 == K)
		{
			cout << "Мест слева: " << findPlaceAmount(mesta, N, place_zan-1, 0) << endl;
			cout << "Мест справа: " << findPlaceAmount(mesta, N, place_zan+1, 1);
		}
	} 
}

	