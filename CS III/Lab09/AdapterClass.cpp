// figures: class adapter pattern
// Mikhail Nesterenko
// 11/7/2022

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// adaptee/implementer
class LegacyRectangle {
   public:
    LegacyRectangle(int topLeftX, int topLeftY, int bottomRightX,
                    int bottomRightY)
        : topLeftX_(topLeftX),
          topLeftY_(topLeftY),
          bottomRightX_(bottomRightX),
          bottomRightY_(bottomRightY) {}

    void oldDraw() const {
        for (int i = 0; i < bottomRightY_; ++i) {
            for (int j = 0; j < bottomRightX_; ++j)
                if (i >= topLeftY_ && j >= topLeftX_)
                    cout << '*';
                else
                    cout << ' ';
            cout << endl;
        }
    }
    void move(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
        topLeftX_ = topLeftX;
        bottomRightX_ = bottomRightX;
        topLeftY_ = topLeftY;
        bottomRightY_ = bottomRightY;
    }

    int getTopLeftX() const { return topLeftX_; }
    int getTopLeftY() const { return topLeftY_; }
    int getBottomRightX() const { return bottomRightX_; }
    int getBottomRightY() const { return bottomRightY_; }

    // defining top/left and bottom/right coordinates
   private:
    int topLeftX_;
    int topLeftY_;
    int bottomRightX_;
    int bottomRightY_;
};

// target interface
class Square {
   public:
    virtual void draw() const = 0;
    virtual ~Square() {}
    virtual int size() const = 0;
    virtual void resize(int) = 0;
};

// adapter uses multiple inheritance to inherit
// interface and implementation
class SquareAdapter : public Square, private LegacyRectangle {
   public:
    SquareAdapter(int size) : LegacyRectangle(0, 0, size, size) {};
    void draw() const override { oldDraw(); }
    int size() const override { return getBottomRightY() - getTopLeftX(); }
    void resize(int newSize) override { move(0, 0, newSize, newSize); }
};

int main() {
    int size = 0;
    cout << "Enter a size: ";
    cin >> size;
    Square *square = new SquareAdapter(size);
    square->draw();
    cout << endl << endl;
    cout <<"Current size is: " << square->size() << endl;
    cout << "Enter a new size: ";
    cin >> size;
    square->resize(size);
    square->draw();
    cout << endl << endl;
    cout << "Current size is: " << square->size() << endl;
}
