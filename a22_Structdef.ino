typedef struct
  {
//    uint8_t source_p ;  // 2 balance module
//    uint8_t source_n ;
//    uint8_t sink_p ;
//    uint8_t sink_n ;

    uint8_t source_active ;  // 1 balance module
    uint8_t source_pos ;
    uint8_t sink_active ;
    uint8_t sink_pos ;
    
  } match_op ;

match_op matchcondition_release[4] = {       // source => sink    cell number    p_key   pin active/position    
  { cell1_active , cell1_pos , 101 , 101 }, // cell 1 => cell x { Cell no.1 => index[0]          (5,10) }
  { cell2_active , cell2_pos , 101 , 101 }, // cell 2 => cell x { Cell no.2 => index[1]          (6,11) }
  { cell3_active , cell3_pos , 101 , 101 }, // cell 3 => cell x { Cell no.3 => index[2]          (7,12) }
  { cell4_active , cell4_pos , 101 , 101 }  // cell 4 => cell x { Cell no.4 => index[3]          (8,13) }
}; 

match_op matchcondition_receive[4] = {       // source => sink    cell number    p_key   pin active/position    
  { 101 , 101 , cell1_active , cell1_pos }, // cell x => cell 1 { Cell no.1 => index[0]          (5,10) }
  { 101 , 101 , cell2_active , cell2_pos }, // cell x => cell 2 { Cell no.2 => index[1]          (6,11) }
  { 101 , 101 , cell3_active , cell3_pos }, // cell x => cell 3 { Cell no.3 => index[2]          (7,12) }
  { 101 , 101 , cell4_active , cell4_pos }  // cell x => cell 4 { Cell no.4 => index[3]          (8,13) }

// 2 balance module
  
//match_op matchcondition_release[4] = {       // source => sink    cell number    p_key   pin p/n    
//  { cell1_rel_p , cell1_rel_n , 101 , 101 }, // cell 1 => cell x { Cell no.1 => index[0] (31,33) }
//  { cell2_rel_p , cell2_rel_n , 101 , 101 }, // cell 2 => cell x { Cell no.2 => index[1] (35,37) }
//  { cell3_rel_p , cell3_rel_n , 101 , 101 }, // cell 3 => cell x { Cell no.3 => index[2] (39,41) }
//  { cell4_rel_p , cell4_rel_n , 101 , 101 }  // cell 4 => cell x { Cell no.4 => index[3] (43,45) }
//}; 
//
//match_op matchcondition_receive[4] = {       // source => sink    cell number    p_key   pin p/n    
//  { 101 , 101 , cell1_rec_p , cell1_rec_n }, // cell x => cell 1 { Cell no.1 => index[0] (30,32) }
//  { 101 , 101 , cell2_rec_p , cell2_rec_n }, // cell x => cell 2 { Cell no.2 => index[1] (34,36) }
//  { 101 , 101 , cell3_rec_p , cell3_rec_n }, // cell x => cell 3 { Cell no.3 => index[2] (38,40) }
//  { 101 , 101 , cell4_rec_p , cell4_rec_n }  // cell x => cell 4 { Cell no.4 => index[3] (42,44) }
};

match_op matchcell_op = {101,101,101,101} ;
