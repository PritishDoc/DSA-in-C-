/*

 Sentence Similarity III

Hint
You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

 

Example 1:

Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

Example 2:

Input: sentence1 = "of", sentence2 = "A lot of words"

Output: false

Explanation:

No single sentence can be inserted inside one of the sentences to make it equal to the other.

Example 3:

Input: sentence1 = "Eating right now", sentence2 = "Eating"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.

 

Constraints:

1 <= sentence1.length, sentence2.length <= 100
sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
The words in sentence1 and sentence2 are separated by a single space.

*/
class Solution {
public:
    // Helper function to split the sentence into words
    vector<string> splitSentence(const string& sentence) {
        vector<string> words;
        string word;
        istringstream iss(sentence);
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split the sentences into words
        vector<string> words1 = splitSentence(sentence1);
        vector<string> words2 = splitSentence(sentence2);
        
        int n1 = words1.size();
        int n2 = words2.size();
        
        // Ensure that sentence1 is the longer one
        if (n1 < n2) {
            swap(words1, words2);
            swap(n1, n2);
        }
        
        // Try to match as many words as possible from the start (prefix)
        int prefixMatch = 0;
        while (prefixMatch < n2 && words1[prefixMatch] == words2[prefixMatch]) {
            prefixMatch++;
        }
        
        // Try to match as many words as possible from the end (suffix)
        int suffixMatch = 0;
        while (suffixMatch < n2 && words1[n1 - 1 - suffixMatch] == words2[n2 - 1 - suffixMatch]) {
            suffixMatch++;
        }
        
        // Check if the combined length of prefix and suffix matches the shorter sentence
        return (prefixMatch + suffixMatch >= n2);
    }
};