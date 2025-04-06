#ifndef __FOO__
#define __FOO__
#include <string>
using namespace std;
class Foo
{
private:
    int _id;//4个字节
    long _data;//4个字节
    string _str;//40个字节
public:
    Foo() :_id(0)       { cout << "default ctor.this = " << this << "id: " << _id << endl; };
    Foo(int i) :_id(i)  { cout << "ctor.this = " << this << "id: " << _id << endl; };
    ~Foo()              { cout << "dtor.this = " << this << "id: " << _id << endl; };
    static void* operator new(size_t size);
    static void operator delete(void* p, size_t size);
    static void* operator new[](size_t size);
    static void operator delete[](void* p, size_t size);
};

void* Foo::operator new(size_t size)
{
    Foo* p = (Foo*)malloc(size);
    cout << "new size = " << size << endl;
    return p;
}

void Foo::operator delete(void* p, size_t size)
{
    cout << "delete size = " << size << endl;
    free(p);
}

void* Foo::operator new[](size_t size)
{
    Foo* p = (Foo*)malloc(size);
    cout << "new[] size = " << size << endl;
    return p;
}

void Foo::operator delete[](void* p, size_t size)
{
    cout << "delete[] size = " << size << endl;
    free(p);
}
// 测试用例
// int main() {
//     Foo* pf = new Foo;
//     delete pf;
//     cout<<"_____________________________________________"<<endl;
//     Foo* pf1 = new Foo[2];
//     delete[] pf1;
// }

#endif