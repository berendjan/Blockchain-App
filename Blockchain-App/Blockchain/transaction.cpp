//
//  transaction.cpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 30/04/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#include "transaction.hpp"

Transaction::Transaction(std::string *fromAddress, std::string toAddress, double amount)
    : fromAddress { fromAddress},
    toAddress{ toAddress },
    amount{ amount } {
        timestamp = getTimestamp();
    }

Transaction::~Transaction() { }


std::string Transaction::calculateHash() {
    if (fromAddress) {
        return sha256(*fromAddress + toAddress + std::to_string(amount));
    } else {
        return sha256(toAddress + std::to_string(amount));
    }
}

void Transaction::signTransactionWithString(std::string publicKey, std::string privateKey) {
    if (*fromAddress != publicKey) {
        printf("You cannot sign transactions for other wallets!");
        return;
    }
    std::string hashTx = calculateHash();
    signature = signMessageWithString(privateKey, hashTx);
}

void Transaction::signTransactionWithRSA(RSA* publicRSA, RSA* privateRSA) {
    // Implement signing check
    std::string hashTx = calculateHash();
    signature = signMessageWithRSA(privateRSA, hashTx);
}

bool Transaction::isValid() {
    if (!fromAddress) {
        return true;
    }
    if (!signature || sizeof(signature) == 0) {
        return false;
    } else {
        std::string fa = *fromAddress;
        return verifySignatureWithString(fa, calculateHash(), signature);
    }
}

unsigned long Transaction::getTimestamp() {
    return (unsigned long) time(NULL);
}
