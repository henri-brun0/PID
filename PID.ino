// Grupo:
// Bruno Henrique Moreira Barbosa
// Igor Carvalho Soares de Souza Lima
// Lucas ferreira souto
// Edvaldo Oliveira Domingues Júnior

#include <PID_v1.h>

//Constantes do PID
double kp = x;
double ki = x;			//Falta substituir valores de KP
double kd = x;

//Declarar Pinos
int sensorPin = A0;
int motor = 2;			// Tem que ver a entrada de tensao no motor

//Definir Setpoint
double setpoint = 25.0;

//Iniciar PID
PID myPID(&input, &output, &setpoint, kp, ki, kd, DIRECT);

//Variáveis PID
double input, output;

void setup()
{
  Serial.Begin(9600);
  myPID.SetMode(AUTOMATIC);

}

void loop()
{
  //Leitura e Conversão de unidade
  input = analogRead(sensorPin);
  input = map(input, 0, 1023, 0, 100);
  
  //Calcular a Saída
  myPID.Compute = ();
  
  //Ajusta a Saída
  int outputMapped = map(output, 0, 100, 0, 255);
  analogWrite(motor, outputMapped);
  
  //Monitor Serial
  Serial.print("Entrada: ");
  Serial.print(input);
  Serial.print(" | Saída: ");
  Serial.print(output);
  
  delay(1000);
}