#pragma once
#include <string>
#include <ostream>
#include <stdlib.h>
#include "land.h"

// class of abstract adventurers
class Adventurer
{
private:
    static bool _randomized_;

protected:
    std::string _name;
    int _health;

    Adventurer (const std::string &name, int health = 100) :_name(name), _health(health) { if (_health > maxHealth) _health = maxHealth; }

public:
    static const int maxHealth = 100;

    std::string name() const{ return _name; }
    int health() const { return _health; }
    bool alive() const { return _health > 0; }
    void heal() { _health = maxHealth; }
    void changeHealth(int health)
    {
        if (_randomized_)
        {
            int multiplier = (health < 0) ? -1 : 1;
            health = multiplier * rand() % abs(health) + 1;
        }
        _health += health;
        if (_health < 0) _health = 0;
        if (_health > 100) _health = 100;
    }
    virtual bool cross(Land* land,int n) = 0;
    virtual bool in() const = 0;
    virtual ~Adventurer () {}
    friend std::ostream &operator<<(std::ostream &os,const Adventurer &a)
    {
        os<<a._name<< " ("<<a._health<<")";
        return os;
    }
};

/*void Adventurer::changeHealth(int health)
{
    if (_randomized_)
    {
        int multiplier = (health < 0) ? -1 : 1;
        health = multiplier * rand() % abs(health) + 1;
    }
    _health += health;
    if (_health < 0) _health = 0;
    if (_health > 100) _health = 100;
}

std::ostream &operator<<(std::ostream &os,const Adventurer &a)
{
    os<<a._name<< " ("<<a._health<<")";
    return os;
}*/


// class of confident adventurer
class Confident : public Adventurer
{
public:
    Confident(const std::string &name, int health = 100) : Adventurer(name, health) { }
    bool cross(Land* land,int n) override { return land->cross(this,n); }
    bool in() const override { return _health > 20; }
};

// class of cautious adventurer
class Cautious : public Adventurer
{
public:
    Cautious(const std::string &name, int health = 100) : Adventurer(name, health) { }
    bool cross(Land* land,int n) override { return land->cross(this,n); }
    bool in() const override { return _health > 40; }
};

// class of brave adventurer
class Brave : public Adventurer
{
public:
    Brave(const std::string &name, int health = 100) : Adventurer(name, health) { }
    bool cross(Land* land,int n) override { return land->cross(this,n); }
    bool in() const override { return _health > 10; }
};

