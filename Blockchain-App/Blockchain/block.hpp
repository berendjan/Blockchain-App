//
//  block.hpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 28/04/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#ifndef block_hpp
#define block_hpp

#include <stdio.h>
#include <iomanip>
#include <sstream>

#include "transaction.hpp"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::to_string;

class Block {


    private:

    protected:

    public:
    
    int index;
    unsigned long timestamp;
    vector<Transaction> transactions;
    string hash;
    string previousHash;
    int nonce;

    Block(int index, unsigned long timestamp, vector<Transaction> transactions, string previousHash);
    ~Block();

    string calculateHash();
    void mineBlock(int difficulty);
    
    string stringifyTransactions();
    
    string stdHash(string str);
    
    
    bool hasValidTransaction();
};

#endif /* block_hpp */
