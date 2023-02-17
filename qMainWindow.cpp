#include <QMainWindow>
#include <QVBoxLayout>
#include <QToolBar>
#include <QSettings>
#include <QSystemTrayIcon>
#include <QMenu>

#include "qTaskWidget.hpp"
#include "qMainWindow.hpp"

namespace ui {
    qMainWindow::qMainWindow(QWidget* parent)
        : QMainWindow(parent)
    {
        scroll = new QScrollArea(this);
        scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scroll->setWidgetResizable(true);
        inner_widget = new QWidget(this);
        lay = new QVBoxLayout(inner_widget);
        scroll->setWidget(inner_widget);
        setCentralWidget(scroll);

        if (QSystemTrayIcon::isSystemTrayAvailable()) {
            sysTray = new QSystemTrayIcon();
        }

        auto* toolbar = addToolBar("Main");
        toolbar->addAction(QIcon::fromTheme("list-add"), "New task", tr("CTRL+P"), this, SLOT(addTask(void)));
        QSettings settings("QTodo", "QTodo");
        auto size = settings.beginReadArray("tasks");
        for (int i = 0; i < size; ++i) {
            settings.setArrayIndex(i);
            addTask(settings.value("task").toString());
        }
        settings.endArray();
        resize(settings.value("size", QSize(300, 400)).toSize());
    }

    void qMainWindow::deleteTask(const QString& t) {
        auto* task = (QWidget*)sender();
        task->hide();
        lay->removeWidget(task);
        tasks.removeIf([t](auto* text) { return !text->getTask().compare(t); });
    }

    void qMainWindow::addTask(void) {
        addTask("");
    }

    void qMainWindow::addTask(const QString& t) {
        qDebug() << "Task added: " << t;
        tasks.push_back(new qTaskWidget(t, inner_widget));
        lay->addWidget(tasks.back());
        connect(tasks.back(), SIGNAL(checked(const QString&)), this, SLOT(deleteTask(const QString&)));
    }

    void qMainWindow::closeEvent(QCloseEvent* event) {
        QSettings settings("QTodo", "QTodo");
        settings.beginWriteArray("tasks");
        for (int i = 0; i < tasks.size(); ++i) {
            settings.setArrayIndex(i);
            settings.setValue("task", tasks[i]->getTask());
        }
        settings.endArray();
        settings.setValue("size", size());
        QMainWindow::closeEvent(event);
    }
} // ui