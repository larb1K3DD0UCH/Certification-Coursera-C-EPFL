#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de dÃ©but de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

/*****************************************************
   * Compléter le code à  partir d'ici
   *****************************************************/
int duree=fin-debut;
int tarif=0;
if((debut<0 or debut>24) and (fin<0 or fin>24)){
    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
}
else if(duree==0){
    cout << "Bizarre, vous n’avez pas loue votre velo bien longtemps !" << endl;
}
else if(duree<0){
    cout << "Bizarre, le debut de la location est après la fin ..." << endl;
    return 0;
}

else {
if(fin<7 ){
    tarif=1;
    cout << "Vous avez loue votre velo pendant" << endl;
    cout <<duree<<"heure(s) au tarif horaire de " <<tarif <<" franc(s)" << endl;
    cout << "Le montant total à  payer est de "<< duree<<" franc(s)." << endl;
}

if(fin<17 && fin>=7){
if(debut>=7){
    tarif=2;
    cout << "Vous avez loue votre velo pendant" << endl;
    cout <<duree<<" heure(s) au tarif horaire de " <<tarif <<" franc(s)" << endl;
    cout << "Le montant total à  payer est de "<< duree*tarif<<" franc(s)." << endl;
}
else if(debut<7){
    tarif=1;
    cout << "Vous avez loue votre velo pendant" << endl;
    cout <<7-debut<<" heure(s) au tarif horaire de " <<tarif <<" franc(s)" << endl;
    cout <<fin-7<<" heure(s) au tarif horaire de " <<tarif*2 <<" franc(s)" << endl;
    cout << "Le montant total à  payer est de "<< 7-debut + (fin-7)*2<<" franc(s)." << endl;
}
}
if(fin<=24 && fin>=17){
if(debut>=17){
    tarif=1;
    cout << "Vous avez loue votre velo pendant" << endl;
    cout <<duree<<" heure(s) au tarif horaire de " <<tarif <<" franc(s)" << endl;
    cout << "Le montant total à  payer est de "<< duree*tarif<<" franc(s)." << endl;
}
else if(debut<7){
    tarif=1;
    cout << "Vous avez loue votre velo pendant" << endl;
    cout <<7-debut+fin-17<<" heure(s) au tarif horaire de " <<tarif <<" franc(s)" << endl;
    cout <<" 10 heure(s) au tarif horaire de " <<tarif*2 <<" franc(s)" << endl;
    cout << "Le montant total à  payer est de "<< 7-debut+fin-17+20<<" franc(s)." << endl;
}
else if(debut>=7 && debut<17){
    tarif=1;
    cout << "Vous avez loue votre velo pendant" << endl;
    cout <<17-debut<<" heure(s) au tarif horaire de " <<tarif*2 <<" franc(s)" << endl;
    cout <<fin-17<<" heure(s) au tarif horaire de " <<tarif <<" franc(s)" << endl;
    cout << "Le montant total à  payer est de "<< 2*(17-debut)+fin-17<<" franc(s)." << endl;
}}} 

  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

  return 0;
}
