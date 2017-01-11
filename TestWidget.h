#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include "ToolBt.h"
#include "BaseWidget.h"

#include <QVBoxLayout>


class TestWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit TestWidget(QWidget *parent = 0);

private:
    ToolBt *TestToolBt;
    QVBoxLayout *TestMainLt;

    void InitUi();
    void InitConnect();

};

#endif // TESTWIDGET_H
