#include "TListProcessor.h"

TListProcessor::TListProcessor()
{
}

void TListProcessor::TestReverse_data()
{
    QTest::addColumn< QList<int> >("list");
    QTest::addColumn< QList<int> >("expected");

    QTest::newRow("empty-list") << QList<int>()
                                << QList<int>();

    QTest::newRow("single-element-list") << (QList<int>() << 1)
                                         << (QList<int>() << 1);

    QTest::newRow("two-elements-list1") << (QList<int>() << 1 << 1)
                                        << (QList<int>() << 1 << 1);


    QTest::newRow("two-elements-list2") << (QList<int>() << 1 << 2)
                                        << (QList<int>() << 2 << 1);

    QTest::newRow("two-elements-list3") << (QList<int>() << 3 << 2)
                                        << (QList<int>() << 2 << 3);

    QTest::newRow("three-elements-list") << (QList<int>() << 1 << 2 << 3)
                                         << (QList<int>() << 3 << 2 << 1);

    QTest::newRow("ten-elements-list") << (QList<int>() << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10)
                                       << (QList<int>() << 10 << 9 << 8 << 7 << 6 << 5 << 4 << 3 << 2 << 1);
}

void TListProcessor::TestSort_data()
{
    QTest::addColumn< QList<int> >("list");
    QTest::addColumn<QList<int> >("expected");

    QTest::newRow("empty-list") << QList<int>()
                                << QList<int>();

    QTest::newRow("one-element-list") << (QList<int>() << 1)
                               << (QList<int>() << 1);

    QTest::newRow("two-elements-list") << (QList<int>() << 2 << 1)
                               << (QList<int>() << 1 << 2);

    QTest::newRow("three-elements-list1") << (QList<int>() << 1 << 3 << 2)
                                 <<(QList<int>() << 1 << 3 << 2);

    QTest::newRow("three-elements-list2") << (QList<int>() << 3 << 2 << 1)
                                << (QList<int>() << 1 << 3 << 2);

    QTest::newRow("four-elements-list1") << (QList<int>() << 2 << 1 << 3 << 4)
                                        << (QList<int>() << 1 << 3 << 2 << 4);

    QTest::newRow("four-elements-list2") << (QList<int>() << 4 << 1 << 2 << 3)
                                        << (QList<int>() << 1 << 3 << 2 << 4);

    QTest::newRow("four-elements-list3") << (QList<int>() << 4 << 3 << 2 << 1)
                                        << (QList<int>() << 1 << 3 << 2 << 4);

    QTest::newRow("ten-elements-list") << (QList<int>() << 4 << 3 << 2 << 1 << 9 << 5 << 7 << 6 << 8 << 10)
                                        << (QList<int>() << 1 << 3 << 5 << 7 << 9 << 2 << 4 << 6 << 8 << 10);
}

void TListProcessor::TestReverse()
{
    QFETCH(QList<int>, list);
    QFETCH(QList<int>, expected);

    const QList<int> actual = ListProcessor::reverse(list);
    QCOMPARE(actual, expected);
}

void TListProcessor::TestSort()
{
    QFETCH(QList<int>, list);
    QFETCH(QList<int>, expected);

    const QList<int> actual = ListProcessor::sort(list);
    QCOMPARE(actual, expected);
}
