#include <iostream>
#include <stdio.h>
#include "Timer.hpp"
#include <vector>

class LargeObject {
public:
    LargeObject();
    virtual ~LargeObject();
private:
    int m_data[1000000];
};

LargeObject::LargeObject(){};
LargeObject::~LargeObject(){};
Timer T1;
Timer T2;
LargeObject O;

int main(){
    Timer timer(true);
    O.pushback("1");
}


