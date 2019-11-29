#ifndef _TWELVE_HPP_
#define _TWELVE_HPP_

#include "Solution.h"

/* #1114
Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
    public void second() { print("second"); }
      public void third() { print("third"); }
      }
      The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().
      https://leetcode-cn.com/problems/print-in-order
      */
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

/* #1143
Given two strings text1 and text2, return the length of their longest common subsequence.
A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not).A common subsequence of two strings is a subsequence that is common to both strings.
If there is no common subsequence, return 0.
https ://leetcode-cn.com/problems/longest-common-subsequence
*/
class LongestCommonSubsequence : public Solution
{
public:
    int longestCommonSubsequence(string text1, string text2) {
        auto len1 = (int)text1.size();
        auto len2 = (int)text2.size();
        vector<vector<int>> buff(len1 + 1, vector<int>(len2 + 1, 0));

        for (int k = 2; k <= len1 + len2; k++)
        {
            for (int i = max(1, k - len2); i <= min(len1, k - 1); i++)
            {
                auto j = k - i;
                if (text1[i - 1] == text2[j - 1])
                {
                    buff[i][j] = buff[i - 1][j - 1] + 1;
                }
                else
                {
                    buff[i][j] = max(buff[i - 1][j], buff[i][j - 1]);
                }
            }
        }

        return buff[len1][len2];
    }

    virtual void Run()
    {
        string text1 = "abcde";
        string text2 = "acd";
        cout << longestCommonSubsequence(text1, text2) << endl;
    }
};

#endif