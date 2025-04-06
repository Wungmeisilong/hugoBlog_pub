#ifndef __TESTCODE__
#define __TESTCODE__

class complex
{
private:
    /* data */
    double re,im;
    friend complex& __doapl (complex*,const complex&);
public:
    complex (double r,double i)
    :re(r),im(i)                //这是一个构造函数，这种写法意思是初始化变量
    {};
    complex& operator += (complex operator&);
    double read () const {return re;}  //这里需要加const 意思就是修饰函数的返回值，不允许改变返回值类型
    double imag () const {return im;}
};

#endif