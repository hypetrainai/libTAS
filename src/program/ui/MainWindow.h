/*
    Copyright 2015-2018 Clément Gallet <clement.gallet@ens-lyon.org>

    This file is part of libTAS.

    libTAS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libTAS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libTAS.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBTAS_MAINWINDOW_H_INCLUDED
#define LIBTAS_MAINWINDOW_H_INCLUDED

#include <QMainWindow>
#include <QActionGroup>
#include <QAction>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>
#include <QLabel>
#include <QCheckBox>
#include <QGroupBox>
#include <QComboBox>
#include <forward_list>

#include "config.h"
#include "EncodeWindow.h"
#include "ExecutableWindow.h"
#include "InputWindow.h"
#include "ControllerTabWindow.h"
#include "GameInfoWindow.h"
#include "RamSearchWindow.h"
#include "RamWatchWindow.h"
#include "InputEditorWindow.h"
#include "OsdWindow.h"
#include "AnnotationsWindow.h"
#include "AutoSaveWindow.h"
#include "../GameLoop.h"
#include "../Context.h"

#include <thread>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Context* c);
    ~MainWindow();

    std::thread game_thread;
    GameLoop *gameLoop;
    Context *context;

    EncodeWindow* encodeWindow;
    InputWindow* inputWindow;
    ExecutableWindow* executableWindow;
    ControllerTabWindow* controllerTabWindow;
    GameInfoWindow* gameInfoWindow;
    RamSearchWindow* ramSearchWindow;
    RamWatchWindow* ramWatchWindow;
    InputEditorWindow* inputEditorWindow;
    OsdWindow* osdWindow;
    AnnotationsWindow* annotationsWindow;
    AutoSaveWindow* autoSaveWindow;

    QList<QWidget*> disabledWidgetsOnStart;
    QList<QAction*> disabledActionsOnStart;

    QAction *saveMovieAction;
    QAction *exportMovieAction;
    QAction *annotateMovieAction;

    QAction *autoRestartAction;
    QActionGroup *movieEndGroup;
    QActionGroup *screenResGroup;

    QAction *renderSoftAction;
    QActionGroup *renderPerfGroup;
    QActionGroup *osdGroup;
    QAction *osdEncodeAction;

    QActionGroup *frequencyGroup;
    QActionGroup *bitDepthGroup;
    QActionGroup *channelGroup;
    QAction *muteAction;

    QActionGroup *localeGroup;

    QActionGroup *timeMainGroup;
    QActionGroup *timeSecGroup;

    QAction *saveScreenAction;
    QAction *preventSavefileAction;
    QAction *recycleThreadsAction;

    QAction *incrementalStateAction;
    QAction *ramStateAction;
    QAction *backtrackStateAction;
    QAction *steamAction;
    QActionGroup *waitGroup;
    QActionGroup *asyncGroup;

    QActionGroup *debugStateGroup;
    QActionGroup *loggingOutputGroup;
    QActionGroup *loggingPrintGroup;
    QActionGroup *loggingExcludeGroup;

    QAction *configEncodeAction;
    QAction *toggleEncodeAction;

    QActionGroup *slowdownGroup;
    QActionGroup *fastforwardGroup;

    QAction *keyboardAction;
    QAction *mouseAction;
    QActionGroup *joystickGroup;


    QComboBox *gamePath;
    QPushButton *browseGamePath;
    QLineEdit *cmdOptions;

    QLineEdit *moviePath;
    QPushButton *browseMoviePath;

    QLineEdit *authorField;

    QRadioButton *movieRecording;
    QRadioButton *moviePlayback;

    QSpinBox *fpsNumField;
    QSpinBox *fpsDenField;
    QLabel *fpsValues;

    QCheckBox *pauseCheck;
    QCheckBox *fastForwardCheck;

    QSpinBox *frameCount;
    QSpinBox *movieFrameCount;
    QSpinBox *rerecordCount;
    QLabel *currentLength;
    QLabel *movieLength;

    QSpinBox *initialTimeSec;
    QSpinBox *initialTimeNsec;

    QPushButton *launchGdbButton;
    QPushButton *stopButton;

    QGroupBox *movieBox;

    QLabel *statusIcon;
    QLabel *statusSoft;
    QLabel *statusMute;


    /* Event filter function to prevent menu close when a checkable option is clicked */
    bool eventFilter(QObject *obj, QEvent *event);

private:
    /* Update the status bar */
    void updateStatusBar();

    /* Update movie parameters from movie file */
    void updateMovieParams();

    /* Update the list of recent gamepaths */
    void updateRecentGamepaths();

    /* Helper function to create a checkable action inside an action group */
    void addActionCheckable(QActionGroup*& group, const QString& text, const QVariant &data, const QString& toolTip);
    void addActionCheckable(QActionGroup*& group, const QString& text, const QVariant &data);

    /* Create the main window actions that will go in the menus */
    void createActions();

    /* Create the main window menus */
    void createMenus();

private slots:

    /* Update UI elements (mainly enable/disable) depending on
     * the game status (running/stopped), to prevent modifying values that
     * are not supposed to be modified when the game is running.
     */
    void updateStatus();

    /* Update UI elements when the shared config has changed (pause, fastforward,
     * encode, etc.
     */
    void updateSharedConfigChanged();

    /* Update frame count and time */
    void updateFrameCountTime();

    /* Update rerecord count */
    void updateRerecordCount();

    /* Update fps values */
    void updateFps(float fps, float lfps);

    /* Update ramsearch and ramwatch values if window is shown */
    void updateRam();

    /* Update input editor if window is shown */
    void updateInputEditor();

    /* Update UI elements when a config file is loaded */
    void updateUIFromConfig();

    /* Show an alert dialog containing alert_msg as text */
    void alertDialog(QString alert_msg);

    /* Show an alert dialog asking the user a question, and get the answer */
    void alertOffer(QString alert_msg, void* promise);



    void slotLaunch();
    void slotStop();
    void slotBrowseGamePath();
    void slotGamePathChanged();
    void slotBrowseMoviePath();
    void slotMoviePathChanged();
    void slotSaveMovie();
    void slotExportMovie();
    void slotPause(bool checked);
    void slotFastForward(bool checked);
    void slotMovieEnable(bool checked);
    void slotMovieRecording();
    void slotToggleEncode();
    void slotMuteSound(bool checked);
    void slotRenderSoft(bool checked);
    void slotDebugState();
    void slotLoggingPrint();
    void slotLoggingExclude();
    void slotSlowdown();
    void slotFastforwardMode();
    void slotScreenRes();
#ifdef LIBTAS_ENABLE_HUD
    void slotOsd();
    void slotOsdEncode(bool checked);
#endif
    void slotSaveScreen(bool checked);
    void slotPreventSavefile(bool checked);
    void slotMovieEnd();
    void slotPauseMovie();
    void slotIncrementalState(bool checked);
    void slotRamState(bool checked);
    void slotBacktrackState(bool checked);
    void slotRecycleThreads(bool checked);
    void slotSteam(bool checked);
    void slotAsyncEvents(bool checked);
    void slotCalibrateMouse();
    void slotAutoRestart(bool checked);
};

#endif
