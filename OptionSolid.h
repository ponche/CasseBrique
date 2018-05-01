#ifndef OPTIONSOLID_H_INCLUDED
#define OPTIONSOLID_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

#include "OptionBrique.h"


class OptionSolid : public OptionBrique
{
protected :

public:
    OptionSolid() ;
    ~OptionSolid() ;

    void start() ;

};



#endif // OPTIONSOLID_H_INCLUDED
