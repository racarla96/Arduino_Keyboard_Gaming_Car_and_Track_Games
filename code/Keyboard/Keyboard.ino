#define DEBUG false

#if !DEBUG
#include <Keyboard.h>
#endif

#define BT1_R A0
#define BT1_L A1
#define BT2_R A3
#define BT2_L A2
#define BT3_R A5
#define BT3_L A4
#define BT4 3
#define BT5 2
#define BT6 12
#define BT7 10
#define BT8 11
#define BT9 4

#define BT1_LED 13
#define BT2_LED 9
#define BT3_LED 7

#define BT1_R_KEY 'p'
#define BT1_L_KEY 'o'
#define BT2_R_KEY 'i'
#define BT2_L_KEY 'u'
#define BT3_R_KEY 'y'
#define BT3_L_KEY 't'
#define BT4_KEY 'r'
#define BT5_KEY 'e'
#define BT6_KEY 'l'
#define BT7_KEY 'k'
#define BT8_KEY 'j'
#define BT9_KEY 'm'

int BT1_R_State = LOW;
int BT1_L_State = LOW;
int BT2_R_State = LOW;
int BT2_L_State = LOW;
int BT3_R_State = LOW;
int BT3_L_State = LOW;
int BT4_State = LOW;
int BT5_State = LOW;
int BT6_State = LOW;
int BT7_State = LOW;
int BT8_State = LOW;
int BT9_State = LOW;

int BT1_R_State_prev = LOW;
int BT1_L_State_prev = LOW;
int BT2_R_State_prev = LOW;
int BT2_L_State_prev = LOW;
int BT3_R_State_prev = LOW;
int BT3_L_State_prev = LOW;
int BT4_State_prev = LOW;
int BT5_State_prev = LOW;
int BT6_State_prev = LOW;
int BT7_State_prev = LOW;
int BT8_State_prev = LOW;
int BT9_State_prev = LOW;

int BT1_LED_State = LOW;
int BT2_LED_State = LOW;
int BT3_LED_State = LOW;

const unsigned long FPS = 30; // Hz
const unsigned long period_ms = 1000/FPS;
unsigned long next_period_ms, current_time_ms;

void setup() {
#if DEBUG
  Serial.begin(115200);
#else
  Keyboard.begin();
#endif

  pinMode(BT1_R, INPUT);
  pinMode(BT1_L, INPUT);
  pinMode(BT2_R, INPUT);
  pinMode(BT2_L, INPUT);
  pinMode(BT3_R, INPUT);
  pinMode(BT3_L, INPUT);
  pinMode(BT4, INPUT);
  pinMode(BT5, INPUT);
  pinMode(BT6, INPUT);
  pinMode(BT7, INPUT);
  pinMode(BT8, INPUT);
  pinMode(BT9, INPUT);

  pinMode(BT1_LED, OUTPUT);
  pinMode(BT2_LED, OUTPUT);
  pinMode(BT3_LED, OUTPUT);

  update_BTNS_States();
  
  BT1_R_State_prev = BT1_R_State; 
  BT1_L_State_prev = BT1_L_State; 
  BT2_R_State_prev = BT2_R_State; 
  BT2_L_State_prev = BT2_L_State; 
  BT3_R_State_prev = BT3_R_State; 
  BT3_L_State_prev = BT3_L_State;
  BT4_State_prev = BT4_State; 
  BT5_State_prev = BT5_State; 
  BT6_State_prev = BT6_State; 
  BT7_State_prev = BT7_State; 
  BT8_State_prev = BT8_State; 
  BT9_State_prev = BT9_State; 

  update_LEDS_States();
  
  current_time_ms = millis();
  next_period_ms = current_time_ms + period_ms;
}

