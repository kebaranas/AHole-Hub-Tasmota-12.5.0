
/*
  support_ahole.ino - AHole Hub main support for Tasmota

  Copyright (C) 2023 Kyle Aranas

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#define PRESSURE_INDEX 0
#define TEMPERATURE_INDEX 1
#define DEPTH_INDEX 2
#define EC_INDEX 3
#define TDS_INDEX 4
#define SALINITY_INDEX 5
#define PH_INDEX 6
#define ORP_INDEX 7
#define DO_INDEX 8
#define TURBIDITY_INDEX 9
#define FLOW_RATE_INDEX 10

#define AMOUNT_OF_CHARTS 11

// const char aholeVersion[] PROGMEM = "0.5.0";
uint8_t maxDataPoints = 20;

const char jsChartVarNames[] PROGMEM = "pc|tc|dc|ecc|tdsc|sc|phc|orpc|doc|tbc|frc";
const char jsChartAddDatasetFuncNames[] PROGMEM = "pcads|tcads|dcads|eccads|tdscads|scads|phcads|orpads|docads|tbcads|frcads";
const char jsChartRemoveDatasetFuncNames[] PROGMEM = "pcrds|tcrds|dcrds|eccrds|tdscrds|scrds|phcrds|orprds|docrds|tbcrds|frcrds";
const char jsChartAddDataFuncNames[] PROGMEM = "pcad|tcad|dcad|eccad|tdscad|scad|phcad|orpad|docad|tbcad|frcad";
const char jsChartRemoveDataFuncNames[] PROGMEM = "pcrd|tcrd|dcrd|eccrd|tdscrd|scrd|phcrd|orprd|docrd|tbcrd|frcrd";
const char jsChartInitFuncNames[] PROGMEM = "pci|tci|dci|ecci|tdsci|sci|phci|orpi|doci|tbci|frci";
const char jsChartSensorName[] PROGMEM = D_PRESSURE "|" D_TEMPERATURE "|" D_DEPTH "|" D_EC "|" D_TDS "|" D_SALINITY "|" D_PH "|" D_ORP "|" D_DO "|" D_TURBIDITY "|" D_FLOW_RATE;
const char jsChartColors[] PROGMEM = COLOR_PALETTE_1 "|" COLOR_PALETTE_2 "|" COLOR_PALETTE_3 "|" COLOR_PALETTE_4 "|" COLOR_PALETTE_5 "|" COLOR_PALETTE_6 "|" COLOR_PALETTE_7 "|" COLOR_PALETTE_8 "|" COLOR_PALETTE_9 "|" COLOR_PALETTE_10 "|" COLOR_PALETTE_11;

const char siUnit[] PROGMEM = "Pa|°C|m|S/m|ppm|psu| |mV|ppm|NTU|L/min";
const char imperialUnit[] PROGMEM = "psi|°F|ft|S/ft|ppm|psu| |mV|ppm|NTU|gal/min";

bool isChartActive[AMOUNT_OF_CHARTS] = {true, true, true, true, true, true, true, true, true, true, true};
bool isSiUnit[AMOUNT_OF_CHARTS] = {true, true, true, true, true, true, true, true, true, true, true};

void AHoleInit(void) {

}