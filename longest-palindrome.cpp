#include <iostream>
#include <map>

using namespace std;

int longestPalindrome(string s);
void printMap(map<char, int> &letters);

int main(int argc, char const *argv[]) {
  string input1 = "abccccdd";
  string input2 = "a";
  string input3 = "ccccc";

  int longestPal1 = longestPalindrome(input1);
  int longestPal2 = longestPalindrome(input2);
  int longestPal3 = longestPalindrome(input3);

  cout << "Longest Pal 1: " << longestPal1 << endl;
  cout << "Longest Pal 2: " << longestPal2 << endl;
  cout << "Longest Pal 3: " << longestPal3 << endl;
  return 0;
}

int longestPalindrome(string s) {
  map<char, int> letters;
  int longestPal = 0;

  if (s.length() == 0) return 0;
  if (s.length() == 1) return 1;

  // count the number of occurences of each character
  // letters['a'] = 5
  // letters['c'] = 3
  // letters['d'] = 2
  for (char c : s) {
    if (letters.count(c))
      letters[c]++;
    else
      letters.insert(std::pair<char, int>(c, 1));
  }

  // if the string only contains one kind of letter
  // eg. aaaa, bbbbbbb, cc or dddd
  if (letters.size() == 1) {
    return s.size();
  }

  // Iterate letters map to find 2 things:
  // if a letter has even number of occurances, count them all
  // if a letter has odd number of occurances, count them all and subtract 1
  // if even a single letter is odd, add 1 to the total count. This should only be done once
  bool foundOdd = false;
  for (map<char, int>::iterator it = letters.begin(); it != letters.end(); it++) {
    longestPal += it->second;
    if ((it->second % 2) == 1) {
      longestPal -= 1;
      foundOdd = true;
    }
  }
  if (foundOdd)
    longestPal++;
  return longestPal;
}

void printMap(map<char, int> &letters) {
  for (auto it = letters.cbegin(); it != letters.cend(); ++it) {
    cout << it->first << ": " << it->second << "\n";
  }
}