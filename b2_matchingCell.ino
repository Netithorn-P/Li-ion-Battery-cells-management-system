void matching_cell()
{
  uint8_t i, j, cell_match_boost_op[2] ;

  digitalWrite(cell1_active , mosfetOp_off);  //4.140 3.641
  digitalWrite(cell2_active , mosfetOp_off);
  digitalWrite(cell3_active , mosfetOp_off);
  digitalWrite(cell4_active , mosfetOp_off);  /* MOSFET */ //


  cell_match_boost_op[0] = cell_match_boost[0] - 1 ; // energy release cell (source)
  cell_match_boost_op[1] = cell_match_boost[1] - 1 ; // energy receive cell
  
  i = cell_match_boost_op[0] ; // i = relaease cell 
  
  matchcell_op.source_active = matchcondition_release[i].source_active ; 
  matchcell_op.source_pos = matchcondition_release[i].source_pos ;

  i = cell_match_boost_op[1] ; // i = relaease cell 
  
  matchcell_op.sink_active = matchcondition_receive[i].sink_active ;
  matchcell_op.sink_pos = matchcondition_receive[i].sink_pos ;

  
  //////////////////////////////////// 2 balance module ////////////////////////////////////////
 
//  cell_match_boost_op[0] = cell_match_boost[0] - 1 ; // energy release cell
//  cell_match_boost_op[1] = cell_match_boost[1] - 1 ; // energy receive cell
//  
//  i = cell_match_boost_op[0] ;
//  
//  matchcell_op.source_p = matchcondition_release[i].source_p ; 
//  matchcell_op.source_n = matchcondition_release[i].source_n ;
//
//  i = cell_match_boost_op[1] ;
//  
//  matchcell_op.sink_p = matchcondition_receive[i].sink_p ;
//  matchcell_op.sink_n = matchcondition_receive[i].sink_n ;
//
//  digitalWrite(matchcell_op.source_p,relayOp_on);  //depend on system
//  digitalWrite(matchcell_op.source_n,mosfetOp_on);
//
//  digitalWrite(matchcell_op.sink_p,relayOp_on);
//  digitalWrite(matchcell_op.sink_n,mosfetOp_on);

/*  //for debug
  Serial.print("<cell : ");
  Serial.print(cell_match_boost[0]);
  Serial.print("> [to] <cell : ");
  Serial.print(cell_match_boost[1]);
  Serial.println(">");

  Serial.print("matchcell_op.source_p PIN :");
  Serial.println(matchcell_op.source_p);
  Serial.print("matchcell_op.source_n PIN :");
  Serial.println(matchcell_op.source_n);
  Serial.print("matchcell_op.sink_p PIN :");
  Serial.println(matchcell_op.sink_p);
  Serial.print("matchcell_op.sink_n PIN :");
  Serial.println(matchcell_op.sink_n);
 
  Serial.println("----------------------------------");
*/
}
