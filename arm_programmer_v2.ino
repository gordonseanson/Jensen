#include <Servo.h>
#include <enhancedServo.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Pin numbers
int SAVE = 37;
float PROGRAM = 35;
float PLAYPAUSE = 33;
// Delay between each while() loop
float delay_us = 1;
// Error margin for each move
int errorMargin = 4;
// Number of frames with moves
float actualFrames;

// Array for saving each position
int frames = 100;
int positionArray[100][6] = {
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0}
};

//enhancedServo::enhancedServo(
//  Adafruit_PWMServoDriver _pwm, 
//  0  String _name, 
//  1  uint8_t _feed_pin, 
//  2  uint8_t _pot_pin,
//  3  uint8_t _pot_reference_pin, 
//  4  uint8_t _write_pin, 
//  5  double _write_min, 
//  6  double _write_max, 
//  7  int _feed_min,
//  8  int _feed_max,
//  9  double _Ki, 
//  10 double _alpha, 
//  11 double _errorMargin) {
//                           0          1    2    3    4  5    6    7    8    9      10     11
enhancedServo base(pwm,     "Base",     A0,  A1,  A2,  0, 135, 500, 127, 860, 0.005, 0.02, 3, false);
enhancedServo shoulder(pwm, "Shoulder", A3,  A4,  A5,  1, 170, 500, 158, 807, 0.005, 0.02, errorMargin, false);
enhancedServo elbow(pwm,    "Elbow",    A6,  A7,  A8,  2, 150, 470, 140, 770, 0.005, 0.02, errorMargin, false);
enhancedServo wrist(pwm,    "Wrist",    A9,  A10, A11, 3, 135, 500, 118, 844, 0.005, 0.02, errorMargin, false);
enhancedServo rotation(pwm, "Rotation", A12, A13, A14, 4, 150, 450, 117, 965, 0.005, 0.02, errorMargin, false);
enhancedServo gripper(pwm,  "Gripper",  A15, A13, A14, 5, 290, 390, 248, 332, 0.01, 0.02, 13, true);

void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  
  Serial.begin(2000000);
  pinMode(SAVE, INPUT);
  pinMode(PROGRAM, INPUT);
  pinMode(PLAYPAUSE, INPUT);
  setupInitializer();
  preInitializer();
  loopInitializer();
  while(!isArrived()) {
      base.computePath(480);
      shoulder.computePath(740);
      elbow.computePath(490);
      wrist.computePath(140);
      rotation.computePath(585);
      gripper.computePath(322);
      delayMicroseconds(delay_us);
  }
}

// Main loop; can select various methods with the physical buttons
void loop() {
  // Skips method without these loops
  while (digitalRead(PROGRAM) == HIGH) {
  }
  while (digitalRead(SAVE) == HIGH) {
  }
  while (digitalRead(PLAYPAUSE) == HIGH) {
  }
  // Beginning message and branching logic depending on button pressed
  Serial.print("Standby!\n");
  char button = 'x';
  bool standby = true;
  while (standby) {
    feedbackRefresh();
    if (digitalRead(PROGRAM) == HIGH) {
      button = 'c';
      standby = false;
    }
    if (digitalRead(PLAYPAUSE) == HIGH) {
      button = 'p';
      standby = false;
    }
  }
  switch (button) {
    case 'c':
      Serial.print("Programming Mode!\n");
      program();
      break;
    case 'p':
      Serial.print("Playback Mode!\n");
      while(digitalRead(PLAYPAUSE) == HIGH) {
      }
      while(digitalRead(PLAYPAUSE) == LOW) {
      playback();
      }
      break;
    default:
      break;
  }
}

void setupInitializer() {
  base.setupInitializer();
  shoulder.setupInitializer();
  elbow.setupInitializer();
  wrist.setupInitializer();
  rotation.setupInitializer();
  gripper.setupInitializer();
}

// Delegates all servo attachments
void attach() {
  base.attach();
  shoulder.attach();
  elbow.attach();
  wrist.attach();
  rotation.attach();
  gripper.attach();
}

// Delegates all servo detachments
void detach() {
  base.detach();
  shoulder.detach();
  elbow.detach();
  wrist.detach();
  rotation.detach();
  gripper.detach();
}

// Delegates all pre-initializers
void preInitializer() {
  base.preInitializer();
  shoulder.preInitializer();
  elbow.preInitializer();
  wrist.preInitializer();
  rotation.preInitializer();
  gripper.preInitializer();
}

// Delegates all loop initializers
void loopInitializer() {
  base.loopInitializer();
  shoulder.loopInitializer();
  elbow.loopInitializer();
  wrist.loopInitializer();
  rotation.loopInitializer();
  gripper.loopInitializer();
}

// Delegates all path compute methods
void computePath(int i) {
  base.computePath(positionArray[i][0]);
  shoulder.computePath(positionArray[i][1]);
  elbow.computePath(positionArray[i][2]);
  wrist.computePath(positionArray[i][3]);
  rotation.computePath(positionArray[i][4]);
  gripper.computePath(positionArray[i][5]);
}

// Delegates saving each servo's position
void savePositions(int i) {
  positionArray[i][0] = base.getFeedback();
  positionArray[i][1] = shoulder.getFeedback();
  positionArray[i][2] = elbow.getFeedback();
  positionArray[i][3] = wrist.getFeedback();
  positionArray[i][4] = rotation.getFeedback();
  positionArray[i][5] = gripper.getFeedback();
}

void feedbackRefresh() {
  base.getFeedback();
  shoulder.getFeedback();
  elbow.getFeedback();
  wrist.getFeedback();
  rotation.getFeedback();
  gripper.getFeedback();
}

