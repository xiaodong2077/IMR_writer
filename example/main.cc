#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "IMR_struct.h"
#include "IMR_writer.h"

void Convert() {
  IMR::Writer writer("output.imr");

  // modify header
  IMR::Header header;
  writer.WriteHeader(header);

  // imu raw data to record
  std::ifstream file("../example/input.txt");
  if (!file.is_open()) {
    std::cerr << "Failed to open file." << std::endl;
  }
  std::string line;
  while (std::getline(file, line)) {
    IMR::Record record;

    std::vector<std::string> values;
    std::stringstream        ss(line);
    std::string              field;
    char                     delimiter = ',';
    while (std::getline(ss, field, delimiter)) {
      size_t colonPos = field.find(':');
      if (colonPos != std::string::npos) {
        std::string valueStr = field.substr(colonPos + 1);
        values.push_back(valueStr);
      }
    }
    // 从values获取record
    record.Time = std::stod(values[1]);
    record.ax = static_cast<int32_t>(header.dAccelScaleFactor * std::stod(values[2]));
    record.ay = static_cast<int32_t>(header.dAccelScaleFactor * std::stod(values[3]));
    record.az = static_cast<int32_t>(header.dAccelScaleFactor * std::stod(values[4]));
    record.gx = static_cast<int32_t>(header.dGyroScaleFactor * std::stod(values[5]));
    record.gy = static_cast<int32_t>(header.dGyroScaleFactor * std::stod(values[6]));
    record.gz = static_cast<int32_t>(header.dGyroScaleFactor * std::stod(values[7]));

    writer.WriteRecord(record);
  }
  file.close();
}

void ConvertDirectly() {
  IMR::Writer writer("output-no-padding.imr");

  // modify header
  IMR::Header header;
  writer.WriteHeaderDirectly(header);

  // imu raw data to record
  std::ifstream file("input.txt");
  if (!file.is_open()) {
    std::cerr << "Failed to open file." << std::endl;
  }
  std::string line;
  while (std::getline(file, line)) {
    IMR::Record record;

    std::vector<std::string> values;
    std::stringstream        ss(line);
    std::string              field;
    char                     delimiter = ',';
    while (std::getline(ss, field, delimiter)) {
      size_t colonPos = field.find(':');
      if (colonPos != std::string::npos) {
        std::string valueStr = field.substr(colonPos + 1);
        values.push_back(valueStr);
      }
    }
    // 从values获取record
    record.Time = std::stod(values[1]);
    record.ax = static_cast<int32_t>(header.dAccelScaleFactor * std::stod(values[2]));
    record.ay = static_cast<int32_t>(header.dAccelScaleFactor * std::stod(values[3]));
    record.az = static_cast<int32_t>(header.dAccelScaleFactor * std::stod(values[4]));
    record.gx = static_cast<int32_t>(header.dGyroScaleFactor * std::stod(values[5]));
    record.gy = static_cast<int32_t>(header.dGyroScaleFactor * std::stod(values[6]));
    record.gz = static_cast<int32_t>(header.dGyroScaleFactor * std::stod(values[7]));

    writer.WriteRecordDirectly(record);
  }
  file.close();
}
auto main(int argc, char** argv) -> int {
  Convert();
  ConvertDirectly();

  return 0;
}