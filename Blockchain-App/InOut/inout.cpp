//
//  inout.cpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 28/04/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#include "inout.hpp"

InOut::InOut() { }

InOut::InOut(string path) {
    InOut::path = path;
}

InOut::~InOut() { }

void InOut::read() {

    string line; 
    ifstream file;
    file.open(path);

    if (file.is_open()) {
        while (getline(file, line, '\n'))
        cout << line + "\n";
    }
    else {
        cout << "Could not open file with path: " << path;
    }
    file.close();
}

void InOut::write(map<string, string> object) {
    ofstream file;
    file.open(path);

    if (file.is_open()) {
        file << 1;
    }
    else {
        cout << "Could not open file with path: " << path;
    }
    file.close();
}

void InOut::static_read(string path) {
    string line;
    ifstream file;
    file.open(path);

    if (file.is_open()) {
        while (getline(file, line, '\n'))
        cout << line + "\n";
    }
    else {
        cout << "Could not open file with path: " << path;
    }
    file.close();
}

void InOut::static_write(string path, map<string, string> object) {
    ofstream file;
    file.open(path);

    if (file.is_open()) {
        
    }
    else {
        cout << "Could not open file with path: " << path;
    }
    file.close();
}
