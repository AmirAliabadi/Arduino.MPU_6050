
void log_data(float va, float vc)
{
    Serial.print(thrust, 4);
    Serial.print("\t");
    Serial.print(input_ypr[AC], 2);
    Serial.print("\t");
    Serial.print(setpoint_ac);
    Serial.print("\t");    
    Serial.print(output_ac, 2);
    Serial.print("\t");
    Serial.print(va, 4);
    Serial.print("\t");
    Serial.print(vc, 4);
    Serial.print("\t");
    Serial.print(ac_pid.pterm);
    Serial.print("\t");
    Serial.print(ac_pid.iterm);
    Serial.print("\t");
    Serial.print(ac_pid.dterm);
    Serial.print("\n");  
}

