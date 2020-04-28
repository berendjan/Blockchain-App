//
//  inout.hpp
//  Blockchain-App
//
//  Created by Berend-Jan Lange on 28/04/2020.
//  Copyright © 2020 Berend-Jan Lange. All rights reserved.
//

#ifndef inout_hpp
#define inout_hpp

#include <stdio.h>
#include <string>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

class InOut {

    private:

    string path;

    protected:
    public:

    InOut();
    InOut(string path);
    ~InOut();

    void read();
    void write(map<string, string> object);

    static void static_read(string path);
    static void static_write(string path, map<string, string> object);
};

#endif /* inout_hpp */
