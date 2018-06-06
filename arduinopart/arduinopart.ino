char command;
String string;
#define QUANT_LEDS 20
#define LED_INICIAL 2
int led_vector[QUANT_LEDS];

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < QUANT_LEDS; i ++) {
    pinMode(i+LED_INICIAL, OUTPUT);
    led_vector[i] = 0;
  }
}

void loop()
{
  if (Serial.available() > 0)
  {
    string = "";
  }
  else 
    return;
  while (Serial.available() > 0)
  { 
    //Serial.println("a");
    command = ((byte)Serial.read());
    if (command == ';')
    {
      string += command;
      break;
    }
    else
    {
      string += command;
    }
    delay(5);
  }
  Serial.println(string); //debug
  int num = 0;
  int intensidade = 0;
  String numCod = "";
  int i;
  for(i = 0; string[i] != '-'; i++)
  {
    //Serial.println("b");
    if(string[i] == '\0')
      break;
    if(string[i] >= '0' && string[i] <= '9')
      numCod += string[i];
  }
  numCod += "\0";
  num = valString(numCod);
  num %= QUANT_LEDS;
  numCod = "";
  for(i = i+1; string[i] != ';'; i++)
  {
    //Serial.println("c");
    if(string[i] == '\0')
      break;
    if(string[i] >= '0' && string[i] <= '9')
      numCod += string[i];
  }
  intensidade = valString(numCod);
  intensidade %= 256;
  //Serial.print("numero: ");
  //Serial.print(num);
  //Serial.print("  intensidade: ");
  //Serial.println(intensidade);
  
  led(num, intensidade);
  for(i = 0; i < QUANT_LEDS; i++){
    analogWrite(i+LED_INICIAL, led_vector[i]);  
  }
}

void led(int cled, int intens)
{
  led_vector[cled] = intens;
}

int valString(String strN)
{
  int num = 0;
  int i;
  //Serial.println(strN);
  for(i = 0; strN[i] != '\0'; i++)
  {
    if(strN[i] <= '9' && strN[i] >= '0')
    {
      num += (strN[i]-'0');
      num*=10;
    }  
  }
  num/=10;
  return num;
}
