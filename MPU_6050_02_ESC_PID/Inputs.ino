
boolean readCsvToVector(float* pidVector) 
{
  byte len;
  if (Serial.available() <= 0)
    return 0;
    
  len = Serial.available();
  
  char stream[20];
  char number[5];
  
  // Read the message
  for (byte i = 0; i < len; ++i) {
    stream[i] = Serial.read();
  }
  
  byte i = 0, j = 0, k = 0;
  while ( i < len ) {
    while (stream[i] != ',' && i < len) {
      number[j] = stream[i];
      ++i;
      ++j;
    }
    ++i;
    number[j] = '\0';
    j = 0;
    pidVector[k++] = atof(number);
  }
  return 1;
}

//////////////////////////////////////////////////////////////////////
// POT Inputs
//////////////////////////////////////////////////////////////////////
float read_throttle()
{
  return input_values[0];
  
  float foo = map(analogRead(THROTTLE_PIN), 0.0, 668.0, 0.0, 400.0);

  return (float)( (int) (((foo * 10.0)+.5)/10.0));
}

double read_kp()
{
  return input_values[1];
  
  double foo = map(analogRead(Kp_PIN), 0.0, 644.0, 0.0, 10000.0);
  foo = foo / 1000.0;
  foo = (double)( (int)((foo * 100.0)+.5) / 100.0 );
  return foo;
}
double read_ki()
{
  return input_values[2];
  
  double foo = map(analogRead(Ki_PIN), 0.0, 644.0, 0.0, 10000.0);
  foo = foo / 2000.0;
  foo = (double)( (int)((foo * 100.0)+.5) / 100.0 );
  return foo;
}
double read_kd()
{
  return input_values[3];
  
  double foo = map(analogRead(Kd_PIN), 0.0, 668.0, 0.0, 10000.0);
  foo = foo / 1000.0;
  foo = (double)( (int)((foo * 100.0)+.5) / 100.0 );  
  return foo;
}
///////////////////////////////////////////////////////////////////////
