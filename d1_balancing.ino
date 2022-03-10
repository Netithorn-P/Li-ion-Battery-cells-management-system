void balancing()
{
  bal_con :
  status_balancing = false ;
  
  voltage_check();
  current_check();
  temp_check();

  matching_cal();
  matching_cell();
  
  bal_end = false ;

 for(bal_count ; bal_count <= 180;)
 {
  if(bal_count < 180)  // 1.25 sec per loop (144 = 3 min)   /* check for voltage == (avg_upper + 0.05) then stop balancing */
  {
    status_balancing = true ;
    
    //depend on system
    digitalWrite(matchcell_op.source_pos,relayOp_release);
    digitalWrite(matchcell_op.sink_pos,relayOp_receive);
    
    digitalWrite(matchcell_op.source_active,mosfetOp_on);
    digitalWrite(matchcell_op.sink_active,mosfetOp_on);
    
    if((cell_volt[cell_match_boost[1]-1] >= (avr_upper + 0.01)) || (cell_volt[cell_match_boost[0]-1] <= (avr_lower - 0.01)))  //<<<<<<< rest the cell for check
    {
      bal_count = 180 ;
      deactivate_balancing();
      
      status_balancing = false ; 
      
      for(int i = 1; i <= 30 ;i++)
      {
        cell_resting = i ;
        lcd_tbdelay(1000);
      }
      
      cell_resting = 0 ;

      lcd_tbdelay(20);
        
    }
  }
  else if(bal_count >= 180) //(180 = 3 min)
  {
    status_balancing = false ;  
    deactivate_balancing();

    lcd_tbdelay(20);

    if((balanced_stat == true) && ((cell_volt[cell_match_boost[1]-1] >= avr_upper) || (cell_volt[cell_match_boost[0]-1] <= avr_lower))){
      bal_count = 0 ; 
      goto loop_flag ;}
    else if((balanced_stat == false) && ((cell_volt[cell_match_boost[1]-1] >= avr_upper) || (cell_volt[cell_match_boost[0]-1] <= avr_lower))) //// if else condition : do not enter loop resting 
    {
      loop_resting = 1 ;
      
      for(loop_resting ; loop_resting <= 30 ; loop_resting++)
      { 
         lcd_tbdelay(1000);
      }

      loop_resting = 0 ;
      bal_count = 0 ; 
    }
    else///*if cells are fake bal(sink cell dynamicc voltage == avr_lower)*///
    {
      bal_end = true ;
      lcd_tbdelay(20);
      bal_count = 0 ; 
      goto bal_con ;
    }
    
    goto loop_flag ;
  } 
  }
  
  status_balancing = false ;

  loop_flag :

  bal_end = true ;

}

void deactivate_balancing()
{
  lcd_tbdelay(20);

  digitalWrite(cell1_active , mosfetOp_off);  // n-mos cant check voltage while mosfet are off but p-mos can
  digitalWrite(cell2_active , mosfetOp_off);
  digitalWrite(cell3_active , mosfetOp_off);
  digitalWrite(cell4_active , mosfetOp_off);  /* MOSFET */ //
  
  Serial.println("  System status => \"Balancing deactivated !!\"  ");
}
