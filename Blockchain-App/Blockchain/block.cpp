//
//  block.cpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 28/04/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#include "block.hpp"

Block::Block(int index, unsigned long timestamp, vector<Transaction> transactions, string previousHash)
    : index{ index },
    timestamp{ timestamp },
    transactions{ transactions },
    previousHash{ previousHash } {
        hash = calculateHash();
        nonce = 0;
    }

Block::~Block() { }
    

string Block::calculateHash() {
//    return Block::stdHash(to_string(index) + timestamp + stringifyTransactions() + previousHash + to_string(nonce));
    return sha256(to_string(index) + to_string(timestamp) + stringifyTransactions() + previousHash + to_string(nonce));
}

void Block::mineBlock(int difficulty) {
    do {
        nonce++;
        hash = calculateHash();
    } while (hash.substr(0, difficulty) != string(difficulty, '0'));
}

string Block::stringifyTransactions() {
    string ret;
    for (vector<Transaction>::iterator it = transactions.begin(); it != transactions.end(); it++) {
        ret.append(it->toAddress);
    }
    return ret;
}

string Block::stdHash(string str) {
    return std::to_string((unsigned long) std::hash<std::string>{}(str));
}

bool Block::hasValidTransaction() {
    for (vector<Transaction>::iterator it = transactions.begin(); it != transactions.end(); it++) {
        if (!it->isValid()) {
            printf("Invalid transaction found from:\n%s\nto:\n%s\n", it->fromAddress->c_str(), it->toAddress.c_str());
            return false;
        }
    }
    return true;
}
