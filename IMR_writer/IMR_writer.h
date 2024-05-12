#ifndef IMR_WRITER_IMR_WRITER_H
#define IMR_WRITER_IMR_WRITER_H
#include <fstream>
#include <string>

#include "IMR_struct.h"

namespace IMR {
class Writer {
 public:
  Writer() = delete;                          // constructor
  Writer(const Writer&) = delete;             // copy constructor
  Writer& operator=(const Writer&) = delete;  // copy =
  Writer(Writer&&) = delete;                  // move constructor
  Writer& operator=(Writer&&) = delete;       // move =

  explicit Writer(const std::string& file_name);
  ~Writer() noexcept;

  void WriteRecord(const Record& record);
  void WriteHeader(const Header& header);

  void WriteHeaderDirectly(const Header& header);
  void WriteRecordDirectly(const Record& record);

 private:
  std::ofstream imr_writer;
};

}  // namespace IMR
#endif  // IMR_WRITER_IMR_WRITER_H