#include <iostream>
using namespace std;
 
int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}
 
/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
 
void ajouter_chiffre_droit(int& nombre, int chiffre)
{
        nombre = 10* nombre;
        nombre = nombre + chiffre;
}
 
void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
        ajouter_chiffre_droit(nombre, repetitions_chiffre);
        ajouter_chiffre_droit(nombre, chiffre);
}
 
int lire_et_dire(int nombre)
{
        int n(0);
        int reps(1);
        int temp1(nombre);
        int temp2(0);
        int temp3(0);
        int temp4(0);
       
        do {
                temp2 = separer_chiffre_gauche(nombre);
                temp3 = temp2;
                temp4 = temp3;
                n++;
                } while (nombre >= 0);
                if (temp2 == nombre){
                        reps++;
                        } else {
                                dire_chiffre(nombre, reps, temp2);
                                reps = 1;
                                }
               
               
               
}
 
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
 
void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}
 
int main()
{
  int nombre;
  int fois;
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
