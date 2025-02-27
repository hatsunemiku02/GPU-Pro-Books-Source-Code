// This file was created by Filewrap 1.1
// Little endian mode
// DO NOT EDIT

#include "../PVRTMemoryFileSystem.h"

// using 32 bit to guarantee alignment.
#ifndef A32BIT
 #define A32BIT static const unsigned int
#endif

// ******** Start: SlowFragShader.fsh ********

// File data
static const char _SlowFragShader_fsh[] = 
	"varying lowp vec3  DiffuseIntensity; \r\n"
	"varying lowp vec3  SpecularIntensity;\r\n"
	"\r\n"
	"const lowp vec3 cBaseColor = vec3(0.9, 0.1, 0.1); \r\n"
	" \r\n"
	"void main() \r\n"
	"{ \r\n"
	"\tgl_FragColor = vec4((cBaseColor * DiffuseIntensity) + SpecularIntensity, 1.0); \r\n"
	"}\r\n";

// Register SlowFragShader.fsh in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_SlowFragShader_fsh("SlowFragShader.fsh", _SlowFragShader_fsh, 238);

// ******** End: SlowFragShader.fsh ********

// This file was created by Filewrap 1.1
// Little endian mode
// DO NOT EDIT

#include "../PVRTMemoryFileSystem.h"

// using 32 bit to guarantee alignment.
#ifndef A32BIT
 #define A32BIT static const unsigned int
#endif

// ******** Start: SlowFragShader.fsc ********

// File data
A32BIT _SlowFragShader_fsc[] = {
0x10fab438,0xb0f9e8cc,0x30050100,0x2101,0xa9142cc2,0x0,0x0,0x61020000,0x1000000,0x4000000,0x0,0x18000000,0x303,0x0,0x1010000,0x0,0x0,0xe6000000,0x55535020,0x17,0xda,0x1,0x0,0x848,0x0,0x2,0x79,0x0,0x8,0x0,0xffffffff,0x0,0x770009,0xffff,0x2,0x0,0x30002,0x0,0x0,0x0,0x0,0xfffc0000,0x3,0x10004,0x0,0x20000,0xffffffff,0x10000,0x40000,0x10000,0x30003,0x4,0x30002,0x30003,0x0,0x30014,0x1,0x3000a,0x2,0x40000,0x20000,0x2,0x20003,0x80018001,
0x80018001,0x0,0x0,0x4,0x1000012,0x0,0x64c0fd10,0x806e810,0x2038c880,0x69000,0x68181,0x0,0x5020e600,0x175553,0xda0000,0x10000,0x0,0x9480000,0x0,0x20000,0x790000,0x0,0x80000,0x0,0xffff0000,0xffff,0x90000,0xffff0077,0x20000,0x1,0x20000,0x3,0x0,0x0,0x0,0x0,0x1fffc,0x40000,0x1,0x0,0xffff0002,0xffff,0x1,0x4,0x30001,0x40003,0x20000,0x30003,0x3,0x140000,0x10003,0xa0000,0x20003,0x0,0x4,0x20002,0x30000,0x80010002,0x80018001,0x8001,0x0,0x40000,0x120000,0x100,
0xfd100000,0xe81064c0,0xc8800804,0x10002038,0x81810004,0x6,0x663f0800,0xcc3d6666,0xcc3dcdcc,0xcdcc,0x0,0x0,0x0,0x803f0000,0x2000000,0x66666944,0x49657375,0x6e65746e,0x79746973,0x4000000,0x1000005,0x10000,0x7000300,0x70530000,0x6c756365,0x6e497261,0x736e6574,0x797469,0x5040000,0x10000,0x4000100,0x70003,0x0,
};

// Register SlowFragShader.fsc in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_SlowFragShader_fsc("SlowFragShader.fsc", _SlowFragShader_fsc, 641);

// ******** End: SlowFragShader.fsc ********

