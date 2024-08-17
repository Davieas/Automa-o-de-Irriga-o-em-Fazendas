// C++ code Atuação Contator e Inversor de Frequencia

// Definição Dos Pinos Digitais de sinal para os Relés de controle dos contatores das bombas
#define pump1 13
#define pump2 12
//Pinos de Sinal Analogico dos Sensores
#define umidity1 A0
#define umidity2 A1

//Valores lidos
int valueum1;
int valueum2;
void setup()
{
  Serial.begin(9600);
  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
}

void loop()
{
  //Leitura e estabelecimento de range 0 a 100%
  valueum1 = map(analogRead(umidity1), 0, 1023, 0, 100);
  valueum2 = map(analogRead(umidity2), 0, 1023, 0, 100);

  // Verificação valor sensor 1 maior que 65
  if(valueum1 >= 65){
    digitalWrite(pump1, HIGH);
  }else{
	digitalWrite(pump1, LOW);
  }
  // Verificação valor sensor 2 maior que 65
   if(valueum2 >= 65){
    digitalWrite(pump2, HIGH);
  }else{
    digitalWrite(pump2, LOW);
  }
}