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
    QTest::addColumn< List >("list");
    QTest::addColumn<List >("expected");

    QTest::newRow("empty-list-point") << List()
                                      << List();

    QTest::newRow("one-element-list-point") << (List() << Point(1, 1))
                                            << (List() << Point(1, 1));

    QTest::newRow("two-elements-lis1t-point") << (List() << Point(2, 3) << Point(1, 2))
                                              << (List() << Point(1, 2) << Point(2, 3));

    QTest::newRow("two-elements-list2-point") << (List() << Point(1, 2) <<Point(1, 2))
                                              <<(List() << Point(1, 2) << Point(1, 2));

    QTest::newRow("three-elements-list1-point") << (List() << Point(3, 2) << Point(1, 1) << Point(1, 2))
                                                << (List() << Point(1, 1) << Point(1, 2) << Point(3, 2));

    QTest::newRow("four-elements-list1-point") << (List() << Point(1, 1) << Point(2, 1) << Point(3, 2) << Point(3, 1))
                                               << (List() << Point(1, 1) << Point(2, 1) << Point(3, 1) << Point(3, 2));

    QTest::newRow("four-elements-list2-point") << (List() << Point(1, 3) << Point(3, 3) << Point(4, 2) << Point(2, 4))
                                               << (List() << Point(1, 3) << Point(2, 4) << Point(3, 3) << Point(4, 2));

    QTest::newRow("four-elements-list3-point") << (List() << Point(1, 1) << Point(2, 3) << Point(3, 1) << Point(1, 1))
                                               << (List() << Point(1, 1) << Point(1, 1) << Point(2, 3) << Point(3, 1));

    QTest::newRow("ten-elements-list-point") << (List() << Point(4, 1) << Point(4, 2) << Point(1, 4) << Point(1, 5) << Point(1, 10) << Point(3, 1) << Point(3, 2) << Point(3, 3) << Point(2, 1) << Point(2, 2))
                                             << (List() << Point(1, 4) << Point(1, 5) << Point(1, 10) << Point(2, 1) << Point(2, 2) << Point(3, 1) << Point(3, 2) << Point(3, 3) << Point(4, 1) << Point(4, 2));
}

void TListProcessor::TestSortLarge_data()
{
    QTest::addColumn<Point>("point1");
    QTest::addColumn<Point>("point2");
    QTest::addColumn<bool>("expected");

    QTest::newRow("equal-points") << Point(1, 1) << Point(1, 1)
                                  << false;

    QTest::newRow("less-points") << Point(3, 3) << Point(3, 2)
                                 << true;

    QTest::newRow("greater-points") << Point(2, 3) << Point(1, 2)
                                    << true;

}

void TListProcessor::TestSortLarge()
{
    QFETCH(Point, point1);
    QFETCH(Point, point2);
    QFETCH(bool, expected);

    const bool actual = (point1 > point2);
    QCOMPARE(actual, expected);
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
    QFETCH(List, list);
    QFETCH(List, expected);

    const List actual = ListProcessor::sort(list);
    QCOMPARE(actual, expected);
}

void TListProcessor::TestAdd_data()
{
    QTest::addColumn<Point>("point1");
    QTest::addColumn<Point>("point2");
    QTest::addColumn<Point>("expected");

    QTest::newRow("addition-two-points1") << Point(0, 0) << Point(1, 1)
                                          << Point(1, 1);

    QTest::newRow("addition-two-points2") << Point(1, 2) << Point(3, 4)
                                          << Point(4, 6);

    QTest::newRow("addition-two-points3") << Point(0, 0) << Point(-1, -1)
                                          << Point(-1, -1);

    QTest::newRow("addition-two-points4") << Point(3, 7) << Point(-1, 4)
                                          << Point(2, 11);

}

void TListProcessor::TestAdd()
{
    QFETCH(Point, point1);
    QFETCH(Point, point2);
    QFETCH(Point, expected);

    const Point actual = (point1 + point2);
    QCOMPARE(actual, expected);
}

void TListProcessor::TestMovingSum_data()
{
    QTest::addColumn< List >("list");
    QTest::addColumn<List >("expected");

    QTest::newRow("empty-list-movingSum") << List()
                                          << List();

    QTest::newRow("one-element-list-movingSum") << (List() << Point(1, 1))
                                                << (List() << Point(1, 1));

    QTest::newRow("two-elements-list-movingSum") << (List() << Point(1, 1) << Point(2, 2))
                                                 << (List() << Point(1, 1) << Point(3, 3));

    QTest::newRow("three-elements-list-movingSum") << (List() << Point(1, 1) << Point(2, 2) << Point(3, 3))
                                                   << (List() << Point(1, 1) << Point(3, 3) << Point(6, 6));

    QTest::newRow("four-elements-list-movingSum") << (List() << Point(1, 1) << Point(2, 2) << Point(3, 3) << Point(4, 4))
                                                  << (List() << Point(1, 1) << Point(3, 3) << Point(6, 6) << Point(10, 10));

    QTest::newRow("ten-elements-list-movingSum") << (List() << Point(1, 1) << Point(2, 2) << Point(3, 3) << Point(4, 4) << Point(5, 5) << Point(2, 0) << Point(0, 2) << Point(0, 0) << Point(10, 10) << Point(7, 7))
                                                 << (List() << Point(1, 1) << Point(3, 3) << Point(6, 6) << Point(10, 10) << Point(15, 15) << Point(17, 15) << Point(17, 17) << Point(17, 17) << Point(27, 27) << Point(34, 34));

}
void TListProcessor::TestMovingSum()
{
    QFETCH(QList<Point>, list);
    QFETCH(QList<Point>, expected);

    const QList<Point> actual = ListProcessor::movingSum(list);
    QCOMPARE(actual, expected);
}


void TListProcessor::TestMovingSumSort_data()
{
    QTest::addColumn< List >("list");
    QTest::addColumn<List >("expected");

    QTest::newRow("empty-list-for-movingSumSort") << List()
                                                  << List();

    QTest::newRow("one-element-list-for-movingSumSort") << (List() << Point(1, 1))
                                                        << (List() << Point(1, 1));

    QTest::newRow("two-elements-list-for-movingSumSort") << (List() << Point(2, 2) << Point(1, 1))
                                                         << (List() << Point(1, 1) << Point(3, 3));

    QTest::newRow("three-elements-list-for-movingSumSort") << (List() << Point(1, 1) << Point(3, 3) << Point(2, 2))
                                                           << (List() << Point(1, 1) << Point(3, 3) << Point(6, 6));

    QTest::newRow("four-elements-list-for-movingSumSort") << (List() << Point(1, 1) << Point(3, 3) << Point(4, 4) << Point(2, 2))
                                                          << (List() << Point(1, 1) << Point(3, 3) << Point(6, 6) << Point(10, 10));

    QTest::newRow("ten-elements-list-for-movingSumSort") << (List() << Point(1, 1) << Point(3, 3) << Point(2, 2) << Point(0, 0) << Point(10, 10) << Point(2, 3) << Point(2, 2) << Point(3, 1) << Point(1, 10) << Point(4, 1))
                                                         << (List() << Point(0, 0) << Point(1, 1) << Point(2, 11) << Point(4, 13) << Point(6, 15) << Point(8, 18) << Point(11, 19) << Point(14, 22) << Point(18, 23) << Point(28, 33));


}
void TListProcessor::TestMovingSumSort()
{
    QFETCH(QList<Point>, list);
    QFETCH(QList<Point>, expected);

    const QList<Point> actual = ListProcessor::movingSumSort(list);
    QCOMPARE(actual, expected);
}
