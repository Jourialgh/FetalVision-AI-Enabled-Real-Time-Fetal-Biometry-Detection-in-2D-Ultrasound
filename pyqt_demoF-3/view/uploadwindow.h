#ifndef UPLOADWINDOW_H
#define UPLOADWINDOW_H

#include <QMainWindow>

namespace Ui {
class UploadWindow;
}

class UploadWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UploadWindow(QWidget *parent = nullptr);
    ~UploadWindow();

private:
    Ui::UploadWindow *ui;
};

#endif // UPLOADWINDOW_H
