#include<iostream>
#include <fstream>
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "sha1.h"
#include "mist.h"

using namespace std;

struct bloc{ // Structure d'un bloc
    string nom_bloc; // nom du fichier bloc
    string hash_code_fichier; // code d'identification de l'origine du fichier
    unsigned int ordre_bloc;
    float taille_bloc;
    string date_creation_bloc;
};

struct file_descript{ // Structure d'un descripteur de fichier
    int nbre_blocs;
    string nom_file_descript;
    string hash_code_fichier;
};

int main(){
    string authentificatedvalue="", MistID="", menuchoice="";
    welcome();
    //cout<<"Mist loaded..."<<endl; //The load method here to check in files  for all components and network
    cout<<"MistID(if you don't have one write no)\n >>";
    cin>>authentificatedvalue;
    if(authentificatedvalue=="no"){ //if the one don't have authentifiacation ID for Mist
        //We verify first if an ID don't exist in a file with the SHA1 Crypt ID (l'ordre de cryptage devra etre aleatoire en fonction de chaque creation de son MistID)
        rewriteYourMistId:
            cout<<"\nYou need to create your secure MistID first(more than 7 caracters)!\n >>MistID:";
            cin>>MistID;
            if(MistID.length()<7){
                goto rewriteYourMistId;
            }
            cout << " Your Generated Key: "<<SHA512_encrypt(MistID)<<endl;
            cout<<"[Never forget your MistID, it is very important for log in in your files]\n";
            menu();
            cout<<" >>";cin>>menuchoice;

            makeAction(menuchoice);
    }else{
        //We take the value in the file
        //We test the ID
    }
    return 0;
}