// Returns true if all servos have arrived at their respective positions
boolean isArrived() {
  if (true) {
//    Serial.print(base.getArrived()); Serial.print(" "); Serial.print(base.getFeedback()); Serial.print(" ");
//    Serial.print(shoulder.getArrived()); Serial.print(" ");
//    Serial.print(elbow.getArrived()); Serial.print(" ");
//    Serial.print(wrist.getArrived()); Serial.print(" ");
//    Serial.print(rotation.getArrived()); Serial.print(" ");
//    Serial.print(gripper.getArrived()); Serial.println(" ");
  }
  if (
    base.getArrived() && 
    shoulder.getArrived() && 
    elbow.getArrived() && 
    wrist.getArrived() && 
    rotation.getArrived() && 
    gripper.getArrived()
    ) {
    return true;
  } else {
    return false;
  }
}

// Cycles through saved arm positions
void playback() {
  // Skips method without this loop
  while (digitalRead(PLAYPAUSE) == HIGH) {
  }
  
  // Count number of arm positions
  actualFrames = 0;
  for (int i = 0; i < frames; i++) {
    if (positionArray[i][0] != 0) {
      actualFrames++;
    }
  }

  // Initializes the integral as the pwm output for where the servo already is
  preInitializer();
  // Connects all servos
  attach();
  boolean playing = true;
  // Each for() loop represents one "move" to a arm position
  for (int i = 0; i < actualFrames; i++) {
    // Initializes the arrival conditions as false before each move
    loopInitializer();
    // While the arrival conditions are false, calculates error correction output for each servo
    while(!isArrived()) {
      if (digitalRead(PLAYPAUSE) == HIGH) {
        playing = false;
        break;
      }
      computePath(i);      
      delayMicroseconds(delay_us);
    }
    if (!playing) break;
    Serial.print("Move "); Serial.print(i+1); Serial.print(" completed!"); Serial.print("\n");
  }
}



// "Programs" the robot arm by saving an array of positions. Each position is a "frame."
void program() {
  // Will skip this method without this loop
  while (digitalRead(PROGRAM) == HIGH) {
  }
  // Set all frames to 0
  for (int i = 0; i < frames; i++) {
    for (int j = 0; j < 2; j++) {
      positionArray[i][j] = 0;
    }
  }
  // Assigns values to the array in sequential order
  boolean programming_mode = true;
  detach();
  for (int i = 0; i < frames; i++) {
    //  Exits programming mode when the "Program" button is pressed again
    if (programming_mode == false) {
      break;
    }

    // Will skip without this loop
    while (programming_mode && digitalRead(SAVE) == HIGH) {
    }
    delay(200);

    //  Waits until "Save" or "Program" is pressed
    bool waiting = true;
    while (waiting) {
      feedbackRefresh();
//      Serial.print(base.getFeedback()); Serial.print(" ");
//      Serial.print(shoulder.getFeedback()); Serial.print(" ");
//      Serial.print(elbow.getFeedback()); Serial.print(" ");
//      Serial.print(wrist.getFeedback()); Serial.print(" ");
//      Serial.print(rotation.getFeedback()); Serial.print(" ");
//      Serial.print(gripper.getFeedback()); Serial.println(" ");
      // If "Program" is pressed while in programming mode, the positions are saved and programming mode is exited
      if (digitalRead(PROGRAM) == HIGH) {
        programming_mode = false;
        waiting = false;
      }

      // If "Save" is pressed, feed from the servo is converted to microseconds for the same position, then saved
      if (digitalRead(SAVE) == HIGH) {
        while (digitalRead(PROGRAM)==HIGH) {}
        //Serial.print("beep boop"); Serial.print("\n");
        savePositions(i);
        Serial.print("Saved!\n");
        waiting = false;
      }
    }
  }

  Serial.print("Program Saved!\n");
  int baseF = base.getFeedback();
  int shoulderF = shoulder.getFeedback();
  int elbowF = elbow.getFeedback();
  int wristF = wrist.getFeedback();
  int rotationF = rotation.getFeedback();
  int gripperF = gripper.getFeedback();
  preInitializer();
  loopInitializer();
  while(!isArrived()) {
      base.computePath(baseF);
      shoulder.computePath(shoulderF);
      elbow.computePath(elbowF);
      wrist.computePath(wristF);
      rotation.computePath(rotationF);
      gripper.computePath(gripperF);
      delayMicroseconds(delay_us);
  }
  // Count number of frames
  float actualFrames = 0;
  for (int i = 0; i < frames; i++) {
    if (positionArray[i][0] != 0) {
      actualFrames++;
    }
  }

//  attach();
//  while(!isArrived()) {
//      computePath(actualFrames-1);
//      delay(delay_ms);
//  }

  // Prints saved positions
  for (int i = 0; i < actualFrames; i++) {
    Serial.print("Position "); Serial.print(i + 1); 
    Serial.print(" feedback: "); 
    Serial.print(positionArray[i][0]); Serial.print(" "); 
    Serial.print(positionArray[i][1]); Serial.print(" "); 
    Serial.print(positionArray[i][2]); Serial.print(" "); 
    Serial.print(positionArray[i][3]); Serial.print(" ");
    Serial.print(positionArray[i][4]); Serial.print(" ");
    Serial.println(positionArray[i][5]);
  }
}


float rangeMap(float a, float b, float c, float d, float input) {
  // Takes an input between a and b and linearly maps the output between c and d
  float x = 0;
  if (input > b) {
    x = b;
  } else if (input < a) {
    x = a;
  } else {
    x = input;
  }
  float value = (c * (1 - ((x - a) / (b - a)))) + (d * ((x - a) / (b - a)));
  return value;
}
