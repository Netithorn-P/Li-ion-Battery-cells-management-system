//////////////////////////////////////////////////////////////////////////////////// System User Interface (LCD) ///////////////////////////////////////////////////////////////////////////////////////

void core_func()
{  
  volatile unsigned long lcd_disp_i = 0 ;
  
  for( lcd_disp_i ; lcd_disp_i < 4294967295  ; lcd_disp_i++)
  {
    //lcd_tbdelay(400);  // default 400
    page_check();

//    Serial.print("lcd_disp function count : ");
//    Serial.println(lcd_disp_i);
//
//     //to debug cell voltage
//    Serial.println(cell1_volt);
//    Serial.println(cell2_volt);
//    Serial.println(cell3_volt);
//    Serial.println(cell4_volt);
    
    if(lcd_disp_i >= 4294900000 )
    {
      lcd_disp_i = 0 ;
    }

  }
}
  
void lcd_system_init()
{
  // initialize the LCD,
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.clear();
  page_status = 0 ;
  
  lcd.setCursor (3, 0); //
  lcd.print("Li-ion 4 cells");
  lcd.setCursor (2, 1); //
  lcd.print("balancing system");
  
  lcd.setCursor (2, 3); //
  lcd.print("Please Wait - 3");
 
  ////////////////////////////////////* ADD INITIAL EVENT HERE *///////////////////////////////////////////////////////////
  
  delay(1000);
  lcd.setCursor (2, 3); //
  lcd.print("Please Wait - 2");

  ////////////////////////////////////* ADD INITIAL EVENT HERE *///////////////////////////////////////////////////////////
  
  delay(1000);
  lcd.setCursor (2, 3); //
  lcd.print("Please Wait - 1");

  ////////////////////////////////////* ADD INITIAL EVENT HERE *///////////////////////////////////////////////////////////
  
  delay(1000);
  
  page_status = 1 ;

  flag = true ;

}

void lcd_main()
{
  flag = false ;
  page_status = 1 ;
  
  //lcd.clear();// clearn previous values from screen
  lcd.setCursor (0, 0); 
  lcd.print("      Main menu     "); 

  lcd.setCursor (0, 1); 
  lcd.print("1:Start Operation  "); 

  lcd.setCursor (0, 2); 
  lcd.print("2:Check Cells status"); 

  lcd.setCursor (0, 3); 
  lcd.print("3:Setup System      "); 

  lcd_tbdelay(650);

  flag = true ;

}

