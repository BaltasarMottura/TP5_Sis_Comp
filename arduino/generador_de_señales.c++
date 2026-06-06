const int PIN_SENAL_1 = 8;
const int PIN_SENAL_2 = 9;

bool estado1 = LOW;
bool estado2 = LOW;

unsigned long tiempoAnterior1 = 0;
unsigned long tiempoAnterior2 = 0;

// Mitad del período
const unsigned long intervalo1 = 1000; // 1 s
const unsigned long intervalo2 = 2000; // 2 s

void setup() {
  pinMode(PIN_SENAL_1, OUTPUT);
  pinMode(PIN_SENAL_2, OUTPUT);

  digitalWrite(PIN_SENAL_1, estado1);
  digitalWrite(PIN_SENAL_2, estado2);
}

void loop() {
  unsigned long tiempoActual = millis();

  // Señal de período 2 s
  if (tiempoActual - tiempoAnterior1 >= intervalo1) {
    tiempoAnterior1 = tiempoActual;
    estado1 = !estado1;
    digitalWrite(PIN_SENAL_1, estado1);
  }

  // Señal de período 4 s
  if (tiempoActual - tiempoAnterior2 >= intervalo2) {
    tiempoAnterior2 = tiempoActual;
    estado2 = !estado2;
    digitalWrite(PIN_SENAL_2, estado2);
  }
}