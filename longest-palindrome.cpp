#include <iostream>
#include <map>

using namespace std;

int longestPalindrome(string s);
void printMap(map<char, int> &letters);

int main(int argc, char const *argv[]) {
  string input1 = "abccccdd";
  string input2 = "a";

  int longestPal1 = longestPalindrome(input1);
  int longestPal2 = longestPalindrome(input2);

  cout << "Longest Pal 1: " << longestPal1 << endl;
  cout << "Longest Pal 2: " << longestPal2 << endl;
  return 0;
}

int longestPalindrome(string s) {
  map<char, int> letters;

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

  // print map
  printMap(letters);
  cout << "========\n";

  return 0;
}

void printMap(map<char, int> &letters) {
  for (auto it = letters.cbegin(); it != letters.cend(); ++it) {
    cout << it->first << ": " << it->second << "\n";
  }
}