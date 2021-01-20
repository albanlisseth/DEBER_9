//configura el tiempo del WDT mediante un potenciómetro 
#include <avr/wdt.h>
int tiempo=0;
int pin=9;
int enable=0;

void setup(){
pinMode(pin,INPUT);
Serial.begin(9600);
Serial.println("Instrucciones:");
Serial.println("1) Ajuste el potenciometro en A0 para configurar el tiempo entre 15ms y 8s.");
Serial.println("2) active el pulsador de D9");
delay(3000);
}

void loop(){
enable=digitalRead(pin);
if (enable==LOW)
{
tiempo=analogRead(0)*7.8055+15;
if (tiempo <=30)
{
tiempo=15;}
else if (tiempo <=60)
{
tiempo=30;}
else if (tiempo <=120)
{
 tiempo=60;
}
else if (tiempo <=250)
{
  tiempo=120;
}

else if (tiempo <=500)
{
tiempo=250;
}

else if (tiempo <=1000)
{
  tiempo=500;
}

else if (tiempo <=2000)
{
 tiempo=1000;
}

else if (tiempo <=4000)
{
  tiempo=2000;
}
else if (tiempo <=7000)
{
  tiempo=4000;
}
else
{
   tiempo=8000;

}
Serial.println(tiempo);
delay(100);
}

else
{
  Serial.print(tiempo);
  Serial.println(" ms configurados para reinicio");
if (tiempo <=30)
{
  wdt_enable(WDTO_15MS);
}
else if (tiempo <=60)
{
  wdt_enable(WDTO_30MS);
}
else if (tiempo <=120)
{
  wdt_enable(WDTO_60MS);
}
else if (tiempo <=250)
{
  wdt_enable(WDTO_120MS);
}

else if (tiempo <=500)
{
  wdt_enable(WDTO_250MS);
}

else if (tiempo <=1000)
{
  wdt_enable(WDTO_500MS);
}

else if (tiempo <=2000)
{
  wdt_enable(WDTO_1S);
}

else if (tiempo <=4000)
{
  wdt_enable(WDTO_2S);
}
else if (tiempo <=8000)
{
  wdt_enable(WDTO_4S);
}
else
{
    wdt_enable(WDTO_4S);

}
}
}
