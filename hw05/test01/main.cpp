#include "EqCorpusInterest.h"
#include "EqCorpus.h"
void Show(Loan *);
int main()
{
    // Loan *p;
    EqCorpusInterest eci(120000, 10);
    EqCorpus ec(120000, 10);
    cout << "����: 120000" << "\n�������ޣ��꣩: " << 10 << endl;
    cout << "�ȶϢ�����ܶ" << endl;
    Show(&eci);
    cout.put('\n');
    cout << "�ȶ�𻹿��ܶ" << endl;
    Show(&ec);
    cout.put('\n');
    system("pause");
    return 0;
}

void Show(Loan *p) {
    cout  << fixed << setprecision(2) << p->getPayInfo();
}