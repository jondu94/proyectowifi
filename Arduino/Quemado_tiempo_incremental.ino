int pin=6;                                   //Definimos el pin 6
unsigned long tEncendido=100;                //Tiempo encendido de inicio en milisegundos
unsigned long tApagado=2000;                 //Tiempo apagado constante en milisegundos
unsigned long incremento=1;                  //Tiempo de incremento por cada ciclo en milisegundos
unsigned long ciclomax=20000;                //Tiempo limite encendido en milisegundos
unsigned long tRestante=0;                   //Tiempo de prueba restante en milisegundos
unsigned long tTotal=0;;                     //Tiempo de prueba total en milisegundos
unsigned long tTranscurrido=0;;              //Tiempo de prueba transcurrido en milisegundos
unsigned long tTotalApagado=0;;              //Tiempo de prueba total apagado en milisegundos
unsigned long tTotalEncendido=0;;            //Tiempo de prueba total apagado en milisegundos
unsigned long tRestanteSegu=0;               //Tiempo de prueba total restante segundos
unsigned long tRestanteSeg=0;                //Tiempo de prueba restante segundos
unsigned long tRestanteMin=0;                //Tiempo de prueba restante minutos
unsigned long tRestanteHor=0;                //Tiempo de prueba restante horas

void setup() {
  Serial.begin(115200);                        //Definimos los baudios del monitor serie
  pinMode(pin,OUTPUT);                       //Definimos el pin 6 como salida
}

void loop() {
  tTotalApagado = (ciclomax/incremento)*tApagado;                           //se calcula el tiempo total que el pin estara en LOW en milisegundos
  tTotalEncendido = ((ciclomax + 1) * ciclomax) / (2 * incremento);         //se calcula el tiempo total que el pin estara en HIGH en milisegundos
  tTotal = tTotalApagado + tTotalEncendido;                                 //se calcula el tiempo total en milisegundos
  
  for(tEncendido;tEncendido<ciclomax;tEncendido=tEncendido+incremento)      //bucle hasta que supere el tiempo limite establecido
  {
  tTranscurrido = millis();                                                 //devuelve el valor del tiempo transcurrido desde el inicio del programa en milisegundos
  tRestante = tTotal - tTranscurrido;                                       //se calcula el tiempo restante en milisegundos
  tRestanteSegu = tRestante / 1000;                                         //se calcula el tiempo restante en segundos
  tRestanteHor = tRestanteSegu / 3600;                                      //se calcula las horas restantes
  tRestanteMin = ((tRestanteSegu - tRestanteHor * 3600) / 60);              //se calculan los minutos de las horas restantes
  tRestanteSeg = tRestanteSegu - (tRestanteHor * 3600 + tRestanteMin *60);  //se calculan los segundos de los minutos y horas restantes
  Serial.print("Ciclo encendido: ");
  Serial.print(tEncendido);                   //imprime el valor de encendido en milisegundos
  Serial.print("ms ");
  Serial.print("\n\n");
  Serial.print("Tiempo restante: ");
  Serial.print(tRestanteHor);                 //imprime las horas restantes
  Serial.print("h ");
  Serial.print(tRestanteMin);                 //imprime los minutos restantes
  Serial.print("m ");
  Serial.print(tRestanteSeg);                 //imprime los segundos restantes
  Serial.print("s ");
  Serial.print("\n\n\n\n\n\n\n\n\n\n\n");
  digitalWrite(pin,HIGH);                     //Encendemos el módulo durante "tEncendido" milisegundos
  delay(tEncendido);                          //retraso de "tEncendido" milisegundos
  digitalWrite(pin,LOW);                      //Apagamos el modulo durante "tApagado" milisegundos
  delay(tApagado);                            //retraso de "tApagado" milisegundos                       
  }
}
