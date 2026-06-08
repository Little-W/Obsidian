`ifndef I3C_DEFINE__SVH
`define I3C_DEFINE__SVH

`define MCU_CRG_BASE_ADDR                                     `MCU_SUB_MCU_CRG_BASE_ADDR
`define MCU_CRG_RST_ENABLE1                                   32'h10
`define MCUSS_I3C0_STAT                                       32'h400
`define MCUSS_I3C0_SVL_DBG_PORT_H                             32'h410
`define MCUSS_I3C0_SVL_DBG_PORT_L                             32'h414
`define MCUSS_I3C0_SVL_PID_H                                  32'h404
`define MCUSS_I3C0_SVL_PID_L                                  32'h408
`define MCUSS_I3C0_SVL_DCR                                    32'h40c




`define MCUSS_I3C1_STAT                                       32'h418
`define MCUSS_I3C1_SVL_DBG_PORT_H                             32'h428
`define MCUSS_I3C1_SVL_DBG_PORT_L                             32'h42C
`define MCUSS_I3C1_SVL_PID_H                                  32'h41C
`define MCUSS_I3C1_SVL_PID_L                                  32'h420
`define MCUSS_I3C1_SVL_DCR                                    32'h424



//Base Address
`define I3C0_BASE                                                `MCU_SUB_I3C0_BASE_ADDR
`define I3C1_BASE                                                `MCU_SUB_I3C1_BASE_ADDR
// REG offset
`define DEVICE_CTRL                                                 32'h0 
`define DEVICE_ADDR      						                    32'h4
`define HW_CAPABILITY							                    32'h8
`define COMMAND_QUEUE_PORT  					                    32'hc
`define RESPONSE_QUEUE_PORT						                    32'h10
`define RX_DATA_PORT						                        32'h14
`define TX_DATA_PORT						                        32'h14
`define IBI_QUEUE_DATA							                    32'h18
`define IBI_QUEUE_STATUS					                        32'h18
`define QUEUE_THLD_CTRL						                        32'h1c
`define DATA_BUFFER_THLD_CTRL				                        32'h20
`define IBI_QUEUE_CTRL						                        32'h24
`define IBI_MR_REQ_REJECT					                        32'h2c
`define IBI_SIR_REQ_REJECT						                    32'h30
`define RESET_CTRL							                        32'h34
`define SLV_EVENT_STATUS					                        32'h38
`define INTR_STATUS         				                        32'h3c
`define INTR_STATUS_EN						                        32'h40
`define INTR_SIGNAL_EN  					                        32'h44
`define INTR_FORCE      						                    32'h48
`define QUEUE_STATUS_LEVEL					                        32'h4c
`define DATA_BUFFER_STATUS_LEVEL			                        32'h50
`define PRESENT_STATE					                            32'h54
`define CCC_DEVICE_STATUS      				                        32'h58
`define DEVICE_ADDR_TABLE_POINTER			                        32'h5c
`define DEVICE_CHAR_TABLE_POINTER  					                32'h60
`define VENDOR_SPECIFIC_REG_POINTER				                    32'h6c
`define SLV_MIPI_ID_VALUE					                        32'h70
`define SLV_PID_VALUE           			                        32'h74
`define SLV_CHAR_CTRL   					                        32'h78
`define SLV_MAX_LEN                			                        32'h7c
`define MAX_READ_TURNAROUND					                        32'h80
`define MAX_DATA_SPEED           			                        32'h84
`define SLV_INTR_REQ					                            32'h8c
`define SLV_TSX_SYMBL_TIMING       			                        32'h90
`define DEVICE_CTRL_EXTENDED       			                        32'hb0
`define SCL_I3C_OD_TIMING 					                        32'hb4
`define SCL_I3C_PP_TIMING                	                        32'hb8
`define SCL_I2C_FM_TIMING					                        32'hbc
`define SCL_I2C_FMP_TIMING           			                    32'hc0
`define SCL_EXT_LCNT_TIMING                			                32'hc8        
`define SCL_EXT_TERMN_LCNT_TIMING					                32'hcc
`define SDA_HOLD_SWITCH_DLY_TIMING           			            32'hd0           
`define BUS_FREE_AVAIL_TIMING					                    32'hd4     
`define BUS_IDLE_TIMING       			                            32'hd8
`define SCL_LOW_MST_EXT_TIMEOUT       		                        32'hdc
`define I3C_VER_ID                                                  32'he0 					            
`define I3C_VER_TYPE               	                                32'he4
`define QUEUE_SIZE_CAPABILITY					                    32'he8 
`define DEV_CHAR_TABLE1_LOC1                                        32'h200
`define SEC_DEV_CHAR_TABLE1                                         32'h200
`define DEV_CHAR_TABLE1_LOC2                                        32'h204
`define DEV_CHAR_TABLE1_LOC3                                        32'h208
`define DEV_CHAR_TABLE1_LOC4                                        32'h20c
`define DEV_ADDR_TABLE1_LOC1                                        32'h220
`define DEV_ADDR_TABLE_LOC1                                         32'h280

`endif //I3C_DEFINE__SVH
