#include "applicationui.hpp"
#include "Accounts.hpp"
#include "AccountViewer.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>

using namespace bb::cascades;

ApplicationUI::ApplicationUI() :
        QObject()
{
    m_pTranslator = new QTranslator(this);
    m_pLocaleHandler = new LocaleHandler(this);

    bool res = QObject::connect(m_pLocaleHandler, SIGNAL(systemLanguageChanged()), this, SLOT(onSystemLanguageChanged()));
    Q_ASSERT(res);
    Q_UNUSED(res);

    onSystemLanguageChanged();

    qmlRegisterType<AccountViewer>();

    QmlDocument *qml = QmlDocument::create("asset:///main.qml", false)
    .property("_accounts", new Accounts(this))
    .parent(this);

    if (qml->load()) {
        AbstractPane *root = qml->createRootObject<AbstractPane>();
        Application::instance()->setMenuEnabled(false);
        Application::instance()->setScene(root);
    }
}

void ApplicationUI::onSystemLanguageChanged()
{
    QCoreApplication::instance()->removeTranslator(m_pTranslator);
    QString locale_string = QLocale().name();
    QString file_name = QString("AccountsCleaner_%1").arg(locale_string);
    if (m_pTranslator->load(file_name, "app/native/qm")) {
        QCoreApplication::instance()->installTranslator(m_pTranslator);
    }
}
