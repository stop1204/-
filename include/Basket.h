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

��������ʹ�����ܹ�ָ��һ�������������󣨵� 14.8 �ڣ������ȽϺ���
items ��һ�� multiset�������� Sales_item ����ʹ��Comp ���͵Ķ���Ƚ�����
multiset �ǿյġ�������û���ṩ�κ�Ԫ�أ������ǵ�ȷ�ṩ��һ����Ϊ compare �ıȽϺ���
���� items �����ӻ����Ԫ��ʱ������ compare ������ multiset ��������
    multiset<Sales_item, Comp> item(compare);
*/
class Basket {
  private:
    typedef bool (*Comp) (const Sales_item&, const Sales_item&);
  public:
    //ʹ������׼������ǵļ��ϵ�����
    typedef std::multiset<Sales_item, Comp> set_type;
    //����Ӧ����������֮��ģ��typedefs
    typedef set_type::size_type size_type;
    typedef set_type::const_iterator const_iter;

    //������Ҫ�Լ���Ĭ�Ϲ��캯�����Ա㽫 compare �������� items ��Ա�� multiset ���캯��
    Basket() : items (compare) {} //initialize the comparator

    void add_item (const Sales_item &item) {
        items.insert (item);
    }

    size_type size (const Sales_item &i) const {  //���� std::multiset<Sales_item, Comp> ����
        return items.count (i);
    }

    double total() const; // sum of net prices for all items in the basket

  protected:

  private:
    std::multiset<Sales_item, Comp> items;
};

#endif // BASKET_H
