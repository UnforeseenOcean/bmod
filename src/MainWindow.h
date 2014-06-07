#ifndef BMOD_MAIN_WINDOW_H
#define BMOD_MAIN_WINDOW_H

#include <QList>
#include <QMainWindow>

class QTabWidget;
class QStringList;
class BinaryWidget;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(const QStringList &files = QStringList());

private slots:
  void openBinary();

private:
  void createLayout();
  void createMenu();

  void loadBinary(const QString &file);

  QTabWidget *tabWidget;
  QList<BinaryWidget*> binaryWidgets;
};

#endif // BMOD_MAIN_WINDOW_H