void lcd_op()   /// 1.25 sec per loop
{
  flag = false ;
  page_status = 2 ;

  //////////////////////////////////////////////////////////////////////////////////////*balancing function here*//////////////////////////////////////////////////////////////////////////////////////

//Serial.println(balanced_stat); 

//  Serial.print("balanced_stat ; ");    //for debug
//  Serial.print(balanced_stat);         //
//  Serial.print("  |  no_voltage ; ");  //
//  Serial.println(no_voltage);          //
  
  if( (balanced_stat == false) && (no_voltage == false) && (op_mode_bal == true) )  //enable balancing if mode = bal and cells are not balanced and system have no zero voltage cell detected 
  {
    balancing();
  }
  else if( (op_mode_bal == true) && ((balanced_stat == true) || (no_voltage == true)) ) //disable balancing if mode = bal and cells are balanced and system have any zero voltage cell detected 
  {
    deactivate_balancing();
  }
  else if(op_mode_bal == false)
  {
    discharge();
  }
  
  //lcd.clear();// clearn previous values from screen
  lcd.setCursor (0, 0); //character zero, line 1
  lcd.print("  Balancing System  "); 

  lcd.setCursor (0, 1); 
  if(op_mode_bal == true)
  {
    lcd.print("   Mode : Balance   "); 
  }
  else 
  {
    lcd.print("  Mode : Discharge  "); 
  }

  //---------------------------------------------------------------------------- 1 ---------------------------------------------------------------------------------------//

  lcd.setCursor (0, 2); 
  if(no_voltage == false)
  {
    if((balanced_stat == false) && (op_mode_bal == true))
    {
      lcd.print(" Cell Balancing     "); 
   }
    else if((balanced_stat == true) && (op_mode_bal == true))
    {
      lcd.print("Cell Balancing done "); 
    }
    else if(op_mode_bal == false)
    {
      lcd.print("Cell Voltage  : ");
      lcd.setCursor (16, 2);
      lcd.print(discharge_voltage);   ////default
    }
  }
  else if(no_voltage == true)
  {
    lcd.print("0V Cell Detected");
  }
  lcd.setCursor (0, 3);

  if(op_mode_bal == true)
  {
    lcd.print("Input current :");
    lcd.setCursor (16, 3);
    lcd.print(inboost_current);   ////default 
  }
  else
  {
    //lcd.print("                    ");
    lcd.print("Dis current   :");
    lcd.setCursor (16, 3);
    lcd.print(discharge_current);   ////default  
  }
  
  //lcd.print(cell1_temp); ///dynamic var test
  
  lcd_tbdelay(200);

  //---------------------------------------------------------------------------- 2+- ---------------------------------------------------------------------------------------//
  
  lcd.setCursor (0, 2); 
  if(no_voltage == false)
  {
    if((balanced_stat == false) && (op_mode_bal == true))
    {
      lcd.print(" Cell Balancing.    "); 
    }
    else if((balanced_stat == true) && (op_mode_bal == true))
    {
      lcd.print("Cell Balancing done."); 
    }
    else if(op_mode_bal == false)
    {
      lcd.setCursor (16, 2);
      lcd.print(discharge_voltage);   ////default
    }
  }
  else if(no_voltage == true)
  {
    lcd.print("0V Cell Detected. ");
  }
  
  if(op_mode_bal == true)
  {
    lcd.setCursor (16, 3);
    lcd.print(inboost_current);   ////default 
  }
  else
  {
    lcd.setCursor (16, 3);
    lcd.print(discharge_current);   ////default  
  }
  //lcd.print(cell1_temp); ///dynamic var test

  lcd_tbdelay(200);

  //---------------------------------------------------------------------------- 3 ---------------------------------------------------------------------------------------//
  
  lcd.setCursor (0, 2); 
  if(no_voltage == false)
  {
    if((balanced_stat == false) && (op_mode_bal == true))
    {
      lcd.print(" Cell Balancing..   ");
    }
    else if((balanced_stat == true) && (op_mode_bal == true)) 
    {
      lcd.print("Cell Balancing done "); 
    }
    else if(op_mode_bal == false)
    {
      lcd.setCursor (16, 2);
      lcd.print(discharge_voltage);   ////default
    }  
  }
  else if(no_voltage == true)
  {
    lcd.print("0V Cell Detected..");
  }
  
  if(op_mode_bal == true)
  {
    lcd.setCursor (16, 3);
    lcd.print(inboost_current);   ////default 
  }
  else
  {
    lcd.setCursor (16, 3);
    lcd.print(discharge_current);   ////default  
  }
  //lcd.print(cell1_temp); ///dynamic var test

  lcd_tbdelay(200);

  //---------------------------------------------------------------------------- 4 ---------------------------------------------------------------------------------------//
  
  lcd.setCursor (0, 2); 
  if(no_voltage == false)
  {
    if((balanced_stat == false) && (op_mode_bal == true))
    {
      lcd.print(" Cell Balancing...  ");
    }
    else if((balanced_stat == true) && (op_mode_bal == true))
    {
      lcd.print("Cell Balancing done."); 
    }
    else if(op_mode_bal == false)
    {
      lcd.setCursor (16, 2);
      lcd.print(discharge_voltage);   ////default
    }
  }
  else if(no_voltage == true)
  {
    lcd.print("0V Cell Detected... ");
  } 

  
  if(op_mode_bal == true)
  {
    lcd.setCursor (16, 3);
    lcd.print(inboost_current);   ////default 
  }
  else
  {
    lcd.setCursor (16, 3);
    lcd.print(discharge_current);   ////default  
  }
  //lcd.print(cell1_temp); ///dynamic var test

  lcd_tbdelay(200);

  //---------------------------------------------------------------------------- 5 ---------------------------------------------------------------------------------------//
  
  lcd.setCursor (0, 2); 
  if(no_voltage == false)
  {
    if((balanced_stat == false) && (op_mode_bal == true))
    {
      lcd.print(" Cell Balancing.... ");
    }
    else if((balanced_stat == true) && (op_mode_bal == true))
    {
      lcd.print("Cell Balancing done "); 
    }
    else if(op_mode_bal == false)
    {
      lcd.setCursor (16, 2);
      lcd.print(discharge_voltage);   ////default
    } 
  }
  else if(no_voltage == true)
  {
    lcd.print("0V Cell Detected....");    
  }
  
  if(op_mode_bal == true)
  {
    lcd.setCursor (16, 3);
    lcd.print(inboost_current);   ////default 
  }
  else
  {
    lcd.setCursor (16, 3);
    lcd.print(discharge_current);   ////default  
  }
  //lcd.print(cell1_temp); ///dynamic var test

  lcd_tbdelay(200);  //1000 per loop
  ++bal_count ;
  //---------------------------------------------------------------------------- f ---------------------------------------------------------------------------------------//

  flag = true ;
  
}

