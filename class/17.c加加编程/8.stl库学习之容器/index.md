# 8.STL库学习之容器

## list

## vector

## deque

![alt text](image.png?height=350px&width=600px)

deque的迭代器
![alt text](image-1.png?height=350px&width=600px)

deque实现中间插入值的做法：如果欲插入值在最前端（最尾端）调用`push_front()`（`push_back()`）,否则借助`insert_aux()`迭代器，实现如果欲插入位置靠近前端使用，就让前端的数据往前挪，否则往后挪。

deque中+=的实现：1.先计算+=后是否超过缓冲区，如果没有则直接+=，否则需要判断需要跨几个缓冲区，然后再去确定前进几个缓冲区。
![alt text](image-2.png?height=350px&width=600px)

**Vector的内存扩充：**

std::vector 在需要更多空间时，通常会将容量增加到当前大小的两倍（这是最常见的增长策略，但不是唯一的，具体实现可能有所不同）。

当发生扩充时，std::vector 会分配一个新的更大的内存块，然后将所有元素从旧内存块复制到新内存块，最后释放旧内存块。

**Deque的内存扩充：**

std::deque（双端队列）的内存管理机制与 std::vector 不同。std::deque 是一个使用多个固定大小的内存块来存储元素的容器，这些内存块被称为“chunks”或“maps”。

当 std::deque 需要更多空间时，它可能会在已有的内存块之后添加新的内存块，或者在前面添加，这取决于哪个方向上的空间更紧张。
std::deque 不会像 std::vector 那样将所有元素复制到一个新的连续内存块中，而是在多个内存块之间分配元素。

## stack和queue

stack和queue默认使用deque的功能来分别实现先进后出和先进先出的功能，除此之外还可以使用list，stack还可以使用vector，但是deque就不能用vector，以我的理解，是因为vector不提供后端操作。

## Rb-tree

在C++中，set和map的底层实现都是基于红黑树（RB-tree）。红黑树是一种自平衡的二叉搜索树，能够保证在最坏情况下，插入、删除和查找操作的时间复杂度均为O(log n)。

```cpp
    template <  int key,
                int value,
                identity<int>,
                less<int>,
                alloc
                >
    class rb_tree;
```

**set 和 map 的区别：**

set：set中的元素是唯一的键值，即Key和Value是同一个。插入时使用insert_unique()方法，确保键值不重复。

map：map中的元素是键值对（Key-Value），键值用于索引，值表示与索引相关联的数据。插入时使用insert_equal()方法，允许键值重复。

**红黑树的结构：**

红黑树的结构包括节点、根节点、最左节点和最右节点等。根节点通过header.parent保存，最左节点通过header.left保存，最右节点通过header.right保存。

- 插入操作
  - set：插入操作调用insert_unique()，确保键值唯一。
  - map：插入操作调用insert_equal()，允许键值重复。
- 迭代器
  - set：迭代器是RB-tree的const_iterator，不允许修改元素值。
  - map：迭代器也是RB-tree的const_iterator，但允许修改元素的值（因为值部分不是键）。

## set和multiset

set与map的底层实现基本可以参考下面的源码图，

![alt text](image-3.png?height=350px&width=600px)

需要说明的一点是，在不允许更改键值上，二者的设计还是有区别，主要体现在set使用const_iterator,这样迭代器指向的键值就无法更改，而map在设计上在传进来的Key设置为const，确保键值不会被更改。

## hashtable-哈希表

在C++中，hash_set、hash_map、hash_multiset和hash_multimap等数据结构的底层实现确实采用了哈希表的思想。具体来说，这些数据结构的设计核心是通过哈希函数将键（key）映射到数组的索引位置，从而实现高效的插入、删除和查找操作。

### 数据存储的设计思想

每个键值通过一个哈希函数计算出一个哈希值。这个哈希值通常是一个整数，用于确定键值在数组中的存储位置。例如，对于一个整数键值12，哈希函数可能会直接返回12，这样12就会被存储在数组的第12个位置。

哈希表的核心是一个数组（通常是一个vector），数组的每个元素（即每个位置）可以存储一个指针。这个指针指向一个单向链表的头节点。如果多个键值通过哈希函数计算出相同的哈希值，它们会被存储在同一个位置的链表中。参考下图：
![alt text](image-4.png?height=350px&width=600px)
当多个键值映射到同一个哈希值时，这些键值会被存储在一个链表中。链表的每个节点包含一个键值和指向下一个节点的指针。这种设计允许在发生哈希冲突时，通过遍历链表来查找或插入特定的键值。
![alt text](image-5.png?height=350px&width=600px)
为了保持高效的性能，哈希表通常会有一个动态扩容机制。当哈希表中的元素数量超过一定阈值时，哈希表会自动重新分配更大的数组，并重新计算所有键值的哈希值，以减少链表的长度，从而提高查找效率。

在实际应用中，哈希函数可能会导致不同的键值计算出相同的哈希值，这种现象称为哈希冲突。常见的解决策略包括链地址法（即使用链表存储冲突的元素）和开放地址法（即在数组中寻找下一个空闲位置）。

### 具体实现过程

- 当插入一个新键值时，首先通过哈希函数计算出其哈希值，然后根据哈希值找到对应的数组位置。如果该位置已经有元素（即发生冲突），则将新元素插入到该位置的链表中。
- 查找操作同样通过哈希函数计算出键值的哈希值，然后根据哈希值找到对应的数组位置。如果该位置有元素，则遍历链表，直到找到匹配的键值或链表结束。
- 删除操作首先通过哈希函数计算出键值的哈希值，然后根据哈希值找到对应的数组位置。如果该位置有元素，则遍历链表，找到并删除匹配的键值。

### 实现代码

hashtable类的实现提供了六个模板参数。

```cpp
  template <class value,
            class key,
            class hashFcn,//计算编号
            class extractKey,//取出键值
            class EqualKey,//判断类型是否相等
            class Alloc=alloc
            >
```

![alt text](image-6.png?height=300px&width=600px)

如果要自己使用这个哈希表，需要写hashFcn()的重载，对齐进行偏特化等操作,如下图：
![alt text](image-7.png?height=300px&width=600px)

如果传入的是字符串，那么字符串的编号计算可以参考下图计算方法：
![alt text](image-8.png?height=300px&width=600px)
{{% attachments color="fuchsia" icon="fab fa-hackerrank" /%}}