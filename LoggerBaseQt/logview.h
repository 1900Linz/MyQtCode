#ifndef LOGVIEW_H
#define LOGVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LogView; }
QT_END_NAMESPACE

class LogView : public QMainWindow
{
    Q_OBJECT

public:
    LogView(QWidget *parent = nullptr);
    ~LogView();

private:
    Ui::LogView *ui;
};
#endif // LOGVIEW_H
