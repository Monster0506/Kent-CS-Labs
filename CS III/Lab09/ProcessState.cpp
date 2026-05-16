// demonstrates state design pattern
// Mikhail Nesterenko
// 2/23/2014

#include <iostream>
#include <queue>
#include <string>
using std::cout;
using std::endl;
using std::queue;
using std::string;

class State;

// context
class Process {
   public:
    Process();

    void dispatch();
    void suspend();
    void unblock();
    void exit();
    void block();
    // part of implementation of state pattern
    void changeState(State* state) { state_ = state; }
    string report();

   private:
    static int nextId;
    int id_;
    State* state_;
};

int Process::nextId = 0;

// absract state
class State {
   public:
    virtual void dispatch(Process*) {}
    virtual void suspend(Process*) {}
    virtual void unblock(Process*) {}
    virtual void exit(Process*) {}
    virtual void block(Process*) {}

    virtual string report() = 0;
    void changeState(Process* c, State* s) { c->changeState(s); }
};

class Ready : public State {
   public:
    static State* instance() {
        static State* onlyInstance = new Ready;
        return onlyInstance;
    }
    void dispatch(Process*) override;
    string report() override { return "ready"; }

   private:
    // here and elsewhere should be stated private constructor/assignment
    // to correctly implement singleton, skipped to simplify code
};

class Blocked : public State {
   public:
    static State* instance() {
        static State* onlyInstance = new Blocked;
        return onlyInstance;
    }
    void unblock(Process*) override;
    string report() override { return "blocked"; }
};

class Running : public State {
   public:
    static State* instance() {
        static State* onlyInstance = new Running;
        return onlyInstance;
    }
    void block(Process*) override;
    void suspend(Process*) override;
    void exit(Process*) override;
    string report() override { return "running"; }
};

// state transitions member functions
// Ready
void Ready::dispatch(Process* c) { changeState(c, Running::instance()); }

void Running::block(Process* c) { changeState(c, Blocked::instance()); }
void Running::suspend(Process* c) { changeState(c, Ready::instance()); }
void Running::exit(Process* c) { cout << "Destroying" << endl; }

void Blocked::unblock(Process* c) { changeState(c, Ready::instance()); }

// Process member functions
Process::Process() {
    state_ = Ready::instance();
    id_ = nextId++;
}
void Process::dispatch() { state_->dispatch(this); }
void Process::suspend() { state_->suspend(this); }
void Process::block() { state_->block(this); }
void Process::unblock() { state_->unblock(this); }
void Process::exit() { state_->exit(this); }
// handles/behaviors
string Process::report() {
    return "process " + std::to_string(id_) + " is " + state_->report();
}
void printQueues(queue<Process*> rq, queue<Process*> bq) {
    cout << "  Ready/Running: [";
    bool first = true;
    while (!rq.empty()) {
        if (!first) cout << ", ";
        cout << rq.front()->report();
        rq.pop();
        first = false;
    }
    cout << "]" << endl;
    cout << "  Blocked:       [";
    first = true;
    while (!bq.empty()) {
        if (!first) cout << ", ";
        cout << bq.front()->report();
        bq.pop();
        first = false;
    }
    cout << "]" << endl;
}
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    queue<Process*> readyQueue;
    queue<Process*> blockedQueue;
    const int NUM_PROCESSES = 4;
    cout << "Admitting " << NUM_PROCESSES << " processes" << endl;
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        Process* p = new Process();
        readyQueue.push(p);
        cout << "  admitted -> " << p->report() << "" << endl;
    }
    readyQueue.front()->dispatch();
    cout << "Initial state:" << endl;
    printQueues(readyQueue, blockedQueue);
    cout << "" << endl;
    while ((!readyQueue.empty() || !blockedQueue.empty())) {
        if (readyQueue.empty()) {
            if (!blockedQueue.empty()) {
                Process* p = blockedQueue.front();
                blockedQueue.pop();
                p->unblock();
                readyQueue.push(p);
                cout << "  (no running process) forced unblock: " << p->report()
                     << "" << endl;
                readyQueue.front()->dispatch();
                cout << "  dispatched: " << readyQueue.front()->report()
                     << "" << endl;
            }
            printQueues(readyQueue, blockedQueue);
            cout << "" << endl;
            continue;
        }
        Process* running = readyQueue.front();
        int action = rand() % 3;
        if (action == 0) {
            cout << "  " << running->report() << " -> EXIT (destroyed)" << endl;
            running->exit();
            readyQueue.pop();
            delete running;
        } else if (action == 1) {
            cout << "  " << running->report() << " -> SUSPEND"<<endl;
            running->suspend();
            readyQueue.pop();
            readyQueue.push(running);
            cout << "  " << running->report()
                 << " moved to tail of ready queue"<<endl;
        } else {
            cout << "  " << running->report() << " -> BLOCK"<<endl;
            running->block();
            readyQueue.pop();
            blockedQueue.push(running);
            cout << "  " << running->report() << " moved to blocked queue"<< endl;
            printQueues(readyQueue, blockedQueue);
            if (!blockedQueue.empty() && rand() % 2 == 0) {
                Process* p = blockedQueue.front();
                blockedQueue.pop();
                p->unblock();
                readyQueue.push(p);
                cout << "  unblocked: " << p->report()
                     << " moved to ready queue" << endl;;
            }
        }
        if (!readyQueue.empty()) {
            readyQueue.front()->dispatch();
            cout << "  dispatched: " << readyQueue.front()->report() << endl;
        }
        printQueues(readyQueue, blockedQueue);
        cout << "" << endl;
    }
    while (!readyQueue.empty()) {
        delete readyQueue.front();
        readyQueue.pop();
    }
    while (!blockedQueue.empty()) {
        delete blockedQueue.front();
        blockedQueue.pop();
    }
    cout << "All processes have terminated"<<endl;;
    return 0;
}
