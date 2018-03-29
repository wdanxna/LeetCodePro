#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include "common.h"

#include "zigzagOrderLevel.h"
#include "longestConsecutive.h"
#include "longestCommonPrefix.h"
#include "countandsay.h"
#include "towSum.h"
#include "searchInsert.h"
#include "climbstairs.h"
#include "isBalanced.h"
#include "isValidSudoku.h"
#include "sudokuSolver.h"
#include "wordBreak.h"
#include "atoi.h"
#include "preorderTraversal.h"
#include "flattenBinaryTree.h"
#include "isPalindrome.h"
#include "merge.h"
#include "deleteDuplicates.h"
#include "pascal.h"
#include "pascale2.h"
#include "pathSum.h"
#include "MinStack.h"
#include "pathSum2.h"
#include "minDepth.h"
#include "symmetricTree.h"
#include "sameTree.h"
#include "plusOne.h"
#include "validParentheses.h"
#include "validBST.h"
#include "removeElement.h"
#include "palindromeNumber.h"
#include "LengthOfLongestSubstring.h"
#include "addTwoNumbers.h"
#include "longestPalindrome.h"
#include "containerWithMostWater.h"
#include "searchForARange.h"
#include "ThreeSum.h"
#include "threeSumClosest.h"
#include "letterCombinations.h"
#include "removeDuplicates.h"
#include "HouseRobber.h"
#include "maximumSum.h"
#include "strstr.h"
#include "findMedianSortedArrays.h"
#include "longestValidParentheses.h"
#include "maxSubArray.h"
#include "minDistance.h"
#include "permute.h"
#include "permuteUnique.h"
#include "wordLadder.h"
#include "findLadders.h"
#include "SurroundedRegions.h"
#include "postorderTraversal.h"
#include "maximumGap.h"
#include "oddEven.h"
#include "selfProduct.h"
#include "bubbleSort.h"
#include "quickSort.h"
#include "HappyNumber.h"
#include "removeElements.hpp"
#include "addDigits.hpp"
#include "IntegerReplacement.hpp"
#include "getSum.hpp"
#include "findMaxAverage.hpp"
#include "AverageOfLevels.hpp"
#include "JudgeSquareSum.hpp"
#include "searchforarange.hpp"
#include "regularExpressionMatch.hpp"
#include "solveEquation.hpp"

using namespace std;

/* Reverse Words */
class ReverseWords_Solution {
public:
    void reverseWords(string &s) {
        stack<string> st;
        string t = "";
        int j = 0;
        s += " ";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') { continue; }
            else {
                j = i;
                t="";
                while (j < s.length() && s[j] != ' ') {
                    t += s[j];
                    j++;
                }
                i = j-1;
                st.push(t);
            }
        }
        
        
        string result;
        if (!st.empty()){
            result = st.top();
            st.pop();
        }
        while (!st.empty()) {
            result += " " + st.top();
            st.pop();
        }
        s = result;
    }
};

/* Reverse Integer */
class ReverseInteger_Solution {
public:
    int reverse(int x) {
        int sign = x > 0? 1 : -1;
        int t = x * sign;
        int g = 0;
        while (t > 0) {
            g = 10 * g + (t % 10);
            t /= 10;
        }
        return g * sign;
    }
};

/* Subsets */
class Subsets_Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int> &S) {
        vector<int> tmpres;
        sort(S.begin(), S.end());
        dfs(S, 0, tmpres);
        tmpres.clear();
        return res;
    }
    
    void dfs(vector<int> &S, int iend, vector<int> &tmpres) {
        if (iend >= S.size()) {
            //reach leave
            res.push_back(tmpres);
            return;
        }
        tmpres.push_back(S[iend]);
        dfs(S, iend+1, tmpres);
        tmpres.pop_back();
        dfs(S, iend+1, tmpres);
    }
};


