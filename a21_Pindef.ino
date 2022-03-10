//analog input pin

#define cell1_volt_m A1
#define cell2_volt_m A2
#define cell3_volt_m A3
#define cell4_volt_m A4

#define discharge_current_m A6
#define inboost_current_m A7
#define cell1_temp_m A11
#define cell2_temp_m A12
#define cell3_temp_m A13
#define cell4_temp_m A14
//#define analog_sw_m A10

///////////////////////////////////////////////////////

//digital output pin

#define cell1_active 37  //  /* MOSFET */
#define cell2_active 35  //***Off while balance/discharge : On for voltage check***

#define cell3_active 33
#define cell4_active 31  //   

#define cell1_pos 10 //  /* RELAY */
#define cell2_pos 11
#define cell3_pos 12
#define cell4_pos 13 //
  
#define protect_relay 0
#define external_source 14  // 1 control signal for 2 relay module (+,-)
#define discharge_relay 15   // 1 control signal for 2 relay module (+,-)

#define relayOp_off LOW //Waiting for relay module characteristic
#define relayOp_on HIGH

#define relayOp_receive LOW //common close
#define relayOp_release HIGH //common open

//#define mosfetOp_off LOW // n-channel mosfet 
//#define mosfetOp_on HIGH

#define mosfetOp_off HIGH // p-channel mosfet 
#define mosfetOp_on LOW

/*  //analog input pin
uint16_t cell1_volt_m = A1 , cell2_volt_m = A2 , cell3_volt_m = A3 , cell4_volt_m = A4 ;   //voltage sensors pin
uint16_t sys_current_m = A0 , discharge_current_m = A6 , inboost_current_m = A7 ; //currnet sensors pin (flyingcap and inboost converter are optional)
uint16_t cell1_temp_m = A11 ,cell2_temp_m = A12 , cell3_temp_m = A13 , cell4_temp_m = A14 ; //temperature sensors pin
uint16_t analog_sw_m = A10 ; //raw control switch

    //digital output pin
uint8_t cell1_sink = 5 , cell2_sink = 6 , cell3_active = 7 , cell4_sink = 8 ;  //sink control
uint8_t cell1_source = 10 , cell2_source = 11 , cell3_source = 12 , cell4_source = 13 ; //source control
uint8_t cell1_rel_p = 31 , cell2_rel_p = 35 , cell3_rel_p = 39 , cell4_rel_p = 43 ,
     cell1_rel_n = 33 , cell2_rel_n = 37 , cell3_rel_n = 41 , cell4_rel_n = 45 ; //matching point release
uint8_t cell1_rec_p = 30 , cell2_rec_p = 34 , cell3_rec_p = 38 , cell4_rec_p = 42 ,
     cell1_rec_n = 32 , cell2_rec_n = 36 , cell3_rec_n = 40 , cell4_rec_n = 44 ; //matching point receive
uint8_t protect_relay = 0 ; //protection circuit breaker
//uint8_t //lcd pin */
