#ifndef BASKET_H
#define BASKET_H

#include "Sales_item.h"
#include <set>


inline bool
compare (const Sales_item &lhs, const Sales_item &rhs) {
    return lhs->book() < rhs->book();
}
/*
typedef bool (*Comp)(const Sales_item&, const Sales_item&);

关联容器使我们能够指定一个函数或函数对象（第 14.8 节）用作比较函数
items 是一个 multiset，它保存 Sales_item 对象并使用Comp 类型的对象比较它们
multiset 是空的——我们没有提供任何元素，但我们的确提供了一个名为 compare 的比较函数
当在 items 中增加或查找元素时，将用 compare 函数对 multiset 进行排序。
    multiset<Sales_item, Comp> item(compare);
*/
class Basket {
  private:
    typedef bool (*Comp) (const Sales_item&, const Sales_item&);
  public:
    //使其更容易键入我们的集合的类型
    typedef std::multiset<Sales_item, Comp> set_type;
    //在相应的容器类型之后建模的typedefs
    typedef set_type::size_type size_type;
    typedef set_type::const_iterator const_iter;

    //该类需要自己的默认构造函数，以便将 compare 传给建立 items 成员的 multiset 构造函数
    Basket() : items (compare) {} //initialize the comparator

    void add_item (const Sales_item &item) {
        items.insert (item);
    }

    size_type size (const Sales_item &i) const {  //返回 std::multiset<Sales_item, Comp> 类型
        return items.count (i);
    }

    double total() const; // sum of net prices for all items in the basket

  protected:

  private:
    std::multiset<Sales_item, Comp> items;
};

#endif // BASKET_H
