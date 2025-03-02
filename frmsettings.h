// This file is a part of "grblControl" application.
// Copyright 2015 Hayrullin Denis Ravilevich

#ifndef FRMSETTINGS_H
#define FRMSETTINGS_H

#include <QDialog>
#include <QListWidgetItem>
#include "colorpicker.h"

namespace Ui {
class frmSettings;
}

class frmSettings : public QDialog
{
    Q_OBJECT

public:
    explicit frmSettings(QWidget *parent = 0);
    ~frmSettings();

    int exec();
    void undo();

    QString port();
    void setPort(QString port);
    int baud();
    void setBaud(int baud);
    double toolDiameter();
    void setToolDiameter(double diameter);
    double toolLength();
    void setToolLength(double length);
    bool antialiasing();
    void setAntialiasing(bool antialiasing);
    bool zBuffer();
    void setZBuffer(bool zBuffer);
    double lineWidth();
    void setLineWidth(double lineWidth);
    double arcPrecision();
    void setArcPrecision(double arcPrecision);
    bool showProgramCommands();
    void setShowProgramCommands(bool showProgramCommands);
    bool showUICommands();
    void setShowUICommands(bool showUICommands);
    double safeZ();
    void setSafeZ(double safeZ);
    int spindleSpeedMin();
    void setSpindleSpeedMin(int speed);
    int spindleSpeedMax();
    void setSpindleSpeedMax(int speed);
    int rapidSpeed();
    void setRapidSpeed(int rapidSpeed);
    int heightmapProbingFeed();
    void setHeightmapProbingFeed(int heightmapProbingFeed);
    int acceleration();
    void setAcceleration(int acceleration);
    int queryStateTime();
    void setQueryStateTime(int queryStateTime);
    int toolType();
    void setToolType(int toolType);
    double toolAngle();
    void setToolAngle(double toolAngle);
    int fps();
    void setFps(int fps);
    bool msaa();
    void setMsaa(bool msaa);
    bool autoCompletion();
    void setAutoCompletion(bool autoCompletion);
    int units();
    void setUnits(int units);
    QString touchCommand();
    void setTouchCommand(QString touchCommand);
    bool simplify();
    void setSimplify(bool simplify);
    double simplifyPrecision();
    void setSimplifyPrecision(double simplifyPrecision);
    bool panelHeightmap();
    void setPanelHeightmap(bool panelHeightmap);
    bool panelSpindle();
    void setPanelSpindle(bool panelSpindle);
    bool panelFeed();
    void setPanelFeed(bool panelFeed);
    bool panelJog();
    void setPanelJog(bool panelJog);
    QList<ColorPicker*> colors();
    QColor colors(QString name);
    int fontSize();
    void setFontSize(int fontSize);

protected:
    void showEvent(QShowEvent *se);

private slots:
    void onScrollBarValueChanged(int value);

    void on_cmdRefresh_clicked();
    void on_cmdOK_clicked();
    void on_cmdCancel_clicked();
    void on_cboToolType_currentIndexChanged(int index);
    void on_listCategories_currentRowChanged(int currentRow);

    void on_cmdDefaults_clicked();

    void on_cboFontSize_currentTextChanged(const QString &arg1);

private:
    Ui::frmSettings *ui;
    void searchPorts();

    QList<double> m_storedValues;
    QList<bool> m_storedChecks;
    QList<QString> m_storedCombos;
    QList<QColor> m_storedColors;

    QIntValidator m_intValidator;
};

#endif // FRMSETTINGS_H
