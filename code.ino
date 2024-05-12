#include <LiquidCrystal_I2C.h>

// defining SARGAM Notes
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define A 7
#define B 8
#define Cm 9

// defining midi notes
int c[] = {60, 48, 36, 72, 84};
int d[] = {62, 74, 50, 38, 86};
int e[] = {64, 76,52, 40, 88};
int f[] = {65, 77, 53, 41,89};
int g[] = {67, 79, 55, 43,91};
int a[] = {69, 81, 57, 45, 93};
int b[] = {71, 83, 59, 47, 95};

int played;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  
  for (int i=2; i<10; i++){pinMode(i, OUTPUT);}
}

void loop() {
//  for (int i=2; i<10; i++){digitalWrite(i, HIGH);}
  
  lcd.setCursor(0,0);
  if (Serial.available())
  {
    played = Serial.read();
    lcd.print(check(played));
    if (played == 72){all_off();digitalWrite(Cm, HIGH);}
  }
  
}

String check(int n)
{
  
  Serial.println(n);
  for (int i=0; i<5; i++)
  {
    if (c[i] == n){all_off();digitalWrite(C, HIGH);return "C";}
    else if (d[i] == n){all_off();digitalWrite(D, HIGH);return "D";}
    else if (e[i] == n){all_off();digitalWrite(E, HIGH);return "E";}
    else if (f[i] == n){all_off();digitalWrite(F, HIGH);return "F";}
    else if (g[i] == n){all_off();digitalWrite(G, HIGH);return "G";}
    else if (a[i] == n){all_off();digitalWrite(A, HIGH);return "A";}
    else if (b[i] == n){all_off();digitalWrite(B, HIGH);return "B";}
  }
}

void all_off()
{
  for(int i=2; i<10;i++)
  {
    digitalWrite(i, LOW);
  }
}
