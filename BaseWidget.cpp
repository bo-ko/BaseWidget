#include "BaseWidget.h"

BaseWidget::BaseWidget(QWidget *parent)
    : QWidget(parent)
{
    InitData();
    InitUi();
}

BaseWidget::~BaseWidget()
{
}

void BaseWidget::InitData()
{
    BaseAllowMove = false;
    BaseAllowZoom = false;
    BaseMovePosition = QPoint();
}

void BaseWidget::InitUi()
{
    this->setWindowFlags(Qt::FramelessWindowHint); //无边框
}

/* mouse clicked */
void BaseWidget::mousePressEvent(QMouseEvent *event)
{
    /* clicked mouse left button */
    if ( event->button() == Qt::LeftButton )
    {
        if (this->width() - 10 < event->pos().x() && event->pos().x() < this->width() &&
            this->height() -10 < event->pos().y() && event->pos().y() < this->height() )
        {
            BaseAllowZoom = true;
        }
        else if (this->width() - 5 > event->pos().x() && event->pos().x() > 5 &&
                 event->pos().y() > 5 && event->pos().y() < 23)
        {
            BaseAllowMove = true;
            BaseMovePosition = event->globalPos() - pos();
        }
    }
    return QWidget::mousePressEvent(event);
}

/* mouse move */
void BaseWidget::mouseMoveEvent(QMouseEvent *event)
{
    if ( BaseAllowZoom )
    {
        QPoint pt = event->pos();
        if (pt.x() > 900)
            setFixedWidth(pt.x());
        if (pt.y() > 650)
            setFixedHeight(pt.y());
    }
    else
    {
        if ( BaseAllowMove && (event->buttons() && Qt::LeftButton) \
            && (event->globalPos()-BaseMovePosition).manhattanLength() > \
                QApplication::startDragDistance() )
        {
            move(event->globalPos()-BaseMovePosition);
            BaseMovePosition = event->globalPos() - pos();
        }
    }
    return QWidget::mouseMoveEvent(event);
}

/* mouse free */
void BaseWidget::mouseReleaseEvent(QMouseEvent *event)
{
    BaseAllowMove = false;
    BaseAllowZoom = false;
    return QWidget::mouseReleaseEvent(event);
}

void BaseWidget::mouseDoubleClickEvent(QMouseEvent * event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (this->width() - 5 > event->pos().x() && event->pos().x() > 5 &&
            event->pos().y() > 5 && event->pos().y() < 23)
        {
            this->showMaximized();
        }
    }
}
