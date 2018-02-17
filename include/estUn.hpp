
#ifndef ESTUN_H
#define ESTUN_H

#include <cstring>
#include <typeinfo>
#include "condition.hpp"

class EstUn : public Condition {

public:
    EstUn(const EstUn &other);

    explicit EstUn(const Figure *f) : ftemoin(f) {}

    ~EstUn() override = default;

    /**
     *
     * @return Une string avec le type
     */
    string toString() const override;

    /**
     *
     * @param f
     * @return
     */
    bool verif(const Figure *f) const override;

    /**
     *
     * @param other
     * @return
     */
    EstUn &operator=(const EstUn &other);
private :
    /**
     * Figure temoin
     */
    const Figure *ftemoin;
};

#endif
