#include "land.h"
#include "adventurer.h"

using namespace std;

std::ostream &operator<<(std::ostream &os,const Land &land)
{
    os << land.type()<< "'s land";
    return os;
}

// implementation of class Enemy
Enemy* Enemy::_instance = nullptr;
Enemy* Enemy::instance()
{
    if(_instance == nullptr) {
        _instance = new Enemy();
    }
    return _instance;
}
void Enemy::destroy()
{
    if ( nullptr!=_instance )
    {
        delete _instance;
        _instance = nullptr;
    }
}

bool Enemy::cross(Confident *p,int n)
{
    p->changeHealth(-90/n);
    return p->in();
}

bool Enemy::cross(Cautious *p,int n)
{
    p->changeHealth(-80/n);
    return p->in();
}

bool Enemy::cross(Brave *p,int n)
{
    p->changeHealth(-100/n);
    return p->in();
}

std::string Enemy::type() const
{
    return "Enemy";
}

Land* Enemy::improve() const
{
    return NoMansLand::instance();
}

// implementation of class NoMansLand
NoMansLand* NoMansLand::_instance = nullptr;
NoMansLand* NoMansLand::instance()
{
    if(_instance == nullptr) {
        _instance = new NoMansLand();
    }
    return _instance;
}
void NoMansLand::destroy()
{
    if ( nullptr!=_instance )
    {
        delete _instance;
        _instance = nullptr;
    }
}

bool NoMansLand::cross(Confident *p,int n)
{
    return true;
}

bool NoMansLand::cross(Cautious *p,int n)
{
    return true;
}

bool NoMansLand::cross(Brave *p,int n)
{
    return true;
}

std::string NoMansLand::type() const
{
    return "No man";
}

Land* NoMansLand::improve() const
{
    return Friend::instance();
}


// implementation of class Friend
Friend* Friend::_instance = nullptr;
Friend* Friend::instance()
{
    if(_instance == nullptr) {
        _instance = new Friend();
    }
    return _instance;
}
void Friend::destroy()
{
    if ( nullptr!=_instance )
    {
        delete _instance;
        _instance = nullptr;
    }
}

bool Friend::cross(Confident *p,int n)
{
    p->changeHealth(90/n);
    return true;
}

bool Friend::cross(Cautious *p,int n)
{
    p->changeHealth(80/n);
    return true;
}

bool Friend::cross(Brave *p,int n)
{
    p->changeHealth(100/n);
    return true;
}

std::string Friend::type() const
{
    return "Friend";
}

Land* Friend::improve() const
{
    return Friend::instance();
}
