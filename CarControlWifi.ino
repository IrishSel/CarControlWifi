#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(0, 1);

int m_Right1 = 4;       // Правый
int m_Right2 = 5;

int m_Left1 = 6;        // Левый 
int m_Left2 = 7;

int control;               // двигатели
int m_Speed;            // скорость

void setup() {
  pinMode (m_Right1, OUTPUT);
  pinMode (m_Right2, OUTPUT);

  pinMode (m_Left1, OUTPUT);
  pinMode (m_Left2, OUTPUT);

  Serial.begin(115200);
  mySerial.begin(115200);
}

void stop()
{
  digitalWrite (m_Left2, HIGH);
  analogWrite (m_Left1, 0);
  digitalWrite (m_Right1, HIGH);
  analogWrite (m_Right2, 0);
}

void forward()
{
  digitalWrite (m_Left2, HIGH);
  analogWrite (m_Left1, 250);
  digitalWrite (m_Right1, HIGH);
  analogWrite (m_Right2, 250);
}

void backward()
{
  digitalWrite (m_Left2, LOW);
  analogWrite (m_Left1, 250);
  digitalWrite (m_Right1, LOW);
  analogWrite (m_Right2, 250);
}

void right()
{
    digitalWrite (m_Left2, HIGH);
    analogWrite (m_Left1, 250);
    digitalWrite (m_Right1, HIGH);
    analogWrite (m_Right2, 0);
}

void left()
{
    digitalWrite (m_Left2, HIGH);
    analogWrite (m_Left1, 0);
    digitalWrite (m_Right1, HIGH);
    analogWrite (m_Right2, 250);
}

void loop()
{
  if (mySerial.available() > 0)
  {

    byte message = Serial.read();
    mySerial.println(message);

    if (message == 's')
    {
      stop();
    }
    else if (message == 'f')
    {
      forward();
    }
    else if (message == 'b')
    {
      backward();
    }
    else if (message == 'r')
    {
      right();
    }
    else if (message == 'l')
    {
      left();
    }
  }
}
