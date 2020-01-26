/*
Robert Gogol 26.01.2020 Poznań
PROSTY TRIGGER AUDIO
1.podawany sygnał dostosowac korektorem graficznym / filtrem tak aby uwypuklic 
pasmo, ktore ma triggerować uklad
2.sygnal podac przez kondensator okolo 100uF na dzielnk napiecia 100k/100k rozpiety miedzy GND i A0
3.czułość ukladu to odstępsto od zera wejścia A0, w zakresie od polowy 
rozdzielczosci przetwornika do, jak mi wyszlo z testow - odchylki okolo +/- 100 
czyli 1023/2=ca.512  np. 400-512 lub 512-612
>>490 to czulosc bardzo duza
>>470 to czulosc sredna
>>400 to czulosc bardzo niska 
*/

int sensuj;                       // twórz zmienną detekcji sygnału audio 

void setup() { 
  
  pinMode (LED_BUILTIN, OUTPUT);  //  pin z wbudowaną diodą będzie wyjściem
  Serial.begin(9600);             //  otwórz port szeregowy z szybkością 9600
  
}


void loop() {

  sensuj = analogRead(A0);        // wpisz wartość portu analogowego A0 do zmiennej "sensuj"
  if ( sensuj <= 470 ) {          // TU SIĘ USTAWIA CZUŁOŚĆ - JESLI dolny peak audio zejdzie ponizej 470, wtedy:
    digitalWrite( LED_BUILTIN, 1);// >> zapal LED
    delay(10);                    // >> poczekaj 10 ms dla stabilzacji ukladu
    }
  else {                          // W PRZECIWNYM RAZIE
    digitalWrite( LED_BUILTIN, 0);// >> nie zapalaj / zgas LED 
    }
  
  Serial.println(sensuj);         // wpisz na port szeregowy odczytywane wartosci
  delay(10);                      // poczekaj 10 ms dla stabilzacji ukladu
  
}
