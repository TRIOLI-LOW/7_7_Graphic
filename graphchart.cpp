#include "graphchart.h"

GraphChart::GraphChart(uint32_t number)
{
    numGraph = number;
    ptrGraph.resize(numGraph);

 for (int i = 0; i < numGraph; ++i){
     ptrGraph[i] = new QLineSeries(this);
 }

}

void GraphChart::AddToGraph(QVector<double> x, QVector<double> y, uint32_t numGraph){

    uint32_t size = 0;

    if (x.size() >= y.size()){
        size = y.size();
    }
    else{
        size = x.size();
    }

      qDebug () << x << "______"<< y ;
    //Добавление точек
    for(int i = 0 ; i < size; i++){
        ptrGraph[numGraph]->append(x[i],y[i]);
    }
}

void GraphChart::ClearGraph(QChart *chart){

    for (int i = 0; i < numGraph; i++){
        ptrGraph[i]->clear();
        chart->removeSeries(ptrGraph[i]);
    }
}

void GraphChart::UpdateGraph(QChart *chart){

    for (int i = 0; i < numGraph; i++){
        chart->addSeries(ptrGraph[i]);
    }
}
