#ifndef IMR_WRITER_IMR_STRUCT_H
#define IMR_WRITER_IMR_STRUCT_H

#include <cstdint>

namespace IMR {
#pragma pack(push, 1)
struct Header {
  char szHeader[8] = "$IMURAW";  // "$IMURAW\0"

  int8_t bIsIntelOrMotorola = 0;  // 0 表示小端字节序， 1表示大端字节序

  double dVersionNumber = 8.30;  // ie程序版本号

  int32_t bDeltaTheta = 0;  // 0 角速度（常用单位为deg/s）
                            // 1 （默认）角度增量（deg）

  int32_t bDeltaVelocity = 0;  // 0 加速度（严格说应该是比力，常用单位为m/s2或g）
                               // 1 （默认）速度增量（m/s）

  double dDataRateHz = 50;  //  records/second

  double dGyroScaleFactor = 100000000;

  double dAccelScaleFactor = 980000000;

  int32_t iUtcOrGpsTime = 0;  // degines the time-tags as being in UTC or GPS
                              // seconds of the week
                              // 0 默认为GPS
                              // 1 UTC
                              // 2 GPS

  int32_t iRcvTimeOrCorrTime = 0;  // whether the gps time-tags are on the
                                   // nominal top of the second or are corrected
                                   // for receiver time bias
                                   // 0 default correctedtime
                                   // 1 receive time on the nominal top of the epoch
                                   // 2 corrected time. corr_time = rev_time - ecvr_clock_bias

  double dTimeTagBias = 0.0;  // GPS -> IMU millisecond-level bias

  char szImuName[32] = "imu";  // Name or type of inertial unit that is being used

  uint8_t reserved1[4];

  char szProgramName[32] = "p";  // Name of calling program; skip if writing
                                 // directly to this format

  char tCreate[12];  // Creation time;  skip if writing directly to this  format

  bool bLeverArmValid = false;  //  Lever arm is from IMU to GPS phase centre.

  int32_t lXoffset;  // X value of lever arm  单位mm

  int32_t lYoffset;

  int32_t lZoffset;

  int8_t Reserved[354];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct Record {
  double  Time;
  int32_t gx;
  int32_t gy;
  int32_t gz;
  int32_t ax;
  int32_t ay;
  int32_t az;
};
#pragma pack(pop)
}  // namespace IMR
#endif  // IMR_WRITER_IMR_STRUCT_H