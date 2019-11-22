#pragma once

#include "Solution.h"
#include "Design.hpp"
#include "DP_Algorithm.hpp"
#include "DP_Stock.hpp"
#include "LinkedList.hpp"
#include "MultiThread.hpp"
#include "NumSum.hpp"
#include "NumTheory.hpp"
#include "Others.hpp"
#include "Strings.hpp"
#include "Tree.hpp"

#define test_solution(SolutionClass) \
    SolutionClass inst; \
    inst.Run();

// Design.hpp
#define TEST_MyCircularQueue            test_solution(MyCircularQueue)

// DP_Algorithm.hpp
#define TEST_LongestPalindrome          test_solution(LongestPalindrome)
#define TEST_MaxSubArray                test_solution(MaxSubArray)
#define TEST_CoinChange                 test_solution(CoinChange)
#define TEST_MinCostTickets             test_solution(MinCostTickets)
#define TEST_OddEvenJumps               test_solution(OddEvenJumps)
#define TEST_LongestCommonSubsequence   test_solution(LongestCommonSubsequence)

// DP_Stock.hpp
#define TEST_MaxProfit              test_solution(MaxProfit)
#define TEST_MaxProfitII            test_solution(MaxProfitII)
#define TEST_MaxProfitIII           test_solution(MaxProfitIII)
#define TEST_MaxProfitIV            test_solution(MaxProfitIV)

// LinkedList.hpp
#define TEST_AddTwoNumbers          test_solution(AddTwoNumbers)
#define TEST_CopyRandomList         test_solution(CopyRandomList)

// MultiThread.hpp
#define TEST_Foo                    test_solution(Foo)

// NumSum.hpp
#define TEST_TwoSum                 test_solution(TwoSum)
#define TEST_ThreeSum               test_solution(ThreeSum)
#define TEST_FourSum                test_solution(FourSum)
#define TEST_TwoSumII               test_solution(TwoSumII)
#define TEST_TwoSumIV               test_solution(TwoSumIV)
#define TEST_SubarraySum            test_solution(SubarraySum)
#define TEST_ThreeSumClosest        test_solution(ThreeSumClosest)

// NumTheory.hpp
#define TEST_IsUgly                 test_solution(IsUgly)
#define TEST_IsPerfectSquare        test_solution(IsPerfectSquare)
#define TEST_MySqrt                 test_solution(MySqrt)
#define TEST_BaseNeg2               test_solution(BaseNeg2)

// Others.hpp
#define TEST_FindLengthOfLCIS       test_solution(FindLengthOfLCIS)
#define TEST_MinEatingSpeed         test_solution(MinEatingSpeed)
#define TEST_CarPooling             test_solution(CarPooling)

// Strings.hpp
#define TEST_FindAnagrams           test_solution(FindAnagrams)
#define TEST_ComplexNumberMultiply  test_solution(ComplexNumberMultiply)

// Tree.hpp
#define TEST_PreorderTraversal      test_solution(PreorderTraversal)
#define TEST_InorderTraversal       test_solution(InorderTraversal)
#define TEST_PostorderTraversal     test_solution(PostorderTraversal)
#define TEST_IsValidBST             test_solution(IsValidBST)
