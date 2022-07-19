#include <vector>
#include<iostream>
#include<utility>
#include <string>
#include <tuple>
#include<chrono>
#include "compConexas.h"

using namespace std;

using namespace std::chrono;


int unionfind::find(int x) {
	if (x == -1) {
		return -1;
	}
	if (nodos[x] != x) {
		nodos[x] = find(nodos[x]);
	}
	return nodos[x];
}

void unionfind::unite(int x, int y) {
	link(find(x), find(y));
}

void unionfind::link(int x, int y) {
	if (x == y) {
		return;
	}
	if (rank[x] > rank[y]) {
		nodos[y] = x;
	}
	else {
		nodos[x] = y;
		if (rank[x] == rank[y])
		{
			rank[y]++;
		}
	}
}
