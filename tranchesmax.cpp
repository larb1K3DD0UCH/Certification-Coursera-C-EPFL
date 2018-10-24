#include <iostream>
#include <vector>

using namespace std;

int somme_consecutifs_max(vector<int> ligne) {
	int somme(0), max(0);
	for (auto elem : ligne) {
		if (elem != 0) {
			somme += elem;
			if (somme > max)
				max = somme;
		} else {
			somme = 0;
		}
	}
	return max;
}

vector<size_t> lignes_max(vector<vector<int>> tableau) {
	
	vector<size_t> res;
	vector<int> sommes;
	int max(0);
	
	for (auto ligne : tableau) {
		int somme = somme_consecutifs_max(ligne);
		if (somme > max)
			max = somme;
		sommes.push_back(somme);
	}
	
	for (size_t i = 0; i < sommes.size(); i++) {
		if (sommes[i] == max)
			res.push_back(i);
	}
	
	return res;
}

vector<vector<int>> tranches_max(vector<vector<int>> tableau) {
	
	vector<vector<int>> res;
	vector<size_t> lignes = lignes_max(tableau);
	
	for (size_t i = 0; i < lignes.size(); i++) {
		res.push_back(tableau[lignes[i]]);
	}
	
	return res;
}


int main()
{
	cout << somme_consecutifs_max({ 0, 2, 2, 0 }) << endl;
	cout << somme_consecutifs_max({ 2, 3, 0, 0, 4 }) << endl;
	cout << somme_consecutifs_max({ 4, 0, 2, 3 }) << endl;
	cout << somme_consecutifs_max({ 0, 0, 0, 0, 0 }) << endl;
	cout << endl;

	vector<vector<int>> tableau = {
		{2, 1, 0, 2},
		{0, 1, 0, 3},
		{1, 3, 0, 0},
		{0, 2, 2, 0}
	};
	vector<size_t> resultant = lignes_max(tableau);
	
	bool acc = false;
	cout << "{";
	for (auto element : resultant) {
		if (acc)
			cout << ", ";
		else
			acc = true;
		cout << element;
	}
	cout << "}" << endl;
	cout << endl;

	tableau = {
		{2, 1, 0, 2, 0, 3, 2},
		{0, 1, 0, 7, 0},
		{1, 0, 1, 3, 2, 0, 3, 0, 4},
		{5, 0, 5},
		{1, 1, 1, 1, 1, 1, 1}
	};
	
	vector<vector<int>> res = tranches_max(tableau);
	for (auto ligne : res) {
		acc = false;
		cout << "{";
		for (auto element : ligne) {
			if (acc)
				cout << ", ";
			else
				acc = true;
			cout << element;
		}
		cout << "}" << endl;
	}
	cout << endl;
	
	return 0;
}

