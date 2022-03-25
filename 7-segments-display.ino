int displayValue, decrementDisplayValue;

byte seven_seg_digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, //DIGITO 0
  { 0, 1, 1, 0, 0, 0, 0 }, //DIGITO 1
  { 1, 1, 0, 1, 1, 0, 1 }, //DIGITO 2
  { 1, 1, 1, 1, 0, 0, 1 }, //DIGITO 3
  { 0, 1, 1, 0, 0, 1, 1 }, //DIGITO 4
  { 1, 0, 1, 1, 0, 1, 1 }, //DIGITO 5
  { 1, 0, 1, 1, 1, 1, 1 }, //DIGITO 6
  { 1, 1, 1, 0, 0, 0, 0 }, //DIGITO 7
  { 1, 1, 1, 1, 1, 1, 1 }, //DIGITO 8
  { 1, 1, 1, 1, 0, 1, 1 }, //DIGITO 9
};

void setup() {
  pinMode(2, OUTPUT); //PINO 2 -> SEGMENTO A
  pinMode(3, OUTPUT); //PINO 3 -> SEGMENTO B
  pinMode(4, OUTPUT); //PINO 4 -> SEGMENTO C
  pinMode(5, OUTPUT); //PINO 5 -> SEGMENTO D
  pinMode(6, OUTPUT); //PINO 6 -> SEGMENTO E
  pinMode(7, OUTPUT); //PINO 7 -> SEGMENTO F
  pinMode(8, OUTPUT); //PINO 8 -> SEGMENTO G
  pinMode(9, OUTPUT); //PINO 9 -> SEGMENTO PONTO

  decrementDisplayValue = 9;
  showDisplay(decrementDisplayValue);
}

void ligaPonto(byte dot) { //FUNÇÃO QUE ACIONA O PONTO DO DISPLAY
  digitalWrite(9, dot);
}

void showDisplay(byte digit) {
  byte pino = 2;

  for (byte contadorSegmentos = 0; contadorSegmentos < 7; ++contadorSegmentos) {
    digitalWrite(pino, seven_seg_digits[digit][contadorSegmentos]);
    pino++;
  }
}

void loop() {
  if (displayValue == 10) {
    ligaPonto(1);
    delay(50);
    ligaPonto(0);

    delay(1000);
    showDisplay(decrementDisplayValue);
    decrementDisplayValue--;
  } else if (displayValue < 10) {
    delay(1000);
    showDisplay(displayValue);
    displayValue++;
  }
}
