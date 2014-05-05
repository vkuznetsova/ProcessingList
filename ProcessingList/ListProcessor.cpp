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