void loop() {
  update_BTNS_States();
  update_LEDS_States();
#if !DEBUG
  Keyboard.releaseAll();
  press_keys();
#endif

#if DEBUG
//  Serial.print("PERIOD ms: ");
  Serial.print(period_ms);

//  Serial.print("BUTTONS: ");
    
  Serial.print(" ");
//  Serial.print("BT1_R: ");
  Serial.print(BT1_R_State);
  Serial.print(" ");
//  Serial.print("BT1_L: ");
  Serial.print(BT1_L_State);

  Serial.print(" ");
//  Serial.print("BT2_R: ");
  Serial.print(BT2_R_State);
  Serial.print(" ");
//  Serial.print("BT2_L: ");
  Serial.print(BT2_L_State);

  Serial.print(" ");
//  Serial.print("BT3_R: ");
  Serial.print(BT3_R_State);
  Serial.print(" ");
//  Serial.print("BT3_L: ");
  Serial.print(BT3_L_State);

  Serial.print(" ");
//  Serial.print("BT4: ");
  Serial.print(BT4_State);

  Serial.print(" ");
//  Serial.print("BT5: ");
  Serial.print(BT5_State);

  Serial.print(" ");
//  Serial.print("BT6: ");
  Serial.print(BT6_State);

  Serial.print(" ");
//  Serial.print("BT7: ");
  Serial.print(BT7_State);

  Serial.print(" ");
//  Serial.print("BT8: ");
  Serial.print(BT8_State);

  Serial.print(" ");
//  Serial.print("BT9: ");
  Serial.print(BT9_State);
  
  Serial.println();
#endif

  current_time_ms = millis();
  while(current_time_ms < next_period_ms) current_time_ms = millis();
  next_period_ms = next_period_ms + period_ms;
}

void update_BTNS_States(){
  BT1_R_State_prev = BT1_R_State; 
  BT1_L_State_prev = BT1_L_State; 
  BT2_R_State_prev = BT2_R_State; 
  BT2_L_State_prev = BT2_L_State; 
  BT3_R_State_prev = BT3_R_State; 
  BT3_L_State_prev = BT3_L_State;
  BT4_State_prev = BT4_State; 
  BT5_State_prev = BT5_State; 
  BT6_State_prev = BT6_State; 
  BT7_State_prev = BT7_State; 
  BT8_State_prev = BT8_State; 
  BT9_State_prev = BT9_State;
  BT1_R_State = digitalRead(BT1_R);
  BT1_L_State = digitalRead(BT1_L);
  BT2_R_State = digitalRead(BT2_R);
  BT2_L_State = digitalRead(BT2_L);
  BT3_R_State = digitalRead(BT3_R);
  BT3_L_State = digitalRead(BT3_L);
  BT4_State = digitalRead(BT4);
  BT5_State = digitalRead(BT5);
  BT6_State = digitalRead(BT6);
  BT7_State = digitalRead(BT7);
  BT8_State = digitalRead(BT8);
  BT9_State = digitalRead(BT9);
}

void update_LEDS_States(){
  if(!BT1_LED_State && (BT1_R_State || BT1_L_State)) {digitalWrite(BT1_LED, HIGH); BT1_LED_State = HIGH;}
  else if(BT1_LED_State && !BT1_R_State && !BT1_L_State) {digitalWrite(BT1_LED, LOW); BT1_LED_State = LOW;}

  if(!BT2_LED_State && (BT2_R_State || BT2_L_State)) {digitalWrite(BT2_LED, HIGH); BT2_LED_State = HIGH;}
  else if(BT2_LED_State && !BT2_R_State && !BT2_L_State) {digitalWrite(BT2_LED, LOW); BT2_LED_State = LOW;}

  if(!BT3_LED_State && (BT3_R_State || BT3_L_State)) {digitalWrite(BT3_LED, HIGH); BT3_LED_State = HIGH;}
  else if(BT3_LED_State && !BT3_R_State && !BT3_L_State) {digitalWrite(BT3_LED, LOW); BT3_LED_State = LOW;}
}

#if !DEBUG
void press_keys(){
  if(BT1_R_State_prev != BT1_R_State) Keyboard.press(BT1_R_KEY);
  if(BT1_L_State_prev != BT1_L_State) Keyboard.press(BT1_L_KEY);
  if(BT2_R_State_prev != BT2_R_State) Keyboard.press(BT2_R_KEY);
  if(BT2_L_State_prev != BT2_L_State) Keyboard.press(BT2_L_KEY);
  if(BT3_R_State_prev != BT3_R_State) Keyboard.press(BT3_R_KEY);
  if(BT3_L_State_prev != BT3_L_State) Keyboard.press(BT3_L_KEY);
  if(BT4_State_prev != BT4_State) Keyboard.press(BT4_KEY);
  if(BT5_State_prev != BT5_State) Keyboard.press(BT5_KEY);
  if(BT6_State_prev != BT6_State) Keyboard.press(BT6_KEY);
  if(BT7_State_prev != BT7_State) Keyboard.press(BT7_KEY);
  if(BT8_State_prev != BT8_State) Keyboard.press(BT8_KEY);
  if(BT9_State_prev != BT9_State) Keyboard.press(BT9_KEY);
}
#endif
