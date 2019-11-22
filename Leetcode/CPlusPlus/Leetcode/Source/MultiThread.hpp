#ifndef _MULTI_THREAD_HPP_
#define _MULTI_THREAD_HPP_

#include <condition_variable>
#include <functional>
#include <mutex>
#include <thread>

#include "Solution.h"

class Foo : public Solution
{
public:
    bool b1;
    bool b2;

    Foo() {
        b1 = false;
        b2 = false;
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        b1 = true;
    }

    void second(function<void()> printSecond) {
        while (!b1)
        {
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        b2 = true;
    }

    void third(function<void()> printThird) {
        while (!b2)
        {
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }


    //bool b1;
    //bool b2;
    //std::mutex m1;
    //std::mutex m2;
    //std::condition_variable cv1;
    //std::condition_variable cv2;

    //Foo() {
    //    b1 = false;
    //    b2 = false;
    //}

    //void first(function<void()> printFirst) {
    //    std::unique_lock<std::mutex> lck(m1);

    //    // printFirst() outputs "first". Do not change or remove this line.
    //    printFirst();

    //    b1 = true;
    //    cv1.notify_one();
    //}

    //void second(function<void()> printSecond) {
    //    std::unique_lock<std::mutex> lck(m1);
    //    cv1.wait(lck, [this] { return b1; });

    //    // printSecond() outputs "second". Do not change or remove this line.
    //    printSecond();

    //    std::unique_lock<std::mutex> lck_(m2);
    //    b2 = true;
    //    cv2.notify_one();
    //}

    //void third(function<void()> printThird) {
    //    std::unique_lock<std::mutex> lck(m2);
    //    cv2.wait(lck, [this] { return b2; });

    //    // printThird() outputs "third". Do not change or remove this line.
    //    printThird();
    //}


    static void printFirst()
    {
        cout << "first" << endl;
    }

    static void printSecond()
    {
        cout << "second" << endl;
    }

    static void printThird()
    {
        cout << "third" << endl;
    }

    virtual void Run()
    {
        std::thread t1 = std::thread(std::mem_fn(&Foo::first), this, &Foo::printFirst);
        std::thread t2 = std::thread(std::mem_fn(&Foo::second), this, &Foo::printSecond);
        std::thread t3 = std::thread(std::mem_fn(&Foo::third), this, &Foo::printThird);

        t1.join();
        t2.join();
        t3.join();
    }
};

#endif