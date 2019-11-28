#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <vector>

namespace myCoin{

	class Block;
	class Transaction;

	class Blockchain{
		friend std::ostream& operator<<(std::ostream&, const Blockchain&);
	private:
		size_t difficulty;
		size_t size;

		//Collection to store blocks
		std::vector<Block*> chain;

		//Creation of the first block within the blockchain
		void createGenesisBlock();
	public:
		Blockchain();

		Blockchain(const Blockchain&);

		Blockchain& operator=(const Blockchain&);

		//Removal of all blocks from the heap to prevent memory leaks
		~Blockchain();

		//Function to retrieve the last block in the blockchain
		const Block& getLastBlock() const;

		//Function to check if our blockchain is valid;
		bool isValidChain() const;

		//Mine new blocks into the blockchain using proof of work algorithm
		void mineBlock(const std::string&, double);

		//Function to create a transaction alongside a block
		void createTransaction(const std::string&, double);

		//Function used to generate a random block in the blockchain
		void generateBlock();

	};

}

#endif