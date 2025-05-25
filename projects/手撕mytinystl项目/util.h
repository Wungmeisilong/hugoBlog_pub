#ifndef MYTINYSTL_UTIL_H_
#define MYTINYSTL_UTIL_H_

// 这个文件包含一些通用工具，包括 move, forward, swap 等函数，以及 pair 等 

#include <cstddef>

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
  template <class Other1 = Ty1, class Other2 = Ty2,
    typename = typename std::enable_if<
    std::is_default_constructible<Other1>::value &&
    std::is_default_constructible<Other2>::value, void>::type>
    constexpr pair()
    : first(), second()
  {
  }

  // implicit constructiable for this type
  template <class U1 = Ty1, class U2 = Ty2,
    typename std::enable_if<
    std::is_copy_constructible<U1>::value &&
    std::is_copy_constructible<U2>::value &&
    std::is_convertible<const U1&, Ty1>::value &&
    std::is_convertible<const U2&, Ty2>::value, int>::type = 0>
    constexpr pair(const Ty1& a, const Ty2& b)
    : first(a), second(b)
  {
  }

  // explicit constructible for this type
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

  pair(const pair& rhs) = default;
  pair(pair&& rhs) = default;

  // implicit constructiable for other type
  template <class Other1, class Other2,
    typename std::enable_if<
    std::is_constructible<Ty1, Other1>::value &&
    std::is_constructible<Ty2, Other2>::value &&
    std::is_convertible<Other1&&, Ty1>::value &&
    std::is_convertible<Other2&&, Ty2>::value, int>::type = 0>
    constexpr pair(Other1&& a, Other2&& b)
    : first(mystl::forward<Other1>(a)),
    second(mystl::forward<Other2>(b))
  {
  }

  // explicit constructiable for other type
  template <class Other1, class Other2,
    typename std::enable_if<
    std::is_constructible<Ty1, Other1>::value &&
    std::is_constructible<Ty2, Other2>::value &&
    (!std::is_convertible<Other1, Ty1>::value ||
     !std::is_convertible<Other2, Ty2>::value), int>::type = 0>
    explicit constexpr pair(Other1&& a, Other2&& b)
    : first(mystl::forward<Other1>(a)),
    second(mystl::forward<Other2>(b))
  {
  }

  // implicit constructiable for other pair
  template <class Other1, class Other2,
    typename std::enable_if<
    std::is_constructible<Ty1, const Other1&>::value &&
    std::is_constructible<Ty2, const Other2&>::value &&
    std::is_convertible<const Other1&, Ty1>::value &&
    std::is_convertible<const Other2&, Ty2>::value, int>::type = 0>
    constexpr pair(const pair<Other1, Other2>& other)
    : first(other.first),
    second(other.second)
  {
  }

  // explicit constructiable for other pair
  template <class Other1, class Other2,
    typename std::enable_if<
    std::is_constructible<Ty1, const Other1&>::value &&
    std::is_constructible<Ty2, const Other2&>::value &&
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
    : first(mystl::forward<Other1>(other.first)),
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
    : first(mystl::forward<Other1>(other.first)),
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

  ~pair() = default;

  void swap(pair& other)
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


