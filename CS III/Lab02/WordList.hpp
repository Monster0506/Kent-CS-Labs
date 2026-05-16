#pragma once

#include <algorithm>
#include <iostream>
#include <string>

class WordOccurrence {
   public:
    WordOccurrence(const std::string &word = "", int num = 0)
        : word_(word), num_(num) {}
    bool matchWord(const std::string &w) { return word_ == w; }
    void increment() { ++num_; }
    std::string getWord() const { return word_; }
    int getNum() const { return num_; };

   private:
    std::string word_;
    int num_;
};


class WordList {
   private:
    // not really sure where else to put it or why it needs to be static, but I get an error demanding it otherwise.
    static bool sorter(const WordOccurrence &a, const WordOccurrence &b) {
        if (a.getNum() != b.getNum()) return a.getNum() < b.getNum();
        return a.getWord() < b.getWord();
    }

   public:
    WordList() : wordArray_(nullptr), size_(0) {};

    // add copy constructor, destructor, overloaded assignment
    WordList(const WordList &other) {
        size_ = other.size_;
        wordArray_ = new WordOccurrence[size_];
        for (int i = 0; i < size_; i++) {
            wordArray_[i] = other.wordArray_[i];
        }
    }
    ~WordList() { delete[] wordArray_; }

    WordList &operator=(WordList other) {
        int temp_size = other.size_;
        other.size_ = size_;
        size_ = temp_size;
        WordOccurrence *temp_wordArray = other.wordArray_;
        other.wordArray_ = wordArray_;
        wordArray_ = temp_wordArray;

        return *this;
    }

    // implement comparison as a friend
    friend bool equal(const WordList &lhs, const WordList &rhs) {
        if (lhs.size_ != rhs.size_) return false;
        for (int i = 0; i < lhs.size_; i++) {
            if (lhs.wordArray_[i].getWord() != rhs.wordArray_[i].getWord())
                return false;
            if (lhs.wordArray_[i].getNum() != rhs.wordArray_[i].getNum())
                return false;
        }
        return true;
    }

    void addWord(const std::string &w) {
        for (int i = 0; i < size_; i++) {
            if (wordArray_[i].matchWord(w)) {
                wordArray_[i].increment();
                return;
            }
        }
        WordOccurrence *newArray = new WordOccurrence[size_ + 1];
        for (int i = 0; i < size_; i++) {
            newArray[i] = wordArray_[i];
        }
        newArray[size_] = WordOccurrence(w, 1);
        delete[] wordArray_;
        wordArray_ = newArray;
        size_++;
    }
    void print() {
        std::sort(wordArray_, wordArray_ + size_, sorter);

        for (int i = 0; i < size_; i++) {
            std::cout << wordArray_[i].getWord() << " "
                      << wordArray_[i].getNum() << std::endl;
        }
    }

    // Only use for testing purposes
    WordOccurrence *getWords() const { return wordArray_; }
    int getSize() const { return size_; }

   private:
    WordOccurrence *wordArray_;
    int size_;
};
