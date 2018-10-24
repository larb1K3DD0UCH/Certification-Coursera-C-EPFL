#include <iostream>
using namespace std;

int main()
{
 int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
   int k=0;
   for(int x=debut;x<=fin;x++){
    k=0;
    int b=x;
    while(b!=0){
       if(b%3==0) b=b+4;
       else if(b%4==0) b=b/2;
       else b=b-1;
       k++;
   }
     cout << x <<" -> "<< k << endl;
   }

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
