//void mesaure_value_init() //to identify sensor status               /*apply for each function*/
//{
//cell1_volt = 101 ; cell2_volt = 101 ; cell3_volt_m = 101 ; cell4_volt = 101 ;  //for voltage check func
//sys_current = 101 ; flycap_current = 101 ; inboost_current = 101 ; //for currnet check func
//cell1_temp = 101 ; cell2_temp = 101 ; cell3_temp = 101 ; cell4_temp = 101 ;  //for temperature check func
//}

void pin_init()                                                     
{
  pinMode(cell1_active , OUTPUT);
  pinMode(cell2_active , OUTPUT);
  pinMode(cell3_active , OUTPUT);
  pinMode(cell4_active , OUTPUT);
  pinMode(cell1_pos , OUTPUT);
  pinMode(cell2_pos , OUTPUT);
  pinMode(cell3_pos , OUTPUT);
  pinMode(cell4_pos , OUTPUT);
  pinMode(protect_relay , OUTPUT);
  pinMode(external_source , OUTPUT);
  pinMode(discharge_relay , OUTPUT);
}

void voltage_check() //with out delay             /*not done need specific constant value for each analog pin to correction voltage*/
{  
  static uint16_t volt_measure[4] = {10101,10101,10101,10101} ; //initiate reading value for identify sensor status  

    volt_measure[0] = analogRead(cell1_volt_m)  ;  
    volt_measure[1] = analogRead(cell2_volt_m)  ; 
    volt_measure[2] = analogRead(cell3_volt_m)  ; 
    volt_measure[3] = analogRead(cell4_volt_m)  ;  
  

  double volt1_measure = volt_measure[0] * (5.0/1023) ; 
  double volt2_measure = volt_measure[1] * (5.0/1023) ;  
  double volt3_measure = volt_measure[2] * (5.0/1023) ;  
  double volt4_measure = volt_measure[3] * (5.0/1023) ;   

  //////////////*voltage correction*//////////////

//  double x_1 = (0.0410 * volt1_measure) ;  // out1 //With op-amp buffer  
//  double x_2 = (0.0410 * volt2_measure) ;  // out2
//  double x_3 = (0.0435 * volt3_measure) ;  // out3
//  double x_4 = (0.0360 * volt4_measure) ;  // out4


  double x_1 = (0.0490 * volt1_measure) ;  // out1 //Direct measure 
  double x_2 = (0.0480 * volt2_measure) ;  // out2
  double x_3 = (0.0478 * volt3_measure) ;  // out3
  double x_4 = (0.0475 * volt4_measure) ;  // out4

  cell1_volt = volt1_measure - x_1 ;  //Real part 
  cell2_volt = volt2_measure - x_2 ;
  cell3_volt = volt3_measure - x_3 ;
  cell4_volt = volt4_measure - x_4 ;


//  Serial.println(balanced_stat); 

//
  cell1_volt = 4.13 ;  //Test part
  cell2_volt = 4.13 ;
  cell3_volt = 4.13 ;
  cell4_volt = 4.13 ;

  discharge_voltage = cell1_volt ;

  avr_volt = (cell1_volt + cell2_volt + cell3_volt + cell4_volt) / 4.0 ;  //acpVol_50
  avr_upper = avr_volt + (volt_diff/2.0) ;
  avr_lower = avr_volt - (volt_diff/2.0) ;
  

  if( ((avr_lower <= cell1_volt) && (cell1_volt <= avr_upper)) && ((avr_lower <= cell2_volt) && (cell2_volt <= avr_upper)) && ((avr_lower <= cell3_volt) && (cell3_volt <= avr_upper)) && ((avr_lower <= cell4_volt) && (cell4_volt <= avr_upper)) )
  {
    balanced_stat = true ;
  }
  else
  {
    balanced_stat = false ;
  }
  
  cell_volt[0] = cell1_volt ;
  cell_volt[1] = cell2_volt ;
  cell_volt[2] = cell3_volt ;
  cell_volt[3] = cell4_volt ;
  
  /////////////////////////////////////////////////

  //////////////////*Protection*///////////////////

  if( cell1_volt <= undervolt_limit || cell2_volt <= undervolt_limit ||cell3_volt <= undervolt_limit || cell4_volt <= undervolt_limit || cell1_volt >= overvolt_limit || cell2_volt >= overvolt_limit || cell3_volt >= overvolt_limit || cell4_volt >= overvolt_limit )
 {
    bool cell1_0v = false , cell2_0v = false , cell3_0v = false , cell4_0v = false ;
     
    if(cell1_volt != 0){uv1 = cell1_volt <= undervolt_limit ; ov1 = cell1_volt >= overvolt_limit ;}
    else if(cell1_volt == 0){cell1_0v = true;}
    if(cell2_volt != 0){uv2 = cell2_volt <= undervolt_limit ; ov2 = cell2_volt >= overvolt_limit ;}
    else if(cell2_volt == 0){cell2_0v = true;}
    if(cell3_volt != 0){uv3 = cell3_volt <= undervolt_limit ; ov3 = cell3_volt >= overvolt_limit ;}
    else if(cell3_volt == 0){cell3_0v = true;}
    if(cell4_volt != 0){uv4 = cell4_volt <= undervolt_limit ; ov4 = cell4_volt >= overvolt_limit ;}
    else if(cell4_volt == 0){cell4_0v = true;}


    if((uv1 == true) || (uv2 == true) || (uv3 == true) || (uv4 == true) || (ov1 == true) || (ov2 == true) || (ov3 == true) || (ov4 == true)){

   //for debug
     if(uv1){Serial.println("Cell 1 is undervoltage");
       uv_warn[16] = '1' ;}
     else if(!uv1){uv_warn[16] = '_' ;}
     if(uv2){Serial.println("Cell 2 is undervoltage");
       uv_warn[17] = '2' ;}
     else if(!uv2){uv_warn[17] = '_' ;}
     if(uv3){Serial.println("Cell 3 is undervoltage");
       uv_warn[18] = '3' ;}
     else if(!uv3){uv_warn[18] = '_' ;}
     if(uv4){Serial.println("Cell 4 is undervoltage");
       uv_warn[19] = '4' ;}
     else if(!uv4){uv_warn[19] = '_' ;}

     if(ov1){Serial.println("Cell 1 is overvoltage");
       ov_warn[15] = '1' ;}
     else if(!ov1){ov_warn[15] = '_' ;}
     if(ov2){Serial.println("Cell 2 is overvoltage");
       ov_warn[16] = '2' ;}
     else if(!ov2){ov_warn[16] = '_' ;}
     if(ov3){Serial.println("Cell 3 is overvoltage");
       ov_warn[17] = '3' ;}
     else if(!ov3){ov_warn[17] = '_' ;}
     if(ov4){Serial.println("Cell 4 is overvoltage");
       ov_warn[18] = '4' ;
       oc_warn[18] = '_' ;}////////////////////////////////////////////////////////////////////////////////////////////
     else if(!ov4){ov_warn[18] = '_' ;}

     delay(100); 

     lcd_protect();
     }
  
//ov_warn[20] = "Over voltage : ____"    //15=1 16=2 17=3 18=4
//uv_warn[20] = "Under voltage : ____"    //16=1 17=2 18=3 19=4
     
  }

  /////////////////////////////////////////////////
  
 //test val
//  cell1_volt = (value[0]*5.0) / 1023;  //return value to global variable (cal test)
//  cell2_volt = (value[1]*5.0) / 1023;
//  cell3_volt = (value[2]*5.0) / 1023;
//  cell4_volt = (value[3]*5.0) / 1023;
//cellx_volt = (value[i]*(float 5.0)) / (int 1023);

//cell1_volt += 0.01;  //return value to global variable (dynamic val test)  OK!!
//cell2_volt += 0.01;
//cell3_volt += 0.01;
//cell4_volt += 0.01;



// //to debug cell voltage
//  Serial.println(cell1_volt);
//  Serial.println(cell2_volt);
//  Serial.println(cell3_volt);
//  Serial.println(cell4_volt);
 
}

