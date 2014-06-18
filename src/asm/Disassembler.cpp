#include <QByteArray>

#include "Asm.h"
#include "AsmX86.h"
#include "../Util.h"
#include "Disassembler.h"

Disassembler::Disassembler(BinaryObjectPtr obj) : asm_{nullptr} {
  switch (obj->getCpuType()) {
  case CpuType::X86:
    asm_ = new AsmX86(obj);
    break;

  default: break;
  }
}

Disassembler::~Disassembler() {
  if (asm_) {
    delete asm_;
    asm_ = nullptr;
  }
}

bool Disassembler::disassemble(SectionPtr sec, Disassembly &result) {
  if (!asm_) return false;
  return asm_->disassemble(sec, result);
}

bool Disassembler::disassemble(const QByteArray &data, Disassembly &result) {
  int size = data.size();
  auto sec = SectionPtr(new Section(SectionType::Text, "", 0, size));
  sec->setData(data);
  return disassemble(sec, result);
}

bool Disassembler::disassemble(const QString &data, Disassembly &result) {
  QByteArray input =
    Util::hexToData(data.simplified().trimmed().replace(" ", ""));
  return disassemble(input, result);
}
