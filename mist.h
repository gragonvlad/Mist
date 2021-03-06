using namespace std;

// Prototypes des methodes pour Mist

//Pour la bienvenue
void welcome(){
    cout<<"\n\t\t   -----------------------------------------\n";
    cout<<"\t   -------------------- WelCome to MIST ---------------------\n";
    cout<<"\t\t   ------------------------by S@n1X D4rk3r--\n\n";
}

//Pour la menu
void menu(){
    cout<<"\nMist Help-Menu:\n--------------------------------------------------------------------\n";
    cout<<" [m files] My Files on Mist\n";
    cout<<" [m space] Storage and space level in the network\n";
    cout<<" [m space me] My Storage and space level in the network\n";
    cout<<" [m upload]\n";
    cout<<" [m ?] About Mist\n";
    cout<<" [m ? me] About my Mist\n";
    cout<<" [m conf] Configurations\n";
    cout<<" [m join] Join the community\n [m com ls]Commands list\n";
}


void ClearScreen() { system("cls"); welcome(); }
void PauseScreen() { system("PAUSE"); }


/* =============HEARTS FONCTIONS =====================*/
    void conectionToNetwork(string MistID){
        cout<<"\n Connection to the peers";
        string output_string = "................";
        int length = output_string.length();
        for ( int ix = 0; ix < length; ix++ )
        {
           cout << output_string[ix];
           Sleep(1100);
        }
        cout<<"OK.";
    }

    void ListFiles(string MistID){
        conectionToNetwork(MistID);
        cout<<"\n You have: 0 files";
    }

    void uploadToMist(string MistID){
        conectionToNetwork(MistID);
        cout<<"\n Uploading on going";
    }
/*====================================================*/


void backNewLine(){
    cout<<"\n >>";
    //cin.ignore();
}


void makeAction(string valuee, string MistID){
    string menuchoice;
    if(valuee=="help" || valuee=="h" || valuee=="m"){
        ClearScreen(); menu();
        backNewLine();getline(cin,menuchoice);
        makeAction(menuchoice, MistID);
    }
    else if(valuee.find("files") != string::npos){ // listing files of my MistID

        ClearScreen();
        cout<<"\n-Listing files for M_"<<MistID.substr(0,7)<<" on Mist:\n";
        ListFiles(MistID);
        backNewLine(); getline(cin,menuchoice);
        makeAction(menuchoice, MistID);

    }else if(valuee.find("space") != string::npos){ //wan to see the space capacity

        if(valuee.find("me") != string::npos){ // capacity of MistID

        }else{ //Capacity of Mist

        }

    }else if(valuee.find("upload") != string::npos){

        cout <<" Example: File/Repository path=> C:\\Users\\Documents\\Mist.pdf";
        cout<<"\n File/Repository path=> ";
        getline(cin,menuchoice);
        uploadToMist(MistID);
        backNewLine(); getline(cin,menuchoice);
        makeAction(menuchoice, MistID);

    }else if(valuee.find("?") != string::npos){

    }else if(valuee.find("conf") != string::npos){

    }
    else{
        menu();
        backNewLine();getline(cin,menuchoice);
        makeAction(menuchoice, MistID);
    }
        //switch(valuee){
            //case :
                //List File on Mist

            //break;
            //case "2":
                //Level of storage

            //break;
            //case "3":
                //The uploading files (With repertory address)

            //break;
            //case "4":
                //Make a synchronisation with an or more directories (With repertory address)

            //break;
            //case "5":

            //break;
        //}
}

void verificationMistID(string val){
    cout <<"MistID verification for this host....\n";
}

//For creating the file
void create_write(string filename, string mot){
    ofstream file;
    if(file){
        file.open(filename.c_str());//ou ,ios::app avec la chaine de caracteree
        cout << "writting...."<<endl;
        file<<mot; file.close();
    }else
        cout <<"Error in opening file!";
}

//For forward the file
void forward_write(string filename, string mot){
    ofstream file;
    if(file){
        file.open(filename,ios::app);//ou ,ios::app avec la chaine de caracteree
        cout << "writting...."<<endl;
        file<<mot<<endl; file.close();
    }else
        cout <<"Error in opening file!";
}

