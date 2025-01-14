#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer Params
// {
//
//   uint width;                        // Offset:    0 Size:     4 [unused]
//   uint height;                       // Offset:    4 Size:     4 [unused]
//   uint keycolor0;                    // Offset:    8 Size:     4
//   uint keycolor1;                    // Offset:   12 Size:     4
//   float rangeMin;                    // Offset:   16 Size:     4
//   float rangeMax;                    // Offset:   20 Size:     4
//   float rangeExt;                    // Offset:   24 Size:     4
//   float lumaMin;                     // Offset:   28 Size:     4 [unused]
//   uint enableEdge;                   // Offset:   32 Size:     4 [unused]
//   uint enableAdvanced;               // Offset:   36 Size:     4
//   uint debug;                        // Offset:   40 Size:     4
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// planeIn                           texture   unorm          2d             t0      1 
// planeInUV                         texture  unorm2          2d             t1      1 
// planeOut                              UAV   unorm          2d             u0      1 
// planeOutUV                            UAV  unorm2          2d             u1      1 
// planeOutMask                          UAV   unorm          2d             u2      1 
// Params                            cbuffer      NA          NA            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Output
cs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[3], immediateIndexed
dcl_resource_texture2d (unorm,unorm,unorm,unorm) t0
dcl_resource_texture2d (unorm,unorm,unorm,unorm) t1
dcl_uav_typed_texture2d (unorm,unorm,unorm,unorm) u0
dcl_uav_typed_texture2d (unorm,unorm,unorm,unorm) u1
dcl_uav_typed_texture2d (unorm,unorm,unorm,unorm) u2
dcl_input vThreadID.xy
dcl_temps 7
dcl_thread_group 8, 8, 1
resinfo_indexable(texture2d)(unorm,unorm,unorm,unorm) r0.xy, l(0), t0.xyzw
ftoi r0.xy, r0.xyxx
ige r0.xy, vThreadID.xyxx, r0.xyxx
or r0.x, r0.y, r0.x
if_nz r0.x
  ret 
endif 
ushr r0.xy, vThreadID.xyxx, l(1, 1, 0, 0)
mov r1.xy, vThreadID.xyxx
mov r1.zw, l(0,0,0,0)
ld_indexable(texture2d)(unorm,unorm,unorm,unorm) r1.x, r1.xyzw, t0.xyzw
mov r0.zw, l(0,0,0,0)
ld_indexable(texture2d)(unorm,unorm,unorm,unorm) r2.yz, r0.xyzw, t1.zxyw
ubfe r0.zw, l(0, 0, 10, 10), l(0, 0, 10, 10), cb0[0].zzzw
utof r0.zw, r0.zzzw
and r3.xy, cb0[0].zwzz, l(1023, 1023, 0, 0)
utof r3.xy, r3.xyxx
mad r0.zw, -r0.zzzw, l(0.000000, 0.000000, 0.000977, 0.000977), r2.yyyy
mad r3.xy, -r3.xyxx, l(0.000977, 0.000977, 0.000000, 0.000000), r2.zzzz
mul r3.xy, r3.xyxx, r3.xyxx
mad r0.zw, r0.zzzw, r0.zzzw, r3.xxxy
min r0.z, r0.w, r0.z
and r0.w, cb0[2].z, l(1)
movc r3.xyz, r0.wwww, l(0.901961,0.500000,0.500000,0), l(0,0.500000,0.500000,0)
ine r1.w, cb0[2].y, l(0)
lt r4.xy, r2.yzyy, l(0.580392, 0.580392, 0.000000, 0.000000)
and r1.w, r1.w, r4.x
and r1.w, r4.y, r1.w
ge r4.xy, cb0[1].xyxx, r0.zzzz
add r0.z, r0.z, -cb0[1].x
add r4.z, -cb0[1].x, cb0[1].z
div r0.z, r0.z, r4.z
mad r5.w, r0.z, l(0.996078), l(0.003922)
movc r5.x, r0.w, l(0.500000), r1.x
mov r5.yz, l(0,0.500000,0.500000,0)
dp2 r0.z, r2.yzyy, r2.yzyy
lt r0.z, r0.z, cb0[1].z
mov r1.yz, l(0,0.500000,0.500000,0)
movc r6.xyz, r0.wwww, l(1.000000,1.000000,0,0), r1.xyzx
mov r6.w, l(0.500000)
mov r2.x, r1.x
mov r2.w, l(1.000000)
movc r6.xyzw, r0.zzzz, r6.xyzw, r2.xyzw
movc r5.xyzw, r4.yyyy, r5.xyzw, r6.xyzw
mov r2.w, l(0.500000)
movc r1.xyzw, r1.wwww, r2.xyzw, r5.xyzw
mov r3.w, l(0)
movc r1.xyzw, r4.xxxx, r3.xyzw, r1.xyzw
store_uav_typed u0.xyzw, vThreadID.xyyy, r1.xxxx
store_uav_typed u1.xyzw, r0.xyyy, r1.yzyy
store_uav_typed u2.xyzw, vThreadID.xyyy, r1.wwww
ret 
// Approximately 52 instruction slots used
#endif

