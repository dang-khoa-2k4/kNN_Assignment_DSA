#include "kNN.hpp"

/* TODO: You can implement methods, functions that support your data structures here.
 * */



// TODO : Implementation of MyLinkList
template <class T>
MyLinkList<T>::MyLinkList()
{
    head = tail = nullptr;
    curNode = head;
    nE = 0;
}
template <class T>
MyLinkList<T>::MyLinkList(List<T> *other)
{
    Node *nT = &other->head;
    while (nT)
    {
        push_back(nT->data);
        nT = nT->next;
    }
}

template<class T>
typename MyLinkList<T>::Node *MyLinkList<T>::getHead()
{
    return head;
}

template<class T>
typename MyLinkList<T>::Node *MyLinkList<T>::getCur()
{
    return this->curNode;
}

template<class T>
void MyLinkList<T>::updateCur()
{
    curNode = curNode->next;
}

template<class T>
void MyLinkList<T>::resetCur()
{
    curNode = head;
}

template <class T>
void MyLinkList<T>::push_back(T val)
{
    Node * newNode = new Node(val);
    if (!head) 
    {
        head = tail = newNode;
        curNode = head;
    }
    else 
    {
        tail->next = newNode;
        tail = newNode;
    }
    nE++;
}
template <class T>
void MyLinkList<T>::push_front(T val)
{
    Node * newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
        curNode = head;
    } 
    else 
    {
        newNode->next = head;
        head = newNode;
    }
    nE++;
}
template <class T>
void MyLinkList<T>::insert(int idx, T val)
{
    if (idx < 0 || idx >= nE) return;
    Node ** nT = &head;
    while (idx && *nT)
    {
        --idx;
        nT = &((*nT)->next);
    }
    *nT = new Node(val, *nT);
    if (nE == 1) curNode = head;
    ++nE;
}
template <class T>
void MyLinkList<T>::remove(int idx)
{
    if (idx < 0 || idx >= nE) return;
    Node ** pT = &(this->head);
    while (idx)
    {
        --idx;
        pT = &((*pT)->next);
    }
    Node *delNode = *pT;
    *pT = (*pT)->next;
    delete delNode;
    nE--;
}
template <class T>
T& MyLinkList<T>::get(int idx) const
{
    if (idx < 0 || idx >= nE)  throw std::out_of_range("get(): Out of range");
    Node * pT = head;
    while (idx)
    {
        --idx;
        pT = pT->next;
    }
    return pT->data;
}

template<class T>
T &MyLinkList<T>::getNext(MyLinkList<T>::Node *curNode) const
{
    return curNode->data;
}

