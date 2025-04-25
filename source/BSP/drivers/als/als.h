#ifndef _ALS_H_
#define _ALS_H_

/**
	@struct als_info_t
	@brief Struct containing configurations information pertaining to the light sensor module.
 **/
typedef struct
{
	/** Manufacturer ID**/
	uint8_t ManufacturerID;
	/** Part ID**/
	uint8_t PartID;
}als_info_t;

bool als_init(void);
bool get_als_info(als_info_t* info);
bool get_als_lux(float* lux);

#endif //_ALS_H_
