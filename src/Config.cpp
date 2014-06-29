#include <QDebug>
#include <QStandardPaths>

#include "Config.h"

Config::Config()
  : settings(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/bmod.ini",
             QSettings::IniFormat)
{
  load();
}

Config::~Config() {
  save();
}

void Config::load() {
  backupEnabled = settings.value("backupEnabled", true).toBool();
}

void Config::save() {
  settings.clear();
  settings.setValue("backupEnabled", backupEnabled);
  settings.sync();
}