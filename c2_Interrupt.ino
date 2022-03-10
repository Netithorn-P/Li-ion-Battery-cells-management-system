//////////////////////////////////////////////////////////////////////////////////// External Interrupt (Switch) ///////////////////////////////////////////////////////////////////////////////////////
  
void sw1() // pin2
{
  static unsigned long last_interrupt_time_1 = 0;        // switch debouncing
  unsigned long interrupt_time_1 = millis();
 
  if (interrupt_time_1 - last_interrupt_time_1 > 200)
   {
    userInterface_control_sw1();
    
    //Serial.print("status : K1 >> ");       // interrupt debug
    //Serial.println(sw_k1);
   }
   
  last_interrupt_time_1 = interrupt_time_1;
}

void sw2() // pin3
{
  static unsigned long last_interrupt_time_2 = 0;        // switch debouncing
  unsigned long interrupt_time_2 = millis();
 
  if (interrupt_time_2 - last_interrupt_time_2 > 200)
   {
    userInterface_control_sw2();
    
    //Serial.print("status : K2 >> ");       // interrupt debug
    //Serial.println(sw_k2);
   }
   
  last_interrupt_time_2 = interrupt_time_2;
}

void sw3() // pin19
{
  static unsigned long last_interrupt_time_3 = 0;        // switch debouncing
  unsigned long interrupt_time_3 = millis();
 
  if (interrupt_time_3 - last_interrupt_time_3 > 200)
   {
    userInterface_control_sw3();
  
    //Serial.print("status : K3 >> ");       // interrupt debug
    //Serial.println(sw_k3);
   }
   
  last_interrupt_time_3 = interrupt_time_3;
}

void sw4() // pin18
{
  static unsigned long last_interrupt_time_4 = 0;        // switch debouncing
  unsigned long interrupt_time_4 = millis();
 
  if (interrupt_time_4 - last_interrupt_time_4 > 200)
   {
    userInterface_control_sw4();
    
    //Serial.print("status : K4 >> ");   // interrupt debug
    //Serial.println(sw_k4);
   }
   
  last_interrupt_time_4 = interrupt_time_4;
}

void userInterface_control_sw1() //Interrupt sub function for sw1
{
  if(page_status == 1) //go to start balance
  {
    page_status = 2 ;
  }
  
  else if(page_status == 2) 
  {
    
  }
  
  else if(page_status == 3) 
  {
    
  }

  else if(page_status == 4) 
  {
    inBal_Source = !inBal_Source ;
  }
}

void userInterface_control_sw2() //Interrupt sub function for sw2
{
  if(page_status == 1) //go to check cell status 
  {
    page_status = 3 ;
  }
  
  else if(page_status == 2)
  {
    
  }
  
  else if(page_status == 3)
  {
    
  }

  else if(page_status == 4)
  {
    acpVol_50 = !acpVol_50;
    
    if(acpVol_50 == true)
    {
      volt_diff = 0.05 ;
    }
    else if(acpVol_50 == false)
    {
      volt_diff = 0.01 ;
    }
  }
}

void userInterface_control_sw3() //Interrupt sub function for sw3
{
  if(page_status == 1) //go to system configuration
  {
    page_status = 4 ;
  }
  
  else if(page_status == 2)
  {
    
  }
  
  else if(page_status == 3)
  {
    
  }

  else if(page_status == 4)
  {
    op_mode_bal = !op_mode_bal ;
  }
}

void userInterface_control_sw4() //Interrupt sub function for sw4
{
  if(page_status == 1) // unknow
  {
    
  }
  
  else if(page_status == 2)
  {
    deactivate_balancing() ;
    deactivate_discharge() ;
    page_status = 1 ;
    bal_count = 0 ;
    dis_count = 0 ;
  }
  
  else if(page_status == 3)
  {
    deactivate_balancing() ; 
    deactivate_discharge() ;
    page_status = 1 ;
  }

  else if(page_status == 4)
  {
    deactivate_balancing() ;
    deactivate_discharge() ;
    page_status = 1 ;
  }
  
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
