#include "Loan.h"
double Loan::getMonths() {
    months = pay_term * 12;
    return months;
}

double Loan::getMonthly_interest() {
    monthly_interest = yearly_interest / 12;
    return monthly_interest;
}

double Loan::getYearly_interest() const{
   return yearly_interest;
}

double Loan::getDebt() const {
    return debt;
}

double Loan::getPay_term() const {
    return pay_term;
}

double Loan::setYearly_interest(double interest) {
    yearly_interest = interest;
    return 0;
}
