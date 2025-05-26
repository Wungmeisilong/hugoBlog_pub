#ifndef MYTINYSTL_ITERATOR_H_
#define MYTINYSTL_ITERATOR_H_

// 这个头文件用于迭代器设计，包含了一些模板结构体与全局函数，

#include <cstddef> //

#include "type_traits.h"

namespace mystl
{

// 迭代器类型标签：用于标识迭代器的能力和类别，是迭代器设计中的重要概念

// 输入迭代器：最基本的迭代器类型，只支持单次遍历、只读访问
// 能力：++it, it++, *it(只读), it==it2, it!=it2
// 典型实现：istream_iterator
struct input_iterator_tag {};

// 输出迭代器：只支持单次遍历、只写访问
// 能力：++it, it++, *it(只写)
// 典型实现：ostream_iterator
struct output_iterator_tag {};

// 前向迭代器：支持多次遍历、读写访问
// 能力：继承输入迭代器的所有能力，且可以多次遍历同一范围
// 典型实现：forward_list的迭代器
// 继承自input_iterator_tag表示前向迭代器具有输入迭代器的所有能力
struct forward_iterator_tag : public input_iterator_tag {};

// 双向迭代器：支持双向遍历、读写访问
// 能力：继承前向迭代器的所有能力，增加了--it, it--操作
// 典型实现：list的迭代器
// 继承自forward_iterator_tag表示双向迭代器具有前向迭代器的所有能力
struct bidirectional_iterator_tag : public forward_iterator_tag {};

// 随机访问迭代器：支持随机访问、读写访问
// 能力：继承双向迭代器的所有能力，增加了it+n, it-n, it[n], it<it2, it<=it2, it>it2, it>=it2操作
// 典型实现：vector和deque的迭代器，以及原生指针
// 继承自bidirectional_iterator_tag表示随机访问迭代器具有双向迭代器的所有能力
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

// iterator 模板
template <class Category, class T, class Distance = ptrdiff_t,
  class Pointer = T*, class Reference = T&>
  struct iterator
{
  typedef Category                             iterator_category; // 迭代器类型
  typedef T                                    value_type;  // 迭代器所指对象的类型
  typedef Pointer                              pointer; // 迭代器所指对象的指针
  typedef Reference                            reference;   // 迭代器所指对象的引用
  typedef Distance                             difference_type; // 迭代器距离上一个元素的距离
};

// iterator traits

// has_iterator_cat: 检测类型T是否具有iterator_category成员类型
// 原理：利用SFINAE(Substitution Failure Is Not An Error)和函数重载解析规则
template <class T>
struct has_iterator_cat
{
private:
  // 定义两种不同大小的类型用于重载选择的结果区分
  struct two { char a; char b; };  // 大小为2
  
  // 匹配任意类型的重载版本，返回two类型(大小为2)
  // 这是次优先的匹配选择
  template <class U> static two test(...);
  
