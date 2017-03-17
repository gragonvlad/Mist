
//Ouverture simple d'un fchier en Binaire
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
  char ch;

  ifstream in("logo.png", ios::in | ios::binary);
  if(!in) {
    cout << "Cannot open file.";
    return 1;
  }else{
    cout << "File open with success"<<endl;
  }

  while(in) { // in will be false when eof is reached
    in.get(ch);
    if(in) cout << ch;
  }

  return 0;
}



/*
// Append sur un fichier Binaire on a 2 fichier ici, l'un ki vien s'ajouter a la suite de l'autre
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ofstream outFile("FileWrite.out");

  if (outFile.fail()) {
    cerr << "Unable to open file for writing." << endl;
    exit(1);
  }

  outFile << "Hello!" << endl;
  outFile.close();

  ofstream appendFile("FileWrite.out", ios_base::app);
  if (appendFile.fail()) {
    cerr << "Unable to open file for writing." << endl;
    exit(1);
  }

  appendFile << "Append!" << endl;
  appendFile.close();
}
*/


/*
// Ecris en binaire dans un fichier (Write)
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct inventory {
  char item[20];
  int quantity;
  double cost;
};

int main()
{
  ofstream fout("logo.png", ios::out | ios::binary);

  if(!fout) {
    cout << "Cannot open file.\n";
    return 1;
  }

  inventory inv[3];

  strcpy(inv[0].item,"A");
  inv[0].quantity = 3;
  inv[0].cost = 9.99;

  strcpy(inv[1].item, "B");
  inv[1].quantity = 12;
  inv[1].cost = 7.85;

  strcpy(inv[2].item, "C");
  inv[2].quantity = 19;
  inv[2].cost = 2.75;

  for(int i=0; i<3; i++)
    fout.write((const char *) &inv[i], sizeof(inventory));

  fout.close();

  if(!fout.good()) {
    cout << "A file error occurred.";
    return 1;
  }

  return 0;
}
*/

/*
// Lis parfaitement le fichier et les detaisl de celui ci (utilise Read)
#include <iostream>
#include <fstream>

using namespace std;

struct inventory {
  char item[20];
  int quantity;
  double cost;
};

int main()
{
  ifstream fin("logo.png", ios::in | ios::binary);

  if(!fin) {
    cout << "Cannot open file.\n";
    return 1;
  }
  inventory inv[3];

  for(int i=0; i<3; i++)
    fin.read((char *) &inv[i], sizeof(inventory));

  fin.close();

  if(!fin.good()) {
    cout << "A file error occurred.\n";
    return 1;
  }

  for(int i=0; i < 3; i++) {
    cout << " De type: '" << inv[i].item << "'\n";
    cout << " Quantity on hand: " << inv[i].quantity;
    cout << "\n Cost: " << inv[i].cost << "\n\n";
  }

  return 0;
}
*/


/*
//Ouvrir un fichier en Binaire et le formater en Hexa
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[]){

   ifstream in("logo.png", ios::in | ios::binary);
   if(!in){
      cout << "Ouverture Impossible du fichier." << endl;
      return 0;
   }

   int i, j;
   int count = 0;
   char c[16];

   cout.setf(ios::uppercase);
   while(!in.eof()){
      for(i=0; i<16 && !in.eof(); i++)
         in.get(c[i]);

      if(i<16)
         i--;

      for(j=0; j < i; j++)
         cout << setw(3) << hex << (int) c[j];
      for(; j < 16; j++)
         cout << "  ";

         cout << endl;

      for(j=0; j < i; j++)
         if(isprint(c[j]))
            cout << c[j];
         else
            cout << ".";

      cout << endl;
      count ++;
      if(count==16){
         count = 0;
         cout << "Press ENTER to continue: ";
         cin.get();
         cout << endl;
       }
    }
    in.close();
}
*/
