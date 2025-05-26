#ifndef MYTINYSTL_UTIL_H_
#define MYTINYSTL_UTIL_H_

// 这个文件包含一些通用工具，包括 move, forward, swap 等函数，以及 pair 等 

#include <cstddef> //该库包含 size_t, ptrdiff_t 等类型

#include "type_traits.h"

namespace mystl
{

/* move
* 作用：​将任意类型的实参无条件转换为右值引用（rvalue reference）​​，从而允许移动语义（如调用移动构造函数或移动赋值运算符）。
* 模板参数：
*   T - 任意类型
* 参数：
*   arg - 任意类型的实参
* 返回值：
*   返回 arg 的右值引用*/
template <class T>
typename std::remove_reference<T>::type&& move(T&& arg) noexcept //移除引用修饰（std::remove_reference<T>），确保无论T是否引用类型，最终返回的类型都是非引用类型的右值引用
{
  return static_cast<typename std::remove_reference<T>::type&&>(arg);
}

// forward：这是一个重载函数，它能够将参数 arg 转换为右值引用

template <class T>
T&& forward(typename std::remove_reference<T>::type& arg) noexcept // 确保无论T是否为引用类型，最终返回类型都是​​非引用类型的右值引用
{
  return static_cast<T&&>(arg); //将arg强制转换为目标类型（右值引用）
}

template <class T>
T&& forward(typename std::remove_reference<T>::type&& arg) noexcept
{
  static_assert(!std::is_lvalue_reference<T>::value, "bad forward");
  return static_cast<T&&>(arg); //将arg强制转换为目标类型（右值引用）
}

// swap：交换两个对象

template <class Tp>
void swap(Tp& lhs, Tp& rhs)
{
  auto tmp(mystl::move(lhs)); // 保存左值
  lhs = mystl::move(rhs);
  rhs = mystl::move(tmp);
}

/* 定义一个模板函数 swap_range，用于交换两个前向迭代器范围内的元素
* 模板参数：
*   ForwardIter1 - 第一个范围的前向迭代器类型
*   ForwardIter2 - 第二个范围的前向迭代器类型
* 参数：
*   first1 - 第一个范围的起始迭代器
*   last1  - 第一个范围的结束迭代器（指向末尾的下一个位置）
*   first2 - 第二个范围的起始迭代器
* 返回值：
*   返回交换完成后的第二个范围的结束迭代器（即 first2 + (last1 - first1)）*/
template <class ForwardIter1, class ForwardIter2>
ForwardIter2 swap_range(ForwardIter1 first1, ForwardIter1 last1, ForwardIter2 first2) 
{
  // 遍历第一个范围 [first1, last1)
  for (; first1 != last1; ++first1, (void) ++first2) 
  {
    // 使用自定义的 swap 函数交换两个迭代器指向的元素
    mystl::swap(*first1, *first2); 
    // 注意：此处 (void)++first2 的作用是显式忽略递增操作的返回值，
    // 避免某些编译器对未使用表达式结果的警告（如-Wunused-value）
  }
  
  // 返回交换完成后的第二个范围的结束迭代器
  // 该迭代器指向第二个范围中最后一个被交换元素的下一个位置
  return first2;
}
/* 
 * 作用：交换两个相同类型且长度相等的数组的所有元素。
 * 模板参数：
 *   Tp - 数组元素的类型（如 int、std::string 等）
 *   N  - 数组的长度（编译期常量）
 * 参数：
 *   a - 第一个数组的左值引用，类型为 Tp[N]
 *   b - 第二个数组的左值引用，类型为 Tp[N]
 * 返回值：
 *   无
 */
template <class Tp, size_t N>
void swap(Tp(&a)[N], Tp(&b)[N]) 
{
  // 调用 mystl::swap_range，遍历交换两个数组的每个元素
  // a 指向第一个数组的首地址，a + N 指向第一个数组的末尾（尾后位置）
  // b 指向第二个数组的首地址
  mystl::swap_range(a, a + N, b);
}

// --------------------------------------------------------------------------------------
// pair

// 结构体模板 : pair
// 两个模板参数分别表示两个数据的类型
// 用 first 和 second 来分别取出第一个数据和第二个数据
template <class Ty1, class Ty2>
struct pair
{
  typedef Ty1    first_type;
  typedef Ty2    second_type;

