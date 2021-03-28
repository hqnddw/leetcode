//
// Created by hqnddw on 2020/10/6.
//

static int flag = 0;

int TestAndSet(int *ptr, int new_val) {
    int old = *ptr;
    *ptr = new_val;
    return old;
}

void lock() {
    while (TestAndSet(&flag, 1) == 1);
    //flag=1;
}

void unlock() {
    flag = 0;
}

