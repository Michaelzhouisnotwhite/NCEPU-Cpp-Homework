#include "Loan.h"
class EqCorpusInterest:public Loan {
    double debt{};
    double pay_term = 0;
    double monthly_interest{};
    double yearly_interest{};
    double months{};
public:
    EqCorpusInterest(double , double);
    EqCorpusInterest(double debt, double pay_term, double yearly_interest);
    double setYearly_interest(double ) override;
    double getPayInfo() override;
};