  first_type first;    // 保存第一个数据
  second_type second;  // 保存第二个数据

  // default constructiable
  /*
  * 作用：这段代码是一个模板元编程的典型应用，用于创建一个 pair 对象。
          只有当Other1和Other2都是可默认构造的类型时，这个构造函数才会启用，
          如果任一类型不可默认构造，这个构造函数会被SFINAE排除掉。
          确保了在编译期就能发现类型错误，而不是在运行时才发现问题。
  * 模板参数：
  *  typename = typename std::enable_if<...>::type
  *         1. typename = typename 第一个typename表示这是一个默认模板参数,第二个typename表示后面的表达式是一个依赖类型名
  *         2. std::enable_if 
  *                           如果条件为true，enable_if会定义一个type成员，类型是它的第二个模板参数（这里是void）；
  *                           如果条件为false，则不会定义type成员，导致SFINAE，使得这个函数模板不会参与重载解析。
  *         3. <...>::type 表示两个条件必须满足，检查Other1和Other2类型是否都可以默认构造
  *         
  */
  template <class Other1 = Ty1, class Other2 = Ty2,
    typename = typename std::enable_if< 
    std::is_default_constructible<Other1>::value &&
    std::is_default_constructible<Other2>::value, void>::type>
    constexpr pair()
    : first(), second()
  {
  }

  // implicit constructiable for this type 
  // 模板构造函数：允许隐式转换的构造函数
  template <class U1 = Ty1, class U2 = Ty2,
    typename std::enable_if<                // SFINAE条件检查
    std::is_copy_constructible<U1>::value &&  // U1类型可以拷贝构造
    std::is_copy_constructible<U2>::value &&  // U2类型可以拷贝构造
    std::is_convertible<const U1&, Ty1>::value &&  // const U1& 可以隐式转换为 Ty1
    std::is_convertible<const U2&, Ty2>::value,   // const U2& 可以隐式转换为 Ty2
    int>::type = 0>                               // enable_if成功时类型为int，默认值为0
    constexpr pair(const Ty1& a, const Ty2& b)    // 构造函数参数
    : first(a), second(b)                         //初始化列表
  {
  }

  // explicit constructible for this type
  /*
  作用：当参数Ty1和Ty2类型都可以拷贝构造，且至少有一个参数 
  const U1& 不能隐式转换为 Ty1，或者 const U2& 不能隐式转换为 Ty2 时。
  调用这个构造函数。
  */
// 1. explicit：防止隐式类型转换，必须显式调用构造函数
// 2. constexpr：表示这个构造函数可以在编译时求值（C++11 及以上）
  template <class U1 = Ty1, class U2 = Ty2,
    typename std::enable_if<
    std::is_copy_constructible<U1>::value &&
    std::is_copy_constructible<U2>::value &&
    (!std::is_convertible<const U1&, Ty1>::value ||
     !std::is_convertible<const U2&, Ty2>::value), int>::type = 0>
    explicit constexpr pair(const Ty1& a, const Ty2& b)
    : first(a), second(b)
  {
  }

  pair(const pair& rhs) = default; //
  pair(pair&& rhs) = default;

