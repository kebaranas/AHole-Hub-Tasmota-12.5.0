/*
  xdrv_31_axp192.ino - AXP192 power manangement IC support for Tasmota

  SPDX-FileCopyrightText: 2023 Kyle Aranas

  SPDX-License-Identifier: GPL-3.0-only
*/

#ifdef USE_I2C
#ifdef USE_AXP192
/*********************************************************************************************\
 * AXP192 - Power management IC used in LilyGo T-PCIE
 *
 * Based on datasheet from http://www.x-powers.com/en.php/Info/product_detail/article_id/29
 *
 * I2C Address: 0x68
\*********************************************************************************************/

#define XDRV_128                128
#define XI2C_80                 80           // See I2CDEVICES.md

#define MIN_BATTERY_VOLTAGE 3600
#define MAX_BATTERY_VOLTAGE 4200
#define NUM_READINGS 10

#include <Wire.h>
#include "axp20x.h"

AXP20X_Class axp;

struct AXPSTRUCT {
  // uint8_t capacity = 0;
  bool battery = false;
  bool charging = false;
  bool done = false;
  float voltage = NAN;
} Axp;

void Axp192Init(void) {
  if (!I2cSetDevice(AXP192_SLAVE_ADDRESS)) {
    return;
  }
  if (axp.begin(Wire, AXP192_SLAVE_ADDRESS) == AXP_FAIL) {
    return;
  }
}

void Axp192Read(void) {
  Axp.voltage = axp.getBattVoltage();
  // float voltage = (axp.getBattVoltage() > MAX_BATTERY_VOLTAGE) ? MAX_BATTERY_VOLTAGE : axp.getBattVoltage();
  // Axp.capacity = floor((((voltage - MIN_BATTERY_VOLTAGE) / (MAX_BATTERY_VOLTAGE - MIN_BATTERY_VOLTAGE)) * 100) + 0.5);
  Axp.battery = axp.isBatteryConnect();
  Axp.charging = axp.isCharging();
}

void Axp192Show(bool json) {
  if (json) {

  } else {
    char voltage[FLOATSZ];
    dtostrfd(Axp.voltage, 0, voltage);
    if (Axp.battery) {
      WSContentSend_PD(HTTP_SNS_BATTERY_STATUS, voltage, Axp.charging ? D_CHARGING : D_NOT_CHARGING);
    } else {
      WSContentSend_PD(HTTP_SNS_BATTERY_STATUS, "0", D_NO_BATTERY);
    }
    
  }
}

void Axp192EverySecond(void) {
  if (!(TasmotaGlobal.uptime %1)) {  // Every 1 second
    Axp192Read();
  }
}

/*********************************************************************************************\
 * Interface
\*********************************************************************************************/
bool Xdrv128(uint32_t function) {
  if (!I2cEnabled(XI2C_80)) { return false; }

  bool result = false;
  switch (function) {
    case FUNC_INIT:
      Axp192Init();
      break;
    case FUNC_EVERY_SECOND:
      Axp192EverySecond();
      break;
    case FUNC_JSON_APPEND:
      break;
  #ifdef USE_WEBSERVER
    case FUNC_WEB_SENSOR:
      Axp192Show(0);
      break;
  #endif  // USE_WEBSERVER
  }
  return result;
}

#endif  // USE_AXP192
#endif  // USE_I2C
