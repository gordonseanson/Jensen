#include <Servo.h>
#include <enhancedServo.h>

// Pin numbers
int SAVE = 13;
float PROGRAM = 12;
float PLAYPAUSE = 8;
// Delay between each while() loop
float delay_ms = 2.5;
// Error margin for each move
int errorMargin = 7;
// Number of frames with moves
float actualFrames;

// Array for saving each position
int frames = 15;
int positionArray[15][4] = {
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
};

// enhancedServo(char _name, Servo _servo, int _feed_pin, int _feed_min, int _feed_max, int _write_pin, int _write_min, int _write_max, double _Ki_neg, double _Ki_pos, double _alpha, int _errorMargin)
Servo _base;
enhancedServo base('b', _base, A0, 96, 374, 9, 560, 2300, 0.024, 0.01, 11);
Servo _shoulder;
enhancedServo shoulder('s', _shoulder, A1, 87, 310, 11, 630, 2100, 0.028, 0.01, 15);
Servo _elbow;
enhancedServo elbow('e', _elbow, A2, 100, 369, 10, 600, 2200, 0.021, 0.017, errorMargin);
Servo _wrist;
enhancedServo wrist('w', _wrist, A3, 92, 395, 6, 550, 2350, 0.03, 0.02, errorMargin);

void setup() {
  Serial.begin(57600);
  pinMode(SAVE, INPUT);
  pinMode(PROGRAM, INPUT);
  pinMode(PLAYPAUSE, INPUT);
}

// Main loop; can select various methods with the physical buttons
void loop() {
  // Skips method without these loops
  while (digitalRead(PROGRAM) == HIGH) {
  }
  while (digitalRead(SAVE) == HIGH) {
  }
  // Beginning message and branching logic depending on button pressed
  Serial.print("Standby!"); Serial.print("\n");
  char button = 'x';
  bool standby = true;
  while (standby) {
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
      Serial.print("Programming Mode!"); Serial.print("\n");
      program();
      break;
    case 'p':
      Serial.print("Playback Mode!"); Serial.print("\n");
      playback();
      break;
    default:
      break;
  }
}

// Delegates all servo attachments
void attach() {
  base.attach();
  shoulder.attach();
  elbow.attach();
  wrist.attach();
}

// Delegates all servo detachments
void detach() {
  base.detach();
  shoulder.detach();
  elbow.detach();
  wrist.detach();
}

// Delegates all pre-initializers
void preInitializer() {
  base.preInitializer();
  shoulder.preInitializer();
  elbow.preInitializer();
  wrist.preInitializer();
}

// Delegates all loop initializers
void loopInitializer() {
  base.loopInitializer();
  shoulder.loopInitializer();
  elbow.loopInitializer();
  wrist.loopInitializer();
}

// Delegates all path compute methods
void computePath(int i) {
  base.computePath(positionArray[i][0]);
  shoulder.computePath(positionArray[i][1]);
  elbow.computePath(positionArray[i][2]);
  wrist.computePath(positionArray[i][3]);
}

// Returns true if all servos have arrived at their respective positions
boolean isArrived() {
  if (base.getArrived() && shoulder.getArrived() && elbow.getArrived() && wrist.getArrived()) {
    return true;
  } else {
    return false;
  }
  Serial.print("Base arrival: "); Serial.print(base.getArrived()); Serial.print(" Shoulder arrival: "); Serial.print(shoulder.getArrived()); Serial.print(" Elbow arrival: "); Serial.print(elbow.getArrived()); Serial.print(" Wrist arrival: "); Serial.print(wrist.getArrived()); Serial.print("\n");
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
  // Each for() loop represents one "move" to a arm position
  for (int i = 0; i < actualFrames; i++) {
    // Initializes the arrival conditions as false before each move
    loopInitializer();
    // While the arrival conditions are false, calculates error correction output for each servo
    while(!isArrived()) {
      computePath(i);
      delay(delay_ms);
    }
    Serial.print("Move "); Serial.print(i+1); Serial.print(" completed!"); Serial.print("\n");
  }
  detach();
}

// Delegates saving each servo's position
void savePositions(int i) {
  preInitializer();
  positionArray[i][0] = base.getFeedback();
  positionArray[i][1] = shoulder.getFeedback();
  positionArray[i][2] = elbow.getFeedback();
  positionArray[i][3] = wrist.getFeedback();
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
  for (int i = 0; i < frames; i++) {
    //  Exits programming mode when the "Program" button is pressed again
    if (programming_mode == false) {
      break;
    }

    // Will skip without this loop
    while (programming_mode && digitalRead(SAVE) == HIGH) {
    }
    delay(500);

    //  Waits until "Save" or "Program" is pressed
    bool waiting = true;
    while (waiting) {
      // If "Program" is pressed while in programming mode, the positions are saved and programming mode is exited
      if (digitalRead(PROGRAM) == HIGH) {
        programming_mode = false;
        waiting = false;
      }

      // If "Save" is pressed, feed from the servo is converted to microseconds for the same position, then saved
      if (digitalRead(SAVE) == HIGH) {
        //Serial.print("beep boop"); Serial.print("\n");
        savePositions(i);
        Serial.print("Saved!"); Serial.print("\n");
        waiting = false;
      }
    }
  }

  Serial.print("Program Saved!"); Serial.print("\n");
  // Count number of frames
  float actualFrames = 0;
  for (int i = 0; i < frames; i++) {
    if (positionArray[i][0] != 0) {
      actualFrames++;
    }
  }

  // Prints saved positions
  for (int i = 0; i < actualFrames; i++) {
    Serial.print("Position "); Serial.print(i + 1); Serial.print(" feedback: "); Serial.print(positionArray[i][0]); Serial.print(" "); Serial.print(positionArray[i][1]); Serial.print(" "); Serial.print(positionArray[i][2]); Serial.print(" "); Serial.print(positionArray[i][3]); (Serial.print("\n"));
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
