#include <iostream>
using namespace std;

int demander_annee()
{
	int a(0);
	do {
		cout << "Entrez une annee (1583-4000) : ";
		cin >> a;
	} while (a < 1583 || a > 4000);
	return a;
}

void affiche_date(int annee, int jours)
{
	cout << "Date de Paques en " << annee << " : ";
	if (jours <= 31)
		cout << jours << " mars";
	else
		cout << (jours - 31) << " avril";
	cout << endl;
}

int date_Paques(int annee)
{
	
	// le siècle. Il suffit de diviser l’année par 100
	const int siecle(annee / 100);

	// une valeur p qui vaut 13 plus 8 fois le siècle, le tout divisé par 25
	const int p((13 + 8 * siecle) / 25);
 
	// une valeur q, division du siècle par 4
	const int q(siecle / 4);
	
	// une valeur M valant 15 - p + siecle - q modulo 30
	const int M(15 - p + siecle - q % 30);
	
	// une valeur N valant 4 + siecle - q modulo 7
	const int N(4 + siecle - q % 7);
	
	// une valeur d qui vaut M plus 19 fois « l’année modulo 19 », le tout modulo 30
	const int d((M + 19 * (annee % 19)) % 30);
	
	// une valeur e qu’il serait trop compliqué de décrire en français
	const int e((2 * (annee % 4) + 4 * (annee % 7) + 6 * d + N) % 7);
	
	// le jour (ou presque, voir ci-dessous) : e plus d plus 22
	int jour(e + d + 22);
	
	// la valeur du jour doit cependant encore être corrigée
	if (e == 6 && (d == 29 || (d == 28 && (11 * (M + 1)) % 30 < 19)))
		jour -= 7;

	return jour;
}

int main()
{
	
	int annee(demander_annee());
	int jours(date_Paques(annee));
	affiche_date(annee, jours);
	
	return 0;
}
