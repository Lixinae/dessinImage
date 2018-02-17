
#ifndef NON_H
#define NON_H

#include "condition.hpp"

class Non : public Condition {

public:

    Non(const Non &other);

    explicit Non(Condition *c);

    ~Non() override = default;

    string toString() const override;

    bool verif(const Figure *f) const override;

    Non &operator=(const Non &other);

private:
    Condition *condition;
};

#endif
