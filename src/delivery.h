/*
date 14/04/2023
author Ashutosh
*/
#pragma once
#include <iostream>

class Box
{

private:
    float length, breadth, height, weight;

public:
    /*
    Default constructor
    */
    Box() = default;

    /*
    Constructor
    @param l: length of box
    @param b: breadth of box
    @param h: height of box
    @param w: weight of box
    */
    Box(float l, float b, float h, float w);

    /*
    Constructor
    @param l: edge of box
    @param w: weight of box
    */
    Box(float l, float w);

    /*
    Copy Constructor
    @param &box: reference to a box
    */
    Box(Box &box);

    /*
    Sets length of box
    @param len: length of box
    */
    void setLength(float len);

    /*
    Sets breadth of box
    @param len: breadth of box
    */
    void setBreadth(float len);

    /*
    Sets height of box
    @param len: height of box
    */
    void setHeight(float len);

    /*
    Sets weight of box
    @param w: weight of box
    */
    void setWeight(float w);

    /*
    Returns volume of the box
    @param None
    */
    float calcVolume();

    /*
    Returns density of the box
    @param None
    */
    float calcDensity();

    /*
    Equal to operation between boxes
    @param &box: reference to a box
    */
    bool operator==(Box &box);

    /*
    Prints the configuration of a box
    */
    friend std::ostream& operator<<(std::ostream& out, Box&box);


    /*
    Declared Truckload as friend class to the Box class to access private members
    */
    friend class Truckload;
};

class Package
{
private:
    Package *previousPackage = nullptr;
    Package *nextPackage = nullptr;
    Box box;

public:
    friend class Truckload;
    /*
    Default constructor
    */
    Package() = default;

    /*
    Constructor
    @param l: length of box in package
    @param b: breadth of box in package
    @param h: height of box in package
    @param w: weight of box in package
    */
    Package(float l, float b, float h, float w);

    /*
     Constructor
     @param l: length of box in package
     @param w: weight of box in package
     */
    Package(float l, float w);

    /*
     Constructor
     @param box: reference to box
     */
    Package(Box &box);

    /*
    Equal to operation between packages
    @param &package: refernce to a package
    */
    bool operator==(Package &package);


    /*
    Updates next package address
    @param &pkg: refernce to a package
    */
    void updateNext(Package &pkg);

    /*
    Updates previous package address
    @param &pkg: refernce to a package
    */
    void updatePrevious(Package &pkg);

    

};


class Truckload
{

private:
    Package *head = nullptr;

public:

    /*
    Constructer
    */
    Truckload() = default;
    /*
    Constructer
    @param box: reference to box
    */
    Truckload(Box &box);
    
    /*
    Inserts package at the beginning of truckload
    @param box: reference to a box 
    */
    Truckload *insertBegin(Box &box);
    
    Truckload *insertEnd(Box &box);

    Truckload *sortedInsertbyLength(Box &box);

    Truckload *sortedInsertbyBreadth(Box &box);

    Truckload *sortedInsertbyHeight(Box &box);

    Truckload *sortedInsertbyVolume(Box &box);

    Truckload *insertBegin(Package &pkg);
    
    Truckload *insertEnd(Package &pkg);

    Truckload *sortedInsertbyLength(Package &pkg);

    Truckload *sortedInsertbyBreadth(Package &pkg);

    Truckload *sortedInsertbyHeight(Package &pkg);

    Truckload *sortedInsertbyVolume(Package &pkg);

    Truckload *sortByLength();

    Truckload *sortByBreadth();

    Truckload *sortByHeight();

    Truckload *printPackages();

    Truckload *deleteBegin();

    Truckload *deleteEnd();

    Truckload *deletePackage(Package &package);
};