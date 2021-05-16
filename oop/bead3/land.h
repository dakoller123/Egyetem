#pragma once

#include <string>

class Confident;
class Cautious;
class Brave;

// class of abstract lands
class Land {
public:
    virtual bool cross(Confident* p,int n) = 0;
    virtual bool cross(Cautious* p,int n) = 0;
    virtual bool cross(Brave* p,int n) = 0;
    virtual std::string type() const = 0;
    virtual Land* improve() const = 0;
    virtual ~Land() {}
    friend std::ostream &operator<<(std::ostream &os,const Land &land);
};

// class of enemy's land
class Enemy : public Land
{
public:
    static Enemy* instance();
    bool cross(Confident* p,int n) override;
    bool cross(Cautious* p,int n) override;
    bool cross(Brave* p,int n) override;
    std::string type() const override;
    Land* improve() const override;
    static void destroy();
protected:
    Enemy(){}
private:
    static Enemy* _instance;
};

// class of no man's land
class NoMansLand : public Land ///senkiföldje
{
public:
    static NoMansLand* instance();
    bool cross(Confident* p,int n) override;
    bool cross(Cautious* p,int n) override;
    bool cross(Brave* p,int n) override;
    std::string type() const override;
    Land* improve() const override;
    static void destroy() ;
protected:
    NoMansLand(){}
private:
    static NoMansLand* _instance;
};

// class of friend's land
class Friend : public Land
{
public:
    static Friend* instance();
    bool cross(Confident* p,int n) override;
    bool cross(Cautious* p,int n) override;
    bool cross(Brave* p,int n) override;
    std::string type() const override;
    Land* improve() const override;
    static void destroy() ;
protected:
    Friend(){}
private:
    static Friend* _instance;
};
