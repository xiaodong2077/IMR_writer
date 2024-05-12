#include "IMR_writer.h"

#include <string>

#include "IMR_struct.h"

namespace IMR {

Writer::Writer(const std::string& file_name) {
  imr_writer.open(file_name, std::ios::out | std::ios::binary);
}

Writer::~Writer() noexcept { imr_writer.close(); }

void Writer::WriteHeader(const Header& header) {
  imr_writer.write(reinterpret_cast<const char*>(header.szHeader), sizeof(header.szHeader));
  imr_writer.write(reinterpret_cast<const char*>(&header.bIsIntelOrMotorola),
                   sizeof(header.bIsIntelOrMotorola));
  imr_writer.write(reinterpret_cast<const char*>(&header.dVersionNumber),
                   sizeof(header.dVersionNumber));
  imr_writer.write(reinterpret_cast<const char*>(&header.bDeltaTheta), sizeof(header.bDeltaTheta));
  imr_writer.write(reinterpret_cast<const char*>(&header.bDeltaVelocity),
                   sizeof(header.bDeltaVelocity));
  imr_writer.write(reinterpret_cast<const char*>(&header.dDataRateHz), sizeof(header.dDataRateHz));
  imr_writer.write(reinterpret_cast<const char*>(&header.dGyroScaleFactor),
                   sizeof(header.dGyroScaleFactor));
  imr_writer.write(reinterpret_cast<const char*>(&header.dAccelScaleFactor),
                   sizeof(header.dAccelScaleFactor));
  imr_writer.write(reinterpret_cast<const char*>(&header.iUtcOrGpsTime),
                   sizeof(header.iUtcOrGpsTime));
  imr_writer.write(reinterpret_cast<const char*>(&header.iRcvTimeOrCorrTime),
                   sizeof(header.iRcvTimeOrCorrTime));
  imr_writer.write(reinterpret_cast<const char*>(&header.dTimeTagBias),
                   sizeof(header.dTimeTagBias));
  imr_writer.write(reinterpret_cast<const char*>(header.szImuName), sizeof(header.szImuName));
  imr_writer.write(reinterpret_cast<const char*>(header.reserved1), sizeof(header.reserved1));
  imr_writer.write(reinterpret_cast<const char*>(header.szProgramName),
                   sizeof(header.szProgramName));
  imr_writer.write(reinterpret_cast<const char*>(header.tCreate), sizeof(header.tCreate));
  imr_writer.write(reinterpret_cast<const char*>(&header.bLeverArmValid),
                   sizeof(header.bLeverArmValid));
  imr_writer.write(reinterpret_cast<const char*>(&header.lXoffset), sizeof(header.lXoffset));
  imr_writer.write(reinterpret_cast<const char*>(&header.lYoffset), sizeof(header.lYoffset));
  imr_writer.write(reinterpret_cast<const char*>(&header.lZoffset), sizeof(header.lZoffset));
  imr_writer.write(reinterpret_cast<const char*>(header.Reserved), sizeof(header.Reserved));
}
void Writer::WriteRecord(const Record& record) {
  imr_writer.write(reinterpret_cast<const char*>(&record.Time), sizeof(record.Time));
  imr_writer.write(reinterpret_cast<const char*>(&record.gx), sizeof(record.gx));
  imr_writer.write(reinterpret_cast<const char*>(&record.gy), sizeof(record.gy));
  imr_writer.write(reinterpret_cast<const char*>(&record.gz), sizeof(record.gz));
  imr_writer.write(reinterpret_cast<const char*>(&record.ax), sizeof(record.ax));
  imr_writer.write(reinterpret_cast<const char*>(&record.ay), sizeof(record.ay));
  imr_writer.write(reinterpret_cast<const char*>(&record.az), sizeof(record.az));
}

void Writer::WriteHeaderDirectly(const Header& header) {
  imr_writer.write(reinterpret_cast<const char*>(&header), sizeof(header));
}
void Writer::WriteRecordDirectly(const Record& record) {
  imr_writer.write(reinterpret_cast<const char*>(&record), sizeof(record));
}
}  // namespace IMR