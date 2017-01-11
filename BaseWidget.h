#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QPoint>
#include <QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QPainter>
#include <QPainterPath>

class BaseWidget : public QWidget
{
    Q_OBJECT

public:
    BaseWidget(QWidget *parent = 0);
    ~BaseWidget();

private:
    bool   BaseAllowMove;
    bool   BaseAllowZoom;
    QPoint BaseMovePosition;

    void InitData();
    void InitUi();


protected:
    void mouseMoveEvent(QMouseEvent *event);   /* 鼠标移动 */
    void mousePressEvent(QMouseEvent *event);  /* 鼠标按下 */
    void mouseReleaseEvent(QMouseEvent *event); /* 鼠标释放 */
    void mouseDoubleClickEvent(QMouseEvent * event); /* 鼠标双击 */
    void hoverEvent();
};

#endif // BASEWIDGET_H