/* Binary tree level order traversal*/
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode * right;
//    TreeNode(int x): val(x), left(NULL), right(NULL) {}
//};
class LevelOrder_Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> qu1;
        queue<TreeNode*> qu2;
        vector<queue<TreeNode*>*> qs;
        qs.push_back(&qu1);
        qs.push_back(&qu2);
        
        int qid = 0;
        queue<TreeNode*>* curq = qs[qid];
        curq->push(root);
        
        vector<int> tmp;
        while (!curq->empty()) {
            TreeNode* node = curq->front();
            queue<TreeNode*> *another_q = qs[(qid+1)%2];
            if (node->left) another_q->push(node->left);
            if (node->right) another_q->push(node->right);
            curq->pop();
            tmp.push_back(node->val);
            if (curq->empty()) {
                res.push_back(tmp);
                tmp.clear();
                qid = (qid+1)%2;
                curq = qs[qid];
            }
        }
        return res;
    }
};


/* create BST from singly linked list */

class CreateBST {
public:
    
    int listLength(ListNode* list) {
        ListNode* cur = list;
        int len = 0;
        while (cur != NULL) {
            len++;
            cur = cur->next;
        }
        return len;
    }
    
    ListNode* findMid(ListNode* node, int len) {
        int mid = len / 2;
        for (int i = 0; i < mid; i++) {
            node = node->next;
        }
        return node;
    }
    
    TreeNode* bstIter(ListNode* node, int len) {
        if (len <= 0) {
            return NULL;
        }
        if (len == 1) {
            return new TreeNode(node->val);
        }
        ListNode* mid = findMid(node, len);
        TreeNode* root = new TreeNode(mid->val);
        root->left = bstIter(node, len/2);
        root->right = bstIter(mid->next, len-(len/2)-1);
        return root;
    }
    
    TreeNode* createBST(ListNode* list) {
        int len = listLength(list);
        TreeNode* t = bstIter(list, len);
        return t;
    }
};

class MaxDepth_Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int right_h = maxDepth(root->right);
        int left_h = maxDepth(root->left);
        int max = right_h > left_h ? right_h : left_h;
        return max + 1;
    }
};

class removeNth_Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) return NULL;
        queue<ListNode*> q;
        ListNode *cur = head;
        while (cur != NULL) {
            if (q.size() == n+1) {
                q.pop();
            }
            q.push(cur);
            cur = cur->next;
        }
        if (q.size() < n+1){
            ListNode* res = head->next;
            free(head);
            return res;
        }
        ListNode* prev = q.front(); q.pop();
        ListNode* tar = q.front();
        prev->next = tar->next;
        free(tar);
        return head;
    }
};


class Divide_Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return numeric_limits<int>::infinity();
        }
        unsigned int mask = 0x1;
        unsigned s_mask = 0x1 << 31;
        unsigned sign = s_mask & dividend;
        unsigned unsigned_dividend = dividend;
        
        unsigned dsign = s_mask & divisor;
        
        unsigned unsigned_divisor = divisor;
        int result = 0;
        int n = 0;
        
        while (unsigned_divisor != 0) {
            if ((unsigned_divisor & mask) == 1) {
                result += dividend >> n;
            }
            n++;
            unsigned_divisor = unsigned_divisor >> 1;
        }
//        if ((sign ^ dsign)) {
//            result = -result;
//        }
        return result;
    }
};

void printLinkedList(ListNode* list) {
    while (list != NULL) {
        cout << list->val << "->";
        list = list->next;
    }
    cout << endl;
}

//Evaluate Reverse Polish Notation
// ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
// ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
class EvalRPN_Solution {
public:
    int is_num(string n) {
        return atoi(n.c_str());
    }
    int eval(vector<string> &tockens) {
        stack<int> num_stack;
        int pt = 0;
        while (pt < tockens.size()) {
            string car = tockens[pt];

            if (car == "+") {
                try {
                    int op2 = num_stack.top(); num_stack.pop();
                    int op1 = num_stack.top(); num_stack.pop();
                    num_stack.push(op1+op2);
                } catch (exception e) {
                    cout << " stack underflow when + operation.";
                }
            }
            else if (car == "-") {
                try {
                    int op2 = num_stack.top(); num_stack.pop();
                    int op1 = num_stack.top(); num_stack.pop();
                    num_stack.push(op1-op2);
                } catch (exception e) {
                    cout << " stack underflow when - operation.";
                }
            }
            else if (car == "*") {
                try {
                    int op2 = num_stack.top(); num_stack.pop();
                    int op1 = num_stack.top(); num_stack.pop();
                    num_stack.push(op1*op2);
                } catch (exception e) {
                    cout << " stack underflow when * operation.";
                }
            }
            else if (car == "/") {
                try {
                    int op2 = num_stack.top(); num_stack.pop();
                    int op1 = num_stack.top(); num_stack.pop();
                    num_stack.push(op1/op2);
                } catch (exception e) {
                    cout << " stack underflow when / operation.";
                }
            }
            else {
                num_stack.push(is_num(car));
            }
            pt++;
        }
        return num_stack.top();
    }
    int evalRPN(vector<string> &tokens) {
        int re = eval(tokens);
        return re;
    }
};

