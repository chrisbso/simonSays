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

