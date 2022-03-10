//                /*Matching function describe*/

// require int16_t cell1_volt , cell2_volt , cell3_volt , cell4_volt ;   /*voltage value*/

// return  uint8_t cell_match_boost[2] = {0,0};    /*cell_matching_result*/
//         uint8_t cell_match_cap[2] = {0,0};

void matching_cal()
{  
  /*local variable*/
  uint8_t match[4] ,
          cell_max , cell_min ,cell_high , cell_low ;
  float   val_arr[4] , value[4] ,
          v_max , v_min ,v_high , v_low ;
        
  value[0] = cell1_volt ;  // cell 1
  value[1] = cell2_volt ;  // cell 2
  value[2] = cell3_volt ;  // cell 3
  value[3] = cell4_volt ;  // cell 4

  if ((cell1_volt == 0) || (cell2_volt == 0) || (cell3_volt == 0) || (cell4_volt == 0)) 
  {
    no_voltage = true ;              //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  }
  else 
  {
    no_voltage = false ; 
  }


  for (uint8_t i = 0; i < 4; i++)
  {
    val_arr[i] = value[i];
    cell_volt_list[i] = value[i] ;
  }
 
  for (uint8_t i = 0; i < 4; i++)                     //Loop for descending ordering
  {
    for (uint8_t j = 0; j < 4; j++)             //Loop for comparing other values
    {
      if (val_arr[j] < val_arr[i])                //Comparing other array elements
      {
        float tmp = val_arr[i];         //Using temporary variable for storing last value
        val_arr[i] = val_arr[j];            //replacing value
        val_arr[j] = tmp ;             //storing last value      
      }
    } 
  }
  
  v_max = val_arr[0] ;
  v_high = val_arr[1] ;
  v_low = val_arr[2] ;
  v_min = val_arr[3] ;
  
  for (uint8_t i = 0; i < 4; i++)
  {
    if(v_max == value[i])
    {
     cell_max = i+1 ;
    }

    if(v_high == value[i])
    {
     cell_high = i+1 ;
    }

    if(v_low == value[i])
    {
     cell_low = i+1 ;
    }

    if(v_min == value[i])
    {
     cell_min = i+1 ;
    }
  }

  cell_match_boost[0] = cell_max ; //source cell  default(2 balance system) cell_high
  cell_match_boost[1] = cell_min ; //sink cell                               cell_low

  cell_match_deactivate[0] = cell_high ;
  cell_match_deactivate[1] = cell_low ;
    
//  cell_match_cap[0] = cell_max ; //source cell     default(2 balance system) cell_max                 
//  cell_match_cap[1] = cell_min ; //sink cell                                 cell_min


////////////////////*debug function*///////////////////
//  Serial.print("value  |  avrage voltage ; ");   
//  Serial.println(avr_volt);   
//  Serial.print("upper ; ");
//  Serial.print(avr_upper);
//  Serial.print(" |  under ; ");
//  Serial.println(avr_lower);
//  
//  for(int i = 0 ; i<4 ; ++i)
//  {
//    Serial.print("cell ");
//    Serial.print(i+1);
//    Serial.print(" = ");
//    Serial.print(value[i]);
//    Serial.println("");
//    
//  }
//  Serial.println("-**--**--**--**-");
//  
//
//
//  Serial.print("v_max = ");
//  Serial.println(v_max);
//  Serial.print("v_high = ");
//  Serial.println(v_high);
//  Serial.print("v_low = ");
//  Serial.println(v_low);
//  Serial.print("v_min = ");
//  Serial.println(v_min);
//  Serial.println("-**--**--**--**-");
//
//
//
//  Serial.println("************");
//  Serial.print("Boost : ");
//  Serial.print(cell_match_boost[0]);
//  Serial.print(" to ");
//  Serial.println(cell_match_boost[1]);
//
//  Serial.print("Cap : ");
//  Serial.print(cell_match_cap[0]);
//  Serial.print(" to ");
//  Serial.println(cell_match_cap[1]);
//  Serial.println("************");
//
//  Serial.println("------");
//  delay(5000);
  
/////////////////////////////////////////////////////////

}  //DO NOT COMMENT THIS BRACKET !!!!!!!!!!!!!!!
