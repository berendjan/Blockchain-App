//
//  blockchain.hpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 28/04/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#ifndef blockchain_hpp
#define blockchain_hpp

#include <stdio.h>
#include "block.hpp"

class Blockchain {
    private:
    
    int difficulty;
    double miningReward;
    
    protected:
    public:
    
    vector<Block> blockchain;
    vector<Transaction> pendingTransactions;

    Blockchain();
    ~Blockchain();

    Block createGenesisBlock();
    Block getLatestBlock();
    void minePendingTransactions(string miningRewardAddress);
    bool isChainValid();
    void pushToPendingTransactions(Transaction t);
    double getBalanceOfAddress(string address);
    
    unsigned long getCurrentUTCTime();
};

#endif /* blockchain_hpp */
