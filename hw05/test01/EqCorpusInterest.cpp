#include "EqCorpusInterest.h"

EqCorpusInterest::EqCorpusInterest(double debt, double pay_term):Loan(debt, pay_term) {
    yearly_interest = Loan::getYearly_interest();
    monthly_interest = Loan::getMonthly_interest();
    this->debt = debt;
    months = Loan::getMonths();
}
EqCorpusInterest::EqCorpusInterest(double debt, double pay_term, double yearly_interest)
        : Loan(debt, pay_term, yearly_interest) {
    this->yearly_interest = Loan::getYearly_interest();
    monthly_interest = Loan::getMonthly_interest();
    this->debt = debt;
    months = Loan::getMonths();
}
double EqCorpusInterest::setYearly_interest(double interest) {
    yearly_interest = interest;
    monthly_interest = yearly_interest / 12;
    return 0;
}

double EqCorpusInterest::getPayInfo() {
    /**
     * @brief 
     * 每月还款额=[贷款本金×月利率×（1+月利率）^还款月数]÷[（1+月利率）^还款月数－1]
     */
    double member = debt * monthly_interest * pow((1 + monthly_interest), months);
    double denominator = pow((1 + monthly_interest), months) - 1;
    double monthly_pay = member / denominator;
    return monthly_pay * months;
}

