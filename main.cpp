#include "kNN.hpp"

void tc1(){
    Dataset dataset;
    dataset.loadFromCSV("../datasets/mnist_test.csv");
    dataset.printHead();
    dataset.printTail();
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

int main() {
    tc1();
    return 0;
}