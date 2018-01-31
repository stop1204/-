#include <iostream>

#include <Basket.h>
#include <Sales_item.h>

using namespace std;

//15.35 句柄类和容器
int main() {
    Basket basket;
    Sales_item item1 (Bulk_item ("7-115-14554-7", 99, 20, 0.2) );
    Sales_item item2 (Item_base ("7-115-14554-8", 39) );
    Sales_item item3 (Lds_item ("7-115-14554-9", 50, 200, 0.2) );
    Sales_item item4 (Bulk_item ("7-115-14554-7", 99, 20, 0.2) );


    cout << item1->net_price (19) << "\t\t" << 20 * 99 << " 折扣0.2后 " << (*item1).net_price (20) << endl;
    cout << item2->net_price (10) << "\t\t" << 20 * 39 << " 折扣0后 " << (*item2).net_price (20) << endl;
    cout << item3->net_price (199) << "\t\t" << 201 * 50 << " 有限折扣0.2后 " << (*item3).net_price (201) << endl;
    cout << item4->net_price (19) << "\t\t" << 20 * 99 << " 折扣0.2后 " << (*item4).net_price (20) << endl;


    basket.add_item (item1);
    basket.add_item (item2);
    basket.add_item (item3);
    basket.add_item (item4);

    cout << basket.total() << endl;
    // 2个Bulk + 1个Item + 1个Lds (低于200个折扣0.2 所以 = 40) 结果277
    return 0;
}
