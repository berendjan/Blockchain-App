//
//  openssl.cpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 02/05/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#include "openssl.hpp"


OpenSSL::OpenSSL() { }

OpenSSL::~OpenSSL() { }

std::string privateKey ="-----BEGIN RSA PRIVATE KEY-----\n"\
"MIIEowIBAAKCAQEA3Z4TqhN0tZ4Qq57ki4WEMcM95xssTlLSHUJNL7joT4i7jDfM\n"\
"JnfgU/JTXIeVRVvlrE5+Tnzj7/fF4y5n8wddRfEYz+bq3dnlD1FDKkLPFAycYMat\n"\
"CxDu0RbP36KAWJmaSJ+Gz7ljUKQGMfIBC4dod1U7XkMp2d9Ktyx5926uEXiqyVTQ\n"\
"cM22b9jF8ElthrXRCqnJ5FE4Mk0upXSaEyKOpIqvI5mD5tldnyOwtLtnX421V3jV\n"\
"gldUtHfxz/jLO1cTESjyb1qZWBeuNNSR0F2eH/AhXCISbSnulU9HVtaSN+AHxHAV\n"\
"BelAGKQVxb4LkWQ5BfhPg4vdDENpEOKZHc6yLQIDAQABAoIBACEwpnNHPKhihs6d\n"\
"Gk9G7LhjLCcra6RDRRJ6toKaJ7iZmrTyOlHcjC0mUpO9/n4HuEro6oOosp5itjFC\n"\
"5vB/vtlVtUiVpcEZ+/MiUXPH06mGBfl8Z7gLjiikSPeOJ7idMH0F3zPG6PfPyNm8\n"\
"C6oFWoDcs+p3FpJ5nX/3WkDTQ6B78X6p5HxiUmIB6Zy+BnZLKyTvVDkbfj4K2fgq\n"\
"V74OAil0VcYM4PWxGf3x2lLVI/oziZfVgl2zS6zid6CK9Hcr+KWJ7UpGcA4iMbif\n"\
"msDsx5Qbp511SEgLWm9MzyVthw1zlqpMCtsmM78j9yfiLkIKi91L8xv9Ay5x3a3E\n"\
"+UuB8AECgYEA9c4/yODFhFiPf0X/U9Gc3trE/XqQJm1xv6ChSNiYxlgtQhxRPN5L\n"\
"s5sj5OjZ4fhMQRxTR7ZwrMTLeD8eaieSmYya6tzFG2v2evXGDwiy6h6yH63XyYGX\n"\
"DWviq1ty3zJF6hw+RHSmKIFGmwK5PLqOjm9/C7QvGG4yhbCyp+dDbAECgYEA5s8E\n"\
"xrbZC2bokmr4dO+O2o258NbJWsKPOGAh2qxXwB9VYvNWmLWBSH3puSfV+LSNBT19\n"\
"z9up5mYwYw5s28QgSjeEpPMEpaGUTmB8aay8WQ7Z6LeGrDU22Q8nHSLwZuniuf+o\n"\
"LFjKuViePBbkM3xisnFWRxJq2SHpcrwcdPgsti0CgYBdxQ2OKzkOUN6FFgXeSuOG\n"\
"HHzzmdLt5ehzyupcKMy3NaImSzkueDr2zGM4CyA7VQZ5/D1E6TM4pWZde+61Xl1N\n"\
"mFbs68WBvYDszV9+Erp2F7mp3h6or3gZVaPF7P/4Z2xGb/nNEZblctOlhLd3lE+X\n"\
"xK75nwYsUrWRTKQK621MAQKBgDUekf/V1y/7mC0Sd2oaNCtykMev9xlvS5zy6vez\n"\
"0GJEE9e5H0X4B/ASInddhq49h3McStdKu9htzlcN29ncUn4iNuHrmDcyb7p2FEwR\n"\
"2Cs68sXPbyw09xGPnjXjc6aLz4V1JFRIfyeXEJvNvOloiCJ/WRb0Uyjz2BFy362/\n"\
"7DJlAoGBAIzwxRfGhoiEKFJeK1QxDettdspLmm+wC4zCnIaEMw1/eDjkrZs4VQ9Y\n"\
"/Dw+zGq0HTnjjhd3hj8ED/K9DcgME8jpShiSIF0isCv3G9GYpSDX20w/KoKjWLsc\n"\
"0YFFmSUikllbQ9Pd/5rbNJleWEa6RvXgDWoINwKd88UPUPa5TS8n\n"\
"-----END RSA PRIVATE KEY-----\n\0";

