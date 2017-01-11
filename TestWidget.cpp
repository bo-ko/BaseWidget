#include "TestWidget.h"

TestWidget::TestWidget(QWidget *parent) : BaseWidget(parent)
{
   InitUi();
   InitConnect();
}

void TestWidget::InitUi()
{
    this->setFixedSize(900, 650);

    TestToolBt = new ToolBt();
    TestMainLt = new QVBoxLayout();

    TestMainLt->addWidget(TestToolBt, 0, Qt::AlignTop | Qt::AlignRight);
    TestMainLt->setContentsMargins(0, 0, 0, 0);

    this->setLayout(TestMainLt);
}

void TestWidget::InitConnect()
{
    connect(TestToolBt, SIGNAL(Closed()), this, SLOT(close()));
    connect(TestToolBt, SIGNAL(Minimi()), this, SLOT(showMinimized()));
}
