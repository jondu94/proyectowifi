int pin = 6;                           //Definimos el pin 6
float tEncendido = 5000;               //Tiempo encendido en milisegundos
float tApagado = 1000;                 //Tiempo apagado en milisegundos

void setup() {
  pinMode(pin, OUTPUT);                //Definimos el pin 6 como salida
}

void loop() {
    digitalWrite(pin, HIGH);            //Encendemos el módulo durante "tEncendido" milisegundos
    delay(tEncendido);
    digitalWrite(pin, LOW);             //Apagamos el módulo durante "tApagado" milisegundos
    delay(tApagado);              
}
