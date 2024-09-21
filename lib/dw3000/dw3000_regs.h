#ifndef __DW3000_REGS_H__
#define __DW3000_REGS_H__

/******************************************************************************
* @brief Bit definitions for register 0
**/
#define DW3000_REG_0_ADDR                                 0x00

#define DW3000_REG_0_DEV_ID_OFFSET                        0x00                  
#define DW3000_REG_0_DEV_ID_LEN                           (4U)                
#define DW3000_REG_0_DEV_ID_MASK                          0xFFFFFFFFUL        
#define DW3000_REG_0_DEV_ID_RIDTAG_BIT_OFFSET             (16U)               
#define DW3000_REG_0_DEV_ID_RIDTAG_BIT_LEN                (16U)               
#define DW3000_REG_0_DEV_ID_RIDTAG_BIT_MASK               0xffff0000UL         
#define DW3000_REG_0_DEV_ID_MODEL_BIT_OFFSET              (8U)                
#define DW3000_REG_0_DEV_ID_MODEL_BIT_LEN                 (8U)                
#define DW3000_REG_0_DEV_ID_MODEL_BIT_MASK                0xff00U              
#define DW3000_REG_0_DEV_ID_VER_BIT_OFFSET                (4U)                
#define DW3000_REG_0_DEV_ID_VER_BIT_LEN                   (4U)                
#define DW3000_REG_0_DEV_ID_VER_BIT_MASK                  0xf0U                
#define DW3000_REG_0_DEV_ID_REV_BIT_OFFSET                (0U)                
#define DW3000_REG_0_DEV_ID_REV_BIT_LEN                   (4U)                
#define DW3000_REG_0_DEV_ID_REV_BIT_MASK                  0xfU  

#define DW3000_REG_0_EUI_64_LO_OFFSET                     0x04                  
#define DW3000_REG_0_EUI_64_LO_LEN                        (4U)                
#define DW3000_REG_0_EUI_64_LO_MASK                       0xFFFFFFFFUL        
#define DW3000_REG_0_EUI_64_LO_EUI_64_BIT_OFFSET          (0U)                
#define DW3000_REG_0_EUI_64_LO_EUI_64_BIT_LEN             (32U)               
#define DW3000_REG_0_EUI_64_LO_EUI_64_BIT_MASK            0xffffffffUL       

#define DW3000_REG_0_EUI_64_HI_OFFSET                     0x08                  
#define DW3000_REG_0_EUI_64_HI_LEN                        (4U)                
#define DW3000_REG_0_EUI_64_HI_MASK                       0xFFFFFFFFUL        
#define DW3000_REG_0_EUI_64_HI_EUI_64_BIT_OFFSET          (0U)                
#define DW3000_REG_0_EUI_64_HI_EUI_64_BIT_LEN             (32U)               
#define DW3000_REG_0_EUI_64_HI_EUI_64_BIT_MASK            0xffffffffUL    

#define DW3000_REG_0_PANADR_OFFSET                        0x0c                 
#define DW3000_REG_0_PANADR_LEN                           (4U)                
#define DW3000_REG_0_PANADR_MASK                          0xFFFFFFFFUL        
#define DW3000_REG_0_PANADR_PAN_ID_BIT_OFFSET             (16U)               
#define DW3000_REG_0_PANADR_PAN_ID_BIT_LEN                (16U)               
#define DW3000_REG_0_PANADR_PAN_ID_BIT_MASK               0xffff0000UL         
#define DW3000_REG_0_PANADR_SHORTADDR_BIT_OFFSET          (0U)                
#define DW3000_REG_0_PANADR_SHORTADDR_BIT_LEN             (16U)               
#define DW3000_REG_0_PANADR_SHORTADDR_BIT_MASK            0xffffU     



#endif // __DW3000_REGS_H__