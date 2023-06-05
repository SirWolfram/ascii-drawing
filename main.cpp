#include <iostream>
#include <unistd.h>

using namespace std;

int cursorX = 0;
int cursorY = 0;
/*
length: lengths of line
padding: how far over line will be printed
doubleLine: whether or not the 2 lines are to be printed to console with a space
*/
void drawVert(int length, int padding, bool doubleLine) {
  if (doubleLine == true) {
    cout << "\n";
    for (int i = 0; i < length; i++) {
      cout << char(124) << string(padding, char(32)) << char(124) << "\n";
      cursorY--;
    }
    cursorX += padding;
  } else {
    cout << "\n";
    for (int i = 0; i < length; i++) {
      cout << string(padding, char(32)) << char(124) << "\n";
      cursorY--;
    }
  }
}

void drawHori(int length) {
    for (int i = 0; i < length; i++) {
      cout << char(95) << char(32);
      if (cursorX < length) {
        cursorX++;
      }
    }
  cursorY--;
}

void idle() {
  int tempLength = 0;
  while (true) {
      cout << char(46) << "\n";
      tempLength++;
      usleep(250000);
      cout << string(tempLength, char(32));
  }
}

void drawSquare(int length) {
  drawHori(length);
  drawVert(length, (length * 2), true);
  drawHori(length);
}

int consoleInput() {
  string input1; //what function
  int input2; //length
  int input3; //padding
  bool input4; //double or not
  
  cout << "\ndraw vertical or horizontal: ";
  cin >> input1;
  
  if (input1 == "vertical") {
    cout << "\nline length: ";
    cin >> input2;
    cout << "\npadding length: ";
    cin >> input3;
    cout << "\ndouble line? true (1) or false (0): ";
    cin >> input4;
    drawVert(input2, input3, input4);
    
  } else if (input1 == "horizontal") {
    cout << "\nline length: ";
    cin >> input2;
    drawHori(input2);
    
  } else if (input1 == "DONE") {
    return 0;
    
  } else {
    cout << "\nerror\n";
  }

  cout << "\n\n\n  X: " << cursorX << "\n  Y: " << cursorY << "\n\n\n";
  cursorX = 0;
  cursorY = 0;
  consoleInput();
}

int main() {
  //comment out "consoleInput();" to manually use draw functions
  //consoleInput();
  idle();
}
