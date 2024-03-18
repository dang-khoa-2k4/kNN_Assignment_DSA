#include "kNN.hpp"

void tc1(){
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    dataset.printHead();
    cout << endl;
    dataset.printTail();
    cout << endl;
    int nRows, nCols;
    dataset.getShape(nRows, nCols);
    cout << "Shape: " << nRows << "x" << nCols << endl;
    
    kNN knn(5);
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);
    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
    
    // X_train.getShape(nRows, nCols);
    // cout << "Shape: " << nRows << "x" << nCols << endl;
    // X_test.getShape(nRows, nCols);
    // cout << "Shape: " << nRows << "x" << nCols << endl;
    // y_train.getShape(nRows, nCols);
    // cout << "Shape: " << nRows << "x" << nCols << endl;
    // y_test.getShape(nRows, nCols);
    // cout << "Shape: " << nRows << "x" << nCols << endl;


    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);
    double accuracy = knn.score(y_test, y_pred);
    cout << "Accuracy: " << accuracy << endl;
}

void tc2()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    int nRows, nCols;

    kNN knn;
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    cout << "y_pred" << endl;
    y_pred.printHead(10, 10);
    cout << endl;
    cout << "y_test" << endl;
    y_test.printHead(10, 10);
    cout << endl;
    y_test.printTail(10, 10);
    cout << endl;
}

void tc1009()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    List<int> *row = dataset.getData()->get(0);

    for (int i = 0; i < 10000; i++)
    {
        row->push_back(1);
    }

    cout << row->length() << endl;
    row->print();
}
void tc1029()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    List<int> *row = dataset.getData()->get(0);

    row->insert(0, 1);
    row->insert(1, 3);
    row->insert(2, 2);
    row->insert(3, 5);

    cout << row->length() << endl;
    row->print();
}

int main() {
    // tc1009();
    // tc1029();
    tc1();
    return 0;
}