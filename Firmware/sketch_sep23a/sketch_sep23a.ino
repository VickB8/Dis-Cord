#include <Keyboard.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SW1 1
#define SW2 2
#define SW3 3
#define SW4 0
#define SW5 10
#define SW6 6

#define ENCODER_A 9
#define ENCODER_B 8
#define ENCODER_BUTTON 10

#define OLED_SCL 6
#define OLED_SDA 5

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

bool discordMode = false;

bool lastSW1 = HIGH;
bool lastSW2 = HIGH;
bool lastSW3 = HIGH;
bool lastSW4 = HIGH;
bool lastSW5 = HIGH;
bool lastSW6 = HIGH;
bool lastEncoderButton = HIGH;

int lastEncoderA = HIGH;

int volumeLevel = 50;

unsigned long lastButtonTime = 0;
unsigned long lastDisplayTime = 0;

const unsigned long debounceDelay = 150;

void updateDisplay(const char *action = "") {
  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("STARDANCE");

  display.setTextSize(1);
  display.setCursor(0, 25);

  if (discordMode)
    display.println("DISCORD MODE");
  else
    display.println("NORMAL MODE");

  display.setCursor(0, 38);
  display.print("VOLUME: ");
  display.print(volumeLevel);
  display.println("%");

  if (action[0] != '\0') {
    display.setCursor(0, 52);
    display.println(action);
  }

  display.display();
}

void presskey(uint8_t key) {
  Keyboard.press(key);
  delay(40);
  Keyboard.release(key);
  delay(40);
}

void ctrlShiftKey(char key) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(key);
  delay(50);
  Keyboard.releaseAll();
  delay(50);
}

void openWindowsApp(const char *appName) {
  Keyboard.press(KEY_LEFT_GUI);
  delay(50);
  Keyboard.release(KEY_LEFT_GUI);

  delay(300);

  Keyboard.print(appName);

  delay(500);

  Keyboard.press(KEY_RETURN);
  delay(50);
  Keyboard.release(KEY_RETURN);

  delay(800);
}

void openWebsite(const char *url) {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');

  delay(100);

  Keyboard.releaseAll();

  delay(300);

  Keyboard.print(url);

  delay(100);

  Keyboard.press(KEY_RETURN);
  delay(50);
  Keyboard.release(KEY_RETURN);

  delay(800);
}

void volumeUp() {
  if (volumeLevel < 100)
    volumeLevel++;

  presskey(KEY_VOLUME);
  updateDisplay();
}

void volumeDown() {
  if (volumeLevel > 0)
    volumeLevel--;

  presskey(KEY_VOLUME);
  updateDisplay();
}

void normalSW1() {
  updateDisplay("FUSION 360");
  openWindowsApp("FUSION 360");
}

void normalSW2() {
  updateDisplay("MICROSOFT EDGE");
  openWindowsApp("Microsoft Edge");
}

void normalSW3() {
  updateDisplay("KICAD");
  openWindowsApp("KiCad");
}

void normalSW4() {
  updateDisplay("VALORANT");
  openWindowsApp("VALORANT");
}

void normalSW5() {
  updateDisplay("YOUTUBE");
  openWebsite("https://youtube.com");
}

void normalSW6() {
  updateDisplay("ARDUINO IDE");
  openWindowsApp("Arduino IDE");
}

void discordSW1() {
  updateDisplay("MUTE");
  ctrlShiftKey('m');
}

void discordSW2() {
  updateDisplay("DEAFEN");
  ctrlShiftKey('d');
}

void discordSW3() {
  updateDisplay("PUSH TO TALK");
  ctrlShiftKey('p');
}

void discordSW4() {
  updateDisplay("SCREEN SHARE");
  ctrlShiftKey('l');
}

void discordSW5() {
  updateDisplay("DISCORD OVERLAY");

  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('`');

  delay(50);

  Keyboard.releaseAll();
}

void discordSW6() {
  updateDisplay("STREAMER MODE");
  ctrlShiftKey('s');
}

void handleSW1() {
  if (discordMode)
    discordSW1();
  else
    normalSW1();
}

void handleSW2() {
  if (discordMode)
    discordSW2();
  else 
    normalSW2();
}

void handleSW3() {
  if (discordMode)
    discordSW3();
  else
    normalSW3();
}

void handleSW4() {
  if (discordMode)
    discordSW4();
  else
    normalSW4();
}

void handleSW5() {
  if (discordMode)
    discordSW5();
  else
    normalSW5();
}

void handleSW6() {
  if (discordMode)
    discordSW6();
  else
    normalSW6();
}

void handleEncoderButton() {
  discordMode = !discordMode;

  if (discordMode)
    updateDisplay("DISCORD MODE");
  else 
    updateDisplay("NORMAL MODE");

  delay(300);
}

void readEncoder() {
  int currentA = digitalRead(ENCODER_A);

  if (currentA != lastEncoderA) {
    if (currentA == LOW) {
      int currentB = digitalRead(ENCODER_B);

      if (currentB == HIGH)
        volumeUp();
      else
        volumeDown();
    }
  }

  lastEncoderA == currentA;
}

void setup() {

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  pinMode(SW5, INPUT_PULLUP);
  pinMode(SW6, INPUT_PULLUP);

  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  pinMode(ENCODER_BUTTON, INPUT_PULLUP);

  Wire.setSDA(OLED_SDA);
  Wire.setSCL(OLED_SCL);
  Wire.begin();

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);

  display.clearDisplay();
  display.display();

  Keyboard.begin();

  delay(1500);

  lastEncoderA = digitalRead(ENCODER_A);

  updateDisplay();
}

void loop() {

  bool sw1 = digitalRead(SW1);
  bool sw2 = digitalRead(SW2);
  bool sw3 = digitalRead(SW3);
  bool sw4 = digitalRead(SW4);
  bool sw5 = digitalRead(SW5);
  bool sw6 = digitalRead(SW6);

  bool encoderButton = digitalRead(ENCODER_BUTTON);

    if (sw1 == LOW && lastSW1 == HIGH &&
      millis() - lastButtonTime > debounceDelay) {

    handleSW1();
    lastButtonTime = millis();
  }

  if (sw2 == LOW && lastSW2 == HIGH &&
      millis() - lastButtonTime > debounceDelay) {

    handleSW2();
    lastButtonTime = millis();
  }

  if (sw3 == LOW && lastSW3 == HIGH &&
      millis() - lastButtonTime > debounceDelay) {

    handleSW3();
    lastButtonTime = millis();
  }

  if (sw4 == LOW && lastSW4 == HIGH &&
      millis() - lastButtonTime > debounceDelay) {

    handleSW4();
    lastButtonTime = millis();
  }

  if (sw5 == LOW && lastSW5 == HIGH &&
      millis() - lastButtonTime > debounceDelay) {

    handleSW5();
    lastButtonTime = millis();
  }

  if (sw6 == LOW && lastSW6 == HIGH &&
      millis() - lastButtonTime > debounceDelay) {

    handleSW6();
    lastButtonTime = millis();
  }

  if (encoderButton == LOW &&
      lastEncoderButton == HIGH &&
      millis() - lastButtonTime > debounceDelay) {

    handleEncoderButton();
    lastButtonTime = millis();
  }

  readEncoder();

  lastSW1 = sw1;
  lastSW2 = sw2;
  lastSW3 = sw3;
  lastSW4 = sw4;
  lastSW5 = sw5;
  lastSW6 = sw6;

  lastEncoderButton = encoderButton;

  delay(2);
}