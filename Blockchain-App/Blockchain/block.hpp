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
#include <vector>
#include <string>

using namespace std;

class Block {


    private:

    string previousHash;
    string transactions;
    string timestamp;
    int index;

    protected:

    public:

    // Constructors
    Block();
    Block(int index, string timestamp, string transactions, string previousHash);
    // Deconstructor
    ~Block();

    void calculateHash();
    void mineBlock();

};

#endif /* block_hpp */
