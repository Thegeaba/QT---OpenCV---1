#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QtGui>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_alege_fisier_sursa_clicked();

    void on_button_alege_fisier_destinatie_clicked();

    void on_button_oglindire_clicked();

    void on_Cale_Fisier_Sursa_returnPressed();

    void on_Cale_Fisier_Destinatie_returnPressed();

private:
    Ui::MainWindow *ui;
    Mat poza;
    QString folder_sursa;
    QString folder_destinatie;

};
#endif // MAINWINDOW_H
