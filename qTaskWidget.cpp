#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>

#include "qTaskWidget.hpp"

namespace ui {
    qTaskWidget::qTaskWidget(const QString& task, QWidget* parent)
        : QWidget(parent)
    {
        auto* layout = new QHBoxLayout(this);
        auto* check = new QCheckBox(this);
        lineEdit = new QLineEdit(this);
        lineEdit->setText(task);
        layout->addWidget(check);
        layout->addWidget(lineEdit);
        connect(check, &QCheckBox::toggled, [&] { emit checked(lineEdit->text()); });
    }
} // ui