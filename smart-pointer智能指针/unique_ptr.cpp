//
// Created by hqnddw on 2020/9/6.
//
template<typename T>
class myUniquePtr {
public:
    explicit myUniquePtr(T *ptr = nullptr) : mPtr(ptr) {}

    ~myUniquePtr() {
        if (mPtr)
            delete mPtr;
    }

    myUniquePtr(const myUniquePtr &p) = delete;

    myUniquePtr &operator=(const myUniquePtr &p) = delete;

    myUniquePtr(myUniquePtr &&p) : mPtr(p.mPtr) {
        p.mPtr = nullptr;
    }

    myUniquePtr &operator=(const myUniquePtr &&p) {
        if (p == *this)
            return *this;
        if (mPtr)
            delete mPtr;
        mPtr = p.mPtr;
        p.mPtr = nullptr;
        return *this;
    }


    T *operator->() const {
        return mPtr;
    }

    T &operator*() const {
        return *mPtr;
    }

    void reset(T *p = nullptr) {
        if (mPtr != p) {
            if (mPtr)
                delete mPtr;
            mPtr = p;
        }
    }

    T *release() {
        T *res = mPtr;
        mPtr = nullptr;
        return res;
    }

private:
    T *mPtr;
};