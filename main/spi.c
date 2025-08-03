#include "spi.h"

#include "driver/spi_master.h"   //SPI header :ESP-IDF platform

#define OLED_HOST  HSPI_HOST  //SPI Peripheral :ESP_IDF platform

//pin definitions :ESP32
//replace with your gpio pins
int8_t mosiPin = 13;    // (Master Out Slave In) - SPI
int8_t clkPin  = 14;    // (Clock Pin) - SPI
int8_t dcPin   = 4;     // (Data Pin) - SPI
int8_t csPin   = 2;     // (Chip Select Pin) - SPI 
int8_t rstPin  = 16;    // Display reset pin assignment

spi_device_handle_t spi_dev;     //SPI Handle :ESP-IDF platform

/**  
 * @brief  init function for spi peripheral
 * @param  None
 * @retval None.
 * @note   called in oled_begin function to init peripheral.
 *         updated according to ESP-IDF platform
*/
void spi_init(void){
    printf("spi init.\n");

    //spi initialization code
    spi_bus_config_t buscfg={
        .mosi_io_num=mosiPin,
        .miso_io_num=-1,
        .sclk_io_num=clkPin,
        .quadwp_io_num=-1,
        .quadhd_io_num=-1,
        .max_transfer_sz=4096,
    };
    //Initialize the SPI bus
    esp_err_t ret=spi_bus_initialize(OLED_HOST, &buscfg, SPI_DMA_CH_AUTO);
    ESP_ERROR_CHECK(ret);

    spi_device_interface_config_t devcfg={
        .clock_speed_hz=10*1000*1000,           //Clock out at 1 MHz
        .mode=0,                                //SPI mode 0
        .spics_io_num=csPin,               //CS pin
        .queue_size = 1,
    };
    //Attach the OLED to the SPI bus
    ret=spi_bus_add_device(OLED_HOST, &devcfg, &spi_dev);
    ESP_ERROR_CHECK(ret);
}

/**  
 * @brief  transfer function for spi peripheral
 * @param  c buffer with transfer data
 * @param  len length of buffer
 * @retval None.
 * @note   called in commandlist and datalist function
 *         updated according to ESP-IDF platform
*/
void spi_transfer(uint8_t *c,size_t len){
    printf("spi_transfer called. len = %d, buf addr = %p\n", (int)len, c);

    //spi mosi data transfer code
    assert(spi_dev != NULL);
    spi_transaction_t spi_transaction = {
        .length=len*8,              //transaction length is in bits.
        .tx_buffer=c,               //Data
        .rx_buffer=NULL,
    };
    esp_err_t ret=spi_device_polling_transmit(spi_dev, &spi_transaction);  //Transmit!
    ESP_ERROR_CHECK(ret);                      //Check if issues.
}

/**  
 * @brief  Reset function for spi peripheral
 * @param  level logic level for reset pin
 * @retval None.
 * @note   called in oled_begin function
 *         updated according to ESP-IDF platform
*/
void spi_reset(bool level){
  //reset pin high or low
  gpio_set_level(rstPin, level);
}

/**  
 * @brief  Chp Select function for spi peripheral
 * @param  level logic level for cs pin
 * @retval None.
 * @note   called before and after spi transaction
 *         updated according to ESP-IDF platform
*/
void spi_set_cs(bool level){
  //cs pin high or low
  gpio_set_level(csPin, level);
}

/**  
 * @brief  Data/Command function for spi peripheral
 * @param  level logic level for dc pin
 * @retval None.
 * @note   called before sending data or command
 *         updated according to ESP-IDF platform
*/
void spi_set_dc(bool level){
  //dc pin high or low
  gpio_set_level(dcPin, level);
}