#include <EEPROM.h>
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
}
//		   |;-----------------------------------;-------;-----;|
//         |;---------------;------;------;|
//EEPROM: |H1| |H2| |H3| |N1C1| |N1C2| |N1C3| |N2C1| |N2C2| |N2C3| |N3C1| |N3C2| |N3C3|
//	addr:   0    1    2     3      4     5      6      7      8      9      10     11  