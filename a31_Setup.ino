
void pin_init();                               /*done*/       //a5_mainFunction
void voltage_check();                          /*done*/       //a5_mainFunction
void current_check();                          /*done*/       //a5_mainFunction
void temp_check();                             /*done*/       //a5_mainFunction
void matching_cal();                           /*done*/       //b1_matchingCal /*main func => done , additional => not done*/  ** 0 volt ??????
void matching_cell();                          /*done*/   //b2_matchingCell
void balancing();                              /*done*/   //d1_balancing
void deactivate_balancing();                   /*done*/   //d1_balancing
void tbdelay(unsigned long func_time);         /*done*/       //a5_mainFunction   /*timerbase delay*/
void lcd_tbdelay(unsigned long func_time);     /*done*/       //a5_mainFunction   /*timerbase delay for lcd function*/ 
void discharge();
void deactivate_discharge();

///////////////////////

void core_func();           
void lcd_system_init();
void lcd_main();
void lcd_op();
void lcd_check();
void lcd_system_config();

void lcd_protect();

void sw1();                                     /*Interrupt section*/
void sw2();
void sw3();
void sw4();

void userInterface_control_sw1();
void userInterface_control_sw2();
void userInterface_control_sw3();
void userInterface_control_sw4();

void page_check();

/////////////////////////////////////////////////////////////////////////////

void setup() 
{

  //test_val(); //only use for system def and test 
  
  Serial.begin(9600);

  pin_init();
  sw_init();

  lcd_system_init();
  attachInterrupt(digitalPinToInterrupt(2)  , sw1 , FALLING);
  attachInterrupt(digitalPinToInterrupt(3)  , sw2 , FALLING);
  attachInterrupt(digitalPinToInterrupt(19) , sw3 , FALLING);
  attachInterrupt(digitalPinToInterrupt(18) , sw4 , FALLING);  //back

  
  
}
