
#ifndef NON_H
#define NON_H

#include "condition.hpp"

class Non : public Condition {

public:

    Non(const Non &other) : condition(other.condition) {}

    explicit Non(Condition *c) : condition(c) {}

    ~Non() override = default;

    string toString() const override {
        return "NON " + condition->toString();
    }

    bool verif(const Figure *f) const override {
        return !(condition->verif(f));
    }

    Non &operator=(const Non &other) {
        condition = other.condition;
        return *this;
    }

private:
    Condition *condition;
};

#endif
