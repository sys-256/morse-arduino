const int buttonPin = 2;


int buttonState = 0;
long lastTimeChanged = 0;

void setup() {
  pinMode(buttonPin, INPUT);	
  Serial.begin(9600);
}

void loop() {

  if(digitalRead(buttonPin) == 1){
    lastTimeChanged = millis();

    while(digitalRead(buttonPin) == 1){};


    if(millis() - lastTimeChanged < 250){
        Serial.println("Short");

      }else if(millis() - lastTimeChanged < 500){
        Serial.println("Long");

      }else if(millis() - lastTimeChanged < 2000){
        Serial.println("Space");

      }


    
  };


}
