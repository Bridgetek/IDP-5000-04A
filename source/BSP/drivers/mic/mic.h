#ifndef _MIC_H_
#define _MIC_H_

bool mic_init(void);
bool mic_exit();
uint32_t mic_available();
uint32_t mic_read(uint8_t* buff, uint32_t len);

#endif //_MIC_H_
