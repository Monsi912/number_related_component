#include <vector>
#include<iostream>
#include<utility>
#include <string>
#include <ios>
#include <tuple>

#include "compConexas.h"


using namespace std;
#define range pair<int, int>

int unionByRank2(int n, int m) {
	unionfind disjoinset;
	int res = 0;

	int indice = 0;
	bool tengoJefe = false;
	vector<int> filaActual;

	for (int i = 0; i < n; i++)
	{
		string l;
		cin >> l;
		filaActual.push_back(stoi(l));
	}

	for (int i = 0; i < n; i++)
	{
		if (filaActual[i]) {
			if (!tengoJefe) {
				indice = i;
				tengoJefe = true;
			}
			disjoinset.nodos.push_back(indice);
			if (i > 0 && disjoinset.nodos[i - 1] != -1) {
				disjoinset.rank[i - 1] = 1;
				disjoinset.rank.push_back(1);
			}
			else {
				disjoinset.rank.push_back(0);
			}
		}
		else {
			disjoinset.nodos.push_back(-1);
			disjoinset.rank.push_back(-1);
			tengoJefe = false;
		}
	}
	for (int i = 0; i < n; i++)
	{
		disjoinset.nodos.push_back(-1);
		disjoinset.rank.push_back(-1);
	}

	for (int i = 1; i < m; i++) //ciclo principal
	{
		tengoJefe = false;

		for (int j = 0; j < n; j++)
		{
			string l;
			cin >> l;
			filaActual[j] = stoi(l);
		}


		for (int j = 0; j < n; j++)     //[Elementos viejos...Elementos nuevos]
		{

			if (filaActual[j]) {
				if (!tengoJefe) {
					indice = n + j;
					tengoJefe = true;
				}
				disjoinset.nodos[n + j] = indice;
				if (n + j > 0 && disjoinset.nodos[n + j - 1] != -1) {
					disjoinset.rank[n + j - 1] = 1;
					disjoinset.rank[n + j] = 1;
				}
				else {
					disjoinset.rank[n + j] = 0;
				}
			}
			else {
				disjoinset.nodos[n + j] = -1;
				disjoinset.rank[n + j] = -1;
				tengoJefe = false;
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (disjoinset.nodos[n + j] != -1) {
				if (disjoinset.nodos[j] != -1) {
					disjoinset.unite(j, n + j);
				}

			}
		}

		for (int j = 0; j < n; j++)
		{
			if (disjoinset.nodos[n + j] != -1) {
				if (disjoinset.find(n + j) < n)
				{
					disjoinset.rank[n + j] = disjoinset.rank[disjoinset.find(n + j)];
					disjoinset.nodos[disjoinset.find(n + j)] = n + j;
					disjoinset.nodos[n + j] = n + j;
				}
			}
		}
		bool limpio = true;
		for (int j = 0; j < n; j++)
		{
			if (disjoinset.find(j) == j && limpio && disjoinset.nodos[j] != -1) {
				limpio = false;
				res++;
			}
			else if (disjoinset.nodos[j] == -1) {
				limpio = true;
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (disjoinset.find(n + j) == -1) {
				disjoinset.nodos[j] = -1;
				disjoinset.rank[j] = -1;
				continue;
			}
			disjoinset.nodos[j] = disjoinset.find(n + j) - n;
			disjoinset.rank[j] = disjoinset.rank[n + j];

		}

	}
	for (int i = 0; i < n; i++)
	{
		if (disjoinset.find(i) == i) {
			res++;
		}
	}
	return res;
}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	int m;
	cin >> n;
	cin >> m;
	cout << unionByRank2(m, n) << endl;

}