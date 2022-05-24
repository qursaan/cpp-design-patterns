#include <iostream>
using namespace std;

class ISquare
{
public:
    virtual draw()=0;
};

class ICircle
{
public:
    virtual draw()=0;
};

class IDiamon
{
public:
    virtual draw()=0;
};

class YellowSquare : public ISquare
{
public:
        draw(){
        cout<< "[Y]";
    }
};

class GreenSquare : public ISquare
{
public:
        draw(){cout<< "[G]";}
};

class RedSquare : public ISquare
{
public:
        draw(){cout<< "[R]";}
};

class YellowCircle : public ICircle
{
public:
        draw(){cout<< "(Y)";}
};

class GreenCircle : public ICircle
{
public:
        draw(){cout<< "(G)";}
};

class RedCircle : public ICircle
{
public:
        draw(){cout<< "(R)";}
};


class YellowDiamon : public IDiamon
{
public:
    draw(){cout<< "<Y>";}
};

class GreenDiamon : public IDiamon
{
public:
    draw(){cout<< "<G>";}
};

class RedDiamon : public IDiamon
{
public:
    draw(){cout<< "<R>";}
};

class IShapeFactory {
public:
    virtual ISquare* createSquare()=0;
    virtual IDiamon* createDiamon()=0;
    virtual ICircle* createCircle()=0;
};

class YellowFactory: public IShapeFactory {
public:
    ISquare* createSquare(){return new YellowSquare;}
    IDiamon* createDiamon(){return new YellowDiamon;}
    ICircle* createCircle(){return new YellowCircle;}
};
class RedFactory: public IShapeFactory {
public:
    ISquare* createSquare(){return new RedSquare;}
    IDiamon* createDiamon(){return new RedDiamon;}
    ICircle* createCircle(){return new RedCircle;}
};
class GreenFactory: public IShapeFactory {
public:
    ISquare* createSquare(){return new GreenSquare;}
    IDiamon* createDiamon(){return new GreenDiamon;}
    ICircle* createCircle(){return new GreenCircle;}
};
int main()
{
    IShapeFactory *factory = new YellowFactory(); //try another factory without any change

    ISquare*s1 = factory->createSquare();
    ICircle*s2 = factory->createCircle();
    IDiamon*s3 = factory->createDiamon();

    s1->draw();
    s2->draw();
    s3->draw();

    return 0;
}
