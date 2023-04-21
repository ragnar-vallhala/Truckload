#include "delivery.h"
#include <iostream>

int main(){

    Truckload t;
    Box b1(3,5,6,2);
    Box b2(2,2);
    Box b3(1,45,3,1);
    t.sortedInsertbyHeight(b1)->sortedInsertbyHeight(b2)->sortedInsertbyHeight(b3);
    t.printPackages();
    std::cout<<"Done"<<std::endl;

}
