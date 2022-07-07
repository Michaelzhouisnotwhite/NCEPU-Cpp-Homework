//
// Created by pce on 2021/3/30.
//

#include "EqCorpus.h"

double EqCorpus::setYearly_interest(double interest) {
    yearly_interest = interest;
    monthly_interest = yearly_interest / 12;
    return 0;
}

EqCorpus::EqCorpus(double debt, double pay_term) : Loan(debt, pay_term){
    yearly_interest = Loan::getYearly_interest();
    monthly_interest = Loan::getMonthly_interest();
    this->debt = Loan::getDebt();
    months = Loan::getMonths();
    monthly_principal = this->debt / months;
}

EqCorpus::EqCorpus(double debt, double pay_term, double yearly_interest) : Loan(debt, pay_term, yearly_interest){
    this->yearly_interest = Loan::getYearly_interest();
    monthly_interest = Loan::getMonthly_interest();
    this->debt = Loan::getDebt();
    months = Loan::getMonths();
    monthly_principal = this->debt / months;
}

double EqCorpus::getPayInfo() {
    /**
     * @brief
     * 还款总额=（还款月数+1）×贷款额×月利率/2+ 贷款额
     */
    return (months + 1) * debt * monthly_interest / 2 + debt;
}
