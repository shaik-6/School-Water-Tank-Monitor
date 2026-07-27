const int sensorPin = 34;
const int greenLED = 2;
const int redLED = 4;
const int buzzer = 5;


unsigned long previousMillis = 0;
const unsigned long interval = 2000;


int samples[5] = {50,50,50,50,50};
int sampleIndex = 0;


int highCount = 0;
int lowCount = 0;


int lastAverage = -1;
int sameCount = 0;

void setup() {

  Serial.begin(115200);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);

  Serial.println("School Water Tank Monitor Started");
}

void loop() {

  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval){

    previousMillis = currentMillis;

    
    int raw = analogRead(sensorPin);

    
    Serial.print("Raw = ");
    Serial.println(raw);

    
    int level = map(raw,0,4095,0,100);

   
    if(level < 0 || level > 100){

      Serial.println("Invalid Sensor Reading");
      return;

    }

  
    samples[sampleIndex] = level;
    sampleIndex = (sampleIndex + 1) % 5;

    int sum = 0;

    for(int i=0;i<5;i++){

      sum += samples[i];

    }

    int average = sum / 5;

    Serial.print("Water Level = ");
    Serial.print(average);
    Serial.println("%");

   
    if(abs(average-lastAverage)<=1){

      sameCount++;

    }
    else{

      sameCount=0;

    }

    lastAverage=average;

    if(sameCount>=10){

      Serial.println("***************");
      Serial.println("SENSOR FAULT");
      Serial.println("***************");

      digitalWrite(redLED,HIGH);
      digitalWrite(greenLED,LOW);

      tone(buzzer,1500);

      Serial.println("--------------------------");

      return;
    }

   

    if(average>90)
      highCount++;
    else
      highCount=0;

  

    if(average<20)
      lowCount++;
    else
      lowCount=0;



    if(highCount>=3){

      Serial.println("OVERFLOW ALERT");

      digitalWrite(redLED,HIGH);
      digitalWrite(greenLED,LOW);

      tone(buzzer,1000);

    }

    else if(lowCount>=3){

      Serial.println("LOW WATER ALERT");

      digitalWrite(redLED,HIGH);
      digitalWrite(greenLED,LOW);

      tone(buzzer,700);

    }

    else{

      Serial.println("STATUS : NORMAL");

      digitalWrite(redLED,LOW);
      digitalWrite(greenLED,HIGH);

      noTone(buzzer);

    }

    Serial.println("--------------------------");

  }

}