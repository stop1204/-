#include <iostream>

#include <Basket.h>
#include <Sales_item.h>

using namespace std;

//15.35 ����������
int main() {
    Basket basket;
    Sales_item item1 (Bulk_item ("7-115-14554-7", 99, 20, 0.2) );
    Sales_item item2 (Item_base ("7-115-14554-8", 39) );
    Sales_item item3 (Lds_item ("7-115-14554-9", 50, 200, 0.2) );
    Sales_item item4 (Bulk_item ("7-115-14554-7", 99, 20, 0.2) );


    cout << item1->net_price (19) << "\t\t" << 20 * 99 << " �ۿ�0.2�� " << (*item1).net_price (20) << endl;
    cout << item2->net_price (10) << "\t\t" << 20 * 39 << " �ۿ�0�� " << (*item2).net_price (20) << endl;
    cout << item3->net_price (199) << "\t\t" << 201 * 50 << " �����ۿ�0.2�� " << (*item3).net_price (201) << endl;
    cout << item4->net_price (19) << "\t\t" << 20 * 99 << " �ۿ�0.2�� " << (*item4).net_price (20) << endl;


    basket.add_item (item1);
    basket.add_item (item2);
    basket.add_item (item3);
    basket.add_item (item4);

    cout << basket.total() << endl;
    // 2��Bulk + 1��Item + 1��Lds (����200���ۿ�0.2 ���� = 40) ���277
    return 0;
}
