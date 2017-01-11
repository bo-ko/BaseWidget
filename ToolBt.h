#ifndef TOOLBT_H
#define TOOLBT_H

#include <QWidget>
#include <QToolButton>

class ToolBt : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBt(QWidget *parent = 0);

private:
    QToolButton *ExitBt; // close
    QToolButton *MiniBt; // minimize

    void InitUi();
    void InitConnect();

signals:
    void Minimi();
    void Closed();

public slots:
};

#endif // TOOLBT_H
