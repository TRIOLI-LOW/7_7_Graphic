#ifndef GRAPHCHART_H
#define GRAPHCHART_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>

#define FIRST_GRAPH 0

class GraphChart : public QObject
{
    Q_OBJECT
public:

    GraphChart (uint32_t number = 0);
    void AddToGraph (QVector<double> x, QVector<double> y, uint32_t number);
    void UpdateGraph (QChart* chart);
    void ClearGraph (QChart* chart);

Q_SIGNALS:
       void signalsGraph(QChart* chart);
private:

   QList <QLineSeries*> ptrGraph;
   uint32_t numGraph = 0;



};

#endif // GRAPHCHART_H
