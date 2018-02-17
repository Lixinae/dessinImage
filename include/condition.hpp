
#ifndef CONDITION_H
#define CONDITION_H

#include <list>
#include "figure.hpp"

using namespace figure;

class Condition {
public:
    virtual bool verif(const Figure *f) const = 0;

    virtual string toString() const = 0;

protected:
    virtual ~Condition() = default;
};

#endif
