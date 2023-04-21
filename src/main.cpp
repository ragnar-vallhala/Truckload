#include "delivery.h"
#include <iostream>

int main(){

    Truckload t;
    Box b1(3,2);
    Box b2(2,2);
    Box b3(1,2,3,1);
    t.sortedInsertbyLength(b1)->sortedInsertbyLength(b2)->sortedInsertbyLength(b3);
    t.printPackages();
    std::cout<<"Done"<<std::endl;

}
