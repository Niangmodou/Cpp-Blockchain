#include <iostream>
#include <string>
#include "Blockchain.h"
#include "sha256.h" //Sha256 hashing algorithm

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
	return 0;
}
