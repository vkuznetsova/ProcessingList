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
};

#endif // TLISTPROCESSOR_H
