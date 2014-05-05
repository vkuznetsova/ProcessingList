#include <QCoreApplication>

#include "TListProcessor.h"

int main(int argc, char *argv[])
{
    TListProcessor tListProcessor;
    QTest::qExec(&tListProcessor);

    return 0;
}