//void Swap(int &a, int &b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}
//void permutations(vector<int> &num, int k, unsigned long m, vector<vector<int>> &res) {
//    if (k == m) {
//        res.push_back(num);
//        for (int i=0; i<num.size(); i++) {
//            cout << num[i];
//        }
//        cout << endl;
//    }
//    else {
//        for (int i = k; i <= m; i++) {
//            Swap(num[k], num[i]);
//            permutations(num, k+1, m, res);
//            Swap(num[k], num[i]);
//        }
//    }
//}
//
//vector<vector<int>> permute(vector<int> &num) {
//    vector<vector<int>> result;
//    permutations(num, 0, num.size()-1, result);
//    return result;
//}

ListNode *swapPairs(ListNode *head) {
    if (!head) return head;
    if (!head->next) return head;
    ListNode* newhead = head->next;
    ListNode *tmp = NULL;
    ListNode *fakeNode = new ListNode(-1);
    fakeNode->next = head;
    ListNode *pt = fakeNode;
    while (pt->next && pt->next->next) {
        ListNode *first = pt->next;
        ListNode *second = first->next;
        tmp = second->next;
        second->next = first;
        first->next = tmp;
        pt->next = second;
        pt = first;
    }
    return newhead;
}

int maxSum(int *num, int len) {
    int sum,max = 0;
    for (int i=0; i < len; i++) {
        sum = 0;
        for (int j=i; j < len; j++) {
            sum += num[j];
            if (sum > max) max=sum;
        }
    }
    return max;
}

int maxSum2(int *num, int len) {
    int sum = 0;
    int max = 0;
    for (int i=0; i<len; i++) {
        for (int j=i; j<len; j++) {
            sum = 0;
            for (int k=i; k<j; k++) {
                sum += num[k];
                if (sum > max) max = sum;
            }
        }
    }
    return max;
}

int maxSum3(int *num, int len) {
    int max = 0;
    int sum = 0;
    for (int i=0; i<len; i++) {
        sum += num[i];
        if (sum < 0) sum = num[i] < 0? 0 : num[i];
        if (sum > max) max = sum;
    }
    return max;
}

vector<int> findSubstring(string s, vector<string> &l) {
    map<string, int> words;
    map<string, int> curStr;
    int N = l.size();
    int M = l[0].size();
    for (int i=0; i<N; i++) {
        ++words[l[i]];
    }
    vector<int> result;
    if (N <= 0 || s.size() < M*N) return result;
    
    for (int i=0; i< s.size() - M*N; i++) {
        curStr.clear();
        int j = 0;
        for (j=0; j < N; j++) {
            string w = s.substr(i+j*M, M);
            if (words.find(w) == words.end())
                break;
            ++curStr[w];
            if (curStr[w] > words[w])
                break;
        }
        if (j==N) result.push_back(i);
    }
    return result;
}

void wb(string s, int left, int right, unordered_set<string> &dict, vector<string> t,  vector<string> &re) {
    if (s.length() <= 0)
        return;
    if (left >= right) {
        string k;
        for (int i=0; i<t.size(); i++) {
            if (i != t.size()-1) {
                k = k + t[i] + " ";
            }
            else
                k+=t[i];
        }
        re.push_back(k);
        return;
    }
    //find matches
    for (const auto& elem: dict) {
        int len = (int)((string)elem).size();
        if (left+len > s.length()) continue;
        string sub = s.substr(left, len);
        if (elem.compare(sub) == 0) {
            t.push_back(sub);
            wb(s, left+len, right, dict, t, re);
            if (t.size())
                t.pop_back();
        }
    }
}

