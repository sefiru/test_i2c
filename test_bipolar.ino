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

void setup () {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  

}

void loop () {
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
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      if ( minus[y][x] == 1 ) {
        digitalWrite(y + 4, HIGH);
        digitalWrite(x + 7, HIGH);
      }
    }
  }
}

void showPlus () {
  
  for ( byte y = 0; y < 3; y++ ) {
    for ( byte x = 0; x < 3; x++ ) {
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      if ( plus[y][x] == 1 ) {
        digitalWrite(y + 4, HIGH);
        digitalWrite(x + 7, HIGH);
      }
    }
  }
}

void showZero () {
  for ( byte y = 0; y < 3; y++ ) {
    for ( byte x = 0; x < 3; x++ ) {
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      if ( zero[y][x] == 1 ) {
        digitalWrite(y + 4, HIGH);
        digitalWrite(x + 7, HIGH);
      }
    }
  }
}

void showX () {
  for ( byte y = 0; y < 3; y++ ) {
    for ( byte x = 0; x < 3; x++ ) {
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      if ( X[y][x] == 1 ) {
        digitalWrite(y + 4, HIGH);
        digitalWrite(x + 7, HIGH);
      }
    }
  }
}

