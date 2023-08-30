
#include <iostream>
#include <string>

#include "include/linker.hpp"
#include "include/writer.hpp"

#include "../../include/utils.hpp"

static void dosHeader(Linker::PEWriter *writer) {
  writer->int16(0x5a4d);
  writer->int16(0x80);
  writer->int16(1);
  writer->int16(0);
  writer->int16(4);
  writer->int16(0x10);
  writer->int16(0xffff);
  writer->int16(0);
  writer->int16(0x140);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0x40);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0x80);
  writer->int16(0);
}

static void dosStub(Linker::PEWriter *writer) {
  writer->int8(0x0e);
  writer->int8(0x1f);
  writer->int8(0xba);
  writer->int8(0x0e);
}

static void peSections(Linker::PEWriter *writer) {
  writer->padTo(writer->buf(), 0x180);
  writer->int64(0);
  writer->strPadding(".idata", 8);
  writer->int32(0x89);
  writer->int16(0x1000);
  writer->int32(0x02000000);
  writer->int32(0x02000000);
  writer->zeroes(14);
  writer->int16(64);
  writer->int8(0);
  writer->int8(192);
  writer->strPadding(".text", 8);
  writer->int32(75);
  writer->int8(0);
  writer->int32(0x20);
  writer->int32(0x00004);
  writer->int32(4);
  writer->int32(0);
  writer->int32(0);
  writer->int32(0x20000000);
  writer->write({0, 0, 96});
  writer->zeroes(52);
  writer->write({72, 16, 0, 0});
  writer->write({40, 16, 0, 0});
  writer->zeroes(20);
  writer->write({96, 16, 0, 0});
  writer->int32(0);
  writer->write({110, 16, 0, 0});
  writer->int32(0);
  writer->write({125, 16, 0, 0});
  writer->zeroes(12);
  // TODO: system libraries
}

static void peSection(Linker::PEWriter *writer) {
  writer->strPadding(".text", 8);
  writer->int32(0x0);
  writer->int32(0x1000);
  writer->int32(0x400);

  writer->int32(0);
  writer->int32(0);
  writer->int32(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
}

static void peHeader(Linker::PEWriter *writer) {
  // required stuff
  writer->int16(0x4550);
  writer->int16(0);
  writer->int16(0x8664); // amd64
  writer->int16(2);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0xf0);
  writer->int16(0x2f); // executable image

  // optional stuff
  writer->int16(0x20b);
  writer->int8(0x1);
  writer->int8(0x49);
  writer->int32(0x200);
  writer->int32(0x200);
  writer->int32(0);

  writer->int32(0x2000);
  writer->int32(0x2000);
  writer->int64(0x400000);
  writer->int32(0x1000);
  writer->int32(0x200);
  writer->int16(1);
  writer->int16(0);
  writer->int16(0);
  writer->int16(0);
  writer->int16(5);
  writer->int16(0);

  writer->int32(0);
  writer->int32(0x3000);
  writer->int32(0x200);

  writer->int32(0);
  writer->int16(5);
  writer->int16(0);

  writer->int64(0x1000);
  writer->int64(0x1000);
  writer->int64(0x10000);
  writer->int64(0);
  writer->int64(0);
  writer->int32(0x10);

  writer->int32(0);
  writer->int32(0);
  writer->int32(0x1000);
  writer->int32(0x100);
}

void Linker::linkPE(std::string obj, std::string filepath) {
  PEWriter *writer = new PEWriter();

  dosHeader(writer);
  dosStub(writer);
  peHeader(writer);
  peSection(writer);

  // writer->padTo(writer->buf(), 0x4000);
  std::cout << "??\n";
  // TODO: call stuff

  // write footer
  
  // writer->padTo(writer->buf(), 0x600);
  //

  // write the file
  Utilities::writeBinaryFile(filepath, writer->buf());
}
