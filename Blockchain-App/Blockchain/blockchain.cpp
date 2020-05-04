//
//  blockchain.cpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 28/04/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#include "blockchain.hpp"

Blockchain::Blockchain() {
    blockchain.push_back(Blockchain::createGenesisBlock());
    difficulty = 4;
}

Blockchain::~Blockchain() { }

Block Blockchain::createGenesisBlock() {
    return Block(0, getCurrentUTCTime(), vector<Transaction>{}, "Genesis Block");
}

Block Blockchain::getLatestBlock() {
    return blockchain.back();
}

void Blockchain::minePendingTransactions(string miningRewardAddress) {
    unsigned long earliest_timestamp = pendingTransactions.begin()->timestamp;
    for (vector<Transaction>::iterator it = ++pendingTransactions.begin(); it != pendingTransactions.end(); it++) {
        if (earliest_timestamp > it->timestamp)
            earliest_timestamp = it->timestamp;
    }
    
    Block newBlock = Block((int)blockchain.size(), earliest_timestamp, pendingTransactions, getLatestBlock().hash);
    newBlock.mineBlock(difficulty);
    
    cout << "Block Succesfully Mined" << endl;
    blockchain.push_back(newBlock);
    
    pendingTransactions = vector<Transaction> {
        Transaction (
            NULL,                   // fromAddress
            miningRewardAddress,    // toAddress
            miningReward)           // amount
    };
}

void Blockchain::pushToPendingTransactions(Transaction t) {
    if (!t.fromAddress || sizeof(t.toAddress) == 0) {
        printf("New transaction is missing to or from address\n");
        return;
    }
    if (!t.isValid()) {
        printf("Cannot add invalid transaction to blockchain\n");
        return;
    }
    pendingTransactions.push_back(t);
}

double Blockchain::getBalanceOfAddress(string address) {
    double balance = 0;
    for (vector<Block>::iterator blockIterator = blockchain.begin(); blockIterator != blockchain.end(); blockIterator++) {
        for (vector<Transaction>::iterator transactionIterator = blockIterator->transactions.begin();
             transactionIterator != blockIterator->transactions.end(); transactionIterator++) {
            if (*transactionIterator->fromAddress == address) {
                balance -= transactionIterator->amount;
            }
            if (transactionIterator->toAddress == address) {
                balance += transactionIterator->amount;
            }
        }
    }
    return balance;
}

bool Blockchain::isChainValid() {
    for (vector<Block>::iterator currentBlock = ++blockchain.begin(), previousBlock = blockchain.begin();
         currentBlock != blockchain.end(); previousBlock = currentBlock, currentBlock++) {
        
        string rehash = currentBlock->calculateHash();
        if (currentBlock->calculateHash() != currentBlock->hash) {
            cout << "Invalid blockchain: hash of block " << currentBlock->index << " does not match to content" << endl;
            return false;
        }
        
        if (!currentBlock->hasValidTransaction()) {
            printf("Invalid blockchain: invalid transaction found...\n");
            return false;
        }
        
        if (currentBlock->previousHash != previousBlock->hash) {
            cout << "Invalid blockchain: previoushash does not match" << endl;
            return false;
        }
    }
    cout << "Valid blockchain" << endl;
    return true;
}

unsigned long Blockchain::getCurrentUTCTime() {
//    time_t now = time(0);
//    tm *gmtm = gmtime(&now);
//    return asctime(gmtm);
    return (unsigned long) time(NULL);
}
