#ifndef MYTINYSTL_TYPE_TRAITS_H_
#define MYTINYSTL_TYPE_TRAITS_H_

// 这个头文件用于提取类型信息

// use standard header for type_traits
#include <type_traits> //作用：type_traits是C++的标准库，提供了一些模板类，用于提取类型信息

namespace mystl
{

// helper struct

template <class T, T v>
struct m_integral_constant // 用于提取类型信息
{
  static constexpr T value = v; //static constexpr的意思是编译期常量，即编译期就确定值
};

template <bool b>
using m_bool_constant = m_integral_constant<bool, b>;

typedef m_bool_constant<true>  m_true_type;
typedef m_bool_constant<false> m_false_type;

/*****************************************************************************************/
// type traits

// is_pair

// --- forward declaration begin 即前向声明
template <class T1, class T2>
struct pair; 
// --- forward declaration end 

template <class T>
struct is_pair : mystl::m_false_type {}; // is_pair默认为false_type

template <class T1, class T2>
struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {};    // is_pair为true_type

} // namespace mystl

#endif // !MYTINYSTL_TYPE_TRAITS_H_

