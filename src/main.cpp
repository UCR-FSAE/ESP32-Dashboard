#include <Arduino.h>
#include "EVE.h"

void setup() {
  EVE_init();
}
//all from READme

void loop() {
  EVE_start_cmd_burst();
  EVE_cmd_dl_burst(CMD_DLSTART);
  EVE_cmd_dl_burst(DL_CLEAR_COLOR_RGB | 0xFFFFFF);
  EVE_cmd_dl_burst(DL_CLEAR | CLR_COL | CLR_STN | CLR_TAG);
  EVE_color_rgb_burst(0x000000);
  EVE_cmd_text_burst(5, 15, 28, 0, "Hello there!");
  EVE_cmd_dl_burst(DL_DISPLAY);
  EVE_cmd_dl_burst(CMD_SWAP);
  EVE_end_cmd_burst();
  while (EVE_busy());
}