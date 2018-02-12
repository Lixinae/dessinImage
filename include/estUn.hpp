
#ifndef ESTUN_H
#define ESTUN_H

#include <cstring>
#include <typeinfo>
#include "condition.hpp"

class EstUn : public Condition {

public:
    EstUn(const EstUn &other) : ftemoin(other.ftemoin) {}

    explicit EstUn(const Figure *f) : ftemoin(f) {}

    ~EstUn() override = default;

    string toString() const override {
        return "EST UN " + string(typeid(*ftemoin).name());
    }

    bool verif(const Figure *f) const override {
        return typeid(*ftemoin) == typeid(*f);
    }

    EstUn &operator=(const EstUn &other) {
        ftemoin = other.ftemoin;
        return *this;
    }

private :
    const Figure *ftemoin;
};

#endif