  // 只有当U::iterator_category存在时才能匹配的重载版本，返回char类型(大小为1)
  // 参数默认值使得可以以U::iterator_category*类型作为参数调用
  // 当U没有iterator_category成员时，这个重载版本会SFINAE失败
  template <class U> static char test(typename U::iterator_category* = 0);
  
public:
  // 通过比较返回类型大小判断是否存在iterator_category
  // 如果T有iterator_category成员，test<T>(0)会调用第二个重载版本，返回sizeof(char)
  // 如果T没有iterator_category成员，test<T>(0)会调用第一个重载版本，返回sizeof(two)
  static const bool value = sizeof(test<T>(0)) == sizeof(char);
};

template <class Iterator, bool>
struct iterator_traits_impl {};

template <class Iterator>
struct iterator_traits_impl<Iterator, true>
{
  typedef typename Iterator::iterator_category iterator_category; //typename关键字：告诉编译器Iterator::iterator_category是一个类型成员而不是静态成员或嵌套类
  typedef typename Iterator::value_type        value_type;          //这是必需的，因为C++语法规定：在依赖名称中，默认假定名称代表的是值而不是类型
  typedef typename Iterator::pointer           pointer;
  typedef typename Iterator::reference         reference;
  typedef typename Iterator::difference_type   difference_type;
};

template <class Iterator, bool>
struct iterator_traits_helper
{
};

/**
 * @brief 针对原生指针特化的迭代器特性辅助类
 *
 * 该模板特化用于处理原生指针类型的迭代器特性，继承自iterator_traits_impl，
 * 根据迭代器类别是否可转换为input_iterator_tag或output_iterator_tag来选择不同的实现。
 *
 * @tparam Iterator 迭代器类型
 */
template <class Iterator>
struct iterator_traits_helper<Iterator, true>
    : public iterator_traits_impl<Iterator,
    std::is_convertible<typename Iterator::iterator_category, input_iterator_tag>::value ||
    std::is_convertible<typename Iterator::iterator_category, output_iterator_tag>::value>
{
};

// 萃取迭代器的特性
template <class Iterator>
struct iterator_traits 
  : public iterator_traits_helper<Iterator, has_iterator_cat<Iterator>::value> {};

// 针对原生指针的偏特化版本
template <class T>
struct iterator_traits<T*>
{
  typedef random_access_iterator_tag           iterator_category;
  typedef T                                    value_type;
  typedef T*                                   pointer;
  typedef T&                                   reference;
  typedef ptrdiff_t                            difference_type;
};

template <class T>
struct iterator_traits<const T*>
{
  typedef random_access_iterator_tag           iterator_category;
  typedef T                                    value_type;
  typedef const T*                             pointer;
  typedef const T&                             reference;
  typedef ptrdiff_t                            difference_type;
};

/**
 * @brief 检查迭代器类型T的iterator_category是否能转换为类型U
 *
 * 这是一个模板元函数，用于在编译时判断给定迭代器类型T的迭代器类别
 * 是否可以隐式转换为指定的迭代器类别U。第三个模板参数用于SFINAE机制，
 * 确保只有当T具有有效的iterator_traits时才参与重载解析。
 *
 * @tparam T 要检查的迭代器类型
 * @tparam U 目标迭代器类别类型
 * @tparam has_iterator_cat 是否具有有效的iterator_traits(默认为true)
 */
template <class T, class U, bool = has_iterator_cat<iterator_traits<T>>::value>
struct has_iterator_cat_of
    : public m_bool_constant<std::is_convertible< //继承m_bool_constant{static constexpr bool value = U;}
          typename iterator_traits<T>::iterator_category, U>::value>
{
};

// 萃取某种迭代器
template <class T, class U>
struct has_iterator_cat_of<T, U, false> : public m_false_type
{
};

/**
 * @brief 检查迭代器是否为严格的输入迭代器
 *
 * 该模板用于判断给定的迭代器类型Iter是否是严格的输入迭代器(仅支持input_iterator_tag，
 * 而不支持forward_iterator_tag)。继承自m_bool_constant，结果为true或false。
 *
 * @tparam Iter 要检查的迭代器类型
 */
template <class Iter>
struct is_exactly_input_iterator : public m_bool_constant<has_iterator_cat_of<Iter, input_iterator_tag>::value &&
                                                          !has_iterator_cat_of<Iter, forward_iterator_tag>::value>
{
};

template <class Iter>
struct is_input_iterator : public has_iterator_cat_of<Iter, input_iterator_tag> {};

template <class Iter>
struct is_output_iterator : public has_iterator_cat_of<Iter, output_iterator_tag> {};

template <class Iter>
struct is_forward_iterator : public has_iterator_cat_of<Iter, forward_iterator_tag> {};

template <class Iter>
struct is_bidirectional_iterator : public has_iterator_cat_of<Iter, bidirectional_iterator_tag> {};

template <class Iter>
struct is_random_access_iterator : public has_iterator_cat_of<Iter, random_access_iterator_tag>
{
};

/**
 * @brief 判断类型是否为迭代器
 *
 * 通过检查是否为输入迭代器或输出迭代器来确定给定类型是否为迭代器类型。
 * 继承自m_bool_constant，提供编译时的布尔值判断。
 *
 * @tparam Iterator 待检查的类型
 */
template <class Iterator>
struct is_iterator : public m_bool_constant<is_input_iterator<Iterator>::value ||
                                            is_output_iterator<Iterator>::value>
{
};

// 萃取某个迭代器的 category
template <class Iterator>
typename iterator_traits<Iterator>::iterator_category
iterator_category(const Iterator&)
{
  typedef typename iterator_traits<Iterator>::iterator_category Category;
  return Category(); 
}

// 萃取某个迭代器的 distance_type
template <class Iterator>
typename iterator_traits<Iterator>::difference_type*
distance_type(const Iterator&)
{
    //static_cast: 进行安全的类型转换
    //typename: 指明iterator_traits<Iterator>::difference_type是一个类型
    //返回空指针(0): 因为只需要类型信息而不需要实际对象
  return static_cast<typename iterator_traits<Iterator>::difference_type*>(0); 
}

// 萃取某个迭代器的 value_type
template <class Iterator>
typename iterator_traits<Iterator>::value_type*
value_type(const Iterator&)
{
  return static_cast<typename iterator_traits<Iterator>::value_type*>(0);
}

// 以下函数用于计算迭代器间的距离

// distance 的 input_iterator_tag 的版本
template <class InputIterator>
typename iterator_traits<InputIterator>::difference_type
distance_dispatch(InputIterator first, InputIterator last, input_iterator_tag)//添加input_iterator_tag的作用：编译器期多态，只有输入迭代器才能调用这个版本
{
  typename iterator_traits<InputIterator>::difference_type n = 0; 
  while (first != last)
  {
    ++first;
    ++n;
  }
  return n;
}

// distance 的 random_access_iterator_tag 的版本
template <class RandomIter>
typename iterator_traits<RandomIter>::difference_type
distance_dispatch(RandomIter first, RandomIter last,
                  random_access_iterator_tag)
{
  return last - first;
}

template <class InputIterator>
typename iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last)
{
  return distance_dispatch(first, last, iterator_category(first));
}

