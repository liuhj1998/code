// dfsMinPath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include <vector>

const int MATRIX_VAL_MAX = 100;

int** generateMatrix(int m, int n)
{
	int** tmpMatrix = new int*[m];
	for (int i = 0; i < m; ++i)
	{
		tmpMatrix[i] = new int[n];
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			tmpMatrix[i][j] = rand() % MATRIX_VAL_MAX;
		}
	}

	return tmpMatrix;
}

void printOutMatrix(int** matrix, int m, int n)
{
	for (int i = 0; i < m; ++i)
	{
		std::cout << std::endl;
		for (int j = 0; j < n; ++j)
		{
			std::cout << std::setw(4) << matrix[i][j] << ",";
		}
	}

	std::cout << std::endl << std::endl;
}

std::vector<int> minSumPath;
int minPathSum = INT_MAX;		

const int rows = 2;
const int cols = 2;
int totalFuncCalls = 0;

void dfsMinSumPath(int** matrix, int row, std::vector<int>& path, int sum)
{
	//std::cout << "row: " << row << std::endl;
	totalFuncCalls++;

	std::cout << "LHJ address is " << &path << std::endl;

	if (row == rows)
	{
		if (sum < minPathSum)
		{
			minPathSum = sum;
			minSumPath = path;
		}
		
		std::cout << "One complelte path with sum " << std::setw(6) << sum << ", is: ";
		for (std::vector<int>::iterator it = path.begin(); it != path.end(); ++it)
		{
			std::cout << std::setw(4) << *it << ", ";
		}
		std::cout << std::endl;
		return;
	}

	for (int j = 0; j < cols; ++j)
	{
		path.push_back(matrix[row][j]);
		dfsMinSumPath(matrix, row+1, path, sum + matrix[row][j]);
		path.pop_back();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int** matrix = generateMatrix(rows, cols);
	printOutMatrix(matrix, rows, cols);
	std::vector<int> tmpPath;

	dfsMinSumPath(matrix, 0, tmpPath, 0);
	std::cout << "The min path sum is: " << minPathSum << std::endl;
	std::cout << "The min sum path is: ";
	for (int i = 0; i < minSumPath.size(); ++i)
		std:: cout << minSumPath[i] << ", ";

	std::cout << std::endl << "Total func calls: " << totalFuncCalls << std::endl;
	std::cout << std::endl;

	return 0;
}

