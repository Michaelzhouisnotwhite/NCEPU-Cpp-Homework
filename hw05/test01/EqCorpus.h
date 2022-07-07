//
// Created by pce on 2021/3/30.
//
#include "Loan.h"

class EqCorpus:public Loan {
    double debt{};
    double pay_term = 0;
    double monthly_interest{};
    double yearly_interest{};
    double months{};
    double monthly_principal{};
public:
    EqCorpus(double, double);
    EqCorpus(double, double , double );
    double setYearly_interest(double ) override;
    double getPayInfo() override;
};


