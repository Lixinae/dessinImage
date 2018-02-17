
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

    /**
     *
     * @return Une string avec le type
     */
    string toString() const override {
        return "EST UN " + string(typeid(*ftemoin).name());
    }

    /**
     *
     * @param f
     * @return
     */
    bool verif(const Figure *f) const override {
        return typeid(*ftemoin) == typeid(*f);
    }

    /**
     *
     * @param other
     * @return
     */
    EstUn &operator=(const EstUn &other) {
        ftemoin = other.ftemoin;
        return *this;
    }

private :
    /**
     * Figure temoin
     */
    const Figure *ftemoin;
};

#endif
