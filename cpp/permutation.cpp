// permutationII.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

void swap(std::vector<int> &arr, int m, int n)
{	
	int tmp = arr[m];
	arr[m] = arr[n];
	arr[n] = tmp;
}

#include <unordered_map>

void permDup(std::vector<std::vector<int>> &res, std::vector<int>& arr, int pos)
{
	if (pos == arr.size())
	{
		res.push_back(arr);
		return;
	}

	std::unordered_map<int, bool> used;

	for (int i = pos; i < arr.size(); ++i)
	{
		if (used.find(arr[i]) == used.end())
		{
			used.insert(std::unordered_map<int, bool>::value_type(arr[i], true));
			swap(arr, i, pos);
			permDup(res, arr, pos + 1);
			swap (arr, i, pos);
		}
	}
}

void permNonDup(std::vector<std::vector<int>> &res, std::vector<int>& arr, int pos)
{
	if (pos == arr.size())
	{
		res.push_back(arr);
		return;
	}

	int size = arr.size();
	for (int i = pos; i < size; ++i)
	{
		swap(arr, pos, i);
		permNonDup(res, arr, pos + 1);
		swap(arr, pos, i);
	}
}

void dumpOnePerm(std::vector<int>& per)
{	
	std::cout << "Permutation: ";
	int size = per.size();

	for (int i = 0; i < size; ++i)
	{
		std::cout << per[i] << ", ";
	}

	std::cout << std::endl;
	
}

int _tmain(int argc, _TCHAR* argv[])
{

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::vector<std::vector<int>> result;
	permNonDup(result, vec, 0);

	int numOfPerm = result.size();
	for (int i = 0; i < numOfPerm; ++i)
	{
		dumpOnePerm(result[i]);
	}

	std::cout << "***************" << std::endl;
	std::vector<std::vector<int>> resDup;
	std::vector<int> dupVec;
	dupVec.push_back(1);
	dupVec.push_back(1);
	dupVec.push_back(3);

	permDup(resDup, dupVec, 0);
	numOfPerm = resDup.size();
	for (int i = 0; i < numOfPerm; ++i)
	{
		dumpOnePerm(resDup[i]);
	}

	if (result == resDup)
		std::cout << "The two permutation results are same!" << std::endl;
	else
		std::cout << "The two permutation resutls are not same." << std::endl;



	return 0;
}

