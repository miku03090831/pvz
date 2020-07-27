#include "common.h"

Common::Common(QWidget* parent):QLabel(parent)
{
    this->setMouseTracking(true);
    this->hide();
}
