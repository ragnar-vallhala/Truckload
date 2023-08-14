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
    void setBreadth(float brd);

    /*
    Sets height of box
    @param len: height of box
    */
    void setHeight(float ht);

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
    friend std::ostream &operator<<(std::ostream &out, Box &box);

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
    Constructor
    */
    Truckload() = default;
    /*
    Constructor
    @param box: reference to box
    */
    Truckload(Box &box);

    /*
    Inserts package at the beginning of truckload
    @param box: reference to a box
    */
    Truckload *insertBegin(Box &box);

    /*
    Inserts package at the end of truckload
    @param box: reference to a box
    */
    Truckload *insertEnd(Box &box);

    /*
    Inserts package in ascending order of length
    @param box: reference to a box
    */
    Truckload *sortedInsertbyLength(Box &box);

    /*
    Inserts package in ascending order of breadth
    @param box: reference to a box
    */
    Truckload *sortedInsertbyBreadth(Box &box);

    /*
    Inserts package in ascending order of height
    @param box: reference to a box
    */
    Truckload *sortedInsertbyHeight(Box &box);

    /*
    Inserts package in ascending order of volume
    @param box: reference to a box
    */
    Truckload *sortedInsertbyVolume(Box &box);

    /// @brief Inserts the package at the beginning of the truck
    /// @param pkg :reference to a package
    Truckload *insertBegin(Package &pkg);

    /// @brief Inserts the package at the end of the truck
    /// @param pkg :reference to a package
    Truckload *insertEnd(Package &pkg);

    /// @brief inserts a package in ascending order of length
    /// @param pkg : reference to a package
    Truckload *sortedInsertbyLength(Package &pkg);

    /// @brief inserts a package in ascending order of breadth
    /// @param pkg : reference to a package
    Truckload *sortedInsertbyBreadth(Package &pkg);

    /// @brief inserts a package in ascending order of height
    /// @param pkg : reference to a package
    Truckload *sortedInsertbyHeight(Package &pkg);

    /// @brief inserts a package in ascending order of volume of the package
    /// @param pkg : reference to a package
    Truckload *sortedInsertbyVolume(Package &pkg);

    /// @brief sorts the packages by length
    Truckload *sortByLength();

    /// @brief sorts the packages by breadth
    Truckload *sortByBreadth();

    /// @brief sorts the packages by height
    Truckload *sortByHeight();

    /// @brief prints the dimensions of the packages in the truckload 
    Truckload *printPackages();

    /// @brief 
    Truckload *deleteBegin();

    /// @brief
    Truckload *deleteEnd();

    /// @brief
    /// @param package
    Truckload *deletePackage(Package &package);
};