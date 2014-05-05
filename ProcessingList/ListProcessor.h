#ifndef LISTPROCESSOR_H

#define LISTPROCESSOR_H

#include <QtCore>

class ListProcessor
{
public:
    ListProcessor();

    static QList<int> reverse(const QList<int> &list);
    static QList<int> sort(QList<int> list);
};

#endif // LISTPROCESSOR_H
