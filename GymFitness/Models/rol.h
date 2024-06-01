#ifndef ROL_H
#define ROL_H
#include <string>

class Rol
{
public:
    Rol(int id, std::string description);

    std::string getDescription() const { return description; }
    int getId( ) const { return id; }


private:
    int id;
    std::string description;
};

#endif // ROL_H