void lcd_check()
{
  flag = false ;
  page_status = 3 ;

  
  //lcd.clear();// clearn previous values from screen
  lcd.setCursor (0, 0); 
  lcd.print("Voltage; c1|c2|c3|c4"); 


  // layout " x.xx|x.xx|x.xx|x.xx"
  
  lcd.setCursor (0, 1); 
  lcd.print(" ");
  
  //dtostrf(voltc1 , 4 , 2, voltc1_disp );
  lcd.setCursor (1, 1);
  lcd.print(cell1_volt);
  lcd.setCursor (5, 1);
  lcd.print("|");
  
  //dtostrf(voltc2 , 4 , 2, voltc2_disp );
  lcd.setCursor (6, 1);
  lcd.print(cell2_volt);
  lcd.setCursor (10, 1);
  lcd.print("|");
  
  //dtostrf(voltc3 , 4 , 2, voltc3_disp );     //////////////////////////// char array
  lcd.setCursor (11, 1);
  lcd.print(cell3_volt);
  lcd.setCursor (15, 1);
  lcd.print("|");
  
  //dtostrf(voltc4 , 4 , 2, voltc4_disp );
  lcd.setCursor (16, 1);
  lcd.print(cell4_volt);      //////////////////////////// variable
  

  //layout "T xxC| xxC| xxC| xxC"
  
  lcd.setCursor (0, 2); 
  lcd.print("T");
  
  lcd.setCursor (1, 2); 
  lcd.print(" ");
  lcd.setCursor (2, 2); 
  lcd.print(cell1_temp);
  lcd.setCursor (4, 2);
  lcd.print("C");
  lcd.setCursor (5, 2);
  lcd.print("|");

  lcd.setCursor (6, 2); 
  lcd.print(" ");
  lcd.setCursor (7, 2); 
  lcd.print(cell2_temp);
  lcd.setCursor (9, 2);
  lcd.print("C");
  lcd.setCursor (10, 2);
  lcd.print("|");

  lcd.setCursor (11, 2); 
  lcd.print(" ");
  lcd.setCursor (12, 2); 
  lcd.print(cell3_temp);
  lcd.setCursor (14, 2);
  lcd.print("C");
  lcd.setCursor (15, 2);
  lcd.print("|");

  lcd.setCursor (16, 2); 
  lcd.print(" ");
  lcd.setCursor (17, 2); 
  lcd.print(cell4_temp);
  lcd.setCursor (19, 2);
  lcd.print("C");
  

  if(inBal_Source == true)
  {
    digitalWrite(external_source,relayOp_off);
    //layout "Icap:x.xxIboost:x.xx"
    lcd.setCursor (0, 3); //character zero, line 1
    lcd.print("BalSource=>Internal");
  }
  else if(inBal_Source == false)
  {
    digitalWrite(external_source,relayOp_on);
    lcd.setCursor (0, 3); //character zero, line 1
    lcd.print("BalSource=>External");
  } 

  lcd_tbdelay(500);

  flag = true ;

}

void lcd_system_config()
{

  flag = false ;
  page_status = 4 ;

  //lcd.clear();// clearn previous values from screen

  lcd.setCursor (0, 3); 
  lcd.print("Boost Output : 4.2 V"); 
  
  if(inBal_Source == true)
  {
    lcd.setCursor (0, 0); //character zero, line 1
    lcd.print("BalSource=>Internal");
  }
  else if(inBal_Source == false)
  {
    lcd.setCursor (0, 0); //character zero, line 1
    lcd.print("BalSource=>External");
  }  

  if(acpVol_50 == true)
  {
    lcd.setCursor (0, 1); //character zero, line 1
    //lcd.print("Voltage diff : 20 mV");
    lcd.print("Bal.mode : fast     ");
  }
  else if(acpVol_50 == false)
  {
    lcd.setCursor (0, 1); //character zero, line 1
    //lcd.print("Voltage diff : 10 mV");
    lcd.print("Bal.mode : normal   ");
  }  

  if(op_mode_bal == true)   ////////////////////////////////// already disable this function waiting for dev new function ////////////////////////////////
  {
    lcd.setCursor (0, 2); //character zero, line 1
    lcd.print("Mode : Balance      ");
  }
  else if(op_mode_bal == false)
  {
    lcd.setCursor (0, 2); //character zero, line 1
    lcd.print("Mode : Discharge    ");
  }  
     
/*
  lcd.setCursor (0, 2); 
  lcd.print("Cap freq : 20 Hz.   "); 
*/

  lcd_tbdelay(1000);

  flag = true ;


}

void page_check()
{
  flag = false ;
  
  if(page_status == 1)
    { 
      lcd_main();
    }
    else if(page_status == 2)
    {
      lcd_op();
    }
    else if(page_status == 3)
    {
      lcd_check();
    }
    else if(page_status == 4)
    {
      lcd_system_config();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
