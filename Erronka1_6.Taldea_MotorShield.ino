/* L298P Motor Shield-a eta DC motorra
    Joystic-aren posizioaren arabera DC motorarren noranzkoa eta abiadura kontrolatu. Joystick-aren          muturretan motorraren abiadura maximoa eta joystic-aren zerntroan abiadura 0.
    Aurrerantz doanean argi berdea piztu eta atzerantz argi gorria.
    Bi argien intentsitateak abiadurarekin batera handitu.
    Motorra atzerantz doanean soinua egingo du.
  2020 ko Azaroan, Xabier Odriozola, Imanol Eizaguirre eta Maider Olaizola
  This example code is in the public domain.
*/
 
int E1 = 10; //Motorraren Abiadura PWM.
int M1 = 12; // Motorraren Norantza.
int piezoPin=4; //Soinuaren pin-a izendatu.
int x=0;           // Joystic-aren x ardatzen pina izendatu.
int geldirik=0;// Geldiriko posizioa markatzeko.
int pwm1;          //Alde batera izango duen abiadura PWM 1.
int pwm2;          //Beste aldera izango duen abiadura PWM 2.
int ledgorri=9;  //Led gorriaren pina-a izendatu.
int ledberde=11;//Led berdearen pin-a izendatu.
 
void setup()
{
pinMode(M1, OUTPUT);
pinMode (ledgorri, OUTPUT);
pinMode (ledberde, OUTPUT);
Serial.begin(9600);
}
 
void loop(){
  x=analogRead(0); //Joystic-aren x posizioa irakurri.
  Serial.print("X Ardatza=     "); //Posizioa serial monitorean idatzi
  Serial.println(x);
  
  if(x<500){    // Motorra AURRERANTZ
     digitalWrite(M1,HIGH); //Motorra aurrerantz piztu
     pwm1 = map(x, 0, 500, 255, 0); //Abiadura mapeatu, hau da, x posizioaren arabera aldatu
     analogWrite(E1, pwm1); //Abiadura mapeoaren arabera ezarri
     delay(200);
     Serial.print("Abiadura: "); //Abiadura serial monitorean idatzi
     Serial.println(pwm1);
     Serial.println("FORWARD"); // Serial monitorean aurrerantz idatzi
     int argi = map (x, 0, 500, 255, 0); //Argi intentsitatea mapeatu, hau da, x posizioaren arabera aldatu
     analogWrite (ledberde,argi); //Led berdea piztu mapeoaren arabera
     analogWrite (ledgorri, 0); //Led gorria itsali
    }
 
 
   if(x>550){     // Motorra ATZERANTZ
   
    digitalWrite(M1,LOW); //Motorra atzerantz piztu
    pwm2 = map(x, 550, 1023, 0, 255); //Abiadura mapeatu, hau da, x posizioaren arabera aldatu
    analogWrite(E1, pwm2);//Abiadura mapeoaren arabera ezarri
    delay(200);
    Serial.print("Abiadura: ");//Abiadura serial monitorean idatzi
    Serial.println(pwm2);
    Serial.println("BACKWARD"); // Serial monitorean atzerantz idatzi
    tone(piezoPin, 1000, 50);       // Tonua egin 
    delay(50);
    tone(piezoPin, 2000, 50);
    int argi2 = map (x, 550, 1023, 0, 255); //Argi intentsitatea mapeatu, hau da, x posizioaren arabera aldatu
    analogWrite (ledgorri, argi2); //Led gorria piztu mapeoaren arabera
    analogWrite (ledberde, 0); //Led berdea itsali
 }
 
      if(x<515 && x>485){    // Motorra GELDIRIK
     digitalWrite(M1,HIGH);
     analogWrite(E1, geldirik); //Motorrari geldirik abiadura ezarri, hau da, 0
     delay(200);
     Serial.print("Abiadura: "); //Abiadura serial monitorean idatzi
     Serial.println(geldirik);
     Serial.println("geldirik");
     analogWrite (ledberde,0); //Led berdea itsali
     analogWrite (ledgorri, 0); //Led gorria itsali
    }
 
}
