#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
	struct Position {
		int i;
		int j;
	};
	typedef vector <vector <int> > Carte;
	bool binaire(Carte const& carte);
	void affiche(Carte const& carte);
	bool verifie_et_modifie(Carte& carte);
	double longueur_cloture(Carte const& carte, double echelle = 2.5);
	void ajoute_unique(vector<int>& ensemble, int valeur);
	bool convexite_lignes(Carte& carte, vector<int> const& labels_bords);
	bool convexite_lignes(Carte& carte);
	void marque_composantes(Carte& carte);
	void testEau(Carte& carte, Position pos, int composante, vector<Position>& eau);
	
	bool binaire(Carte const& carte) {
		for(size_t i(0); i<carte.size(); ++i) {
			for(size_t j(0); j<carte[i].size(); ++j) {
				if(carte[i][j]!=0 && carte[i][j]!=1) {
					return false;
				}
			}
		}
		return true;
	}
	
	void affiche(Carte const& carte) {
		for(size_t i(0); i<carte.size(); ++i) {
			for(size_t j(0); j<carte[i].size(); ++j) {
				cout << carte[i][j];
			}
			cout << endl;
		}
		cout << "----" << endl;
	}
	
	bool verifie_et_modifie(Carte& carte) {
		if(0==1) {
			affiche(carte);
		}
		if(!binaire(carte)) {
			cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
			return false;
		}
		if (!convexite_lignes(carte)) {
			return false;
		}
		size_t hauteur(carte.size());
		size_t largeur(carte[0].size());
		for(size_t i(1); i<hauteur; ++i) {
			for(size_t j(1); j<largeur; ++j) {
				vector<vector<bool> > etang(hauteur, vector<bool>(largeur));
				for(size_t b1(0); b1<etang.size(); ++b1) {
					for(size_t b2(0); b2<etang[b1].size(); ++b2) {
						etang[b1][b2]=false;
					}
				}
				bool bord(false);
				if(carte[i][j]!=1 && carte[i-1][j]==1 && carte[i][j-1]==1) {
					size_t m(i);
					size_t n(j);
					do{
						do{
							etang[m][n]=true;
							++n;
						}while(n<largeur && carte[m][n]!=1);
						if(n==largeur) {
							bord = true;
						}
						n=j;
						++m;
						if(m==hauteur) {
							bord = true;
						}
					}while(m<hauteur && carte[m][n]!=1 && !bord);
				}
				if(!bord) {
					for(size_t k(0); k<etang.size(); ++k) {
						for(size_t l(0); l<etang[k].size(); ++l) {
							if(etang[k][l]) {
								carte[k][l] = 1;
							}
						}
					}
				}
			}
		}
		return true;
	}
	
	double longueur_cloture(Carte const& carte, double echelle) {
		double perimetre(0);
        vector<int> coteOuest(carte.size());
        vector<int> coteEst(carte.size());
        vector<int> terre(carte.size());
        for(size_t i(0); i<carte.size(); ++i) {
        	size_t y(0);
			int z(0);
        	while (y<carte[i].size() && carte[i][y]!=1) {
        		++y;
        	}
        	coteOuest[i]=y;
        	z=carte[i].size()-1;
        	while (z>=0 && carte[i][z]!=1) {
        		--z;
        	}
        	coteEst[i]=z+1;
        	terre[i]=z+1-y;
        	if (terre[i]>0) {
        		perimetre += (2*echelle);
        		if(i>0) {
					int a(coteOuest[i]-coteOuest[i-1]);
					int b(coteEst[i]-coteEst[i-1]);
					if(a<0) {
						a *= -1;
					}
					if(b<0) {
						b *= -1;
					}
        			 perimetre += a*echelle + b*echelle;
        		}
        	}
        }
        perimetre += terre[0]*echelle + terre[terre.size()-1]*echelle;
        return perimetre;
	}
	
	void ajoute_unique(vector<int>& ensemble, int valeur) {
		bool trouve(false);
		size_t i(0);
		while(i<ensemble.size() && !trouve) {
			if(ensemble[i]==valeur) {
				trouve = true;
			}
			++i;
		}
		if(!trouve) {
			ensemble.push_back(valeur);
		}
	}

	bool convexite_lignes(Carte& carte, vector<int> const& labels_bords) {
		for(size_t i(1); i<carte.size(); ++i) {
			for(size_t j(1); j<carte[i].size()-1; ++j) {
				if(carte[i][j]!=1 && carte[i][j-1]==1) {
					int tmp(j);
					do{
						if(carte[i][j]!=1 && carte[i][j+1]==1) {
							size_t k(0);
							while(k<labels_bords.size() && carte[i][j]!=labels_bords[k]) {
								 ++k;
							}
							if(k<labels_bords.size() && carte[i][j]==labels_bords[k]) {
								cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
								cout << "bord extérieur entrant trouvé en position [";
								cout << i;
								cout << "][";
								cout << tmp;
								cout << "]" << endl;
								return false;
							}
						}
						++j;
					}while(j<carte[i].size()-1);
				}
			}
		}
		return true;
	}

	bool convexite_lignes(Carte& carte) {
		marque_composantes(carte);
		vector<int> test;
		for(size_t i(0); i<carte[0].size(); ++i) {
			if(carte[0][i]!=1) {
				ajoute_unique(test,carte[0][i]);
			}
			if(carte[carte.size()-1][i]!=1) {
				ajoute_unique(test,carte[carte.size()-1][i]);
			}
		}
		for(size_t i(0); i<carte.size(); ++i) {
			if(carte[i][0]!=1) {
				ajoute_unique(test,carte[i][0]);
			}
			if(carte[i][carte[i].size()-1]!=1) {
				ajoute_unique(test,carte[i][carte[i].size()-1]);
			}
		}
		return (convexite_lignes(carte,test));
	}

	void marque_composantes(Carte& carte) {
		vector<Position> eau;
		int composante(1);
		for(size_t i(0); i<carte.size(); ++i) {
			for(size_t j(0); j<carte[i].size(); ++j) {
				if(carte[i][j]==0) {
					int m(i);
					int n(j);
					Position p = {m,n};
					eau.push_back(p);
					testEau(carte,p,++composante,eau);
				}
			}
		}
	}
	
	void testEau(Carte& carte, Position pos, int composante, vector<Position>& eau) {
		if(carte[pos.i][pos.j]==0) {
			carte[pos.i][pos.j]=composante;
			if(pos.i>=1 && carte[(pos.i)-1][pos.j]==0) {
				Position p = { (pos.i)-1,(pos.j) };
				eau.push_back(p);
				testEau(carte,p,composante,eau);
			}
			if(pos.j>=1 && carte[pos.i][(pos.j)-1]==0) {
				Position p = { (pos.i),(pos.j)-1 };
				eau.push_back(p);
				testEau(carte,p,composante,eau);
			}
			if(pos.i<carte.size()-1 && carte[(pos.i)+1][pos.j]==0) {
				Position p = { (pos.i)+1,(pos.j) };
				eau.push_back(p);
				testEau(carte,p,composante,eau);
			}
			if(pos.j<carte[0].size()-1 && carte[pos.i][(pos.j)+1]==0) {
				Position p = { (pos.i),(pos.j)+1 };
				eau.push_back(p);
				testEau(carte,p,composante,eau);
			}
		}
	}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  if (verifie_et_modifie(carte)) {
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
