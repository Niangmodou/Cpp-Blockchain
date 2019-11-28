#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include <ctime>
#include "sha256.h" //sha256 hashing algorithm

namespace myCoin{

	//Transaction information will be stored in a Transaction object
	class Transaction{
		friend class Block;
		friend std::ostream& operator<<(std::ostream&, const Transaction&);
	public:
		Transaction(const std::string&,double);
	private:
		std::string name;
		std::string timestamp;
		double amount;
	};

	class Block{
		friend class Blockchain;
		friend std::ostream& operator<<(std::ostream&, const Block&);
	public:
		Block(size_t, const std::string&, const std::string& , double);

	private:
		//Uses the sha256 to calculate the hash of the current block
		const std::string calculateHash() const;
		
		//Proof of work algorithm to mine new blocks
		void mineBlock(size_t difficulty);

		size_t nonce;
		size_t index;
		Transaction data;
		std::string blockHash;
		std::string previousHash;

	};

}

#endif