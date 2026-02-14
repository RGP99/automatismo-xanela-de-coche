int boton = 2;
int motorSubir = 3;
int motorBajar = 4;

//  VARIABLES
int estado = 0;        
int siguienteMov = 1;  
unsigned long tiempoInicio = 0; 

// Para detectar el clic del botón
int botonAntes = 0; 

void setup() {
  pinMode(boton, INPUT);
  pinMode(motorSubir, OUTPUT);
  pinMode(motorBajar, OUTPUT);
  digitalWrite(motorSubir, LOW); 
  digitalWrite(motorBajar, LOW);
}

void loop() {
  int botonAhora = digitalRead(boton);
  // Si acabas de pulsar (pasó de 0 a 1)
  if (botonAhora == HIGH && botonAntes == LOW) {
    tiempoInicio = millis();  
    estado = siguienteMov;     
    
    if (siguienteMov == 1) {
      siguienteMov = 2;
    } else {
      siguienteMov = 1;
    }
  }
  botonAntes = botonAhora; 

  // COMPROBAR TIEMPO (7 Segundos)
  // Si se pasa de tiempo, forzamos el estado a 0 (Parado)
  if (millis() - tiempoInicio > 7000) {
    estado = 0; 
  }

  // MOVER LOS MOTORES
  
  if (estado == 0) { // PARADO
    digitalWrite(motorSubir, HIGH); 
    digitalWrite(motorBajar, HIGH); 
  }
  else if (estado == 1) {
    digitalWrite(motorSubir, LOW); 
    digitalWrite(motorBajar, HIGH); 
  }
  else if (estado == 2) { 
    digitalWrite(motorSubir, HIGH); 
    digitalWrite(motorBajar, LOW);  
  }
}
