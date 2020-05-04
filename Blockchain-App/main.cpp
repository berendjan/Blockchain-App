//
//  main.cpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 28/04/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#include <iostream>
#include "blockchain.hpp"
#include "keygenerator.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    KeyGenerator gen = KeyGenerator();

    gen.generateKey();
    
//    std::string plainText = "My secret message.\n";
//    char* signature = signMessageWithRSA(gen.privateKey, plainText);
//    bool authentic = verifySignatureWithRSA(gen.publicKey, "My secret message.\n", signature);
//    if ( authentic ) {
//      std::cout << "Authentic" << std::endl;
//    } else {
//      std::cout << "Not Authentic" << std::endl;
//    }
    
    Blockchain blockchain1 = Blockchain();
    
    std::string fromAddress = getPublicKey();
    Transaction transaction1(&fromAddress, "berend", 11.413);
//    fromAddress = "berend";
    
    Transaction transaction2(&fromAddress, "phyllis", 39.233 );
//    fromAddress = "phyllis";
    Transaction transaction3(&fromAddress, "1", 4.233 );
    transaction1.signTransactionWithString(fromAddress, getPrivateKey());
    blockchain1.pushToPendingTransactions(transaction1);
    blockchain1.pushToPendingTransactions(transaction2);
    
    blockchain1.minePendingTransactions("berend");
    
    printf("Balance beredn: %f\n", (blockchain1.getBalanceOfAddress("berend")));

    printf("Printing all blocks:\n");
    for (vector<Block>::iterator it = blockchain1.blockchain.begin(); it != blockchain1.blockchain.end(); it++) {
        cout << "index: " << it->index << endl << "  timestamp: " << it->timestamp;// << endl;
        cout << "  hash: " << it->hash << endl << "  previousHash: " << it->previousHash << endl;
        for (vector<Transaction>::iterator it2 = it->transactions.begin(); it2 != it->transactions.end(); it2++) {
            time_t now = (time_t)it2->timestamp;
//            tm *gmtm = gmtime(&now);
            tm *gmtm = localtime(&now);
            string t = asctime(gmtm);
            printf(" %s\n", it2->fromAddress->c_str());
            cout << "  -  from: " << *it2->fromAddress << " to: " << it2->toAddress << " amount: " << it2->amount << " timestamp: " << t;
        }
    }
    
    blockchain1.isChainValid();
    
    return 0;
}
