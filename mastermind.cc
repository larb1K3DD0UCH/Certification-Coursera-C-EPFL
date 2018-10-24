#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> 

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); 

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
bool verifier(char c1, char& c2, int& score);
void apparier(char c1, char& c2, char& c3, char& c4, char& c5, int& score);
bool gagne(char c1, char c2, char c3, char c4, char r1, char r2, char r3, char r4);
void jouer(int n=8);
// ======================================================================
bool couleur_valide(char c) {
	return (c=='.' || c=='R'|| c=='G'|| c=='B'|| c=='C'|| c=='Y'|| c=='M');
}

// ======================================================================
bool verifier(char c1, char& c2, int& score) {
	bool b(false);
	if(c1==c2) {
		++score;
		b=true;
		c2='x';
	}
	return b;
}

// ======================================================================
void apparier(char c1, char& c2, char& c3, char& c4, int& score) {
	bool b1(verifier(c1,c2,score));
	if(!b1) {
		bool b2(verifier(c1,c3,score));
		if(!b2) {
			verifier(c1,c4,score);
		}
	}
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4, char r1, char r2, char r3, char r4) {
	int bien(0);
	int mal(0);
	if(c1==r1) {
		++bien;
		r1='z';
	}
	if(c2==r2) {
		++bien;
		r2='z';
	}
	if(c3==r3) {
		++bien;
		r3='z';
	}
	if(c4==r4) {
		++bien;
		r4='z';
	}
	if(r1!='z') {
		apparier(c1,r2,r3,r4,mal);
	}
	if(r2!='z') {
		apparier(c2,r1,r3,r4,mal);
	}
	if(r3!='z') {
		apparier(c3,r1,r2,r4,mal);
	}
	if(r4!='z') {
		apparier(c4,r1,r2,r3,mal);
	}
	int faux(4-bien-mal);
	afficher(bien,'#');
	afficher(mal,'+');
	afficher(faux,'-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4, char r1, char r2, char r3, char r4) {
	return (c1==r1 && c2==r2 && c3==r3 && c4==r4);
}

// ======================================================================
void jouer(int n) {
	char a(tirer_couleur());
	char b(tirer_couleur());
	char c(tirer_couleur());
	char d(tirer_couleur());
	char c1('x');
	char c2('x');
	char c3('x');
	char c4('x');
	int m(0);
	do{
		c1=lire_couleur();
		c2=lire_couleur();
		c3=lire_couleur();
		c4=lire_couleur();
		afficher_coup(c1,c2,c3,c4,a,b,c,d);
		++m;
	}while(!gagne(c1,c2,c3,c4,a,b,c,d) && m<n);
	if(gagne(c1,c2,c3,c4,a,b,c,d)) {
			message_gagne(m);
		} else {
			message_perdu(a,b,c,d);
		}
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
