#include "colorselector.h"

ColorSelector::ColorSelector(QWidget *parent) : QLabel(parent) {
    setAlignment(Qt::AlignCenter);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setAutoFillBackground(true);
    m_color = QColor("black");
    setCursor(Qt::PointingHandCursor);
    setToolTip("Cambia colore ...");
    setProperty("class", "labelColor");
}

void ColorSelector::setColor(QColor color)
{
    m_color = color;
    setStyleSheet(QString(".labelColor {background-color: %1;}").arg(m_color.name()));
}

void ColorSelector::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QColorDialog colorDialog(this);
        QColor color = colorDialog.getColor(getColor(), this, "Seleziona colore");

        if (color.isValid()) {
            setColor(color);
            emit colorChanged();
        }
    }
}
