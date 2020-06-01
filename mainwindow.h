#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include  <QMouseEvent>
#include <QTimer>
#include <QDebug>
#include <QPushButton>

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent*);
    MainWindow(QWidget*parent =nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
