#ifndef __DW3000_INTERFACE_H__
#define __DW3000_INTERFACE_H__

#include <stdint.h>

/*! ------------------------------------------------------------------------------------------------------------------
    * @brief The dwt_spi_s structure is a structure assembling all the SPI functions that must be defined externally
    * NB: In porting this to a particular microprocessor, the implementer needs to define the low
    * level abstract functions matching the selected hardware.
*/
struct dwt_spi_s
{
/*! ------------------------------------------------------------------------------------------------------------------
    * @brief readfromspi
    * Low level abstract function to read from the SPI
    * Takes two separate byte buffers for write header and read data
    * input parameters:
    * @param headerLength  - number of bytes header to write
    * @param headerBuffer  - pointer to buffer containing the 'headerLength' bytes of header to write
    * @param readlength    - number of bytes data being read
    * @param readBuffer    - pointer to buffer containing to return the data (NB: size required = headerLength + readlength)
    *
    * output parameters:
    * returns DWT_SUCCESS for success, or DWT_ERROR for error
    */
    int (*readfromspi)(uint16_t headerLength, /*const*/ uint8_t *headerBuffer, uint16_t readlength, uint8_t *readBuffer);

/*! ------------------------------------------------------------------------------------------------------------------
    * @brief writetospi
    * Low level abstract function to write to the SPI
    * Takes two separate byte buffers for write header and write data
    * input parameters:
    * @param headerLength  - number of bytes header being written
    * @param headerBuffer  - pointer to buffer containing the 'headerLength' bytes of header to be written
    * @param bodylength    - number of bytes data being written
    * @param bodyBuffer    - pointer to buffer containing the 'bodylength' bytes od data to be written
    *
    * output parameters:
    * returns DWT_SUCCESS for success, or DWT_ERROR for error
    */
    int (*writetospi)(uint16_t headerLength, const uint8_t *headerBuffer, uint16_t bodyLength, const uint8_t *bodyBuffer);

/*! ------------------------------------------------------------------------------------------------------------------
    * @brief writetospiwithcrc
    * Low level abstract function to write to the SPI, this should be used when DW3000 SPI CRC mode is used
    * Takes two separate byte buffers for write header and write data
    * input parameters:
    * @param headerLength  - number of bytes header being written
    * @param headerBuffer  - pointer to buffer containing the 'headerLength' bytes of header to be written
    * @param bodylength    - number of bytes data being written
    * @param bodyBuffer    - pointer to buffer containing the 'bodylength' bytes od data to be written
    * @param crc8          - 8-bit crc, calculated on the header and data bytes
    *
    * output parameters:
    * returns DWT_SUCCESS for success, or DWT_ERROR for error
    */
    int (*writetospiwithcrc)(uint16_t headerLength, const uint8_t *headerBuffer, uint16_t bodyLength, const uint8_t *bodyBuffer, uint8_t crc8);

    /*! ------------------------------------------------------------------------------------------------------------------
     * @brief setslowrate
     * Low level abstract function to switch the SPI into slow rate mode
     *
     * input parameters:
     *
     * output parameters
     *
     */
    void (*setslowrate)(void);

    /*! ------------------------------------------------------------------------------------------------------------------
     * @brief setspifastrate
     * Low level abstract function to switch the SPI into fast rate mode
     *
     * input parameters:
     *
     * output parameters
     *
     */
    void (*setfastrate)(void);
};

/*The contract is that we have the SPI interface to the DW chip*/
struct dwchip_s {
    /*HAL*/
    struct dwt_spi_s *SPI; // first
};

struct dwlibutils_s {
    void (*delayms)(uint32_t delay);
};

extern struct dwchip_s dw3000_hw;
extern struct dwlibutils_s dwlibutils;

extern void dw3000_interface_init(void);

#endif // __DW3000_INTERFACE_H__
