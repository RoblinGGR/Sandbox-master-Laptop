void setup() {
// inicializa el pin digital 2 como salida
pinMode(13, OUTPUT);
}
void loop() {
digitalWrite(13, HIGH); // Enciende el LED
delay(1000); // Espera un segundo
digitalWrite(13, LOW); // Apaga el LED
delay(1000); // Espera un segundo
}
