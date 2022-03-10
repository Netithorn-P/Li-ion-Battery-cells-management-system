void discharge()  /*not done ALGORITHM*/
{
  voltage_check();
  current_check();
  temp_check();
  
  if(balanced_stat == false)
  {
    Serial.print("  System status => \"Discharging\"  ");           /////////////////////////////////////////////////* for debug *////////////////////////////////////////////////////
  }
  else if(balanced_stat == true)
  {
    Serial.print("  System status => \"Discharge done!!\"  ");
  }

  Serial.println(dis_count);

  if(dis_count < 144) // 1.25 sec per loop (144 = 3 min)   
  {    
    digitalWrite(cell1_pos,relayOp_release);
    digitalWrite(discharge_relay,relayOp_on);  // system mode select
    
    digitalWrite(cell1_active,mosfetOp_on);   // cell 1 slot depend on system  ******************************************** waiting for pin assign

    ++dis_count ;
    
    if(cell1_volt == (undervolt_limit + 0.05))  //<<<<<<< rest the cell for check
    {
      lcd_tbdelay(30000); // wait for 30 sec
      page_status = 3 ;
    }
  }
  else if(dis_count >= 144) //(144 = 3 min)
  {
    dis_count = 0 ;
    deactivate_discharge();
  }  
}

void deactivate_discharge()
{
  digitalWrite(cell1_active,mosfetOp_off);   // cell 1 slot depend on system  ******************************************** waiting for pin assign
  digitalWrite(cell1_pos,relayOp_receive);  
  digitalWrite(discharge_relay,relayOp_off);  // system mode select

  Serial.println("  System status => \"Discharging deactivated !!\"  ");
}
 
