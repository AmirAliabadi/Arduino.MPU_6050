#ifdef DEBUG 

/********************************************
 * Serial Communication functions / helpers
 ********************************************/

union _from_processing { 
  byte asBytes[8];    
  float asFloat[2];   
}                    
from_processing; 


void SerialReceive()
{
  Serial.readBytes( from_processing.asBytes, 8 );

  int cmd = (int)from_processing.asFloat[0];
  if( cmd <= 13 ) {
    input_values[ cmd ] = from_processing.asFloat[1] ;
    
  } else {
    if(cmd == 100) {
      aserial_data_mode = (int)from_processing.asFloat[1];
            
    } else if (cmd == 101) {
      
    } else if (cmd == 102) {
      
    }
  }

  Serial.flush();  
}


void SerialSend_YAW()
{
// PID _ setpoint _ input_gyro _ input_angle  _ output_angle _ output_gyro _ pid.p _ pid.i _ pid.d _ rat.p _ rat.i _ rat.d _ man/auto _ dir/inder

  Serial.print(F("S "));  
  Serial.print(selected_pot_tuning);
  Serial.print(F("_"));
  Serial.print(aserial_data_mode);
  Serial.print(F(" "));

  Serial.print(INPUT_THRUST);  
  Serial.print(F(" "));
  
/////////////////////////////
// INPUTS
  Serial.print(setpoint[YW]);   
  Serial.print(F(" "));
  Serial.print(input_gyro[YW]);   
  Serial.print(F(" "));
  Serial.print(input_ypr[YW]);   
  Serial.print(F(" "));  
//
/////////////////////////////  

/////////////////////////////  
/// outputs
  Serial.print(output_ypr[YW]);   
  Serial.print(F(" "));  
  Serial.print(output_rate[YW]);   
  Serial.print(F(" "));
/////////////////////////////  

  Serial.print(pid_yw_stable.GetKp(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_yw_stable.GetKi(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_yw_stable.GetKd(), 3);   
  Serial.print(F(" "));
  
  Serial.print(pid_yw_rat.GetKp(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_yw_rat.GetKi(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_yw_rat.GetKd(), 3);   
  Serial.print(F(" "));

  
  if(pid_yw_stable.GetMode()==AUTOMATIC) Serial.print(F("Automatic"));
  else Serial.print(F("Manual"));  
  Serial.print(F(" "));
  if(pid_yw_stable.GetDirection()==DIRECT) Serial.print(F("Dir"));
  else Serial.print(F("Rev"));
  Serial.print(F(" "));
  if(pid_yw_rat.GetDirection()==DIRECT) Serial.println(F("Dir"));
  else Serial.println(F("Rev"));  

  Serial.print(F(" "));
  
  Serial.print(va); Serial.print(F(" "));
  Serial.print(vb); Serial.print(F(" "));
  Serial.print(vc); Serial.print(F(" "));
  Serial.print(vd); Serial.print(F(" "));

  Serial.println(F("E"));  
}

void SerialSend_BD()
{
// PID _ setpoint _ input_gyro _ input_angle  _ output_angle _ output_gyro _ pid.p _ pid.i _ pid.d _ rat.p _ rat.i _ rat.d _ man/auto _ dir/inder

  Serial.print(F("S "));  
  Serial.print(selected_pot_tuning);//"PID ");
  Serial.print(F("_"));
  Serial.print(aserial_data_mode);
  Serial.print(F(" "));

  Serial.print(INPUT_THRUST);  
  Serial.print(F(" "));
  
/////////////////////////////
// INPUTS
  Serial.print(setpoint[BD]);   
  Serial.print(F(" "));
  Serial.print(input_gyro[BD]);   
  Serial.print(F(" "));
  Serial.print(input_ypr[BD]);   
  Serial.print(F(" "));  
//
/////////////////////////////  

/////////////////////////////  
/// outputs
//  Serial.print(va - MIN_ESC_SIGNAL - INPUT_THRUST); //output_ypr[AC]);   
//  Serial.print(" ");  
//  Serial.print(vc - MIN_ESC_SIGNAL - INPUT_THRUST); //output_rate[AC]);   
//  Serial.print(" ");
  Serial.print(output_ypr[BD]);   
  Serial.print(F(" "));  
  Serial.print(output_rate[BD]);   
  Serial.print(F(" "));
/////////////////////////////  

  Serial.print(pid_bd_stable.GetKp(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_bd_stable.GetKi(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_bd_stable.GetKd(), 3);   
  Serial.print(F(" "));
  
  Serial.print(pid_bd_rat.GetKp(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_bd_rat.GetKi(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_bd_rat.GetKd(), 3);   
  Serial.print(F(" "));

  
  if(pid_bd_stable.GetMode()==AUTOMATIC) Serial.print(F("Automatic"));
  else Serial.print(F("Manual"));  
  Serial.print(F(" "));
  if(pid_bd_stable.GetDirection()==DIRECT) Serial.print(F("Dir"));
  else Serial.print(F("Rev"));
  Serial.print(F(" "));
  if(pid_bd_rat.GetDirection()==DIRECT) Serial.print(F("Dir"));
  else Serial.print(F("Rev")); 
  Serial.print(F(" "));
  Serial.print(va); Serial.print(F(" "));
  Serial.print(vb); Serial.print(F(" "));
  Serial.print(vc); Serial.print(F(" "));
  Serial.print(vd); Serial.print(F(" "));

  Serial.println(F("E"));  
}

void SerialSend_AC()
{
// PID _ setpoint _ input_gyro _ input_angle  _ output_angle _ output_gyro _ pid.p _ pid.i _ pid.d _ rat.p _ rat.i _ rat.d _ man/auto _ dir/inder

  Serial.print(F("S "));
  Serial.print(selected_pot_tuning);
  Serial.print(F("_"));
  Serial.print(aserial_data_mode);
  Serial.print(F(" "));

  Serial.print(INPUT_THRUST);  
  Serial.print(F(" "));
  
/////////////////////////////
// INPUTS
  Serial.print(setpoint[AC]);   
  Serial.print(F(" "));
  Serial.print(input_gyro[AC]);   
  Serial.print(F(" "));
  Serial.print(input_ypr[AC]);   
  Serial.print(F(" "));  
//
/////////////////////////////  

/////////////////////////////  
/// outputs
  Serial.print(output_ypr[AC]);   
  Serial.print(F(" "));  
  Serial.print(output_rate[AC]);   
  Serial.print(F(" "));
/////////////////////////////  

  Serial.print(pid_ac_stable.GetKp(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_ac_stable.GetKi(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_ac_stable.GetKd(), 3);   
  Serial.print(F(" "));
   
  Serial.print(pid_ac_rat.GetKp(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_ac_rat.GetKi(), 3);   
  Serial.print(F(" "));
  Serial.print(pid_ac_rat.GetKd(), 3);   
  Serial.print(F(" "));

  
  if(pid_ac_stable.GetMode()==AUTOMATIC) Serial.print(F("Automatic"));
  else Serial.print(F("Manual"));  
  Serial.print(F(" "));
  if(pid_ac_stable.GetDirection()==DIRECT) Serial.print(F("Dir"));
  else Serial.print(F("Rev"));
  Serial.print(F(" "));
  if(pid_ac_rat.GetDirection()==DIRECT) Serial.print(F("Dir"));
  else Serial.print(F("Rev"));  
  Serial.print(F(" "));
  
  Serial.print(va); Serial.print(F(" "));
  Serial.print(vb); Serial.print(F(" "));
  Serial.print(vc); Serial.print(F(" "));
  Serial.print(vd); Serial.print(F(" "));

  Serial.println(F("E"));
    
}

void log_data()
{
  if( aserial_data_mode == 0 ) SerialSend_AC();
  else if( aserial_data_mode == 1 ) SerialSend_BD();
  else if( aserial_data_mode == 2 ) SerialSend_YAW(); 
}

#endif
