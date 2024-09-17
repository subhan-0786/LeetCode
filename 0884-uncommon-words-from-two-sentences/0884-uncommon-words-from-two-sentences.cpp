class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
    string concatenated = s1 + " " + s2;
    vector<string> uncommonWords;
    int start = 0;
    
        
    for (int i = 0; i <= concatenated.size(); i++) {
        if (i == concatenated.size() || concatenated[i] == ' ') {
            
            string word = concatenated.substr(start, i - start);
            start = i + 1;  
            
            
            if (!word.empty() && wordFrequency(concatenated, word) == 1) {
                uncommonWords.push_back(word);  
            }
        }
    }
    
    return uncommonWords;
}

private:
    int wordFrequency(const string &concatenated, const string &word) {
    int frequency = 0;
    string currentWord = "";
    
    for (int i = 0; i <= concatenated.size(); i++) {
        if (i == concatenated.size() || concatenated[i] == ' ') {
            if (currentWord == word) {
                frequency++;
            }
            currentWord = "";  
        } else {
            currentWord += concatenated[i];
        }
    }
    
    return frequency;
}
};