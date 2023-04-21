#include "delivery.h"
#include <iostream>

int main(){

    Truckload t;
    Box b1(1,2);
    Box b2(1,2);
    Box b3(1,2,3,1);
    t.insertEnd(b1)->insertBegin(b3)->insertEnd(b3);
    t.printPackages();
    std::cout<<"Done"<<std::endl;

}
