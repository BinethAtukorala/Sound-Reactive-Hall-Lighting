int sound = A0;

int R = 3, r = 0;
int G = 5, g = 0;
int B = 6, b = 255;

char curLight = 'r';

void setup() {

  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  analogWrite(B, 255);
  analogWrite(R, 255);
  Serial.begin(9600);   
}

void loop() {

  while (1) { 
    Serial.println(analogRead(sound));
    if(analogRead(sound) > 46){
      b=200;
      analogWrite(B, b);
      
    }
    else{
      if(b<255){
      b+=1;}else{b=255;}
      analogWrite(B, b);
      delay(1);
    }
    if (analogRead(sound) > 48) {
      r=0;
      analogWrite(G, r);
//      out(255);
      delay(45);
    }
    else {
      if(r<255){
      r+=5;}else{r=255;}
      analogWrite(G, r);
//        out(0);
      delay(1);
    }

  }
//    while(1){
//    Serial.println(curLight);
//    colourChange();
//    out(100);
//    delay(100);}
}

void colourChange() {
  if (curLight == 'r') {
    r += 5;
    b -= 5;
    g=0;
    if (r == 255) {
      curLight = 'g';
    }
  }
  else if (curLight == 'g') {
    g += 5;
    r -= 5;
    b=0;
    if (g == 255) {
      curLight == 'b';
    }
  }
  else if (curLight == 'b') {
    b += 5;
    g -= 5;
    r=0;
    if (b == 255) {
      curLight == 'r';
    }
  }

}

void out(int brightness) 
  {

    analogWrite(R, 255 - r);
    analogWrite(G, 255 - g);
    analogWrite(B, 255 - b);

  }