std::string publicKey ="-----BEGIN RSA PUBLIC KEY-----\n"\
"MIIBCgKCAQEA3Z4TqhN0tZ4Qq57ki4WEMcM95xssTlLSHUJNL7joT4i7jDfMJnfg\n"\
"U/JTXIeVRVvlrE5+Tnzj7/fF4y5n8wddRfEYz+bq3dnlD1FDKkLPFAycYMatCxDu\n"\
"0RbP36KAWJmaSJ+Gz7ljUKQGMfIBC4dod1U7XkMp2d9Ktyx5926uEXiqyVTQcM22\n"\
"b9jF8ElthrXRCqnJ5FE4Mk0upXSaEyKOpIqvI5mD5tldnyOwtLtnX421V3jVgldU\n"\
"tHfxz/jLO1cTESjyb1qZWBeuNNSR0F2eH/AhXCISbSnulU9HVtaSN+AHxHAVBelA\n"\
"GKQVxb4LkWQ5BfhPg4vdDENpEOKZHc6yLQIDAQAB\n"\
"-----END RSA PUBLIC KEY-----\n";

std::string sha256(const std::string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

RSA* createPrivateRSAFromString(std::string key) {
    RSA *rsa = NULL;
    const char* c_string = key.c_str();
    BIO * keybio = BIO_new_mem_buf((void*)c_string, -1);
    if (keybio==NULL) {
      return 0;
    }
    rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, NULL, NULL);
    return rsa;
}

RSA* createPublicRSAFromString(std::string key) {
    RSA *rsa = NULL;
    const char* c_string = key.c_str();
    BIO * keybio = BIO_new_mem_buf((void*)c_string, -1);
    if (keybio==NULL) {
      return 0;
    }
    rsa = PEM_read_bio_RSAPublicKey(keybio, &rsa, NULL, NULL);
    return rsa;
}

bool RSASign( RSA* rsa,
              const unsigned char* Msg,
              size_t MsgLen,
              unsigned char** EncMsg,
              size_t* MsgLenEnc) {
    EVP_MD_CTX* m_RSASignCtx = EVP_MD_CTX_create();
    EVP_PKEY* priKey  = EVP_PKEY_new();
    EVP_PKEY_assign_RSA(priKey, rsa);
    if (EVP_DigestSignInit(m_RSASignCtx,NULL, EVP_sha256(), NULL,priKey)<=0) {
      return false;
    }
    if (EVP_DigestSignUpdate(m_RSASignCtx, Msg, MsgLen) <= 0) {
      return false;
    }
    if (EVP_DigestSignFinal(m_RSASignCtx, NULL, MsgLenEnc) <=0) {
      return false;
    }
    *EncMsg = (unsigned char*)malloc(*MsgLenEnc);
    if (EVP_DigestSignFinal(m_RSASignCtx, *EncMsg, MsgLenEnc) <= 0) {
      return false;
    }
    EVP_MD_CTX_free(m_RSASignCtx);
    return true;
}

