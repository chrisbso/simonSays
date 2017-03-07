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
  readFromEEPROM(highScore, highScoreInitials)
}

void readFromEEPROM(int& highScore[3], char& highScoreInitials[3][3]) {
int sum = 0;
int addr = 0;
for (addr = 0; addr < 3; addr++) {
	highScore[addr] = EEPROM.read(addr); //read the scores
	sum += EEPROM.read(addr); //for checking if there are no score already
}
if (sum == 0) //doNothing; 
else {
	addr = 3;
	for (int row = 0; row < 3; row++) {
		for int (col = 0; col < 3; col++) {
			highScoreInitials[row][col] = (char)EEPROM.read(addr);
			addr++;
		}
	}
}

//		   |;-----------------------------------;-------;-----;|
//         |;---------------;------;------;|
//EEPROM: |H1| |H2| |H3| |N1C1| |N1C2| |N1C3| |N2C1| |N2C2| |N2C3| |N3C1| |N3C2| |N3C3|
//	addr:   0    1    2     3      4     5      6      7      8      9      10     11  

}

void writeToEEPROM(const int& highScore[3],const char& highScoreInitials[3][3]) {
for (addr = 0; addr < 3; addr++) {
	EEPROM.write(addr, highScore[addr]);
}
addr = 3;
	for (int row = 0; row < 3; row++) {
		for int (col = 0; col < 3; col++) {
			EEPROM.write(addr, (int)highScoreInitials[row][col]);
			addr++;
		}
	}
}



//bool readColorGreen = digitalRead(0);  //DISSE VIL IKKE OPPDATERES UNDER KJØRING!
//bool readColorBlue = digitalRead(1);
//bool readColorYellow = digitalRead(6);
//bool readColorRed = digitalRead(7);
//int highscoreListLength = 3;
//int highscoreList[int highscorelistLength][2] = {};**/

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
      if (digitalRead(0)) {
        choice = 1; //START
        break;
      }
      else if (digitalRead(1) {
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
  int place;
  randomSeed(analogRead(A5)); //sjekk denne mot https://www.arduino.cc/en/Reference/Random
  while (correct == true && level <= maxLevel) {
      colors[level-1] = random(11,14);
      element = 0;
    while (correct == true && element < level) {
      if (digitalRead(0)) {
          userGuess[element]= 11; //color 1
        }
        else if (digitalRead(1)) {
          userGuess[element]= 12; //color 2
        }
        else if (digitalRead(6)) {
          userGuess[element]= 13; //color 3
        }
        else if (digitalRead(7)) {
          userGuess[element]= 14 ; //color 4
        }
        element += 1;
        correct = (colors[element] == userGuess[element]);
    }
    level += 1;
  } 
if (correct == false) {
  lcd.print("Your score was:");
  lcd.print(level);
  for (int place = 0; place < 3; place++) {
	  if (highScore[place] < level)
	  fillInName();
	  writeToEEPROM();
}
else if (level == maxLevel) {
  //print "404: u dun fuckd up."
}
return highscoreList
}
}

void printHighscores() {
	char initials[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			initials[j] = highScoreInitials[i][j];
		}
		lcd.setCursor(i,0)
		lcd.print(initials);
		lcd.setCursor(i,5);
		lcd.print(highScore[i]);
		lcd.setCursor(i,15);
		if ( i== 1 ) {
		lcd.print(00001111,BIN); //print arrow down)
		}
		else if (i == 2) {
			lcd.print(00000000,BIN) //print arrow right
		}
		
		while(i > 0) {
		if (digitalRead(7)) break;
		lcd.clear();
		}
		
	}
	
	lcd.clear();	
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

