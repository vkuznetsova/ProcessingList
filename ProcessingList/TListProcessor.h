#ifndef TLISTPROCESSOR_H

#define TLISTPROCESSOR_H

#include <QtTest/QtTest>

#include "ListProcessor.h"

class TListProcessor : public QObject
{
    Q_OBJECT
public:
    TListProcessor();

private slots:
    void TestReverse_data();
    void TestReverse();

    void TestSort_data();
    void TestSort();

    void TestSortLarge_data();
    void TestSortLarge();

    void TestAdd_data();
    void TestAdd();
};

#endif // TLISTPROCESSOR_H
