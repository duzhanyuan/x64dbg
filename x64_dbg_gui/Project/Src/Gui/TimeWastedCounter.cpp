#include "TimeWastedCounter.h"
#include "Bridge.h"

TimeWastedCounter::TimeWastedCounter(QObject* parent, QAction* label)
    : QObject(parent), mLabel(label)
{
    mLabel->setEnabled(false);
    connect(Bridge::getBridge(), SIGNAL(updateTimeWastedCounter()), this, SLOT(updateTimeWastedCounter()));
}

void TimeWastedCounter::updateTimeWastedCounter()
{
    duint timeWasted = DbgGetTimeWastedCounter();
    int days = timeWasted / (60 * 60 * 24);
    int hours = (timeWasted / (60 * 60)) % 24;
    int minutes = (timeWasted / 60) % 60;
    int seconds = timeWasted % 60;
    mLabel->setText(QString().sprintf("Time Wasted Debugging: %d:%02d:%02d:%02d", days, hours, minutes, seconds));
}