vector<string> wordBreakII(string s,  unordered_set<string> &dict) {
    vector<string> ret;
    vector<string> t;
    wb(s, 0, (int)s.size()-1, dict,t, ret);
    return ret;
}



//2014-2-19 update
void word(vector<string> &rs, string &tmp, string &s, vector<vector<int> > &tbl,
          unordered_set<string> &dict, int start=0)
{
    if (start == s.length())
    {
        rs.push_back(tmp);
        return;
    }
    for (int i = 0; i < tbl[start].size(); i++)
    {
        string t = s.substr(start, tbl[start][i]-start+1);
        if (!tmp.empty()) tmp.push_back(' ');
        tmp.append(t);
        word(rs, tmp, s, tbl, dict, tbl[start][i]+1);
        while (!tmp.empty() && tmp.back() != ' ') tmp.pop_back();//tmp.empty()
        if (!tmp.empty()) tmp.pop_back();
    }
}

vector<vector<int> > genTable(string &s, unordered_set<string> &dict)
{
    int n = s.length();
    vector<vector<int> > tbl(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if(dict.count(s.substr(i))) tbl[i].push_back(n-1);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (!tbl[i+1].empty())//if we can break i->n
        {
            for (int j = i, d = 1; j >= 0 ; j--, d++)
            {
                if (dict.count(s.substr(j, d))) tbl[j].push_back(i);
            }
        }
    }
    return tbl;
}

vector<string> wordBreak2(string s, unordered_set<string> &dict)
{
    vector<string> rs;
    string tmp;
    vector<vector<int> > tbl = genTable(s, dict);
    word(rs, tmp, s, tbl, dict);
    return rs;
}

int lengthOfLastWord(const char *s) {
    int i=0, j=0;
    while (*s != '\0') {
        if (*s == ' ') {
            if (i != 0){
                j = i;
                i = 0;
            }
        }
        else {
            i++;
        }
        s++;
    }
    if (i == 0 ) return j;
    return i;
}


int main(int argc, const char * argv[])
{
//    longestConsecutiveTest();
//    longestCommonPrefixTest();
//    countAndSayTest();
//    twoSumTest();
//    searchInsertTest();
//    climbstairsTest();
//    isBalancedTest();
//    isValidSudokuTest();
//    sudokuSolverTest();
//    wordBreakTest();
//    atoiTest();
//    preorderTraversalTest();
//    flattenTest();
//    isPalindromeTest();
//    mergeTest();
//    deleteDuplicatesTest();
//    pascaleTest();
//    pascale2Test();
//    pathSumTest();
//    minStackTest();
//    pathSum2Test();
//    minDepthTest();
//    symmetricTreeTest();
//    sameTreeTest();
//    plusOneTest();
//    validParenthesesTest();
//    validBSTTest();
//    removeElementTest();
//    palindromNumberTest();
//    lengthOfLongestSubstringTest();
//    addTwoNumbersTest();
//    longestPalindormTest();
//    containerWithMostWaterTest();
//    searchForARangeTest();
//    ThreeSumTest();
//    threeSumClosestTest();
//    letterCombinationsTest();
//    removeDuplicatesTest();
//    maximumSumTest();
//    strstrTest();
//    findMedianOfTwoSortedArraysTest();
//    longestValidParenthesesTest();
//    maxSubArrayTest();
//    minDistanceTest();
//    permuteTest();
//    permutationUniqueTest();
//    longestPalindormTest();
//    houseRobberTest();
//    ladderLengthTest();
//    findLaddersTest();
//    surroundedRegionsTest();
//    postorderTraversalTest();
//    maximumGapTest();
//    oddEvenTest();
//    selfProduct();
//    bubbleSortTest();
//    quickSortTest();
//    HappyNumberTest();
//    removeElementsTest();
//    addDigitsTest();
//    integerReplacementTest();
//    getSumTest();
    
//    FindMaxAverage fa;
//    fa.testFindMaxAverage();
    
//    AverageOfLevels av;
//    av.testAverageOfLevels();
    
//    JudgeSquareSum js;
//    js.testJudgeSquareSum();
    
//    minStackTest();
//    search_for_a_range_test();
//    regularMatchingTest();
    solveEquationTest();
}
