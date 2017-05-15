// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int dfs(int daVez, vector<vector<int> > &adj, bool visitado[], int ages[], int min_age){
	cout << daVez << endl;
	for(int i = 0; i < (int) adj[daVez].size(); i++){
		min_age = min(ages[daVez], ages[adj[daVez][i]]);
		if(!visitado[adj[daVez][i]]){
			visitado[adj[daVez][i]] = true;
			dfs(adj[daVez][i], adj, visitado, ages, min_age);
		}
	}

	return min_age;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n_empregado, n_relacao, n_instrucao;
	while(cin >> n_empregado >> n_relacao >> n_instrucao){
		vector< vector<int> > adj(n_empregado + 1);
		int * ages = new int[n_empregado+1];
		for(int name = 1; name <= n_empregado; name++){
			int age;
			cin >> age;
			ages[name] = age;
		}

		for(int i = 0; i < n_relacao; i++){
			int a, b;
			cin >> a >> b;
			adj[b].push_back(a);
		}

		for(int i = 0; i < n_instrucao; i++){
			char opr; int name1, name2;
			cin >> opr;
			if(opr == 'T'){
				cin >> name1 >> name2;
				vector<int> aux;
				for(int j = 0; j < (int) adj[name1].size(); j++)
					aux.push_back(adj[name1][j]);
				adj[name1] = adj[name2];
				adj[name2] = aux;
			} else {
				bool * visitado = new bool[n_empregado+1];
				memset(visitado, false, sizeof(bool) * (n_empregado + 1));
				int name, min_idade;
				cin >> name;
				min_idade = dfs(name, adj, visitado, ages, -1);
				if(min_idade == -1)
					cout << "*" << endl;
				else
					cout << min_idade << endl;
			}
		}
		system("PAUSE");
	}
	return 0;
}

