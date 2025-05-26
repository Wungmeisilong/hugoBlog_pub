#ifndef MYTINYSTL_CONSTRUCT_H_
#define MYTINYSTL_CONSTRUCT_H_

// 这个头文件包含两个函数 construct，destroy
// construct : 负责对象的构造
// destroy   : 负责对象的析构

#include <new>

#include "type_traits.h"
#include "iterator.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4100)  // unused parameter
#endif // _MSC_VER

namespace mystl
{

// construct 构造对象
/*定位 new（placement new）的用法：用于在指定内存地址上构造对象。
 * 它不会分配内存，只是在已有的内存（ptr 指向的位置）上调用 Ty 的构造函数。
 */
template <class Ty>
void construct(Ty* ptr)
{
    //((void *)ptr) 是一个强制类型转换，将 ptr 转换为 void* 类型
    // ::new 是一个全局函数，用于在指定内存地址上构造对象
    // 这里的 Ty() 是调用默认构造函数
  ::new ((void*)ptr) Ty();
}

template <class Ty1, class Ty2>
void construct(Ty1* ptr, const Ty2& value)
{
  ::new ((void*)ptr) Ty1(value);
}

template <class Ty, class... Args>  //这是一个可变参数模板，可以接受任意数量和类型的参数。
void construct(Ty* ptr, Args&&... args) //完美转发参数包，支持任意构造参数。
{
  ::new ((void*)ptr) Ty(mystl::forward<Args>(args)...); //保证参数的左值/右值属性不变，完美转发到 Ty 的构造函数。
}

// destroy 将对象析构

template <class Ty>
void destroy_one(Ty*, std::true_type) {}

template <class Ty>
void destroy_one(Ty* pointer, std::false_type)
{
  if (pointer != nullptr)
  {
    pointer->~Ty();
  }
}

template <class ForwardIter>
void destroy_cat(ForwardIter , ForwardIter , std::true_type) {}

template <class ForwardIter>
void destroy_cat(ForwardIter first, ForwardIter last, std::false_type)
{
  for (; first != last; ++first)
    destroy(&*first);   //解引用迭代器，并获取迭代器所指向的地址的元素
                        //目的是：无论迭代器是指针还是自定义迭代器类型，都能安全地获得元素的指针，以便调用 destroy 对该元素进行析构。
}
/*
用法说明：
    如果 Ty 是平凡析构类型（如 int、指针、POD 类型），destroy_one 的第一个重载（空函数）会被调用，不做任何事，无需手动析构。
    如果 Ty 不是平凡析构类型（如自定义类有析构函数），会调用第二个重载，显式调用析构函数。
*/
template <class Ty>
void destroy(Ty* pointer)
{
  destroy_one(pointer, std::is_trivially_destructible<Ty>{});
  // std::is_trivially_destructible<Ty> 是一个类型特征，用于判断类型 Ty 是否具有平凡析构函数（如 int、指针、POD 类型）
}

template <class ForwardIter>
void destroy(ForwardIter first, ForwardIter last)
{
  destroy_cat(first, last, std::is_trivially_destructible<
              typename iterator_traits<ForwardIter>::value_type>{});
}

} // namespace mystl

#ifdef _MSC_VER
#pragma warning(pop)
#endif // _MSC_VER

#endif // !MYTINYSTL_CONSTRUCT_H_

