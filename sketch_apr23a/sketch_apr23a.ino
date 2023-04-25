#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

byte data1;
const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  // Initialise l'écran LCD
  lcd.init();
  
  // Active la rétroéclairage de l'écran
  lcd.backlight();
  lcd.clear();

  // Affiche un message d'accueil sur l'écran LCD
  lcd.print("systeme ouvert");
  lcd.setCursor(0,1);
  lcd.print("Veuillez Connecté");

  delay(10000);
  lcd.clear();
}

void loop() {
  char key=keypad.getKey();
  
  if (key) {
    Serial.print(key);
    delay(100); // Ajouter une pause de 100 millisecondes
  }
  if (Serial.available()) { 
    data1 = Serial.read();
    
    if (data1 == '0') {
      String receivedString = Serial.readStringUntil('\n');
      lcd.clear();
      lcd.print("bonjour");
      lcd.print(" ");
      lcd.print(receivedString);
      delay(500);
      
  lcd.cursor();
  delay(500);
  lcd.noCursor();
  delay(500);
    }
    else if (data1 == '1') {
      lcd.clear();
      lcd.print("mot de passe");
       lcd.setCursor(0,1);
  lcd.print("incorrect!!");
      delay(500);
      
  lcd.cursor();
  delay(500);
  lcd.noCursor();
  delay(500);
    }
  }

}
