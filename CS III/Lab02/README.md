# Word Count

## Lab Assignment

Implement a program that reads in a text file, counts how many times each word occurs in the file and outputs the words (and counts) in the increasing order of occurrence, i.e. the counts need to be output in sorted order: rare words first. If the two words have the same number of occurences, the words should be sorted in alphabetical order.

_Word_ is any sequence of alphanumeric characters separateed by whitespace or punctuation marks. Whitespace and punctuation marks are to be discarded. That is, the punctuation marks should not be counted either as a part of the word or as a separate word. You are free to make your program case sensitive (Hello and hello are counted as separate words) or case insensitive. File name is supplied on command line. You are to use the following classes. class WordOccurrence {
public:
    WordOccurrence(const string& word="", int num=0);
    bool matchWord(const string &); // returns true if word matches stored
    void increment(); // increments number of occurrences
    string getWord() const; 
    int getNum() const;

private:
    string word_;
    int num_;
};

class WordList{
public:
    // add copy constructor, destructor, overloaded assignment

    // implement comparison as friend
    friend bool equal(const WordList&, const WordList&);

    void addWord(const string &);
    void print();

    // Only use for testing purposes
    WordOccurrence * getWords() const {return wordArray_;};
    int getSize() const {return size_;};
private:
    WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    int size_;
};

 Using vectors is not allowed. You may use standard sorting algorithms or implement insertion or selection sort form scratch. For the second class (WordList), implement a copy constructor (implementing deep copy), destructor and an overloaded assignment (either classical or copy-and-swap). Make sure your class works correctly with the [following code](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/Lab2/files.html). For your constructors, use member initialization lists where possible, use default values for function parameters where appropriate. Enhance class interface if necessary. 
**Milestone**. Code that inputs a file and prints a list of words (possibly repeating).

**Hint:** you can use ctype functions to check if a character is alphanumeric. [Here](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/Lab2/ctypedemo.cpp) is an example use.
