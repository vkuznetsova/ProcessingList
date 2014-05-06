#ifndef LISTPROCESSOR_H

#define LISTPROCESSOR_H

#include <QtCore>


class Point
{
public:
    Point() :
        x(0),
        y(0)
    {
    }

    Point(const int x, const int y) :
        x(x),
        y(y)
    {
    }

    //todo упростить условия до 1ой строки
    bool operator >(const Point &point) const
    {
        return (x > point.x) || ( x == point.x && y > point.y);
       /* if(x > point.x)
        {
            return true;
        }
        if(x == point.x)
        {
            if(y > point.y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }*/
    }

    bool operator ==(const Point &point) const
    {
        return x == point.x && y == point.y;
    }

    Point operator +(const Point point) const
    {
        return Point(x + point.x, y + point.y);
    }

    int x;
    int y;
};

Q_DECLARE_METATYPE(Point)

typedef QList<Point> List;

class ListProcessor
{
public:
    ListProcessor();

    static QList<int> reverse(const QList<int> &list);
    static List sort(List list);
    static List movingSum(const List &list);
    static List movingSumSort(List list);
};

#endif // LISTPROCESSOR_H
