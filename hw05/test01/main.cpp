#include "EqCorpusInterest.h"
#include "EqCorpus.h"
void Show(Loan *);
int main()
{
    // Loan *p;
    EqCorpusInterest eci(120000, 10);
    EqCorpus ec(120000, 10);
    cout << "本金: 120000" << "\n还款年限（年）: " << 10 << endl;
    cout << "等额本息还款总额：" << endl;
    Show(&eci);
    cout.put('\n');
    cout << "等额本金还款总额：" << endl;
    Show(&ec);
    cout.put('\n');
    system("pause");
    return 0;
}

void Show(Loan *p) {
    cout  << fixed << setprecision(2) << p->getPayInfo();
}