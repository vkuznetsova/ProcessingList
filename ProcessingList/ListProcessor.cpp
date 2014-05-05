#include "ListProcessor.h"

ListProcessor::ListProcessor()
{
}

QList<int> ListProcessor::reverse(const QList<int> &list)
{
    QList<int> reversed;
    foreach(const int x, list)
    {
        reversed.prepend(x);
    }
    return reversed;
}

QList<int> ListProcessor::sort(QList<int> list)
{
    for(int i = 0; i < list.size() - 1; i++)
    {
        for(int j = 0; j < list.size() - i - 1; j++)
        {
            int temp;
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
