#include "Basket.h"
#include "iostream"
double Basket::total() const {
    double sum = 0.0; //holds the running total

    /* 找到每个具有相同isbn的项目并计算该项目数量的净价格
     * iter是指集合中每本书的第一个副本
     * upper_bound指向一个不同的isbn的下一个元素
     */
    for (const_iter iter = items.begin();
            iter != items.end();
            iter = items.upper_bound (*iter) ) {
        // 我们知道Basket里至少有一个这个键的元素
        // 对net_price的虚拟调用适用适当的折扣（如果有的话）
        //测试内容std::cout<< "---------" << (*iter)->net_price (items.count (*iter) ) <<endl;
        sum += (*iter)->net_price (items.count (*iter) );
    }
    return sum;
}
/*
调用 net_price 函数时，需要告诉它某本书已经购买了多少本，
    net_price函数使用这个实参确定是否打折
这个要求暗示着我们希望成批处理multiset——处理给定标题的所有记录，
    然后处理下一个标题的所有记录

for 循环开始于定义 iter 并将 iter 初始化为指向 multiset 中的第一个元素。
    我们使用 multiset 的 count 成员（第 10.3.6 节）确定 multiset 中
    的多少成员具有相同的键（即，相同的 isbn），并且使用该数目作为实参调用net_price 函数。
upper_bound 函数的调用返回一个迭代器，该迭代器指向与 iter 键相同的
    最后一个元素的下一元素，即，该迭代器指向集合的末尾或下一本书

对 iter 解引用获得基础 Sales_item 对象，对该对象应用 Sales_item类重载的箭头操作符，
    该操作符返回句柄所关联的基础 Item_base 对象，
    用该Item_base 对象调用 net_price 函数，传递具有相同 isbn 的图书的 count 作为实参。
    net_price是虚函数，所以调用的定价函数的版本取决于基础Item_base 对象的类型
*/
