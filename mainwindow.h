#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDataStream>
#include <QMessageBox>
#include <QtGlobal>
#include <QtConcurrent>
#include <QElapsedTimer>
#include <QVector>
#include <QList>
#include <algorithm>
#include "graphchart.h"
#include "dialog.h"

///Подключаем все что нужно для графиков
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>

#define NUM_GRAPHS 1
#define FD 1000.0 //частота дискретизации

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Метод считывает данные из исходного файла
    QVector<uint32_t> ReadFile(QString path, uint8_t numberChannel);
    //Метод преобразует данные физические величины, В?
    QVector<double> ProcessFile(QVector<uint32_t> dataFile);
    //Метод ищет Максимумы
    QVector<double> FindMax(QVector<double> resultData);
    //Метод ищет минимумы
    QVector<double> FindMin(QVector<double> resultData);
    //Метод отображает результаты
    void DisplayResult(QVector<double> mins, QVector<double> maxs);


Q_SIGNALS:
    void sig_graphPrint(QChart* chart);


private slots:
    void on_pb_path_clicked();
    void on_pb_start_clicked();
    void graphPrint(QChart* chart);


private:
    Ui::MainWindow *ui;
    QString pathToFile = "";
    uint8_t numberSelectChannel = 0xEA;

    QChart* chart;
    QChartView* chartView;
    GraphChart* graphClass;
    QGridLayout *layout;

    QDialog* dialog;

    QVector<uint32_t> readData;
    QVector<double> procesData;
    QVector<double> mins, maxs;
    QVector<double> x ;
    QVector<double> y ;

};
#endif // MAINWINDOW_H