  // implicit constructiable for other type
  /*
  *作用：这个构造函数允许使用任意类型的参数来构造pair对象，只要这些参数可以转换为pair的成员类型。
        它支持移动语义，能够高效处理临时对象，避免不必要的拷贝。
    参数说明：
            1.Other1&& a和Other2&& b是通用引用(universal reference)，可以接受左值或右值，这与普通右值引用不同，通用引用可以绑定到任何值类别。
            2.完美转发：mystl::forward<Other1>(a)保留了参数a的值类别（左值保持左值，右值保持右值），确保如果传入临时对象，可以触发移动构造而非拷贝构造；
            3.SFINAE：只有当所有类型转换条件都满足时，这个构造函数才会被启用，否则排除。
            4.与explicit构造函数相对，这个构造函数允许隐式转换。
  */
  // 隐式构造函数：接受其他类型参数的构造函数（支持移动语义）
template <class Other1, class Other2,  // 定义两个不同于pair原始类型的模板参数
    typename std::enable_if<           // SFINAE条件开始
    std::is_constructible<Ty1, Other1>::value &&  // 检查Ty1是否可以由Other1构造
    std::is_constructible<Ty2, Other2>::value &&  // 检查Ty2是否可以由Other2构造
    std::is_convertible<Other1&&, Ty1>::value &&  // 检查Other1的右值引用是否可转换为Ty1
    std::is_convertible<Other2&&, Ty2>::value,    // 检查Other2的右值引用是否可转换为Ty2
    int>::type = 0>                     // enable_if成功时类型为int，默认值为0
    constexpr pair(Other1&& a, Other2&& b)  // 构造函数参数为通用引用，可接受左值或右值
    : first(mystl::forward<Other1>(a)),     // 使用完美转发初始化first成员
    second(mystl::forward<Other2>(b))       // 使用完美转发初始化second成员
{
}

  // explicit构造函数：用于需要显式类型转换的情况
template <class Other1, class Other2,  // 定义两个模板参数，用于接收不同于pair原始类型的参数
    typename std::enable_if<           // SFINAE条件开始
        // 检查Other1是否可以构造Ty1，Other2是否可以构造Ty2
        std::is_constructible<Ty1, Other1>::value &&  
        std::is_constructible<Ty2, Other2>::value &&
        // 检查是否至少有一个类型不能隐式转换,就是不能隐式转换的类型，需要显示转换
        (!std::is_convertible<Other1, Ty1>::value ||  
         !std::is_convertible<Other2, Ty2>::value),
        int>::type = 0>               // enable_if成功时类型为int，默认值为0
    explicit constexpr pair(Other1&& a, Other2&& b)  // 构造函数参数为通用引用
    : first(mystl::forward<Other1>(a)),    // 使用完美转发初始化first
      second(mystl::forward<Other2>(b))    // 使用完美转发初始化second
{
}

  // 这个构造函数是一个从其他pair类型构造当前pair类型的隐式转换构造函数
  /*
  使用const pair<Other1, Other2>& other作为参数的原因：
      1.支持不同类型pair之间的转换
      2. 使用const引用的原因，安全性好、兼容性高、效率高
  */
template <class Other1, class Other2,
  typename std::enable_if<
  std::is_constructible<Ty1, const Other1&>::value &&  // 确保可以从Other1构造Ty1
  std::is_constructible<Ty2, const Other2&>::value &&  // 确保可以从Other2构造Ty2
  std::is_convertible<const Other1&, Ty1>::value &&    // 确保可以隐式转换
  std::is_convertible<const Other2&, Ty2>::value, int>::type = 0>
  constexpr pair(const pair<Other1, Other2>& other)    // 接受其他pair类型的常量引用
  : first(other.first),    // 使用other的first初始化当前pair的first
    second(other.second)   // 使用other的second初始化当前pair的second
{
}

  // 允许从pair<Other1, Other2>类型构造pair<Ty1, Ty2>类型，这个构造函数是一个从其他pair类型构造当前pair类型的显式转换构造函数
  template <class Other1, class Other2,
    typename std::enable_if<
    // 确保可以从const Other构造Ty
    std::is_constructible<Ty1, const Other1&>::value &&
    std::is_constructible<Ty2, const Other2&>::value &&
    // 检查是否至少有一个类型不能隐式转换,
    (!std::is_convertible<const Other1&, Ty1>::value ||
     !std::is_convertible<const Other2&, Ty2>::value), int>::type = 0>
    explicit constexpr pair(const pair<Other1, Other2>& other)
    : first(other.first),
    second(other.second)
  {
  }

