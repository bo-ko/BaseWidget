#include "ToolBt.h"

ToolBt::ToolBt(QWidget *parent) : QWidget(parent)
{
    InitUi();
    InitConnect();
}

void ToolBt::InitUi()
{
    ExitBt = new QToolButton(this);
    MiniBt  = new QToolButton(this);

    ExitBt->setGeometry(64, 2, 24, 24);
    MiniBt->setGeometry(36, 2, 24, 24);

    this->setFixedSize(93, 26);
}

void ToolBt::InitConnect()
{
    connect(ExitBt, SIGNAL(clicked()), this, SIGNAL(Closed()));
    connect(MiniBt, SIGNAL(clicked()), this, SIGNAL(Minimi()));
}