bool RSAVerifySignature( RSA* rsa,
                         unsigned char* MsgHash,
                         size_t MsgHashLen,
                         const char* Msg,
                         size_t MsgLen,
                         bool* Authentic) {
    *Authentic = false;
    EVP_PKEY* pubKey  = EVP_PKEY_new();
    EVP_PKEY_assign_RSA(pubKey, rsa);
    EVP_MD_CTX* m_RSAVerifyCtx = EVP_MD_CTX_create();

    if (EVP_DigestVerifyInit(m_RSAVerifyCtx,NULL, EVP_sha256(),NULL,pubKey)<=0) {
    return false;
    }
    if (EVP_DigestVerifyUpdate(m_RSAVerifyCtx, Msg, MsgLen) <= 0) {
    return false;
    }
    int AuthStatus = EVP_DigestVerifyFinal(m_RSAVerifyCtx, MsgHash, MsgHashLen);
    if (AuthStatus==1) {
    *Authentic = true;
    EVP_MD_CTX_free(m_RSAVerifyCtx);
    return true;
    } else if(AuthStatus==0){
    *Authentic = false;
    EVP_MD_CTX_free(m_RSAVerifyCtx);
    return true;
    } else{
    *Authentic = false;
    EVP_MD_CTX_free(m_RSAVerifyCtx);
    return false;
    }
}

void Base64Encode( const unsigned char* buffer,
                   size_t length,
                   char** base64Text) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_write(bio, buffer, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);
    BIO_free_all(bio);

    *base64Text=(*bufferPtr).data;
}

size_t calcDecodeLength(const char* b64input) {
    size_t len = strlen(b64input), padding = 0;

    if (b64input[len-1] == '=' && b64input[len-2] == '=') //last two chars are =
    padding = 2;
    else if (b64input[len-1] == '=') //last char is =
    padding = 1;
    return (len*3)/4 - padding;
}

void Base64Decode(const char* b64message, unsigned char** buffer, size_t* length) {
    BIO *bio, *b64;

    int decodeLen = calcDecodeLength(b64message);
    *buffer = (unsigned char*)malloc(decodeLen + 1);
    (*buffer)[decodeLen] = '\0';

    bio = BIO_new_mem_buf(b64message, -1);
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_push(b64, bio);

    *length = BIO_read(bio, *buffer, strlen(b64message));
    BIO_free_all(bio);
}

char* signMessageWithString(std::string privateKey, std::string plainText) {
    RSA* privateRSA = createPrivateRSAFromString(privateKey);
    unsigned char* encMessage;
    char* base64Text;
    size_t encMessageLength;
    RSASign(privateRSA, (unsigned char*) plainText.c_str(), plainText.length(), &encMessage, &encMessageLength);
    Base64Encode(encMessage, encMessageLength, &base64Text);
    free(encMessage);
    return base64Text;
}

char* signMessageWithRSA(RSA* privateRSA, std::string plainText) {
    unsigned char* encMessage;
    char* base64Text;
    size_t encMessageLength;
    RSASign(privateRSA, (unsigned char*) plainText.c_str(), plainText.length(), &encMessage, &encMessageLength);
    Base64Encode(encMessage, encMessageLength, &base64Text);
    free(encMessage);
    return base64Text;
}

bool verifySignatureWithString(std::string publicKey, std::string plainText, char* signatureBase64) {
    RSA* publicRSA = createPublicRSAFromString(publicKey);
    unsigned char* encMessage;
    size_t encMessageLength;
    bool authentic;
    Base64Decode(signatureBase64, &encMessage, &encMessageLength);
    bool result = RSAVerifySignature(publicRSA, encMessage, encMessageLength, plainText.c_str(), plainText.length(), &authentic);
    return result & authentic;
}

bool verifySignatureWithRSA(RSA* publicRSA, std::string plainText, char* signatureBase64) {
    unsigned char* encMessage;
    size_t encMessageLength;
    bool authentic;
    Base64Decode(signatureBase64, &encMessage, &encMessageLength);
    bool result = RSAVerifySignature(publicRSA, encMessage, encMessageLength, plainText.c_str(), plainText.length(), &authentic);
    return result & authentic;
}


std::string getPrivateKey() {
    return privateKey;
}

std::string getPublicKey() {
    return publicKey;
}
