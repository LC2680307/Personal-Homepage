#include <stdio.h>
#include "Timer.hpp"
#include <iostream>

int fib(int n){
    if(n<2){
        return n;
    }else{
        return fib(n-1) + fib(n-2);
    }
}

int main(){
    Timer timer(true);
    fib(40);
    timer.stop();

    std::cout << "fib(40) took " << timer.averageTime() << " seconds to run";
}