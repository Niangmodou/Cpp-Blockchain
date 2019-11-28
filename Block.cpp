#include "Block.h"
#include "sha256.h"
#include <ctime>
#include <sstream>

using namespace std;

namespace myCoin{

	Transaction::Transaction(const std::string& name,double amount) 
		: name(name),amount(amount){
			time_t currTime = time(nullptr);
			timestamp = ctime(&currTime);
		}

	ostream& operator<<(ostream& os, const Transaction& trans){
		os << "	Name: " << trans.name << endl;
		os << "	Amount: " << trans.amount << endl;
		os << "	TimeStamp:" << trans.timestamp << endl;
		return os;
	}

	Block::Block(size_t index, const string& previousHash, const string& name,double amount) 
	: index(index), previousHash(previousHash), nonce(0), data(name,amount),
		blockHash(calculateHash()){}

	const string Block::calculateHash() const {
		stringstream blockInfo;
		blockInfo << index << data.amount << data.name 
			<< data.timestamp << nonce;

		return sha256(blockInfo.str());
	}

	void Block::mineBlock(size_t difficulty){
		string subString(difficulty, '0');

		while(blockHash.substr(0,difficulty) != subString){
			blockHash = calculateHash();
			nonce++;
		}
	}

	ostream& operator<<(ostream& os, const Block& currBlock){
		//check for genesis block
		if(currBlock.index != 0){
			os << "Block Number: " << currBlock.index << endl;
			os << "Block Hash: " << currBlock.blockHash << endl;
			os << "Previous Hash: " << currBlock.previousHash << endl;
			os << "Nonce: " << currBlock.nonce << endl;
			os << "	TRANSACTION \n" << currBlock.data;

		}
		return os;
	}

}