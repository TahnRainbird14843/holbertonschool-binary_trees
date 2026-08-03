## Memory Visualising for stack_example.c
# Entry main() - depth 0

No variables created, calls walk_stack(0,3)

# call walk_stack - depth: 0

| Variable     | Storage Location | Value   | Lifetime  |
|--------------|------------------|---------|-----------|
| marker       | stack            | 0       | until walk_stack is left at depth
 0 |

calls dump_frame("enter", 0)

# call dump_frame - depth: 0

| Variable     | Storage Location | Value   | Lifetime  |
|--------------|------------------|---------|-----------|
| local_int    | stack            | 100     | until dump_frame is left at depth
 0   |
| local_buf    | stack    |  address of local_buf[0] = 0x7ffd2df760d4 | until
 dump_frame is left at depth 0 |
| local_buf[0] | stack | 'A' | until dump_frame is left at depth 0 |
| p_local | stack | &local_int = 0x7ffd2df76054 | until dump_frame is left at
 depth 0 |

leave dump_frame, this deallocates the variables in the above table. This 
returns to walk_stack at depth 0 and calls walk_stack(1,3)

# call walk_stack - depth: 1
| Variable     | Storage Location | Value   | Lifetime  |                       
|--------------|------------------|---------|-----------|                       
| marker       | stack            | 10     | until walk_stack is left at depth 
 0 |

calls dump_frame("enter", 1)

# call dump_frame - depth 0:

| Variable     | Storage Location | Value   | Lifetime  |                       
|--------------|------------------|---------|-----------|                       
| local_int    | stack            | 101     | until dump_frame is left at depth 
 0   |                                                                          
| local_buf    | stack    |  address of local_buf[0] = 000000BA58DFF8D0 | until 
 dump_frame is left at depth 0 |                                                
| local_buf[0] | stack | 'A' | until dump_frame is left at depth 0 |            
| p_local | stack | &local_int = 000000BA58DFF8E4 | until dump_frame is left at 
 depth 0 | 

# call walk_stack - depth: 1                                                    
| Variable     | Storage Location | Value   | Lifetime  |                       
|--------------|------------------|---------|-----------|                       
| marker       | stack            | 10     | until walk_stack is left at depth  
 0 |                                                                            
                                                                                
calls dump_frame("enter", 1)                                                    
                                                                                
# call dump_frame - depth 0:                                                    
                                                                                
| Variable     | Storage Location | Value   | Lifetime  |                       
|--------------|------------------|---------|-----------|                       
| local_int    | stack            | 101     | until dump_frame is left at depth 
 0   |                                                                          
| local_buf    | stack    |  address of local_buf[0] = 000000BA58DFF8D0 | until 
 dump_frame is left at depth 0 |                                                
| local_buf[0] | stack | 'A' | until dump_frame is left at depth 0 |            
| p_local | stack | &local_int = 000000BA58DFF8E4 | until dump_frame is left at 
 depth 0 |

# call walk_stack - depth: 1                                                    
| Variable     | Storage Location | Value   | Lifetime  |                       
|--------------|------------------|---------|-----------|                       
| marker       | stack            | 10     | until walk_stack is left at depth  
 0 |                                                                            
                                                                                
calls dump_frame("enter", 1)                                                    
                                                                                
# call dump_frame - depth 0:                                                    
                                                                                
| Variable     | Storage Location | Value   | Lifetime  |                       
|--------------|------------------|---------|-----------|                       
| local_int    | stack            | 101     | until dump_frame is left at depth 
 0   |                                                                          
| local_buf    | stack    |  address of local_buf[0] = 000000BA58DFF8D0 | until 
 dump_frame is left at depth 0 |                                                
| local_buf[0] | stack | 'A' | until dump_frame is left at depth 0 |            
| p_local | stack | &local_int = 000000BA58DFF8E4 | until dump_frame is left at 
 depth 0 |

# call walk_stack - depth: 1                                                    
| Variable     | Storage Location | Value   | Lifetime  |                       
|--------------|------------------|---------|-----------|                       
| marker       | stack            | 10     | until walk_stack is left at depth  
 0 |                                                                            
                                                                                
calls dump_frame("enter", 1)                                                    
                                                                                
# call dump_frame - depth 0:                                                    
                                                                                
| Variable     | Storage Location | Value   | Lifetime  |                       
|--------------|------------------|---------|-----------|                       
| local_int    | stack            | 101     | until dump_frame is left at depth 
 0   |                                                                          
| local_buf    | stack    |  address of local_buf[0] = 000000BA58DFF8D0 | until 
 dump_frame is left at depth 0 |                                                
| local_buf[0] | stack | 'A' | until dump_frame is left at depth 0 |            
| p_local | stack | &local_int = 000000BA58DFF8E4 | until dump_frame is left at 
 depth 0 |
