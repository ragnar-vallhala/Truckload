#include "delivery.h"
#include <iostream>

int main(){

    Truckload Truck;
    Box b1(3,5,6,2);
    Box b2(2,2);
    Box b3(1,45,3,1);
    Truck.sortedInsertbyHeight(b1)->sortedInsertbyHeight(b2)->sortedInsertbyHeight(b3);
    Truck.printPackages();
    std::cout<<"Done"<<std::endl;

}
