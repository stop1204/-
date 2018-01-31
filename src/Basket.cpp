#include "Basket.h"
#include "iostream"
double Basket::total() const {
    double sum = 0.0; //holds the running total

    /* �ҵ�ÿ��������ͬisbn����Ŀ���������Ŀ�����ľ��۸�
     * iter��ָ������ÿ����ĵ�һ������
     * upper_boundָ��һ����ͬ��isbn����һ��Ԫ��
     */
    for (const_iter iter = items.begin();
            iter != items.end();
            iter = items.upper_bound (*iter) ) {
        // ����֪��Basket��������һ���������Ԫ��
        // ��net_price��������������ʵ����ۿۣ�����еĻ���
        //��������std::cout<< "---------" << (*iter)->net_price (items.count (*iter) ) <<endl;
        sum += (*iter)->net_price (items.count (*iter) );
    }
    return sum;
}
/*
���� net_price ����ʱ����Ҫ������ĳ�����Ѿ������˶��ٱ���
    net_price����ʹ�����ʵ��ȷ���Ƿ����
���Ҫ��ʾ������ϣ����������multiset�������������������м�¼��
    Ȼ������һ����������м�¼

for ѭ����ʼ�ڶ��� iter ���� iter ��ʼ��Ϊָ�� multiset �еĵ�һ��Ԫ�ء�
    ����ʹ�� multiset �� count ��Ա���� 10.3.6 �ڣ�ȷ�� multiset ��
    �Ķ��ٳ�Ա������ͬ�ļ���������ͬ�� isbn��������ʹ�ø���Ŀ��Ϊʵ�ε���net_price ������
upper_bound �����ĵ��÷���һ�����������õ�����ָ���� iter ����ͬ��
    ���һ��Ԫ�ص���һԪ�أ������õ�����ָ�򼯺ϵ�ĩβ����һ����

�� iter �����û�û��� Sales_item ���󣬶Ըö���Ӧ�� Sales_item�����صļ�ͷ��������
    �ò��������ؾ���������Ļ��� Item_base ����
    �ø�Item_base ������� net_price ���������ݾ�����ͬ isbn ��ͼ��� count ��Ϊʵ�Ρ�
    net_price���麯�������Ե��õĶ��ۺ����İ汾ȡ���ڻ���Item_base ���������
*/