void current_check() //with out delay                               /*calculation is missing*/
{
  int count = 150;
  const int VOLTAGE_REF = 5; // Reference voltage for analog read
  uint16_t value ;
  double inboost_current_cal = 0.0 , discharge_current_cal = 0.0 ;
  
if(op_mode_bal == true){
  for(uint8_t i = 0 ; i <= count ; i++)
  {
  value = analogRead(inboost_current_m) - 520 ;   //0A = 520 5A = 320
  inboost_current_cal += value * (4.971/200.0) ;
  }

  inboost_current = (inboost_current_cal/count) + 0.482 ;  //
}
else{
  for(uint8_t i = 0 ; i <= count ; i++)
  {
  value = analogRead(discharge_current_m) - 520 ;   //0A = 520 5A = 320
  discharge_current_cal += value * (4.971/200.0) ;
  }

  discharge_current = (discharge_current_cal/count) + 0.482 ;  //
}
  //////////////////*Protection*///////////////////

  if(inboost_current > current_limit)
  {
     oc = inboost_current > current_limit ;
     
     if(oc)
     {
       Serial.println("Over current at in_booster");
       oc_warn[15] = 'B' ;
       oc_warn[16] = 'A' ;
       oc_warn[17] = 'L' ;
     }
     else if(!oc)
     {
       oc_warn[15] = '_' ;
       oc_warn[16] = '_' ;
       oc_warn[17] = '_' ;
     }   //oc_warn[20] = "Over Current : ___"  //15=O 16=C 17=C    

     delay(100);  

     lcd_protect();
  }

  if(discharge_current > current_limit)
  {
     oc = discharge_current > current_limit ;
     
     if(oc)
     {
       Serial.println("Over current at in_booster");
       oc_warn[15] = 'D' ;
       oc_warn[16] = 'I' ;
       oc_warn[17] = 'S' ;
     }
     else if(!oc)
     {
       oc_warn[15] = '_' ;
       oc_warn[16] = '_' ;
       oc_warn[17] = '_' ;
     }   //oc_warn[20] = "Over Current : ___"  //15=O 16=C 17=C    

     delay(100);

     lcd_protect();
  }

  /////////////////////////////////////////////////
}

