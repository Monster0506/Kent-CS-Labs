// filled/hollow figures demonstrates Bridge Design Pattern,
// square is either hollow or square and is painted with a particular character,
// it is bridged over Figure --> Fill abstract body/handle
// Mikhail Nesterenko
// 2/12/2014

#include <iostream>

using std::cout; using std::endl; using std::cin;

// abstract body 
class Fill{
public:
   Fill(char fillChar=' ', char inChar=' '): fillChar_(fillChar),inChar_(inChar){}
   virtual char getBorder()=0;
   virtual char getInternal()=0;
   virtual ~Fill() {}
protected:
   char fillChar_;
   char inChar_;
};

// concrete body
class Hollow: public Fill{
public:
   Hollow(char fillChar):Fill(fillChar, ' '){}
   char getBorder() override {return fillChar_;}
   char getInternal() override {return inChar_;}
   ~Hollow() override {}
};


// another concrete body
class Filled: public Fill {
public:
   Filled(char fillChar):Fill(fillChar, fillChar){}
   char getBorder() override {return fillChar_;}
   char getInternal() override {return inChar_;}
   ~Filled() override {}
protected:
    Filled(char fillChar1, char fillChar2): Fill(fillChar1, fillChar2){}
};

class FullyFilled: public Filled {
public:
    FullyFilled(char fillChar1, char fillChar2):Filled(fillChar1, fillChar2){}
    ~FullyFilled(){}
};

class RandomFilled: public FullyFilled {
public:
    RandomFilled(char fillChar1, char fillChar2): FullyFilled(fillChar1, fillChar2){}
    char getBorder() override   { return rand() % 2 ? fillChar_:inChar_;}
    char getInternal() override { return rand() % 2 ? fillChar_:inChar_;}
    ~RandomFilled(){}
};

// abstract handle
class Figure {
public:
   Figure(int size, Fill* fill): size_(size), fill_(fill){}
   virtual void draw() =0;
   virtual ~Figure(){}
protected:
   int size_;
   Fill *fill_;
};

// concrete handle
class Square: public Figure{
public:
   Square(int size, Fill* fill): Figure(size, fill){}
   void draw() override;

};

void Square::draw(){
   for(int i=0; i < size_; ++i){
      for(int j=0; j < size_; ++j)
	 if(i==0 || j==0 || i==size_-1 || j==size_-1 )
	    cout << fill_ -> getBorder();
	 else
	    cout << fill_ -> getInternal();
      cout << endl;
   }
}

int main(){
   Fill* hollowPaintStar = new Hollow('*');
   Fill* filledPaintJ = new Filled('j');
   Fill* fullyFilledPaintOHash = new FullyFilled('O','#');
   Fill* randomPaintPercentAt = new RandomFilled('%','@');
   
   Figure *smallBox = new Square(24, hollowPaintStar);
   Figure *bigBox = new Square(40, filledPaintJ);
   
   smallBox->draw();
   cout << endl<<endl;
   bigBox -> draw();
   cout << endl << endl;   
/* 
   // ask user for figure parameters
   cout << "Enter fill character: "; 
            char fchar; cin >> fchar;
   cout << "Filled or hollow? [f/h] "; 
           char ifFilled; cin >> ifFilled;
   cout << "Enter size: "; int size; cin >> size;
      
   Figure *userBox = ifFilled == 'f'?
      new Square(size, new Filled(fchar)):
      new Square(size, new Hollow(fchar));
userBox -> draw();
*/       
   
   smallBox = new Square(10, fullyFilledPaintOHash);
   smallBox -> draw();
   cout << endl << endl;
   smallBox = new Square(10, randomPaintPercentAt);
   smallBox -> draw();
   cout << endl;
   
}
