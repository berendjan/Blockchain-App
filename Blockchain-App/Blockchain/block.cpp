//
//  block.cpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 28/04/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#include "block.hpp"

Block::Block() { }

Block::Block(int index, string timestamp, string transactions, string previousHash = "")
    : timestamp{ timestamp }, transactions{ transactions }, previousHash{ previousHash }, index{index} { }

Block::~Block() { }
    


void Block::calculateHash() {

}

void Block::mineBlock() {
    
}
