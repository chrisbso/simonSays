#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int highScore[3] = {};
char highScoreInitials[3][3];

void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  lcd.begin(16,2); //sjekk denne når skjermen kommer!
  Serial.begin(9600);
readFromEEPROM(int& highScore[3], char& highScoreInitials[3][3])
}

bool readColorGreen = digitalRead(0);
bool readColorBlue = digitalRead(1);
bool readColorYellow = digitalRead(6);
bool readColorRed = digitalRead(7);
int highscoreListLength = 3;
int highscoreList[int highscorelistLength][2] = {};

int Sort(int highscoreList) {
  // skriv en srteringsfuncsjon som vi kan bruke senere. husk å sortere navnene også
  return highscoreList;
}
void fillInName(int highscoreList){
  // lag en funksjon som tar inn navnet til personen og putter det inn i element highscoreList[highscoreListLength -1][2]
  return highscoreList
}
int menu() {
  int choice = 0;
  int buttonPress = 0;
   lcd.print("Start (1) \n Highscore (2)");
   lcd.display();
      while (true) {
      if (readColorGreen) {
        choice = 1; //START
        break;
      }
      else if (readColorBlue) {
        choice = 2; //HIGHSCORES
        break;
      }
    }
  return choice;
}
 void highscore(int highscoreList[int highscorelistLength][2]) {
  
 }


int  game(int highscoreList[int highscorelistLength][2]) {
  int maxLevel = 50;
  bool correct = true;
  int level  = 1;
  int element = 0;
  int colors[maxLevel] = {};
  int userGuess [maxLevel] = {};
  randomSeed(analogRead(A5)); //sjekk denne mot https://www.arduino.cc/en/Reference/Random
  while (correct == true && level <= maxLevel) {
      colors[level-1] = random(11,14);
      element = 0;
    while (correct == true && element < level) {
      if (readColorGreen) {
          userGuess[element]= 11; //color 1
        }
        else if (readColorBlue) {
          userGuess[element]= 12; //color 2
        }
        else if (readColorYellow) {
          userGuess[element]= 13; //color 3
        }
        else if (readColorRed) {
          userGuess[element]= 14 ; //color 4
        }
        element += 1;
        correct = (colors[element] == userGuess[element]);
    }
    level += 1;
  } 
if (correct == false) {
  lcd.print("Your score was:" level);
  if level - 1 > highscoreList[highscorelistLength - 1] {
    higscoreList[highscorelistLength - 1][1] = level - 1;
    fillInName(highscoreList)
    sort(highscoreList);
    
    highscore(int highscoreList[int highscorelistLength][2])
  }
}
else if (level == maxLevel) {
  //print "404: u dun fuckd up."
}
return highscoreList
}



void loop() {
    digitalWrite(A0, HIGH);
    int choice = menu();
    switch (choice) {
      case 1:
        game();
        break;
      case 2:
        highscore(int highscoreList[int highscorelistLength][2]);
        break;
      default:
      //do nothing
        break;
  }
}





//void showColors(int[] colors, int lengthOfColors) {
//  for (int i = 0; i < lengthOfColors; i++) {
//     //nothing
//  }
//}

