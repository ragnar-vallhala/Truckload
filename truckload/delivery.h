/*
date 14/04/2023
author Ashutosh
*/

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
    void setHeight(float w);

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
};

class Package
{
private:
    Box *previousBox = nullptr;
    Box *nextBox = nullptr;
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
    @param b: length of box in package
    @param h: length of box in package
    @param w: length of box in package
    */
    Package(float l, float b, float h, float w);

    /*
     Constructor
     @param l: length of box in package
     @param w: length of box in package
     */
    Package(float l, float w);

    /*
    Equal to operation between packages
    @param &package: refernce to a package
    */
    bool operator==(Package &package);
};

class Truckload
{

private:
    Package *head;

public:
    Truckload();

    Truckload *insertBegin(Box &box);

    Truckload *insertEnd(Box &box);

    Truckload *sortedInsertbyLength(Box &box);

    Truckload *sortedInsertbyBreadth(Box &box);

    Truckload *sortedInsertbyHeight(Box &box);

    Truckload *sortedInsertbyVolume(Box &box);

    Truckload *sortByLength();

    Truckload *sortByBreadth();

    Truckload *sortByHeight();

    Truckload *printPackages();

    Truckload *deleteBegin();

    Truckload *deleteEnd();

    Truckload *deletePackage(Package &package);
};