  // implicit constructiable for other pair
  template <class Other1, class Other2,
    typename std::enable_if<
    std::is_constructible<Ty1, Other1>::value &&
    std::is_constructible<Ty2, Other2>::value &&
    std::is_convertible<Other1, Ty1>::value &&
    std::is_convertible<Other2, Ty2>::value, int>::type = 0>
    constexpr pair(pair<Other1, Other2>&& other)
    : first(mystl::forward<Other1>(other.first)),//使用完美转发从一个pair隐式构造另一个pair对象。
    second(mystl::forward<Other2>(other.second))
  {
  }

  // explicit constructiable for other pair
  template <class Other1, class Other2,
    typename std::enable_if<
    std::is_constructible<Ty1, Other1>::value &&
    std::is_constructible<Ty2, Other2>::value &&
    (!std::is_convertible<Other1, Ty1>::value ||
     !std::is_convertible<Other2, Ty2>::value), int>::type = 0>
    explicit constexpr pair(pair<Other1, Other2>&& other)
    : first(mystl::forward<Other1>(other.first)),//使用完美转发从一个pair显示构造另一个pair对象。
    second(mystl::forward<Other2>(other.second))
  {
  }

  // copy assign for this pair
  pair& operator=(const pair& rhs)
  {
    if (this != &rhs)
    {
      first = rhs.first;
      second = rhs.second;
    }
    return *this;
  }

  // move assign for this pair
  pair& operator=(pair&& rhs)
  {
    if (this != &rhs)
    {
      first = mystl::move(rhs.first);
      second = mystl::move(rhs.second);
    }
    return *this;
  }

  // copy assign for other pair
  template <class Other1, class Other2>
  pair& operator=(const pair<Other1, Other2>& other)
  {
    first = other.first;
    second = other.second;
    return *this;
  }

  // move assign for other pair
  template <class Other1, class Other2>
  pair& operator=(pair<Other1, Other2>&& other)
  {
    first = mystl::forward<Other1>(other.first);
    second = mystl::forward<Other2>(other.second);
    return *this;
  }

  /**
   * @brief 默认析构函数
   */
  ~pair() = default;

  /**
   * @brief 交换当前pair对象与另一个pair对象的内容
   * @param other 要交换的另一个pair对象
   * @note 如果传入的是同一个对象，则不执行任何操作
   */
  void swap(pair &other)
  {
    if (this != &other)
    {
      mystl::swap(first, other.first);
      mystl::swap(second, other.second);
    }
  }
};

// 重载比较操作符 
template <class Ty1, class Ty2>
bool operator==(const pair<Ty1, Ty2>& lhs, const pair<Ty1, Ty2>& rhs)
{
  return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <class Ty1, class Ty2>
bool operator<(const pair<Ty1, Ty2>& lhs, const pair<Ty1, Ty2>& rhs)
{
  return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
}

template <class Ty1, class Ty2>
bool operator!=(const pair<Ty1, Ty2>& lhs, const pair<Ty1, Ty2>& rhs)
{
  return !(lhs == rhs);
}

template <class Ty1, class Ty2>
bool operator>(const pair<Ty1, Ty2>& lhs, const pair<Ty1, Ty2>& rhs)
{
  return rhs < lhs;
}

template <class Ty1, class Ty2>
bool operator<=(const pair<Ty1, Ty2>& lhs, const pair<Ty1, Ty2>& rhs)
{
  return !(rhs < lhs);
}

template <class Ty1, class Ty2>
bool operator>=(const pair<Ty1, Ty2>& lhs, const pair<Ty1, Ty2>& rhs)
{
  return !(lhs < rhs);
}

// 重载 mystl 的 swap
template <class Ty1, class Ty2>
void swap(pair<Ty1, Ty2>& lhs, pair<Ty1, Ty2>& rhs)
{
  lhs.swap(rhs);
}

// 全局函数，让两个数据成为一个 pair
template <class Ty1, class Ty2>
pair<Ty1, Ty2> make_pair(Ty1&& first, Ty2&& second)
{
  return pair<Ty1, Ty2>(mystl::forward<Ty1>(first), mystl::forward<Ty2>(second));
}

}

#endif // !MYTINYSTL_UTIL_H_


