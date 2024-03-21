#include "main.hpp"

/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */

#define DEFAULT_CAPACITY 10
#define DEFAULT_SIZE_BLOCK 32

template<class T>
class List {
public:
    List() {};
    virtual ~List() = default;
    virtual void push_back(T value) = 0;
    virtual void push_front(T value) = 0;
    virtual void insert(int index, T value) = 0;
    virtual void remove(int index) = 0;
    virtual T& get(int index) const = 0;
    virtual int length() const = 0 ;
    virtual void clear() = 0;
    virtual void print() const = 0;
    virtual void reverse() = 0;
};  

template<class T>
class MyLinkList : public List<T>
{
protected:
    struct Node
    {
        T data;
        Node *next;
        Node(const T& val, Node *p = nullptr): data(val), next(p) {}
        Node(const T&& val, Node *p = nullptr): data(std::move(val)), next(p) {}
    };
    Node *head;
    Node *tail;
    Node *curNode;
    int nE;
public:
    MyLinkList();
    MyLinkList(List<T> *other);
    ~MyLinkList() { clear(); }
    Node * getHead();
    Node * getCur();
    void updateCur();
    void resetCur();
    void push_back(T value);
    void push_front(T value);
    void insert(int index, T value);
    void remove(int index);
    T& get(int index) const;
    int length() const ;
    void clear();
    void print() const;
    void reverse();
    
    void traverse(MyLinkList<T> * other, void (*f)(T&, MyLinkList<T>*));    
    void traverse(int val, void (*f)(T&, int));    
};


class Dataset {
private:
    List<List<int>*>* data;
    //You may need to define more
    MyLinkList<string> * columnNames;
    // MyLinkList<int> * label;
public:
    Dataset();
    ~Dataset();
    Dataset(const Dataset& other);
    Dataset& operator=(const Dataset& other);
    List<string> * getColumnNames();
    bool loadFromCSV(const char* fileName);
    void printHead(int nRows = 5, int nCols = 5) const;
    void printTail(int nRows = 5, int nCols = 5) const;
    void getShape(int& nRows, int& nCols) const;
    void columns() const;
    List<List<int> *>* getData() const;
    bool drop(int axis = 0, int index = 0, std::string columns = "");
    Dataset extract(int startRow = 0, int endRow = -1, int startCol = 0, int endCol = -1) const;
};

class kNN {
private:
    int k;
    //You may need to define more
    Dataset * X_train;
    Dataset * y_train;
    struct imageInfo
    {
        float distanceToTrain;
        int label;
        bool operator<(const imageInfo& other) 
        {return this->distanceToTrain < other.distanceToTrain;};
    };
public:
    kNN(int k = 5);
    void fit(const Dataset& X_train, const Dataset& y_train);
    Dataset predict(const Dataset& X_test);
    double score(const Dataset& y_test, const Dataset& y_pred);
};

void train_test_split(Dataset& X, Dataset& y, double test_size, 
                        Dataset& X_train, Dataset& X_test, Dataset& y_train, Dataset& y_test);


// Please add more or modify as needed
template<class T> void merge(T * arr, int l, int m, int r);
template<class T> void mergeSort(T * arr, int l, int r);