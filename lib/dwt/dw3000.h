#ifndef __DW3000_H__
#define __DW3000_H__

#include "dw3000_regs.h"
#include "dw3000_interface.h"

#define DW3000_DRIVER_VERSION 0
#define DW3000_DEV_ID 0xDECA0302u

typedef enum
{
    DWT_SUCCESS = 0,
    DWT_ERROR = -1,
    DWT_ERR_PLL_LOCK = -2,
    DWT_ERR_RX_CAL_PGF = -3,
    DWT_ERR_RX_CAL_RESI = -4,
    DWT_ERR_RX_CAL_RESQ = -5,
    DWT_ERR_RX_ADC_CAL = -6,
} dwt_error_e;


/********************************************************************************************************************/
/*                                                     API LIST                                                     */
/********************************************************************************************************************/

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to return the read device type and revision information of the DW UWB chip
 *
 * input parameters
 *
 * output parameters
 *
 * returns the silicon DevID
 */
uint32_t dwt_readdevid(void);


/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function resets the DW3000
 *
 * NOTE: SPI rate must be <= 7MHz before a call to this function as the device will use FOSC/4 as part of internal reset
 *
 * input parameters:
 * @param reset_semaphore - if set to 1 the semaphore will be also reset. (only valid for DW3720 device)
 *
 * output parameters
 *
 * no return value
 */
void dwt_softreset(int reset_semaphore);


/*! ------------------------------------------------------------------------------------------------------------------
 *
 * @brief this function clears the AON configuration in DW3000
 *
 * input parameters:
 *
 * output parameters
 *
 * no return value
 */
void dwt_clearaonconfig(void);







#endif // __DW3000_H__