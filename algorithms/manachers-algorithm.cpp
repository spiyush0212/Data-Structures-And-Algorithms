
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Manacher's Algorithm: Longest Palindromic Substring
// Time: O(N) | Auxiliary Space: O(N)
//
// USE CASES:
// 1. Find the longest palindromic substring in linear time.
// 2. Compute palindrome radii for efficient palindrome-related queries.
//
// ALGORITHM:
// 1. Every palindrome has a center: a character (odd length) or a gap between two characters (even length).
// 2. Compute palindrome radii separately for odd and even centers.
// 3. Maintain [l, r], the rightmost palindrome found so far.
// 4. If i <= r, reuse the mirrored center's radius, limited to the current right boundary.
// 5. Expand while characters match, then update [l, r] if the palindrome extends farther right.
// 6. Track the maximum palindrome length and its starting index.
//
// d1[i] = Odd palindrome radius, including the center. Length = 2 * d1[i] - 1
// d2[i] = Even palindrome radius, centered between i-1 and i. Length = 2 * d2[i]
//
// Odd palindrome start  = i - d1[i] + 1
// Even palindrome start = i - d2[i]
//
// WHY O(N) Time?
// The right boundary r only moves forward, so total expansions across all centers are O(N).

vector<int> manacherOdd(const string& s) {
    int n = s.size();
    vector<int> d1(n);
    int l = 0, r = -1;

    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);

        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }

        d1[i] = k;

        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    return d1;
}

vector<int> manacherEven(const string& s) {
    int n = s.size();
    vector<int> d2(n);
    int l = 0, r = -1;

    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }

        d2[i] = k;

        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }

    return d2;
}

string longestPalindrome(const string& s) {
    if (s.empty()) 
        return "";

    vector<int> d1 = manacherOdd(s);
    vector<int> d2 = manacherEven(s);

    int start = 0;
    int maxLenPalindrome = 0;

    for (int i = 0; i < s.size(); i++) {
        int oddLenPalindrome = (2 * d1[i]) - 1;

        if (oddLenPalindrome > maxLenPalindrome) {
            maxLenPalindrome = oddLenPalindrome;
            start = i - d1[i] + 1;
        }

        int evenLenPalindrome = 2 * d2[i];

        if (evenLenPalindrome > maxLenPalindrome) {
            maxLenPalindrome = evenLenPalindrome;
            start = i - d2[i];
        }
    }

    return s.substr(start, maxLenPalindrome);
}