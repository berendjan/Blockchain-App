//
//  transaction.hpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 30/04/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#ifndef transaction_hpp
#define transaction_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

#include "openssl.hpp"


class Transaction {
    
    private:

    protected:

    public:
    
    Transaction(std::string *fromAddress, std::string toAddress, double amount);
    ~Transaction();
    
    std::string *fromAddress;
    std::string toAddress;
    char* signature;
    double amount;
    unsigned long timestamp;
    
    unsigned long getTimestamp();
    
    std::string calculateHash();
    
    void signTransactionWithString(std::string publicKey, std::string privateKey);
    void signTransactionWithRSA(RSA* publicRSA, RSA* privateRSA);
    
    bool isValid();
    
};

#endif /* transaction_hpp */

