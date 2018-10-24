#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // RÃ©duire le format d'affichage
  cout << setprecision(4);

  // ParamÃ¨tres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * ComplÃ©ter le code Ã  partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales
  do{
  cout << "Combien de renards au dÃ©part (>= 2) ? ";
  cin >>renards_i;
  }while(renards_i<2);
  
  do{
  cout << "Combien de lapins au dÃ©part  (>= 5) ? ";  
  cin >>lapins_i;
  }while(lapins_i<5);

  // ===== PARTIE 2 =====
  // PremiÃ¨re simulation
  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
  double pop_lapins(lapins_i);
  double pop_renards(renards_i);

for(int i=1;i<=duree;i++){
double nb_renards(pop_renards);
double nb_lapins(pop_lapins);
pop_lapins=(1.0 + taux_croissance_lapins - taux_attaque * nb_renards )*pop_lapins;
pop_renards=(1.0 + taux_attaque * nb_lapins * taux_croissance_renards
- taux_mortalite)*pop_renards;
cout << "Après "<< i<<" mois, il y a "<< pop_lapins <<" lapins et "<< pop_renards<< "renards"<<endl;

}


  // ===== PARTIE 3 =====
  // Variation du taux d'attaque
  cout << endl;
int cpt=0;
for(int i=1;i<=duree;i++){
double nb_renards(pop_renards);
double nb_lapins(pop_lapins);
pop_lapins=(1.0 + taux_croissance_lapins - taux_attaque * nb_renards )*pop_lapins;
pop_renards=(1.0 + taux_attaque * nb_lapins * taux_croissance_renards
- taux_mortalite)*pop_renards;
cpt++;
}
cout << "Après "<< cpt<<" mois, il y a "<< pop_lapins <<" lapins et "<< pop_renards<< "renards"<<endl;
/*
  cout << "taux d'attaque au dÃ©part en % (entre 0.5 et 6) ? ";

  cout << "taux d'attaque Ã  la fin  en % (entre ";
  cout << " et 6) ? ";

  cout << "Les renards ont Ã©tÃ© en voie d'extinction" << endl;
  cout << "mais la population est remontÃ©e ! Ouf !" << endl;
  cout << "et les renards ont disparu :-(" << endl;
  cout << "Les lapins ont Ã©tÃ© en voie d'extinction" << endl;
  cout << "mais la population est remontÃ©e ! Ouf !" << endl;
  cout << "et les lapins ont disparu :-(" << endl;
  cout << "Les lapins et les renards ont des populations stables." << endl;

  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

  return 0;
}
