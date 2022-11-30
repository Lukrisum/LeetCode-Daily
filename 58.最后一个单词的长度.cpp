/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;

        while (s[index] == ' ') {
            index--;
        }
        int wordLength = 0;
        while (index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }

        return wordLength;
    }
};
// @lc code=end

