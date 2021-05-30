#pragma once
#include <string>
class Fogas{
private:
    int _weight;
    std::string _verseny_id;
protected:
    virtual int getBaseValue() const = 0;
public:
    Fogas(int weight, std::string verseny_id) : _weight(weight), _verseny_id(verseny_id) {}
    int getValue(){return _weight * getBaseValue();}
    virtual bool is_Harcsa() const {return false;}
    virtual ~Fogas(){}
    std::string getVersenyId(){return _verseny_id;}
};

class Ponty: public Fogas{
protected:
    int getBaseValue() const  override  {return 2;}
public:
    Ponty(int weight, std::string verseny_id): Fogas(weight, verseny_id){};
};

class Keszeg: public Fogas{
protected:
    int getBaseValue()  const override {return 1;}
public:
    Keszeg(int weight, std::string verseny_id): Fogas(weight, verseny_id){};
};

class Harcsa: public Fogas{
protected:
    int getBaseValue()  const  override {return 4;}
public:
    bool is_Harcsa()  const override {return true;}
    Harcsa(int weight, std::string verseny_id): Fogas(weight, verseny_id){};
};
