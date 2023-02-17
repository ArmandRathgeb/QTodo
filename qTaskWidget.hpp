#ifndef QTODO_QTASKWIDGET_HPP
#define QTODO_QTASKWIDGET_HPP

#include <QWidget>
#include <QLineEdit>

namespace ui {

    class qTaskWidget : public QWidget {
    Q_OBJECT
    public:
        qTaskWidget(const QString& task, QWidget* parent = nullptr);

        [[nodiscard]] auto getTask() const { return lineEdit->text(); }

    signals:
        void checked(const QString&);

    private:
        QLineEdit* lineEdit;
    };

} // ui

#endif //QTODO_QTASKWIDGET_HPP