template <class T>
int MyLinkList<T>::length() const 
{
    return nE;
}
template <class T>
void MyLinkList<T>::clear()
{
    Node * pT = head;
    while (pT)
    {
        Node *temp = pT;
        pT = pT->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    curNode = nullptr;
    nE = 0;
}
template <class T>
void MyLinkList<T>::print() const
{
    Node * pT = head;
    cout << pT->data;
    pT = pT->next;
    while (pT)
    {
        cout << " " << pT->data;
        pT = pT->next;
    }
}
template <class T>
void MyLinkList<T>::reverse()
{
    Node * pT = nullptr;
    while (head)
    {
        Node * temp = head;
        head = head->next;
        temp->next = pT;
        pT = temp;
    }
    head = pT;
}

template<class T> 
void MyLinkList<T>::traverse(MyLinkList<T> * other, void (*f)(T &, MyLinkList<T> *))
{
    Node * pT = head;
    while (pT)
    {
        f(pT->data, other);
        pT = pT->next;
    }
}
template<class T> 
void MyLinkList<T>::traverse(int val, void (*f)(T &, int))
{
    Node * pT = head;
    while (pT)
    {
        f(pT->data, val);
        pT = pT->next;
    }
}

//TODO : Implementation of Array List
// template <class T>
// ArrayList<T>::ArrayList()
// {
//     pA = new T[DEFAULT_CAPACITY];
//     capacity = DEFAULT_CAPACITY;
//     nE = 0;
// }

// template <class T>
// ArrayList<T>::ArrayList(const List<T> *other)
// {
//     Node *nT = &other->head;
//     while (nT)
//     {
//         push_back(nT->data);
//         nT = nT->next;
//     }
// }

// template <class T>
// ArrayList<T>::ArrayList(const int capacity)
// {
//     pA = new T[capacity];
//     this->capacity = capacity;
//     nE = 0;
// }

// template <class T>
// void ArrayList<T>::push_back(T val)
// {
//     Node * newNode = new Node(val);
//     if (!head) head = tail = newNode;
//     else 
//     {
//         tail->next = newNode;
//         tail = newNode;
//     }
// }

// template <class T>
// void ArrayList<T>::push_front(T val)
// {
//     Node * newNode = new Node(val);
//     if (!head) head = tail = newNode;
//     else 
//     {
//         newNode->next = head;
//         head = newNode;
//     }
// }
// template <class T>
// void ArrayList<T>::insert(int idx, T val)
// {
//     if (nE == capacity) reSize(capacity + 1);
//     if (idx >= nE)
//     {
//         idx = nE;
//     }
//     if (idx < 0) idx = 0;
//     for (int i = nE; i > idx; i--)
//     {
//         pA[i] = std::move(pA[i - 1]);
//     }
//     pA[idx] = std::move(val);
//     nE++;
// }

// template <class T>
// void ArrayList<T>::remove(int idx)
// {
//     if (idx < 0 || idx >= nE) return;
//     nE--;
//     for (int i = idx; i < nE; i++)
//     {
//         pA[i] = std::move(pA[i + 1]);
//     }
// }
// template <class T>
// T& ArrayList<T>::get(int idx) const
// {
//     if (idx < 0 || idx >= nE)  throw std::out_of_range("get(): Out of range");
//     return std::move(pA[idx]);
// }
// template <class T>
// int ArrayList<T>::length() const 
// {
//     return nE;
// }
// template <class T>
// void ArrayList<T>::clear()
// {
//     delete [] pA;
//     pA = nullptr;
//     capacity = 0; 
//     nE = 0;
// }
// template <class T>
// void ArrayList<T>::print() const
// {
// }
// template <class T>
// void ArrayList<T>::reverse()
// {

// }

// TODO : Implementation of Dataset
Dataset::Dataset()
{   
    data = new MyLinkList<List<int>*>();
    columnNames = new MyLinkList<std::string>();
    label = new MyLinkList<int>();
}
Dataset::~Dataset()
{
    delete label;
    delete columnNames;

    ((MyLinkList<List<int>*>*) data)
    ->traverse((MyLinkList<List<int> *> *) this->data, 
    [](List<int> * &l, MyLinkList<List<int> *> * p)
    {
        l->clear();
        delete l;
    });
    // if (((MyLinkList<List<int> *> *) data)->getHead()) 
    // {
    //     List<int> * pT = ((MyLinkList<List<int> *> *) data)->getHead()->data;
    //     while (pT)
    //     {
    //         List<int> *delList = pT;
    //         if (((MyLinkList<List<int> *> *) data)->getCur()->next)
    //         {
    //             pT = ((MyLinkList<List<int> *> *) data)->getCur()->next->data;
    //             ((MyLinkList<List<int> *> *) data)->updateCur(); 
    //         }    
    //         else pT = nullptr;
    //         delete delList;
    //     }
    // }
    delete data;
}

// NOTE : Have reset cur node to head after each operation
Dataset::Dataset(const Dataset& other)
{
    this->data = new MyLinkList<List<int>*>();
    ((MyLinkList<List<int>*>*)other.data)->traverse((MyLinkList<List<int> *> *) this->data, 
    [](List<int> * &l, MyLinkList<List<int> *> * p)
    {
        List<int> * newRow = new MyLinkList<int>();
        ((MyLinkList<int>*)l)->traverse((MyLinkList<int> *) newRow, [](int &i, MyLinkList<int> * p) {p->push_back(i);});
        p->push_back(newRow);
    });
    // Dataset * pT = new Dataset();
    // int sizeRow = ((MyLinkList<List<int> *> *) other.data)->length();
    // ((MyLinkList<List<int> *> *) other.data)->resetCur(); // make sure curNode of Row is at head
    // while (sizeRow--)
    // {
    //     MyLinkList<int> * newRow = new MyLinkList<int>();
    //     List<int> * pL = ((MyLinkList<List<int> *> *) other.data)->getCur()->data;
    //     int sizeCol = pL->length();
    //     ((MyLinkList<int> *)pL)->resetCur(); // make sure curNode of Col is at head
    //     while (sizeCol--)
    //     {
    //         newRow->push_back(((MyLinkList<int> *)pL)->getCur()->data);
    //         ((MyLinkList<int> *)pL)->updateCur(); // go to next col
    //     }
    //     pT->data->push_back(newRow);
    //     ((MyLinkList<List<int> *> *) other.data)->updateCur(); // go to new row
    // }
    this->columnNames = new MyLinkList<std::string>();
    other.columnNames->traverse(this->columnNames,[](std::string &s, MyLinkList<string> * p){p->push_back(s);});
    this->label = new MyLinkList<int>();
    other.label->traverse(this->label,[](int &i, MyLinkList<int> * p){p->push_back(i);});
}
Dataset &Dataset::operator=(const Dataset& other)
{
    this->data = new MyLinkList<List<int>*>();
    ((MyLinkList<List<int> *> *)other.data)
    ->traverse((MyLinkList<List<int> *> *) this->data, 
    [](List<int> * &l, MyLinkList<List<int> *> * p)
    {
        MyLinkList<int> * newRow = new MyLinkList<int>();
        ((MyLinkList<int>*) l)->traverse(newRow, [](int &i, MyLinkList<int> * p){p->push_back(i);});
        p->push_back(newRow);
    });
    this->columnNames = new MyLinkList<std::string>();
    other.columnNames->traverse(this->columnNames,[](std::string &s, MyLinkList<string> * p){p->push_back(s);});
    this->label = new MyLinkList<int>();
    other.label->traverse(this->label, [](int &i, MyLinkList<int> * p){p->push_back(i);});
    return *this;
}

bool Dataset::loadFromCSV(const char* fileName)
{
    ifstream file(fileName);
    if (!file.is_open()) return false;
    string line;
    getline(file, line);
    stringstream ss(line);
    string token;
    while (getline(ss, token, ','))
    {
        columnNames->push_back(token);
    }
    while (getline(file, line))
    {
        stringstream ss(line);
        List<int> * newRow = new MyLinkList<int>();
        label->push_back(stoi(line.substr(0, line.find(','))));
        while (getline(ss, token, ','))
        {
            newRow->push_back(stoi(token));
        }
        data->push_back(newRow);
    }
    return true;
}

List<std::string> *Dataset::getColumnNames()
{
    return columnNames;
}

void Dataset::printHead(int nRows, int nCols) const
{
    int i = 0;
    columnNames->resetCur();
    while (i < nCols)
    {
        cout << columnNames->getCur()->data;
        if (i < nCols - 1) cout << " ";
        columnNames->updateCur();
        i++;
    }
    cout << endl;
    i = 0;
    ((MyLinkList<List<int> *> *) data)->resetCur();
    while (i < nRows && ((MyLinkList<List<int> *> *) data)->getCur())
    {
        int j = 0;
        List<int> * pL = ((MyLinkList<List<int> *> *) data)->getCur()->data;
        ((MyLinkList<int>*) pL)->resetCur();
        while (j < nCols && ((MyLinkList<int> *) pL)->getCur())
        {
            cout << ((MyLinkList<int> *) pL)->getCur()->data;
            if (j < nCols - 1) cout << " ";
            ((MyLinkList<int> *) pL)->updateCur();
            j++;
        }
        cout << endl;
        ((MyLinkList<List<int> *> *) data)->updateCur();
        i++;
    }
}
void Dataset::printTail(int nRows, int nCols) const
{
    int i = 0;
    columnNames->resetCur();
    while (columnNames->getCur())
    {
        if (i >= columnNames->length() - nCols)
        {
            cout << columnNames->getCur()->data;
            if (i < columnNames->length() - 1) cout << " ";
        }
        columnNames->updateCur();
        i++;
    }
    cout << endl;
    i = 0;
    ((MyLinkList<List<int> *> *) data)->resetCur();
    while (((MyLinkList<List<int> *> *) data)->getCur())
    {
        int j = 0;
        List<int> * pL = ((MyLinkList<List<int> *> *) data)->getCur()->data;
        ((MyLinkList<int>*) pL)->resetCur();
        while (((MyLinkList<int> *) pL)->getCur())
        {
            if  (i >= ((MyLinkList<List<int> *> *) data)->length() - nRows 
                        && j >= ((MyLinkList<int> *) pL)->length() - nCols)
            {
                cout << ((MyLinkList<int> *) pL)->getCur()->data;
                if (j < ((MyLinkList<int> *) pL)->length() - 1) cout << " ";
            }
            ((MyLinkList<int> *) pL)->updateCur();
            j++;
        }
        if (i >= ((MyLinkList<List<int> *> *) data)->length() - nRows) cout << endl;
        ((MyLinkList<List<int> *> *) data)->updateCur();
        i++;
    }
    cout << endl;
}
void Dataset::getShape(int& nRows, int& nCols) const
{
    nRows = ((MyLinkList<List<int> *> *) data)->length();
    nCols = ((MyLinkList<List<int> *> *) data)->getHead()->data->length();
}
void Dataset::columns() const
{
    columnNames->print();
}

// axix = 0 : drop row, axis = 1 : drop column
bool Dataset::drop(int axis, int idx, std::string columns )
{
    if (axis == 0)
    {
        if (idx < 0 || idx >= ((MyLinkList<List<int> *> *) data)->length()) return false;
        ((MyLinkList<List<int> *> *) data)->remove(idx);
    }
    else if (axis == 1)
    {
        ((MyLinkList<List<int> *> *) data)->resetCur();
        columnNames->resetCur();
        int index = 0;
        while (columnNames->getCur())
        {
            if (columnNames->getCur()->data == columns)
            {
                columnNames->remove(index);
                break;
            }
            columnNames->updateCur();
            index++;
        }
        ((MyLinkList<List<int> *> *) data)->traverse(index, 
        [](List<int> * &l, int index)
        {
            ((MyLinkList<int>*)l)->remove(index);
        });
    }
    else return false;
    return true;
        
}
Dataset Dataset::extract(int startRow, int endRow, 
                         int startCol, int endCol ) const
{
    if (endRow == -1) endRow = ((MyLinkList<List<int> *> *) data)->length() - 1;
    if (endCol == -1) endCol = ((MyLinkList<int> *) ((MyLinkList<List<int> *> *) data)->getHead()->data)->length() - 1;
    Dataset * pT = new Dataset();
    ((MyLinkList<List<int> *>*)data)->resetCur();
    columnNames->resetCur();
    label->resetCur();
    int i = 0;
    while (((MyLinkList<List<int> *>*)data)->getCur())
    {
        if (i >= startRow && i <= endRow)
        {
            List<int> * pL = ((MyLinkList<List<int> *>*)data)->getCur()->data;
            ((MyLinkList<int>*)pL)->resetCur();
            pT->label->push_back(label->getCur()->data);
            int j = 0;
            MyLinkList<int> * newRow = new MyLinkList<int>();
            while (((MyLinkList<int>*)pL)->getCur())
            {
                if (j >= startCol && j <= endCol)
                {
                    newRow->push_back(((MyLinkList<int>*)pL)->getCur()->data);
                }
                if (i == startRow && j >= startCol && j <= endCol)
                {
                    pT->columnNames->push_back(columnNames->getCur()->data);
                    columnNames->updateCur();
                }
                if (j == endCol) break;
                ((MyLinkList<int>*)pL)->updateCur();
                j++;
            }
            pT->data->push_back(newRow);
        }
        if (i == endRow) break;
        ((MyLinkList<List<int> *>*)data)->updateCur();
        label->updateCur();
        i++;
    }  
    return *pT;
}

List<List<int> *> *Dataset::getData() const
{
    return data;
}

MyLinkList<int> *Dataset::getLabel() const
{
    return label;
}

// TODO : Implementation of kNN
kNN::kNN(int k)
{
    this->k = k;
    X_train = nullptr;
    y_train = nullptr;
}
void kNN::fit(const Dataset& X_train, const Dataset& y_train)
{
    this->X_train = new Dataset(X_train);
    this->y_train = new Dataset(y_train);
}
Dataset kNN::predict(const Dataset& X_test)
{
    Dataset * y_pred = new Dataset();
    // calc distance from each row of X_test to each row of X_train
    int maxDistance = sqrt(pow(255, 2) * 28 * 28);
    ((MyLinkList<List<int>*>*) X_test.getData())->resetCur();
    // For each row of X_test, calc distance to each row of X_train
    while (((MyLinkList<List<int>*>*)X_test.getData())->getCur())
    {
        // store distance from each row of X_train to 1 image of X_test
        List<int> * image = ((MyLinkList<List<int>*>*) X_test.getData())->getCur()->data;
        int * label = new int[maxDistance];
        int * distanceToTrain = new int[X_train->getData()->length()];
        ((MyLinkList<List<int>*>*) X_train->getData())->resetCur();
        // For each image of X_train, calc distance to 1 image of X_test
        y_train->getLabel()->resetCur();
        int idx = 0;
        while (((MyLinkList<List<int>*>*)X_train->getData())->getCur())
        {
            List<int> * trainImage = ((MyLinkList<List<int>*>*) X_train->getData())->getCur()->data;
            int distance = 0;
            ((MyLinkList<int> *)image)->resetCur();
            ((MyLinkList<int> *)trainImage)->resetCur();
            // for each pixel of 1 image of X_train, calc distance to 1 image of X_test
            while (((MyLinkList<int> *)image)->getCur() && ((MyLinkList<int> *)trainImage)->getCur())
            {
                distance += pow(((MyLinkList<int> *)image)->getCur()->data - 
                                ((MyLinkList<int> *)trainImage)->getCur()->data, 2);
                ((MyLinkList<int> *)image)->updateCur();
                ((MyLinkList<int> *)trainImage)->updateCur();
            }
            distanceToTrain[idx++] = sqrt(distance);
            label[distanceToTrain[idx - 1]] = y_train->getLabel()->getCur()->data;
            // go to next image of X_train
            ((MyLinkList<List<int>*>*) X_train->getData())->updateCur();
            y_train->getLabel()->updateCur();
        }
        // for (int i = 0; i < X_train->getData()->length(); i++)
        // {
        //    cout << distanceToTrain[i] << " ";
        // }
        // cout << endl; 
        // for (int i = 0; i < X_train->getData()->length(); i++)
        // {
        //     cout << label[distanceToTrain[i]] << " ";
        // }
        // cout << endl;  

        // Sort distanceToTrain and map with label of X_train
        mergeSort(distanceToTrain, 0, X_train->getData()->length() - 1);
        // for (int i = 0; i < X_train->getData()->length(); i++)
        // {
        //    cout << distanceToTrain[i] << " ";
        // }
        // cout << endl; 
        // cout << "After\n";
        // for (int i = 0; i < X_train->getData()->length(); i++)
        // {
        //     cout << label[distanceToTrain[i]] << " ";
        // }
        // cout << endl << endl;   
        int maxLabel[10];
        for (int i = 0; i < 10; i++) maxLabel[i] = 0;
        for (int i = 0; i < k; i++)
        {
            maxLabel[label[distanceToTrain[i]]]++;
        }
        int maxIdx = 0;
        for (int i = 0; i < 10; i++)
        {
            if (maxLabel[i] > maxLabel[maxIdx]) maxIdx = i;
        }
        y_pred->getLabel()->push_back(maxIdx);
        delete [] label;
        delete [] distanceToTrain;
        // go to next image of X_test
        ((MyLinkList<List<int>*>*) X_test.getData())->updateCur();
    }
    return *y_pred;
}
double kNN::score(const Dataset& y_test, const Dataset& y_pred)
{
    y_pred.getLabel()->resetCur();
    y_test.getLabel()->resetCur();
    int count = 0;
    while (y_pred.getLabel()->getCur())
    {
        if (y_pred.getLabel()->getCur()->data == y_test.getLabel()->getCur()->data) count++;
        y_pred.getLabel()->updateCur();
        y_test.getLabel()->updateCur();
    }
    // cout << "Accuracy: " << count << " / " << y_pred.getLabel()->length() << endl;
    return (double)count / y_pred.getLabel()->length();
}

// TODO : Extra function
// train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
void train_test_split(Dataset& X, Dataset& y, double test_size, 
                      Dataset& X_train, Dataset& X_test, 
                      Dataset& y_train, Dataset& y_test)
{
    int nRows, nCols;
    X.getShape(nRows, nCols);
    int nData = nRows - (nRows * test_size);
    
    X_train = X.extract(0, nData - 1, 0, -1);
    y_train = y.extract(0, nData - 1, 0, 0);
    X_test = X.extract(nData, -1, 0, -1);
    y_test = y.extract(nData, -1, 0, 0);
}

void merge(int *arr, int l, int m, int r)
{
    int * tempL = new int[m - l + 1];
    for (int i = l; i < m + 1; i++)
    {
        tempL[i - l] = arr[i];
    }
    int i = 0, j = m + 1, k = l;
    while (i < m - l + 1 && j < r + 1)
    {
        if (tempL[i] < arr[j])
        {
            arr[k] = tempL[i];
            i++;
        }
        else 
        {
            arr[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i < m - l + 1)
    {
        arr[k] = tempL[i];
        i++;
        k++;
    }
    delete[] tempL;
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}