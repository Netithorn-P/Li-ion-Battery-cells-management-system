
//                  ////*MANUAL*////
//
// 1.) cell piority  [1] -> [4] -> [2] -> [3] /*not necessary if already have zero voltage protection*/
//
//                 ////*TO DO LIST*////
//
// 1.) complete matching function  <<<<<<<<<<<<<<<<< waiting for relay module activation charecteristic *************
// 2.) design and dev balancing algorithm (1 bal sys [boost] ; original[cap => boost , boost => noting])
//      - balancing condition @ balance() in d1_balancing /* waiting for hardware test */
// 3.) edit LCD main menu , set up page and dev algorithm for cc discharge  (opinion : balanace/discharge in config function)
//      - balancing page => line 3 while discharge mode /* DONE */
//      - algorithm /* waiting for hardware test */
//      - circuit /* waiting for hardware test */
// 4.) add external source function 
//      - external source switch /* DONE */
//      - matching operation (source cell) /* waiting for hardware test */
// 5.) disable select cell amount config and dev for other function <<<<<<<<<<< /* DONE */
// 6.) complete protection function 
//      - waiting for hardware test
// 7.) discharge function
//      - d2_discharge  /* waiting for hardware test */
//      - lcd_op in c1_uiFunction  /* waiting for hardware test */
//
//              ////*PROBLEM TO SLOVE*////
//
// 1.) 0 volt problem @ protection and balancing function. <<<<<<<<<<< /* DONE */
// 2.) discharge current and discharg voltage(cell 1 voltage) in balance ui and ui bug /* DONE */
// 3.) separate relay_op and mosfet_op /* DONE */
// 4.) open all switch at setup << /* DONE */
// 5.) Deactive unmatch cells while balancing/discharging ************************
// 6.) diff voltage change to 0.05 at stasic voltage and 0.1 at dynamic voltage /* DONE */
// 7.) change external source to deactivate balancing
