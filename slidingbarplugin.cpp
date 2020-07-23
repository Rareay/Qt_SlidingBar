#include "slidingbar.h"
#include "slidingbarplugin.h"

#include <QtPlugin>

SlidingBarPlugin::SlidingBarPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SlidingBarPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool SlidingBarPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SlidingBarPlugin::createWidget(QWidget *parent)
{
    return new SlidingBar(parent);
}

QString SlidingBarPlugin::name() const
{
    return QLatin1String("SlidingBar");
}

QString SlidingBarPlugin::group() const
{
    return QLatin1String("");
}

QIcon SlidingBarPlugin::icon() const
{
    return QIcon();
}

QString SlidingBarPlugin::toolTip() const
{
    return QLatin1String("");
}

QString SlidingBarPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool SlidingBarPlugin::isContainer() const
{
    return false;
}

QString SlidingBarPlugin::domXml() const
{
    return QLatin1String("<widget class=\"SlidingBar\" name=\"slidingBar\">\n</widget>\n");
}

QString SlidingBarPlugin::includeFile() const
{
    return QLatin1String("slidingbar.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(slidingbarplugin, SlidingBarPlugin)
#endif // QT_VERSION < 0x050000
