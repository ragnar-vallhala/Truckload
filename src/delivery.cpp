#include "delivery.h"

Box::Box(float l, float b, float h, float w)
{
    this->length = l;
    this->breadth = b;
    this->height = h;
    this->weight = w;
}

Box::Box(float l, float w) : Box(l, l, l, w){};

Box::Box(Box &box)
{
    this->length = box.length;
    this->breadth = box.breadth;
    this->height = box.height;
    this->weight = box.weight;
}

void Box::setLength(float len)
{
    this->length = len;
}

void Box::setBreadth(float len)
{
    this->breadth = len;
}

void Box::setHeight(float len)
{
    this->height = len;
}

void Box::setWeight(float w)
{
    this->weight = w;
}

float Box::calcVolume()
{
    return this->breadth * this->height * this->height;
}

float Box::calcDensity()
{
    return this->weight / (this->breadth * this->height * this->height);
}

bool Box::operator==(Box &box)
{
    if (this->length == box.length && this->breadth == box.breadth && this->height == box.height && this->weight == box.weight)
        return true;
    return false;
}



Package::Package(float l, float b, float h, float w)
{
    Box newBox(l, b, h, w);
    this->box = newBox;
}

Package::Package(float l, float w)
{
    Box newBox(l, w);
    this->box = newBox;
}

Package::Package(Box &box)
{
    this->box = box;
}

bool Package::operator==(Package &package)
{
    if (this->box == package.box)
        return true;
    return false;
}

void Package::updateNext(Package &pkg)
{
    this->nextPackage=&pkg;
}

void Package::updatePrevious(Package &pkg)
{
    this->previousPackage = &pkg;
}

Truckload::Truckload(Box &box)
{
    head = new Package(box);
}

Truckload *Truckload::insertBegin(Box &box)
{   
    Package *newPkg = new Package(box);
    Package* temp = this->head;
    newPkg->updateNext(*temp);
    this->head = newPkg;
    return this;
}

Truckload *Truckload::insertEnd(Box &box)
{   
    Package *newPkg = new Package(box);
    Package* temp = this->head;
    if(temp == nullptr){
        this->head = newPkg;
        return this;
    }
    while(temp->nextPackage!=nullptr){
        temp = temp->nextPackage;
    }
    temp->updateNext(*newPkg);
    return this;
}

Truckload *Truckload::sortedInsertbyLength(Box &box)
{   
    Package *newPkg = new Package(box);
    Package *temp  = this->head;

    if(temp == nullptr || temp->box.length>box.length){
        Package* tempPkg = this->head;
        newPkg->updateNext(*tempPkg);
        this->head = newPkg;
        return this;
    }
    while(temp->box.length<newPkg->box.length && temp->nextPackage!=nullptr){
        temp = temp->nextPackage;
    }
    Package *var = temp->nextPackage;
    newPkg->updateNext(*var);
    temp->updateNext(*newPkg);

    return this;
}

Truckload *Truckload::sortedInsertbyBreadth(Box &box)
{
    Package *newPkg = new Package(box);
    Package *temp  = this->head;

    if(temp == nullptr || temp->box.breadth>box.breadth){
        Package* tempPkg = this->head;
        newPkg->updateNext(*tempPkg);
        this->head = newPkg;
        return this;
    }
    while(temp->box.breadth<newPkg->box.breadth && temp->nextPackage!=nullptr){
        temp = temp->nextPackage;
    }
    Package *var = temp->nextPackage;
    newPkg->updateNext(*var);
    temp->updateNext(*newPkg);

    return this;
}

Truckload *Truckload::sortedInsertbyHeight(Box &box)
{
    Package *newPkg = new Package(box);
    Package *temp  = this->head;

    if(temp == nullptr || temp->box.height>box.height){
        Package* tempPkg = this->head;
        newPkg->updateNext(*tempPkg);
        this->head = newPkg;
        return this;
    }
    while(temp->box.height<newPkg->box.height && temp->nextPackage!=nullptr){
        temp = temp->nextPackage;
    }
    Package *var = temp->nextPackage;
    newPkg->updateNext(*var);
    temp->updateNext(*newPkg);

    return this;
}

Truckload *Truckload::sortedInsertbyVolume(Box &box)
{
    return nullptr;
}

Truckload *Truckload::insertBegin(Package &pkg)
{
    return nullptr;
}

Truckload *Truckload::insertEnd(Package &pkg)
{
    return nullptr;
}

Truckload *Truckload::sortedInsertbyLength(Package &pkg)
{
    return nullptr;
}

Truckload *Truckload::sortedInsertbyBreadth(Package &pkg)
{
    return nullptr;
}

Truckload *Truckload::sortedInsertbyHeight(Package &pkg)
{
    return nullptr;
}

Truckload *Truckload::sortedInsertbyVolume(Package &pkg)
{
    return nullptr;
}

Truckload *Truckload::sortByLength()
{
    return nullptr;
}

Truckload *Truckload::sortByBreadth()
{
    return nullptr;
}

Truckload *Truckload::sortByHeight()
{
    return nullptr;
}

Truckload *Truckload::printPackages()
{
    Package *currPkg = this->head;
    while(currPkg!=nullptr){
        std::cout<<currPkg->box<<std::endl<<"-----------------"<<std::endl;
        currPkg = currPkg->nextPackage;
    }
    std::cout<<std::endl;
    
    return this;
}

Truckload *Truckload::deleteBegin()
{
    return nullptr;
}

Truckload *Truckload::deleteEnd()
{
    return nullptr;
}

Truckload *Truckload::deletePackage(Package &package)
{
    return nullptr;
}

std::ostream &operator<<(std::ostream &out, Box& box)
{
   out<<"Length: "<<box.length<<std::endl<<"Breadth: "<<box.breadth<<std::endl<<"Height: "<<box.height<<std::endl<<"Weight: "<<box.weight<<std::endl;
    return out;
}
