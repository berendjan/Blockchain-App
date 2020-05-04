//
//  openssl.hpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 02/05/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#ifndef openssl_hpp
#define openssl_hpp

#include <stdio.h>
#include <string>
#include <iomanip>
#include <sstream>

#include <iostream>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <assert.h>


//#import <CommonCrypto/CommonDigest.h>
//#import <openssl/asn1.h>
//#import <openssl/pem.h>
//#import <openssl/pkcs7.h>
//#import <openssl/sha.h>
//#import <openssl/x509.h>
//#import "transaction.hpp"

class OpenSSL {
    private:
    
    protected:
        
    public:
    
    OpenSSL();
    ~OpenSSL();
};


std::string sha256(const std::string str);

RSA* createPrivateRSAFromString(std::string key);

RSA* createPublicRSAFromString(std::string key);

bool RSASign( RSA* rsa,
             const unsigned char* Msg,
             size_t MsgLen,
             unsigned char** EncMsg,
             size_t* MsgLenEnc);

bool RSAVerifySignature( RSA* rsa,
                        unsigned char* MsgHash,
                        size_t MsgHashLen,
                        const char* Msg,
                        size_t MsgLen,
                        bool* Authentic);

void Base64Encode( const unsigned char* buffer,
                  size_t length,
                  char** base64Text);

size_t calcDecodeLength(const char* b64input);

void Base64Decode(const char* b64message, unsigned char** buffer, size_t* length);

char* signMessageWithString(std::string privateKey, std::string plainText);
char* signMessageWithRSA(RSA* privateRSA, std::string plainText);

bool verifySignatureWithString(std::string publicKey, std::string plainText, char* signatureBase64);
bool verifySignatureWithRSA(RSA* publicRSA, std::string plainText, char* signatureBase64);

std::string getPrivateKey();
std::string getPublicKey();

#endif /* openssl_hpp */
