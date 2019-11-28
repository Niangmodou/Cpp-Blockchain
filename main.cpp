#include <iostream>
#include <string>
#include "Blockchain.h"
#include "sha256.h" //Sha256 hasing algorithm

using namespace std;
using namespace myCoin;

//
//g++ -std=c++11 Blockchain.cpp Block.cpp main.cpp sha256.cpp

int main(){
	Blockchain blockchain;

	int choice;

	while(choice != 5){
		cout << "1. VIEW TRANSACTIONS\n"<< "2. CREATE TRANSACTION\n" <<
			"3. GENERATE BLOCK\n" << "4. VALIDATE\n" << "5. EXIT\n";

		int choice;
		cin >> choice;

		if(choice == 1){
	    	cout << blockchain;

		}else if(choice == 2){
			string name;
	        cout << "Enter Name: ";
	        cin >> name;

	        double amount;
	        cout << "Enter Amount: ";
	        cin >> amount;

	        blockchain.createTransaction(name,amount);
		}else if(choice == 3){
	        blockchain.createTransaction("NULL",0);
		}else if(choice == 4){
			cout << ( blockchain.isValidChain() 
	        		? "Chain is valid" : "Chain is invalid") << endl << endl;
		}else if(choice == 5){
			break;
		}else{
			cout << "Invalid Choice!" << endl;
		}

	}
	// blockchain.createTransaction("Modou",2456.23);
	// blockchain.createTransaction("Dak",132.00);	
	// blockchain.createTransaction("Chris",29.76);	
	// blockchain.createTransaction("Addy",7653.88);	
	// blockchain.createTransaction("Kaleah",1234.99);	
	// blockchain.createTransaction("Jide",243.96);	
	// blockchain.createTransaction("Gaby",865.09);	
	// blockchain.createTransaction("Joe",83.12);	
	// blockchain.createTransaction("Afnan",65.29);	
	// blockchain.createTransaction("Mousta",983.43);	
	// blockchain.createTransaction("The boy",245.76);	
	// blockchain.createTransaction("Sacha",124.50);	
	// blockchain.createTransaction("Hawa",92.76);	

	//cout << blockchain << endl;
	return 0;
}