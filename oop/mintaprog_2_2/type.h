#ifndef TYPE_H
#define TYPE_H

enum Status { abnorm, norm };

struct Hunting {
    std::string name;
    std::string date;
    int bears_no;
    double bears_we;
    bool reindeer;
};

struct Hunter {
    std::string name;
    int bears_no;
    bool reindeer;
};

#endif // TYPE_H
