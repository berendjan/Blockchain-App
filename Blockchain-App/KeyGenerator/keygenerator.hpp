//
//  keygenerator.hpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 29/04/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#ifndef keygenerator_hpp
#define keygenerator_hpp

#import <openssl/pem.h>
#import <openssl/rsa.h>
#import <openssl/err.h>

#include <stdio.h>
#include <string>
#include <regex>

using std::string;

class KeyGenerator {
    
    private:

    protected:

    public:
    
    KeyGenerator();
    ~KeyGenerator();
    
    RSA* publicKey;
    RSA* privateKey;
    
    bool generateKey();
    
};

#endif /* keygenerator_hpp */


