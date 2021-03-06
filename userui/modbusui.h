#ifndef MODBUSUI_H
#define MODBUSUI_H

#include <QWidget>
#include <QModbusDataUnit>

QT_BEGIN_NAMESPACE
class QModbusClient;
class QModbusReply;

namespace Ui {
class ModbusUi;
}
QT_END_NAMESPACE

class QIntValidator;

class WriteRegisterModel;

class ModbusUi : public QWidget
{
    Q_OBJECT

public:
    explicit ModbusUi(QWidget *parent = 0);
    ~ModbusUi();
    static ModbusUi *getInstance();
    QModbusClient *getModbusDevice();

private slots:
    void checkCustomBaudRatePolicy(int idx);
    void checkCustomDevicePathPolicy(int idx);
    void on_searchButton_clicked();

    void on_connectType_currentIndexChanged(int);
    void onStateChanged(int state);
    void on_connectButton_clicked();

    void on_readButton_clicked();
    void readReady();

    void on_writeButton_clicked();
    void on_readWriteButton_clicked();
    void on_writeTable_currentIndexChanged(int);

private:
    void fillPortsInfo();
    void fillPortsParameters();

    QModbusDataUnit readRequest() const;
    QModbusDataUnit writeRequest() const;


private:
    Ui::ModbusUi *ui;
    QModbusReply* lastRequest;
    QModbusClient* modbusDevice;
    WriteRegisterModel *writeModel;
    quint8 ROW_COUNT;//number of registers

    QIntValidator *intValidator;
    static ModbusUi* instance;
};

#endif // MODBUSUI_H
