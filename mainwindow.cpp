#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_alege_fisier_sursa_clicked()
{
    folder_sursa = QFileDialog::getExistingDirectory(this, "Alege Folder Sursa", QDir::homePath());
    ui->Cale_Fisier_Sursa->setText(folder_sursa);
}


void MainWindow::on_button_alege_fisier_destinatie_clicked()
{
    folder_destinatie = QFileDialog::getExistingDirectory(this, "Alege Folder Destinatie", QDir::homePath());
    ui->Cale_Fisier_Destinatie->setText(folder_destinatie);
}


void MainWindow::on_button_oglindire_clicked()
{
    // Ma asigur ca am selectat atat un folder sursa, cat si unul destinatie.
    if (folder_sursa.isEmpty() || folder_destinatie.isEmpty()) {
        return;
    }

    QDir sourceDir(folder_sursa);
    QStringList filters;

    // Specific extensile pe care le pot avea imaginile.
    // In cazul in care o imagine are o alta extensie(De exemplu .jpeg), se trece peste ea.
    filters << "*.jpg" << "*.png";
    sourceDir.setNameFilters(filters);

    // Se parcurg fisierele din folderul sursă si se prelucreaza.
    QStringList imageFiles = sourceDir.entryList(QDir::Files);
    foreach (const QString &fileName, imageFiles) {
        // Citire imagine
        cv::Mat image = cv::imread(folder_sursa.toStdString() + "/" + fileName.toStdString());
        // Oglindire imagine
        cv::flip(image, image, 1); // Oglindire
        // Salvare imagine
        cv::imwrite(folder_destinatie.toStdString() + "/" + fileName.toStdString(), image);
    }
}

void MainWindow::on_Cale_Fisier_Sursa_returnPressed()
{

}

void MainWindow::on_Cale_Fisier_Destinatie_returnPressed()
{

}