void temp_check()
{
  static uint16_t celltemp[5] = {0,0,0,0,0} ;

  celltemp[0] = analogRead(cell1_temp_m) ;
  celltemp[1] = analogRead(cell1_temp_m) ;
  celltemp[2] = analogRead(cell2_temp_m) ;
  celltemp[3] = analogRead(cell3_temp_m) ;
  celltemp[4] = analogRead(cell4_temp_m) ;
  
//  Serial.print(celltemp[0]);
//  Serial.print(" : ");
//  Serial.print(celltemp[1]);
//  Serial.print(" : ");
//  Serial.print(celltemp[2]);
//  Serial.print(" : ");
//  Serial.print(celltemp[3]);
//  Serial.print(" : ");
//  Serial.println(celltemp[4]);
   
  
  for (uint8_t i = 1; i <= 4; i++)
  {
    uint16_t val = celltemp[i] ;
    float mv = ( val / 1023.0) * 5000 ; 
    float temp = mv / 10 ;
    celltemp[i] = temp ; 
  }
  
  cell1_temp = celltemp[1] ; //Real part  *limit at 40 deg C*
  cell2_temp = celltemp[2] ;
  cell3_temp = celltemp[3] ;
  cell4_temp = celltemp[4] ;

//  cell1_temp = 12 ; //Test part  *limit at 40* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< FOR TEST HERE !!!!!!!!!!!!! <<<<<<<<<<<<<<
//  cell2_temp = 15 ;
//  cell3_temp = 12 ;
//  cell4_temp = 15 ;

  //////////////////*Protection*///////////////////  

  if(cell1_temp > temperature_limit || cell2_temp > temperature_limit || cell3_temp > temperature_limit || cell4_temp > temperature_limit )
  {
     ot1 = cell1_temp > temperature_limit ;
     ot2 = cell2_temp > temperature_limit ;
     ot3 = cell3_temp > temperature_limit ;
     ot4 = cell3_temp > temperature_limit ;

     if(ot1){Serial.println("Cell 1 is Overtempurature");
       ot_warn[12] = '1' ;}
     else if(!ot1){ot_warn[12] = '_' ;}
     if(ot2){Serial.println("Cell 2 is Overtempurature");
       ot_warn[13] = '2' ;}
     else if(!ot2){ot_warn[13] = '_' ;}
     if(ot3){Serial.println("Cell 3 is Overtempurature");
       ot_warn[14] = '3' ;}
     else if(!ot3){ot_warn[14] = '_' ;}
     if(ot4){Serial.println("Cell 4 is Overtempurature");
       ot_warn[15] = '4' ;}
     else if(!ot4){ot_warn[15] = '_' ;}

     
//ot_warn[20] = "Over temp : ____" ;   //12=1 13=2 14=3 15=4

     delay(100);

     lcd_protect();
  }
  
  /////////////////////////////////////////////////

 /*  //tmperature debug
 Serial.print("temp cell_1 : ");
 Serial.println(cell1_temp);
 Serial.print("temp cell_2 : ");
 Serial.println(cell2_temp);
 Serial.print("temp cell_3 : ");
 Serial.println(cell3_temp);
 Serial.print("temp cell_4 : ");
 Serial.println(cell4_temp);
 Serial.println("-----------------------");
 */
}
