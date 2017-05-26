/* =====================================================
*             MIST (Infinite Cloud network)
*                           By S@n1X D4rk3r
*             https://github.com/Sanix-Darker/Mist
*======================================================*/
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>

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
    //The load method here to check in files  for all components and network
    begining:
    cout<<"-MistID(if you don't have one write no)";
    backNewLine(); getline(cin,authentificatedvalue);
    cout<<":"<<authentificatedvalue;
    if(authentificatedvalue=="no" || authentificatedvalue=="n" || authentificatedvalue=="NO" || authentificatedvalue=="N"){ //if the one don't have authentifiacation ID for Mist
        //We verify first if an ID don't exist in a file with the SHA1 Crypt ID (l'ordre de cryptage devra etre aleatoire en fonction de chaque creation de son MistID)
        rewriteYourMistId:
            if(read_file("MistID").length()>10){
                cout<<"\n-You have already an MistID, you need to log in with it!\n";
                goto begining;
            }
            cout<<"\n-You need to create a MistID(more than 7 caracters)!";
            backNewLine(); getline(cin,MistID);
            if(MistID.length()<7){
                cout<<"\n-'More than 7 Caracters please'";
                goto rewriteYourMistId;
            }
            cout << "-Your MISTID_key: "<<SHA512_encrypt(MistID)<<endl; create_write("MistID",SHA512_encrypt(MistID));

            cout<<"\n-[Never forget your MistID, it is very important for login to your Mist space]\n";

            MistID=SHA512_encrypt(authentificatedvalue); // Encryption od ID
            PauseScreen(); ClearScreen();
            cout<< "-Welcome 'M_"<<MistID.substr (0,7)<<"', (You can type 'help' or h command to see options )\n";
            backNewLine();cin>>menuchoice;

            makeAction(menuchoice,MistID);
    }else{
        if(read_file("MistID")==SHA512_encrypt(authentificatedvalue)){
            MistID=SHA512_encrypt(authentificatedvalue); // we put in Mist ID the sha crypt value
            ClearScreen();
            cout<< "-Welcome 'M_"<<MistID.substr (0,7)<<"', (You can type 'help' or h command to see options )\n";
            backNewLine();cin>>menuchoice;

            makeAction(menuchoice, MistID);
        }else{
            cout<<"\n-This Mist ID does not exist or does not match for this host\n";
            goto begining;
        }
    }
    return 0;
}