const BYTE ChromaKeyProcess_CS[] =
{
     68,  88,  66,  67, 101, 158, 
     96, 198,  37,  99,  47, 195, 
    136, 179,  11,  23, 212,  55, 
     61, 140,   1,   0,   0,   0, 
    168,  11,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     40,   4,   0,   0,  56,   4, 
      0,   0,  72,   4,   0,   0, 
     12,  11,   0,   0,  82,  68, 
     69,  70, 236,   3,   0,   0, 
      1,   0,   0,   0,  56,   1, 
      0,   0,   6,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
     83,  67,   0,   1,   0,   0, 
    194,   3,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    252,   0,   0,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   4,   1,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      5,   0,   0,   0,  14,   1, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     23,   1,   0,   0,   4,   0, 
      0,   0,   1,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   1,   0,   0,   0, 
      1,   0,   0,   0,   5,   0, 
      0,   0,  34,   1,   0,   0, 
      4,   0,   0,   0,   1,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   2,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  47,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    112, 108,  97, 110, 101,  73, 
    110,   0, 112, 108,  97, 110, 
    101,  73, 110,  85,  86,   0, 
    112, 108,  97, 110, 101,  79, 
    117, 116,   0, 112, 108,  97, 
    110, 101,  79, 117, 116,  85, 
     86,   0, 112, 108,  97, 110, 
    101,  79, 117, 116,  77,  97, 
    115, 107,   0,  80,  97, 114, 
     97, 109, 115,   0, 171, 171, 
     47,   1,   0,   0,  11,   0, 
      0,   0,  80,   1,   0,   0, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   3,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,  20,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  56,   3, 
      0,   0,   4,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,  20,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  63,   3,   0,   0, 
      8,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
     20,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     73,   3,   0,   0,  12,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0,  20,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  83,   3, 
      0,   0,  16,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0, 100,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 136,   3,   0,   0, 
     20,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    100,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    145,   3,   0,   0,  24,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0, 100,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 154,   3, 
      0,   0,  28,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0, 100,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 162,   3,   0,   0, 
     32,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
     20,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    173,   3,   0,   0,  36,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0,  20,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 188,   3, 
      0,   0,  40,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0,  20,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 119, 105, 100, 116, 
    104,   0, 100, 119, 111, 114, 
    100,   0,   0,   0,  19,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  14,   3, 
      0,   0, 104, 101, 105, 103, 
    104, 116,   0, 107, 101, 121, 
     99, 111, 108, 111, 114,  48, 
      0, 107, 101, 121,  99, 111, 
    108, 111, 114,  49,   0, 114, 
     97, 110, 103, 101,  77, 105, 
    110,   0, 102, 108, 111,  97, 
    116,   0, 171, 171,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     92,   3,   0,   0, 114,  97, 
    110, 103, 101,  77,  97, 120, 
      0, 114,  97, 110, 103, 101, 
     69, 120, 116,   0, 108, 117, 
    109,  97,  77, 105, 110,   0, 
    101, 110,  97,  98, 108, 101, 
     69, 100, 103, 101,   0, 101, 
    110,  97,  98, 108, 101,  65, 
    100, 118,  97, 110,  99, 101, 
    100,   0, 100, 101,  98, 117, 
    103,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  49,  48,  46,  49,   0, 
    171, 171,  73,  83,  71,  78, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     79,  83,  71,  78,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  83,  72, 
     69,  88, 188,   6,   0,   0, 
     80,   0,   5,   0, 175,   1, 
      0,   0, 106,   8,   0,   1, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      0,   0,   0,   0,  17,  17, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   1,   0, 
      0,   0,  17,  17,   0,   0, 
    156,  24,   0,   4,   0, 224, 
     17,   0,   0,   0,   0,   0, 
     17,  17,   0,   0, 156,  24, 
      0,   4,   0, 224,  17,   0, 
      1,   0,   0,   0,  17,  17, 
      0,   0, 156,  24,   0,   4, 
      0, 224,  17,   0,   2,   0, 
      0,   0,  17,  17,   0,   0, 
     95,   0,   0,   2,  50,   0, 
      2,   0, 104,   0,   0,   2, 
      7,   0,   0,   0, 155,   0, 
      0,   4,   8,   0,   0,   0, 
      8,   0,   0,   0,   1,   0, 
      0,   0,  61,   0,   0, 137, 
    194,   0,   0, 128,  67,  68, 
      4,   0,  50,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,  27,   0,   0,   5, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  33,   0, 
      0,   6,  50,   0,  16,   0, 
      0,   0,   0,   0,  70,   0, 
      2,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  60,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  31,   0,   4,   3, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     21,   0,   0,   1,  85,   0, 
      0,   9,  50,   0,  16,   0, 
      0,   0,   0,   0,  70,   0, 
      2,   0,   2,  64,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   4,  50,   0,  16,   0, 
      1,   0,   0,   0,  70,   0, 
      2,   0,  54,   0,   0,   8, 
    194,   0,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  45,   0, 
      0, 137, 194,   0,   0, 128, 
     67,  68,   4,   0,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   8, 194,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     45,   0,   0, 137, 194,   0, 
      0, 128,  67,  68,   4,   0, 
     98,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  38, 125, 
     16,   0,   1,   0,   0,   0, 
    138,   0,   0,  16, 194,   0, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     10,   0,   0,   0,  10,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  10,   0,   0,   0, 
     10,   0,   0,   0, 166, 142, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  86,   0, 
      0,   5, 194,   0,  16,   0, 
      0,   0,   0,   0, 166,  14, 
     16,   0,   0,   0,   0,   0, 
      1,   0,   0,  11,  50,   0, 
     16,   0,   3,   0,   0,   0, 
    230, 138,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,  64,   0,   0, 255,   3, 
      0,   0, 255,   3,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  86,   0,   0,   5, 
     50,   0,  16,   0,   3,   0, 
      0,   0,  70,   0,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  13, 194,   0,  16,   0, 
      0,   0,   0,   0, 166,  14, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,  58,   0,   0, 128,  58, 
     86,   5,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,  13, 
     50,   0,  16,   0,   3,   0, 
      0,   0,  70,   0,  16, 128, 
     65,   0,   0,   0,   3,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  58,   0,   0, 
    128,  58,   0,   0,   0,   0, 
      0,   0,   0,   0, 166,  10, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7,  50,   0, 
     16,   0,   3,   0,   0,   0, 
     70,   0,  16,   0,   3,   0, 
      0,   0,  70,   0,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,   9, 194,   0,  16,   0, 
      0,   0,   0,   0, 166,  14, 
     16,   0,   0,   0,   0,   0, 
    166,  14,  16,   0,   0,   0, 
      0,   0,   6,   4,  16,   0, 
      3,   0,   0,   0,  51,   0, 
      0,   7,  66,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,   1,   0,   0,   8, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  55,   0, 
      0,  15, 114,   0,  16,   0, 
      3,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0, 231, 230, 
    102,  63,   0,   0,   0,  63, 
      0,   0,   0,  63,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,  63,   0,   0,   0,  63, 
      0,   0,   0,   0,  39,   0, 
      0,   8, 130,   0,  16,   0, 
      1,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     49,   0,   0,  10,  50,   0, 
     16,   0,   4,   0,   0,   0, 
    150,   5,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
    149, 148,  20,  63, 149, 148, 
     20,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   7, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   4,   0, 
      0,   0,   1,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     29,   0,   0,   8,  50,   0, 
     16,   0,   4,   0,   0,   0, 
     70, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    166,  10,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   9, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,  10, 
     66,   0,  16,   0,   4,   0, 
      0,   0,  10, 128,  32, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     14,   0,   0,   7,  66,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      4,   0,   0,   0,  50,   0, 
      0,   9, 130,   0,  16,   0, 
      5,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0, 255, 254, 
    126,  63,   1,  64,   0,   0, 
    129, 128, 128,  59,  55,   0, 
      0,   9,  18,   0,  16,   0, 
      5,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,  63,  10,   0,  16,   0, 
      1,   0,   0,   0,  54,   0, 
      0,   8,  98,   0,  16,   0, 
      5,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,  63,   0,   0, 
      0,  63,   0,   0,   0,   0, 
     15,   0,   0,   7,  66,   0, 
     16,   0,   0,   0,   0,   0, 
    150,   5,  16,   0,   2,   0, 
      0,   0, 150,   5,  16,   0, 
      2,   0,   0,   0,  49,   0, 
      0,   8,  66,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   8,  98,   0, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  63, 
      0,   0,   0,  63,   0,   0, 
      0,   0,  55,   0,   0,  12, 
    114,   0,  16,   0,   6,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  54,   0,   0,   5, 
    130,   0,  16,   0,   6,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  63,  54,   0, 
      0,   5,  18,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     54,   0,   0,   5, 130,   0, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  55,   0,   0,   9, 
    242,   0,  16,   0,   6,   0, 
      0,   0, 166,  10,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   6,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  55,   0,   0,   9, 
    242,   0,  16,   0,   5,   0, 
      0,   0,  86,   5,  16,   0, 
      4,   0,   0,   0,  70,  14, 
     16,   0,   5,   0,   0,   0, 
     70,  14,  16,   0,   6,   0, 
      0,   0,  54,   0,   0,   5, 
    130,   0,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  63,  55,   0, 
      0,   9, 242,   0,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      5,   0,   0,   0,  54,   0, 
      0,   5, 130,   0,  16,   0, 
      3,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     55,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   0,  16,   0,   4,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
    164,   0,   0,   6, 242, 224, 
     17,   0,   0,   0,   0,   0, 
     70,   5,   2,   0,   6,   0, 
     16,   0,   1,   0,   0,   0, 
    164,   0,   0,   7, 242, 224, 
     17,   0,   1,   0,   0,   0, 
     70,   5,  16,   0,   0,   0, 
      0,   0, 150,   5,  16,   0, 
      1,   0,   0,   0, 164,   0, 
      0,   6, 242, 224,  17,   0, 
      2,   0,   0,   0,  70,   5, 
      2,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    148,   0,   0,   0,  52,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
      2,   0,   0,   0,   6,   0, 
      0,   0,   2,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  10,   0,   0,   0, 
      7,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0
};
