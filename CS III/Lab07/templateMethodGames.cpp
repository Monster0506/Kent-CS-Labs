#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string; using std::cin;

class Game{
public:
   Game():playersCount_(0), movesCount_(0), playerWon_(noWinner){}

   // template method
   void playGame(const int playersCount = 0) {
      playersCount_ = playersCount;
      movesCount_=0;

      initializeGame();

      for(int i=0; !endOfGame(); i = (i+1) % playersCount_ ){
	 makeMove(i);
	 if (i==playersCount_-1) 
	    ++movesCount_; 
      }
      printWinner();
   }

   virtual ~Game(){}

protected:
   // primitive operations
   virtual void initializeGame() = 0;
   virtual void makeMove(int player) = 0;
   virtual void printWinner() = 0;
   virtual bool endOfGame() { return playerWon_ != noWinner;} // this is a hook
                   // returns true if winner is decided
   static const int noWinner=-1;

   int playersCount_;
   int movesCount_;
   int playerWon_;
};

// Monopoly - a concrete game implementing primitive 
// operations for the template method
class Monopoly: public Game {
public:  
   // implementing concrete methods
   void initializeGame(){
      playersCount_ = rand() % numPlayers_ + 1 ; // initialize players
   }

   void makeMove(int player) {
      if (movesCount_ > minMoves_){ 
	 const int chance = minMoves_ + rand() % (maxMoves_ - minMoves_);
	 if (chance < movesCount_) playerWon_= player;
      }
   }

   void printWinner(){
      cout << "Monopoly, player "<< playerWon_<< " won in "
	   << movesCount_<< " moves." << endl;
   }

private:
   static const int numPlayers_ = 8; // max number of players
   static const int minMoves_ = 20; // nobody wins before minMoves_
   static const int maxMoves_ = 200; // somebody wins before maxMoves_
};

// Chess - another game implementing
// primitive operations
class Chess: public Game {
public:
   void initializeGame(){
      playersCount_ = numPlayers_; // initalize players
      for(int i=0; i < numPlayers_; ++i) 
	     experience_[i] = rand() % maxExperience_ + 1 ; 
   }

   void makeMove(int player){
      if (movesCount_ > minMoves_){
	 const int chance = (rand() % maxMoves_) / experience_[player];
	 if (chance < movesCount_) playerWon_= player;
      }
   }

   void printWinner(){
      cout << "Chess, player " << playerWon_ 
	   << " with experience " << experience_[playerWon_]
	   << " won in "<< movesCount_ << " moves over"
	   << " player with experience " << experience_[playerWon_== 0 ? 1:0] 
           << endl;
   }

private:
   static const int numPlayers_ = 2;
   static const int minMoves_ = 5; // nobody wins before minMoves_
   static const int maxMoves_ = 100; // somebody wins before maxMoves_
   static const int maxExperience_ = 5; // player's experience
                              // the higher, the greater probability of winning
   int experience_[numPlayers_]; 
};

class RockPaperScissors : public Game {
public:

    void initializeGame() {
        playersCount_   = numPlayers_;
        computerChoice_ = noChoice;
        humanChoice_    = noChoice;
    }

    void makeMove(int player) {
        if (player == 0) {
            computerChoice_ = rand() % 3;
        } else {
            char input;
            cout << "Human, (r)ock, (p)aper, or (s)cissors? ";
            cin  >> input;
            switch (input) {
                case 'p': humanChoice_ = paper;    break;
                case 's': humanChoice_ = scissors; break;
                default:
                    humanChoice_ = rock;
            }

            evaluateRound();
        }
    }

    void printWinner() {
        if (playerWon_ == computer)
            cout << "Computer wins the game!" << endl;
        else
            cout << "You win the game!" << endl;
    }

private:
    void evaluateRound() {
        const string names[] = { "rock", "paper", "scissors" };
        cout << "Computer selected " << names[computerChoice_] << ". " << endl;

        if (computerChoice_ == humanChoice_) {
            playerWon_ = noChoice;
            cout << "It is a draw." << endl;
        } else if ((humanChoice_ - computerChoice_ + 3) % 3 == 1) {
            playerWon_ = human;
        } else {
            playerWon_ = computer;
        }
    }

    static const int numPlayers_ = 2;

    static const int computer = 0;
    static const int human = 1;

    static const int noChoice  = -1;
    static const int rock = 0;
    static const int paper = 1;
    static const int scissors = 2;

//    static const string names[] = {"rock", "paper", "scissors"};
    int computerChoice_;
    int humanChoice_;
};


int main() {
   srand(time(nullptr));

   Game* gp = nullptr;

   // play chess 7 times
   for (int i = 0; i < 7; ++i){ 
      gp = new Chess;
      gp -> playGame(); 
      delete gp;
   }
      

   // play monopoly 7 times
   for (int i = 0; i < 7; ++i){
      gp = new Monopoly;
      gp -> playGame(); 
      delete gp;
   }
   int games = 200;
   for (int i = 0; i< games; ++i){
      cout << "Game: " << i+1 << "/" << games << endl;
      gp = new RockPaperScissors;
      gp->playGame();
      delete gp;
   }
}
