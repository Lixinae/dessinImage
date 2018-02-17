#ifndef ET_H
#define ET_H

#include "condition.hpp"

class Et : public Condition {

public:
    Et(const Et &other);

    Et(Condition *c1, Condition *c2);

    ~Et() override = default;

    string toString() const override;

    bool verif(const Figure *f) const override;


    Et &operator=(const Et &other);

private:
    Condition *_c1;
    Condition *_c2;
};

#endif
