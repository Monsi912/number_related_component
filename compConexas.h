#pragma once
#include <vector>
#include<iostream>
#include<utility>
#include <string>
#include <tuple>

#define range pair<int, int>

using namespace std;

class unionfind {
public:
	vector<int> nodos;
	vector<int> rank;

	int find(int x);
	void unite(int x, int y);
	void link(int x, int y);
};
