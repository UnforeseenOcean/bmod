#ifndef BMOD_SECTION_H
#define BMOD_SECTION_H

#include <QList>
#include <QPair>
#include <QString>
#include <QByteArray>

#include <memory>

#include "SectionType.h"

class Section;
typedef std::shared_ptr<Section> SectionPtr;

class Section {
public:
  Section(SectionType type, const QString &name, quint64 addr, quint64 size,
          quint32 offset);

  SectionType getType() const { return type; }
  QString getName() const { return name; }
  quint64 getAddress() const { return addr; }
  quint64 getSize() const { return size; }
  quint32 getOffset() const { return offset; }

  const QByteArray &getData() const { return data; }
  void setData(const QByteArray &data) { this->data = data; }

  void setSubData(const QByteArray &subData, int pos);
  bool isModified() const { return !modifiedRegions.isEmpty(); }
  const QList<QPair<int, int>> &getModifiedRegions() const;

private:
  SectionType type;
  QString name;
  quint64 addr, size;
  quint32 offset;
  QByteArray data;
  QList<QPair<int, int>> modifiedRegions;
};

#endif // BMOD_SECTION_H
