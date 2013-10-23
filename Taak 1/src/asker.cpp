//============================================================================
// Name        : Taak.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "asker.h"
using namespace std;


void asker(string input, string output){
	ifstream enquete (input);
	ofstream answers (output);


	//controleert of de geven bestanden geopend zijn

	if (enquete.is_open()){
	string id;
	string line;
	string answerchoice;
	string answertext;
    string vraag;
	string resultstream;

	for (int i=0 ; i< 4; i++) { //overslaan van de intro, dit zijn de eerste vier lijnen

		if (i == 1){
			getline(enquete,id);
			answers << id <<endl;
		}
		else {
		getline (enquete,line);
	    }
	}

	//wegschrijven van unieke code enquete


        while(  getline(enquete,line)){
    	stringstream ss (line);
    	string vraagnr, identiteit;
    	int aantal_antwoorden;
    	ss >> vraagnr; //nummer
    	ss >> identiteit; //"TEXT" of "CHOICE"


    	//controleert of indentiteit overeen komt met "TEXT"

    	if (identiteit.compare("TEXT") == 0){
    		        getline(ss, vraag);
    	    		cout << ">" << vraag << endl;
    	    	  getline(cin,answertext);

    	    	  //Controle op het niet invullen van een antwoord (gewoon enter drukken)

    	    	while (answertext.empty()){
    	    		  cout << "Gelieve geen vragen over te slaan!" << endl;
    	    		 getline(cin,answertext);
    	    	  }
    	         answers << vraagnr << ") " << answertext << endl;      //wegschrijven van antwoord
    	         cout <<"Ok." << endl;
    	        }


    	    	else {
    	    		ss >> aantal_antwoorden;
    	    		getline(ss, vraag);
    	            cout << ">" << vraag << endl;
    	    	for (int i = 1; i < aantal_antwoorden + 1; i++)// printen van de mogelijkheden
    	    	{getline (enquete,line);
    	    		cout << i << ") " << line << endl;}


    	    	cin >> answerchoice;
    	    	cin.ignore();

    	    	//Controleert of het antwoord voldoet aan de voorwaarden

    	    	while ( integercheck(answerchoice) == 0     // bestaat enkel uit getallen
    	    		|| StringToInteger(answerchoice) < 0    //is groter dan nul
    	    		|| StringToInteger(answerchoice) > aantal_antwoorden){ //kleiner dan het aantal mogelijkheden om de vraag te beantwoorden
    	    		cout << "Selecteer een geldige antwoord tussen ("<< "1-" << aantal_antwoorden << "):" << endl;
    	    		cin >> answerchoice;
    	    		cin.ignore();


    	    	}
    	       answers << vraagnr << ") " << answerchoice << endl;
    	       cout <<"Ok." << endl;
    	    }
     }
cout << "Bedankt voor je deelname!" <<endl;
cout << "Antwoordbestand weggeschreven naar " << output;

	}
	else{ cout << "unable to open (one of the) files";}

}



int main (int argc, const char *argv[]) {
    asker(argv[1],argv[2]);

  return 0;
}


// Zet een string om naar een integer

int StringToInteger(string mijnstring){
std::istringstream convert(mijnstring);
int mijnint;
convert >> mijnint;
return mijnint;
}


//controleert of ingegeven stream allemaal integers zijn

int integercheck (string mijnstring){
string input (mijnstring);
int size  (input.size());
int check (1);
for (int i = 0; i < size ; i++){
	int asciivalue ((int) input[i] - 48);
    if (asciivalue <= 0
    		|| asciivalue >= 9){
    	check = 0;}
}
return check;
}

