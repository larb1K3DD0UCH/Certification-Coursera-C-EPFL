#include <iostream>
using namespace std;

char code(char c, int number);
char decale(char c, char debut, int decalage);
string code(string chaine, int decalage);
string decode(string chaine, int decalage);


int main()
{
cout << code("Fuyez manants", 4) << endl;
cout << code("Fuyez manants", 6) << endl;
cout << code("Fuyez manants", -4) << endl;
cout << code("Avez-vous vu mes 3 chats et mes 2 chiens ?", 4) << endl;
cout << endl;
	
	
cout << decode("Jycid qererxw", 4) << endl;
cout << decode("Laekf sgtgtzy", 6) << endl;
cout << decode("Bquav iwjwjpo", -4) << endl;
cout << decode("Ezid-zsyw zy qiw 3 glexw ix qiw 2 glmirw ?", 4) << endl;

return 0;
}

char code(char c, int number){
if(c>='a' && c<='z'){
return decale(c,'a',number);
}
else if(c>='A' && c<='Z'){
return decale(c,'A',number);
}
else return c;

}

char decale(char c, char debut, int decalage){
while(decalage<0){
decalage=decalage+26;
}
char res;
res=debut+(((c-debut)+decalage)%26);
return res;
}

string code(string chaine, int decalage){
for(size_t i=0;i<chaine.size();i++) chaine[i]=code(chaine[i],decalage);
return chaine;
}

string decode(string chaine, int decalage){
return code(chaine,-decalage);
}