// 以下函数用于让迭代器前进 n 个距离

// advance 的 input_iterator_tag 的版本
template <class InputIterator, class Distance>
void advance_dispatch(InputIterator& i, Distance n, input_iterator_tag)
{
  while (n--) 
    ++i;
}

// advance 的 bidirectional_iterator_tag 的版本
template <class BidirectionalIterator, class Distance>
void advance_dispatch(BidirectionalIterator& i, Distance n, bidirectional_iterator_tag)
{
  if (n >= 0)
    while (n--)  ++i;
  else
    while (n++)  --i;
}

// advance 的 random_access_iterator_tag 的版本
template <class RandomIter, class Distance>
void advance_dispatch(RandomIter& i, Distance n, random_access_iterator_tag)
{
  i += n;
}

template <class InputIterator, class Distance>
/**
 * @brief 将迭代器前进指定距离
 *
 * 根据迭代器类型分派到不同的前进实现
 *
 * @param i 输入迭代器引用，将被前进
 * @param n 要前进的距离
 */
void advance(InputIterator &i, Distance n)
{
    advance_dispatch(i, n, iterator_category(i));
}

/*****************************************************************************************/

// 模板类 : reverse_iterator
// 代表反向迭代器，使前进为后退，后退为前进
template <class Iterator>
class reverse_iterator
{
private:
  Iterator current;  // 记录对应的正向迭代器

public:
  // 反向迭代器的五种相应型别
  typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
  typedef typename iterator_traits<Iterator>::value_type        value_type;
  typedef typename iterator_traits<Iterator>::difference_type   difference_type;
  typedef typename iterator_traits<Iterator>::pointer           pointer;
  typedef typename iterator_traits<Iterator>::reference         reference;

  typedef Iterator                                              iterator_type;  //迭代器类型
  typedef reverse_iterator<Iterator>                            self;       //反向迭代器类型

public:
  // 构造函数
  reverse_iterator() {}
  explicit reverse_iterator(iterator_type i) :current(i) {}
  reverse_iterator(const self& rhs) :current(rhs.current) {}//拷贝构造函数

public:
  // 取出对应的正向迭代器
  iterator_type base() const 
  { return current; }

  // 重载操作符
  reference operator*() const
  { // 实际对应正向迭代器的前一个位置
    auto tmp = current;
    return *--tmp;
  }
  pointer operator->() const
  {
    return &(operator*());
  }

  // 前进(++)变为后退(--)
  self& operator++()
  {
    --current;
    return *this;
  }
  self operator++(int)
  {
    self tmp = *this;
    --current;
    return tmp;
  }
  // 后退(--)变为前进(++)
  self& operator--()
  {
    ++current;
    return *this;
  }
  self operator--(int)
  {
    self tmp = *this;
    ++current;
    return tmp;
  }

  self& operator+=(difference_type n)
  {
    current -= n;
    return *this;
  }
  self operator+(difference_type n) const
  {
    return self(current - n);
  }
  self& operator-=(difference_type n)
  {
    current += n;
    return *this;
  }
  self operator-(difference_type n) const
  {
    return self(current + n);
  }

  reference operator[](difference_type n) const
  {
    return *(*this + n);
  }
};

// 重载 operator-
template <class Iterator>
typename reverse_iterator<Iterator>::difference_type
operator-(const reverse_iterator<Iterator>& lhs,
          const reverse_iterator<Iterator>& rhs)
{
  return rhs.base() - lhs.base();
}

// 重载比较操作符
template <class Iterator>
bool operator==(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs)
{
  return lhs.base() == rhs.base();
}

template <class Iterator>
bool operator<(const reverse_iterator<Iterator>& lhs,
  const reverse_iterator<Iterator>& rhs)
{
  return rhs.base() < lhs.base();
}

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs)
{
  return !(lhs == rhs);
}

template <class Iterator>
bool operator>(const reverse_iterator<Iterator>& lhs,
               const reverse_iterator<Iterator>& rhs)
{
  return rhs < lhs;
}

template <class Iterator>
bool operator<=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs)
{
  return !(rhs < lhs);
}

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs)
{
  return !(lhs < rhs);
}

} // namespace mystl

#endif // !MYTINYSTL_ITERATOR_H_
