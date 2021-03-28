//
// Created by hqnddw on 2020/9/10.
//

#include <iostream>

using namespace std;

#define MAXSIZE 5 //最大队列长度

template<class T>
class RQueue {
public:
    RQueue()
            : _base(NULL), _front(0), _rear(0) {
        _base = (T *) malloc(MAXSIZE * sizeof(T));
        if (!_base) {
            cout << "开辟空间失败" << endl;
        }
    }

    //返回队列元素个数
    int Length() {
        return (_rear - _front + MAXSIZE) % MAXSIZE;
    }

    //插入元素
    bool Insert(const T &x) {
        if ((_rear + 1) % MAXSIZE == _front)//队列满
        {
            cout << "队列已满！" << endl;
            return false;
        }

        _base[_rear] = x;
        _rear = (_rear + 1) % MAXSIZE;
        return true;
    }

    //删除元素
    bool Delete() {
        if (_front == _rear) {
            cout << "队列为空！" << endl;
            return false;
        }
        _front = (_front + 1) % MAXSIZE;
        return true;
    }


private:
    T *_base; //初始化的动态分配存储空间
    int _front;  //头指针，若队列不空，指向队列头元素
    int _rear;   //尾指针，若队列不空，指向队列尾元素的下一个位置
};