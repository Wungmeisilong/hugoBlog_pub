#ifndef __FRACTION__
#define __FRACTION__
class Fraction
{
private:
    int m_num, m_den;
public:
    explicit Fraction(int num, int den = 1)
    : m_num(num),m_den(den){}
    opertaor double() const {
        return (double)(m_num/m_den);
    }
    Fraction operator + (const Fraction& f){
        return Fraction(……);
    }
};
#endif