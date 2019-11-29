#pragma once

#include "Solution.h"
#include "One.hpp"
#include "Two.hpp"
#include "Three.hpp"
#include "Four.hpp"
#include "Five.hpp"
#include "Six.hpp"
#include "Seven.hpp"
#include "Eight.hpp"
#include "Nine.hpp"
#include "Ten.hpp"
#include "Eleven.hpp"
#include "Twelve.hpp"
#include "Others.hpp"

#define test_solution(SolutionClass) \
    SolutionClass inst; \
    inst.Run();

// One.hpp
#define TEST_TwoSum                     test_solution(TwoSum) // #1
#define TEST_AddTwoNumbers              test_solution(AddTwoNumbers) // #2
#define TEST_LongestPalindrome          test_solution(LongestPalindrome) // #5
#define TEST_ThreeSum                   test_solution(ThreeSum) // #15
#define TEST_ThreeSumClosest            test_solution(ThreeSumClosest) // #16
#define TEST_FourSum                    test_solution(FourSum) // #18
#define TEST_MaxSubArray                test_solution(MaxSubArray) // #53
#define TEST_MySqrt                     test_solution(MySqrt) // #69
#define TEST_InorderTraversal           test_solution(InorderTraversal) // #94
#define TEST_IsValidBST                 test_solution(IsValidBST) // #98

// Two.hpp
#define TEST_MaxProfit                  test_solution(MaxProfit) // #121
#define TEST_MaxProfitII                test_solution(MaxProfitII) // #122
#define TEST_MaxProfitIII               test_solution(MaxProfitIII) // #123
#define TEST_CopyRandomList             test_solution(CopyRandomList) // #138
#define TEST_PreorderTraversal          test_solution(PreorderTraversal) // #144
#define TEST_PostorderTraversal         test_solution(PostorderTraversal) // #145
#define TEST_TwoSumII                   test_solution(TwoSumII) // #167

// Three.hpp
#define TEST_IsUgly                     test_solution(IsUgly) // #288

// Four.hpp
#define TEST_MaxProfitIV                test_solution(MaxProfitIV) // #309
#define TEST_CoinChange                 test_solution(CoinChange) // #322
#define TEST_Intersection               test_solution(Intersection) // #349
#define TEST_IsPerfectSquare            test_solution(IsPerfectSquare) // #367
#define TEST_MaxRotateFunction          test_solution(MaxRotateFunction) // #396

// Five.hpp
#define TEST_FindAnagrams               test_solution(FindAnagrams) // #438
#define TEST_FindContentChildren        test_solution(FindContentChildren) // #455

// Six.hpp
#define TEST_ComplexNumberMultiply      test_solution(ComplexNumberMultiply) // #537
#define TEST_SubarraySum                test_solution(SubarraySum) // #560

// Seven.hpp
#define TEST_MyCircularQueue            test_solution(MyCircularQueue) // #622
#define TEST_TwoSumIV                   test_solution(TwoSumIV) // #653
#define TEST_FindLengthOfLCIS           test_solution(FindLengthOfLCIS) // #674

// Eight.hpp
#define TEST_FindLength                 test_solution(FindLength) // #718

// Nine.hpp
#define TEST_MinEatingSpeed             test_solution(MinEatingSpeed) // #875

// Ten.hpp
#define TEST_OddEvenJumps               test_solution(OddEvenJumps) // #975
#define TEST_MinCostTickets             test_solution(MinCostTickets) // #983

// Elven.hpp
#define TEST_BaseNeg2                   test_solution(BaseNeg2) // #1017
#define TEST_CarPooling                 test_solution(CarPooling) // #1094

// Twelve.hpp
#define TEST_Foo                        test_solution(Foo) // #1114
#define TEST_LongestCommonSubsequence   test_solution(LongestCommonSubsequence) // #1143

// Others.hpp
#define TEST_Fraction                   test_solution(Fraction) // LCP2
