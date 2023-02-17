#ifndef QTODO_QMAINWINDOW_HPP
#define QTODO_QMAINWINDOW_HPP

#include <QMainWindow>
#include <QVector>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QSystemTrayIcon>
#include <QMenu>

#include "qTaskWidget.hpp"

namespace ui {

    class qMainWindow : public QMainWindow {
    Q_OBJECT
    public:
        explicit qMainWindow(QWidget* parent = nullptr);

    private slots:
        void deleteTask(const QString& t);
        void addTask(void);
        void addTask(const QString& t);

    private:
        void closeEvent(QCloseEvent* event) override;

        QVBoxLayout* lay;
        QWidget* inner_widget;
        QScrollArea* scroll;
        QVector<qTaskWidget*> tasks;
        QSystemTrayIcon* sysTray;
    };

} // ui

#endif //QTODO_QMAINWINDOW_HPP
