#ifndef MYTINYSTL_TYPE_TRAITS_H_
#define MYTINYSTL_TYPE_TRAITS_H_

// 这个头文件用于提取类型信息

// use standard header for type_traits
#include <type_traits> //作用：type_traits是C++的标准库，提供了一些模板类，用于提取类型信息

namespace mystl
{

  // helper struct

  /**
 * @brief 编译期常量包装器模板
 * @tparam T 常量值的类型（如bool、int等）
 * @tparam v 具体的编译期常量值
 * 
 * 这个模板将值和类型信息包装成一个类型，主要用于：
 * 1. 作为类型特征的基础类
 * 2. 在编译期表示和操作常量值
 * 3. 支持模板元编程中的值到类型的映射
 */
  template <class T, T v>
  struct m_integral_constant // 用于提取类型信息
  {
    // 静态常量成员，存储编译期确定的值
    static constexpr T value = v; // static constexpr的意思是编译期常量，即编译期就确定值
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

