
/*global variable*/ 
//uint8_t (0-255)
uint8_t cell_match_boost[2] = {0,0};
uint8_t cell_match_cap[2] = {0,0};       /*cell matching*/
uint8_t cell_match_deactivate[2] = {0,0};

uint8_t sw_k1 = 0 , sw_k2 = 0 , sw_k3 = 0 , sw_k4 = 0 ; /*for interrupt switch*/
uint8_t page_status = 0 ;  /*lcd initial page*/

uint8_t cell_resting = 0 ;
uint8_t loop_resting = 0 ;

uint8_t bal_count = 0 ;
uint8_t dis_count = 0 ;

bool flag = false ; //lcd flag => true if completed ui function
bool status_balancing = false ;
bool bal_end = false ;
bool balanced_stat = false ;  

////uint16_t (0-65535)      /*Local variable [included in specific function]*/
//uint16_t cell1_volt , cell2_volt , cell3_volt , cell4_volt ;   //voltage value
//uint16_t sys_current , flycap_current , inboost_current ; //currnet value (flyingcap and inboost converter are optional)
//uint16_t cell1_temp ,cell2_temp , cell3_temp , cell4_temp ; //temperature value

//float /*for calculated vlaue from sensor*/
float cell1_volt , cell2_volt , cell3_volt , cell4_volt ; // require cal from uint16_t raw value [cellx_volt (voltage raw value)]
float cell_volt_list[4] ;
uint16_t celltemp[5] = {0,0,0,0,0} ;
float cell_volt[4] = {0,0,0,0} ;
uint8_t cell1_temp , cell2_temp , cell3_temp , cell4_temp ; // require cal from uint16_t raw value [cellx_temp (temperature raw value)]
float sys_current , inboost_current , discharge_current ; // require cal from uint16_t raw value [xxxx_current (current raw value)]
float avr_volt , avr_upper , avr_lower ;
float discharge_voltage ;

/*Balancing System Configuration*/
bool inBal_Source = true ; // true = internal , false = external
bool acpVol_50 = true ; // true = acceptable voltage dif is 20mV, false = acceptable voltage dif is 10mV
bool no_voltage = false ; // true = 0v cell detected , false = no 0v cell detected
bool op_mode_bal = true ; // select system operation mode

float volt_diff = 0.05 ; //0.1 at dynamic 0.05 at static

/*protection system*/

float current_limit = 1.3 ;
float overvolt_limit = 4.24 , undervolt_limit = 3.00 ;
uint8_t temperature_limit = 40 ; //default = 40

bool ov1 = false , ov2 = false , ov3 = false , ov4 = false , uv1 = false , uv2 = false , uv3 = false , uv4 = false 
           ,ot1 = false , ot2 = false , ot3 = false , ot4 = false 
           ,oc = false ;         
            
static char ov_warn[20] = "Over voltage : ____"   //15=1 16=2 17=3 18=4
          , uv_warn[20] = "Under voltage : ____"  //16=1 17=2 18=3 19=4
          , oc_warn[20] = "Over Current : ___"    //15=O 16=O 17=C
          , ot_warn[20] = "Over temp : ____" ;    //12=1 13=2 14=3 15=4
