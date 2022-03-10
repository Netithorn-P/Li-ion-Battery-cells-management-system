void lcd_protect() // manual restart only
{
  volatile unsigned long p_i = 0 ;
  
  for( p_i ; p_i < 4294967295  ; p_i++)
  {
    deactivate_balancing();

    lcd.clear();// clearn previous values from screen

    lcd.setCursor (0, 0); //character zero, line 1
    lcd.print(ov_warn); //15=1 16=2 17=3 18=4

    lcd.setCursor (0, 1); 
    lcd.print(uv_warn); //17=1 18=2 19=3 20=4

    lcd.setCursor (0, 2); 
    lcd.print(ot_warn); //12=1 13=2 14=3 15=4

    lcd.setCursor (0, 3); 
    lcd.print(oc_warn); //16=1 17=2 18=3 19=4

    if(p_i >= 4294900000 )
    {
      p_i = 0 ;
    }

    delay(3000);
    lcd.clear();
    lcd_tbdelay(100);
  }

  
}
