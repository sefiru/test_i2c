#include <Wire.h>
#include "PCF8574.h"

PCF8574 pcf;

byte plus[3][3] = {
  {0, 1, 0},
  {1, 1, 1},
  {0, 1, 0}
};
byte zero[3][3] = {
  {1, 1, 1},
  {1, 0, 1},
  {1, 1, 1}
};
byte minus[3][3] = {
  {0, 0, 0},
  {1, 1, 1},
  {0, 0, 0}
};
byte X[3][3] = {
  {1, 0, 1},
  {0, 1, 0},
  {1, 0, 1}
};

byte pos = 0;
unsigned long _time = 0;

void setup() {
  pcf.begin(0x27);
  
  pcf.pinMode(0, OUTPUT);
  pcf.pinMode(1, OUTPUT);
  pcf.pinMode(2, OUTPUT);
  pcf.pinMode(3, OUTPUT);
  pcf.pinMode(4, OUTPUT);
  pcf.pinMode(5, OUTPUT);
  pcf.pinMode(6, OUTPUT);
  pcf.pinMode(7, OUTPUT);

  pcf.clear();
}

void loop() {
  switch ( pos ) {
    case 0: showX(); break;
    case 1: showZero(); break;
    case 2: showMinus(); break;
    case 3: showPlus(); break;
  }
  
  if ( millis() >= _time + 1000) {
    _time = millis();
    pos++;
    if ( pos > 3 ) {
      pos = 0;
    }
  }
}

void showMinus () {
  for ( byte y = 0; y < 3; y++ ) {
    for ( byte x = 0; x < 3; x++ ) {
      pcf.digitalWrite(4, LOW);
      pcf.digitalWrite(5, LOW);
      pcf.digitalWrite(6, LOW);
      pcf.digitalWrite(7, LOW);
      pcf.digitalWrite(8, LOW);
      pcf.digitalWrite(9, LOW);
      if ( minus[y][x] == 1 ) {
        pcf.digitalWrite(y, HIGH);
        pcf.digitalWrite(x + 3, HIGH);
      }
    }
  }
}

void showPlus () {
  
  for ( byte y = 0; y < 3; y++ ) {
    for ( byte x = 0; x < 3; x++ ) {
      pcf.digitalWrite(4, LOW);
      pcf.digitalWrite(5, LOW);
      pcf.digitalWrite(6, LOW);
      pcf.digitalWrite(7, LOW);
      pcf.digitalWrite(8, LOW);
      pcf.digitalWrite(9, LOW);
      if ( plus[y][x] == 1 ) {
        pcf.digitalWrite(y, HIGH);
        pcf.digitalWrite(x + 3, HIGH);
      }
    }
  }
}

void showZero () {
  for ( byte y = 0; y < 3; y++ ) {
    for ( byte x = 0; x < 3; x++ ) {
      pcf.digitalWrite(4, LOW);
      pcf.digitalWrite(5, LOW);
      pcf.digitalWrite(6, LOW);
      pcf.digitalWrite(7, LOW);
      pcf.digitalWrite(8, LOW);
      pcf.digitalWrite(9, LOW);
      if ( zero[y][x] == 1 ) {
        pcf.digitalWrite(y, HIGH);
        pcf.digitalWrite(x + 3, HIGH);
      }
    }
  }
}

void showX () {
  for ( byte y = 0; y < 3; y++ ) {
    for ( byte x = 0; x < 3; x++ ) {
      pcf.digitalWrite(4, LOW);
      pcf.digitalWrite(5, LOW);
      pcf.digitalWrite(6, LOW);
      pcf.digitalWrite(7, LOW);
      pcf.digitalWrite(8, LOW);
      pcf.digitalWrite(9, LOW);
      if ( X[y][x] == 1 ) {
        pcf.digitalWrite(y, HIGH);
        pcf.digitalWrite(x + 3, HIGH);
      }
    }
  }
}
