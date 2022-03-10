void sw_init()
{
  digitalWrite(cell1_active , mosfetOp_off);  //
  digitalWrite(cell2_active , mosfetOp_off);
  digitalWrite(cell3_active , mosfetOp_off);
  digitalWrite(cell4_active , mosfetOp_off);  /* MOSFET */ //
  
  digitalWrite(cell1_pos , relayOp_receive);//
  digitalWrite(cell2_pos , relayOp_receive);
  digitalWrite(cell3_pos , relayOp_receive);
  digitalWrite(cell4_pos , relayOp_receive);   /* RELAY */
  
  digitalWrite(protect_relay , relayOp_on);  // ********** closed switch (Active HIGH) pos. cell negative side /********************* 
  digitalWrite(external_source , relayOp_off);  // 1 control signal for 2 relay module (+,-))  *** Active HIGH ***
  digitalWrite(discharge_relay , relayOp_off);   // 1 control signal for 2 relay module (+,-)  *** Active HIGH ***
}
