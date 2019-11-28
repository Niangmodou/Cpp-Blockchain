# Cpp-Blockchain
Blockchain implemented in C++

This repository is a basic implementation of a Blockchain. The Transaction class 
stores the name of the sender, the transaction amount, and a timestamp of when the transaction 
took place. The Block contains a Transaction object, the hash of the block, and the hash 
of the previous block. The program works by chaining each block using the cryptographic 
hashes of the previous block. The hashing algorithm that is used is the sha256 hash 
obtained from zedwood.com. The overall structure of the blockchain is implemented 
using a C++ STL Vector.

A possible improvement I may add to this to program is to implement a peer-to-peer 
network where the changes to the chain are tracked along multiple machines.
