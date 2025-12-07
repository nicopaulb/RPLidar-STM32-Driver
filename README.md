# RPLIDAR Driver for STM32 (HAL Based)

This repository contains a lightweight and portable driver for RPLIDAR sensors running on STM32 microcontrollers built on top of the STM32 HAL.

It aims to provide a simple interface for scanning, parsing measurement data, and controlling the LIDAR over UART.

## Key Features

- **Universal RPLIDAR Support**: All RPLIDAR models use the same serial communication protocol, so this driver is designed to be compatible with all of them.
- **Non-blocking UART**: Uses DMA-based or blocking reception depending on configuration.
- **HAL Based** : All STM32 ICs should be supported.

## Getting Started

1. **Hardware Requirements**
- STM32 microcontroller with at least one free UART and DMA support (ex: STM32F411CEUx)
- RPLIDAR (any model; tested with RPLIDAR C1)

2. **STM32CubeMX Configuration**
- Enable USART (RX/TX) and set the baud rate depending on the RPLIDAR device (see datasheets, 460 800 bauds for RPLIDAR C1).
- Enable **circular** DMA for RX and TX
- Enable DMA for TX
- Ensure global and DMA interrup are enabled

4. **Import Driver**
- Copy `Core/Src/rplidar.c` into your project source directory
- Copy `Core/Inc/rplidar.h` into your project header directory

3. **Initialization Example**

```
UART_HandleTypeDef huart1;
...

RPLidar_Init(&huart1);

rplidar_health_t health;
if(RPLIDAR_RequestHealth(&health, 1000)) {
  if(health.status == 0) {
    RPLIDAR_StartScan(NULL, 0, 0);
  }
  else {
    printf("Error: RPLIDAR failure[%hu] with error code %hu", health.status, health.error_code);
  }
else {
  printf("Error: Cannot send or receive messages from RPLIDAR");
}

...
```

## Example

This repository contains a minimal STM32CubeIDE project for STM32F411CEUx, demonstrating the basic usage of the driver.

This example shows how to:
  - Configure UART with DMA to continuously receive lidar data
  - Initialize the RPLIDAR driver
  - Read and print the device health status
  - Start a scanning session
  - Parse and print distance + angle samples received from the RPLIDAR

## Testing

This driver has been successfully tested with:
 - RPLIDAR C1

Other models should work because they implement the same serial command set and response structure.

If you test another model, contributions and reports are welcome!

Unit tests on the parsing functions are implemented, but coverage should be extended.

## License

MIT License. See LICENSE for details.
