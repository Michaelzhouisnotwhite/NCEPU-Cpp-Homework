#pragma once
#include "header.h"
class Loan {
    double debt{};
    double pay_term = 0;
    double monthly_interest{};
    double yearly_interest{};
    double months{};

public:
    Loan(double debt, double pay_term, double yearly_interest = 0.0486)
        : debt(debt), pay_term(pay_term), yearly_interest(yearly_interest) {}
    double getMonths();
    double getMonthly_interest();
    double getYearly_interest() const;
    double getDebt() const;
    double getPay_term() const;
    virtual double setYearly_interest(double);
    virtual double getPayInfo() = 0; //还款信息
};
