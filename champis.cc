#include <iostream>
using namespace std;

int main()
{
	cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle," << endl
	<< "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;
  
	cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
	int chapeau(0);
	cin >> chapeau;
	int reponse(0);
	if (chapeau!=0) {
		cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
		int anneau(0);
		cin >> anneau;
		if (anneau!=0) {
			cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
			int foret(0);
			cin >> foret;
			if (foret!=0) {
				reponse = 1;
			} else {
				reponse = 2;
			}
		} else {
			reponse = 3;
		}
	} else {
		cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
		int foret(0);
		cin >> foret;
		if (foret!=0) {
			cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
			int lamelles(0);
			cin >> lamelles;
			if (lamelles!=0) {
				reponse = 4;
			} else {
				reponse = 5;
			}
		} else {
			reponse = 6;
		}
	}

	cout << "==> Le champignon auquel vous pensez est ";
	switch (reponse) {
		case 1 : cout << "l'amanite tue-mouches";
		break;
		case 2 : cout << "l'agaric jaunissant";
		break;
		case 3 : cout << "le pied bleu";
		break;
		case 4 : cout << "la girolle";
		break;
		case 5 : cout << "le cèpe de Bordeaux";
		break;
		case 6 : cout << "le coprin chevelu";
		break;
		default : cout << "Bien joue !";
		break;
	}

return 0;
}
