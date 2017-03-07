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
		if ( i== 1) {
		lcd.print(00001111,BIN); //print arrow down)
		}
		else if (i == 2) {
			lcd.print(00000000,BIN) //print arrow right
		}
		
		while(i > 0) {
		if (digitalRead(7)) break;
		}
		
	}
	
	lcd.clear();
	
	
	
	
	
}

void setInitials (char& initialArray[3]) {
	
}