string ToHex(const string& s, bool upper_case)
{
    ostringstream ret;
    for (string::size_type i = 0; i < s.length(); ++i)
        ret << hex << setfill('0') << setw(2) << (upper_case ? uppercase : nouppercase) << (int)s[i];
    return ret.str();
}

string read_file(string file){
    string STRING;
	ifstream infile;
	infile.open(file);
    getline (infile,STRING); // To get you all the lines.
	infile.close();
	return STRING;
}

string read_file_to_mist(string filename){
    ifstream::pos_type t_size;
    ifstream file_ (filename, ios::in|ios::binary|ios::ate);
    string ligne(""), tohexed("");
    char * memblock;
    if(file_){
        int t_size = file_.tellg();
        memblock = new char [t_size];
        file_.seekg (0, ios::beg); file_.read (memblock, t_size); file_.close();
        tohexed = ToHex(std::string(memblock, memblock+t_size), true);
        //tohexed = ToHex(memblock, true);
    }else
        cout <<"Error in opening file!";
    return tohexed;
}

//Methode PRICIPALES pour MISTER un fichier ou un dossier
void Mist(){
    string chemin="";
    cout<<"\nEntrez le chemin correct du fichier a mettre sur Mist!";
    cout<<"\n>>";
    cin>>chemin;
}
//Methode PRICIPALES pour DISMISTER un fichier ou un dossier
void DisMist(){

}

string SHA512_encrypt(string value){
    return  sha512(value);
}

static inline void loadbar(unsigned int x, unsigned int n, unsigned int w = 50)
{
    if ( (x != n) && (x % (n/100+1) != 0) ) return;

    float ratio  =  x/(float)n;
    int   c      =  ratio * w;

    cout << setw(3) << (int)(ratio*100) << "% [";
    for (int x=0; x<signed(c); x++) cout << "=";
    for (int x=c; x<signed(w); x++) cout << " ";
    cout << "]\r" << flush;
}

/*
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
*/


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

/*
  Example of how to write binary stuff in C++
  By Darker

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main( int argc, char ** argv)
{
  string X("This is the message");
  unsigned Y = 11;
  vector<double> Z(10,1.0);

  // L'ecriture
  ofstream o("binary_out_test.bin",ios_base::binary);
  //To write a string, print out its length, and then the char *
  //However, X.size() is a temp, and you cannot write a temp,
  //so you need a new variable.
  unsigned Xsize = X.size();
  //The next line is how you write most types:  cast a pointer to a type to a char * and give sizeof the type
  o.write ( reinterpret_cast<char *>(&Xsize),sizeof(unsigned) );
  o.write ( X.c_str(), Xsize*sizeof(char) );

  //Write out that vector

  //Take advantages of the fact that &vector<T>[0] is a pointer to type T.
  //gotta write out the size first!!!
  Xsize=Z.size();
  o.write ( reinterpret_cast<char *>(&Xsize),sizeof(unsigned) );
  o.write( reinterpret_cast<char *>(&Z[0]), Z.size()*sizeof(double) );
  o.close();

  // La lecture
  //Now, read it all back in
  ifstream in("binary_out_test.bin",ios_base::binary);

  unsigned stringsize;
  in.read( reinterpret_cast<char *>(&stringsize),sizeof(unsigned) );

  //Cannot read to a string directly, must have buffer intermediate
  vector<char> temp(stringsize);
  in.read( reinterpret_cast<char *>(&temp[0]), stringsize*sizeof(char) );
  string thestring(temp.begin(),temp.end());

  unsigned vsize;
  in.read( reinterpret_cast<char *>(&vsize),sizeof(unsigned) );
  vector<double> thedoubles(vsize);
  in.read( reinterpret_cast<char *>(&thedoubles[0]), vsize*sizeof(double) );

  cout << stringsize << ' ' << thestring << '\n'
       << vsize << ' ';
  for(unsigned i = 0 ; i < thedoubles.size() ; ++i )
    {
      cout << thedoubles[i] << ' ';
    }
  cout << '\n';
  in.close();
}
*/
