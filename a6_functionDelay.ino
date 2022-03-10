void tbdelay(unsigned long func_time)   //*TEMPLATE*//
{
  long  timer_count = millis() + func_time ;
  bool timer_check = false ;

check:

////////////// function here ///////////////////
////////////////////////////////////////////////

   if ( millis() >= timer_count )
   {
     timer_check = !timer_check ;
   }

   if( timer_check == false )
   {
    goto check ;
   }
}

void lcd_tbdelay(unsigned long func_time) 
{
  long  timer_count = millis() + func_time ;
  bool timer_check = false ; 
  static uint8_t prev_page_status = page_status ;

   voltage_check();
   temp_check();
   current_check();

check:

    if(prev_page_status != page_status)
    {
      prev_page_status = page_status ;
      lcd.clear();// clearn previous values from screen
    }
    else if ( flag == false )
    {
      goto skip ;
    }

    
    prev_page_status = page_status ;
    
    page_check();

skip:    
   
   if ( millis() >= timer_count )
   {
     timer_check = !timer_check ;
   }

   if( timer_check == false )
   {
    voltage_check();
    temp_check();
    current_check();
    goto check ;
   }
}
