// Qursaan(c) Copyright
#include <iostream>
using namespace std;

class ISquare
{
public:
    virtual ~ISquare(){}
    virtual void draw()const =0;
};

class ICircle
{
public:
    virtual ~ICircle(){}
    virtual void draw()const =0;
};

class IDiamon
{
public:
    virtual ~IDiamon(){}
    virtual void draw()const =0;
};

class YellowSquare : public ISquare
{
public:
    void draw()const {cout<< "[Y]";}
};

class GreenSquare : public ISquare
{
public:
    void draw()const {cout<< "[G]";}
};

class RedSquare : public ISquare
{
public:
    void draw()const {cout<< "[R]";}
};

class YellowCircle : public ICircle
{
public:
    void draw()const {cout<< "(Y)";}
};

class GreenCircle : public ICircle
{
public:
   void draw()const {cout<< "(G)";}
};

class RedCircle : public ICircle
{
public:
   void draw()const {cout<< "(R)";}
};


class YellowDiamon : public IDiamon
{
public:
   void draw()const {cout<< "<Y>";}
};

class GreenDiamon : public IDiamon
{
public:
   void draw()const {cout<< "<G>";}
};

class RedDiamon : public IDiamon
{
public:
   void draw()const {cout<< "<R>";}
};

class IShapeFactory {
public:
    virtual ~IShapeFactory(){};
    virtual ISquare* createSquare()const =0;
    virtual IDiamon* createDiamon()const =0;
    virtual ICircle* createCircle()const =0;
};

class YellowFactory: public IShapeFactory {
public:
    ISquare* createSquare()const {return new YellowSquare;}
    IDiamon* createDiamon()const {return new YellowDiamon;}
    ICircle* createCircle()const {return new YellowCircle;}
};
class RedFactory: public IShapeFactory {
public:
    ISquare* createSquare()const {return new RedSquare;}
    IDiamon* createDiamon()const {return new RedDiamon;}
    ICircle* createCircle()const {return new RedCircle;}
};
class GreenFactory: public IShapeFactory {
public:
    ISquare* createSquare()const {return new GreenSquare;}
    IDiamon* createDiamon()const {return new GreenDiamon;}
    ICircle* createCircle()const {return new GreenCircle;}
};

void ClientCode(const IShapeFactory &factory){
    const ISquare*s1 = factory.createSquare();
    const ICircle*s2 = factory.createCircle();
    const IDiamon*s3 = factory.createDiamon();

    s1->draw();
    s2->draw();
    s3->draw();
    delete s1;
    delete s2;
    delete s3;
}

int main()
{
    cout << "Client: Testing clientCode with the Yellow factory type:\n";
    IShapeFactory *f1 = new YellowFactory();
    ClientCode(*f1);
    delete f1;
    cout<< endl << endl;

    cout << "Client: Testing clientCode with the Green factory type:\n";
    IShapeFactory *f2 = new GreenFactory();
    ClientCode(*f2);
    delete f2;
    cout<< endl << endl;

    cout << "Client: Testing clientCode with the Red factory type:\n";
    IShapeFactory *f3 = new RedFactory();
    ClientCode(*f3);
    delete f3;
    cout << endl << endl;
    
    return 0;
}
