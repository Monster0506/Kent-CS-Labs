#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::stack;
using std::string;
using std::vector;
using std::endl;

class Document {
   public:
    void insert(int line, const string& text) {
        lines_.insert(lines_.begin() + (line - 1), text);
    }
    void erase(int line) {lines_.erase(lines_.begin() + (line - 1)); }
    const string& getLine(int line) const { return lines_[line - 1]; }
    int size() const { return (int)lines_.size(); }
    void print() const {
        for (int i = 0; i < (int)lines_.size(); ++i)
            cout << i + 1 << ". " << lines_[i] <<endl;
    }
    const vector<string>& getLines() const { return lines_; }
    void setLines(const vector<string>& lines) { lines_ = lines; }

   private:
    vector<string> lines_;
};

class DocumentMemento {
   public:
    explicit DocumentMemento(const vector<string>& lines) : lines_(lines) {}
    const vector<string>& getLines() const { return lines_; }

   private:
    vector<string> lines_;
};

class Command {
   public:
    virtual void execute(Document&) = 0;
    virtual void undo(Document&) = 0;
    virtual Command* clone() const = 0;
    virtual string show() const = 0;
    virtual ~Command() {}
};

class InsertCommand : public Command {
   public:
    InsertCommand(int line, string text)
        : line_(line), text_(std::move(text)) {}

    void execute(Document& doc) override { doc.insert(line_, text_); }
    void undo(Document& doc) override { doc.erase(line_); }

    Command* clone() const override { return new InsertCommand(line_, text_); }
    string show() const override {
        return "insert \"" + text_ + "\" at line " + std::to_string(line_);
    }

   private:
    int line_;
    string text_;
};

class EraseCommand : public Command {
   public:
    explicit EraseCommand(int line) : line_(line) {}

    void execute(Document& doc) override {
        saved_ = doc.getLine(line_);
        doc.erase(line_);
    }
    void undo(Document& doc) override { doc.insert(line_, saved_); }

    Command* clone() const override { return new EraseCommand(line_); }

    string show() const override {
        return "erase line " + std::to_string(line_) + " with content " + saved_;
    }

   private:
    int line_;
    string saved_;
};

void clearHistory(vector<Command*>& h) {
    for (auto* c : h) delete c;
    h.clear();
}

void clearStack(stack<Command*>& s) {
    while (!s.empty()) s.pop();
}

int main() {
    Document doc;
    doc.insert(1, "Line one");
    doc.insert(2, "Line two");
    doc.insert(3, "Line three");

    vector<Command*> history;
    stack<Command*> undoStack;
    DocumentMemento* checkpoint = nullptr;

    for (char opt;opt != 'q';) {
        cout << endl;
        doc.print();
        cout << "\nEnter option (i)nsert line (e)rase line (u)ndo last command "
                "(c)heckpoint roll(b)ack\n(h)istory (r)edo command: ";
        cin >> opt;

        if (opt == 'i') {
            int line;
            string text;
            cout << "Line number: ";
            cin >> line;
            cout << "Text: ";
            cin.ignore();
            getline(cin, text);
            auto* cmd = new InsertCommand(line, text);
            cmd->execute(doc);
            history.push_back(cmd);
            undoStack.push(cmd);

        } else if (opt == 'e') {
            int line;
            cout << "Line number: ";
            cin >> line;
            auto* cmd = new EraseCommand(line);
            cmd->execute(doc);
            history.push_back(cmd);
            undoStack.push(cmd);

        } else if (opt == 'u') {
            if (undoStack.empty()) {
                cout << "Nothing to undo."<<endl;
            } else {
                Command* cmd = undoStack.top();
                undoStack.pop();
                cmd->undo(doc);
                history.pop_back();
                delete cmd;
            }

        } else if (opt == 'c') {
            delete checkpoint;
            checkpoint = new DocumentMemento(doc.getLines());
            clearStack(undoStack);
            clearHistory(history);
            cout << "Checkpoint saved."<<endl;

        } else if (opt == 'b') {
            if (!checkpoint) {
                cout << "No checkpoint set."<<endl;
            } else {
                doc.setLines(checkpoint->getLines());
                clearStack(undoStack);
                clearHistory(history);
                cout << "Rolled back to checkpoint."<<endl;
            }

        } else if (opt == 'h') {
            if (history.empty()) {
                cout << "(no history since last checkpoint)"<<endl;
            } else {
                for (int i = 0; i < (int)history.size(); ++i)
                    cout << i + 1 << ". " << history[i]->show() << endl;
            }

        } else if (opt == 'r') {
            if (history.empty()) {
                cout << "(history is empty)"<<endl;
            } else {
                int num;
                cout << "Redo command #: ";
                cin >> num;
                if (num < 1 || num > (int)history.size()) {
                    cout << "Invalid number."<<endl;
                } else {
                    Command* cloned = history[num - 1]->clone();
                    cloned->execute(doc);
                    history.push_back(cloned);
                    undoStack.push(cloned);
                }
            }
        }
    }
}
