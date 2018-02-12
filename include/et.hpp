#ifndef ET_H
#define ET_H

#include "condition.hpp"

class Et : public Condition {

public:
    Et(const Et &other) : _c1(other._c1), _c2(other._c2) {}

    Et(Condition *c1, Condition *c2) : _c1(c1), _c2(c2) {}

    ~Et() override = default;

    string toString() const override {
        return _c1->toString() + " ET " + _c2->toString();
    }

    bool verif(const Figure *f) const override {
        return (_c1->verif(f)) && (_c2->verif(f));
    }

    Et &operator=(const Et &other) {
        _c1 = other._c1;
        _c2 = other._c2;
        return *this;
    }

private:
    Condition *_c1;
    Condition *_c2;
};

#endif
