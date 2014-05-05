#include "ListProcessor.h"

ListProcessor::ListProcessor()
{
}

QList<int> ListProcessor::reverse(const QList<int> &list)
{
    QList<int> reversed;
    foreach(const int i, list)
    {
        reversed.prepend(i);
    }
    return reversed;
}

List ListProcessor::sort(List list)
{
    for(int i = 0; i < list.size() - 1; i++)
    {
        for(int j = 0; j < list.size() - i - 1; j++)
        {
            Point temp(0, 0);
            if(list.at(j) > list.at(j + 1))
            {
                temp = list.at(j);
                list[j] = list.at(j + 1);
                list[j + 1] = temp;
            }
        }
    }
    return list;

}
