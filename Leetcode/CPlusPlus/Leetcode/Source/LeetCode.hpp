#pragma once

#include "Solution.h"
#include "Coin.hpp"
#include "LinkedList.hpp"
#include "NumSum.hpp"
#include "Tree.hpp"

#define test_solution(SolutionClass) \
    SolutionClass code; \
    code.Run();

// Coin.hpp
#define TEST_CoinChange             test_solution(CoinChange)

// LinkedList.hpp
#define TEST_AddTwoNumbers          test_solution(AddTwoNumbers)

// NumSum.hpp
#define TEST_TwoSum                 test_solution(TwoSum)
#define TEST_ThreeSum               test_solution(ThreeSum)
#define TEST_FourSum                test_solution(FourSum)
#define TEST_TwoSumII               test_solution(TwoSumII)
#define TEST_TwoSumIV               test_solution(TwoSumIV)
#define TEST_SubarraySum            test_solution(SubarraySum)
#define TEST_ThreeSumClosest        test_solution(ThreeSumClosest)

// Tree.hpp
#define TEST_PreorderTraversal      test_solution(PreorderTraversal)
#define TEST_InorderTraversal       test_solution(InorderTraversal)
#define TEST_PostorderTraversal     test_solution(PostorderTraversal)
#define TEST_IsValidBST             test_solution(IsValidBST)
