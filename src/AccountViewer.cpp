#include "AccountViewer.hpp"

#include <bb/pim/account/Account>
#include <bb/pim/account/Provider>

using namespace bb::cascades;
using namespace bb::pim::account;

static QString valueToString(const QVariant &value)
{
    switch (value.type()) {
        case QVariant::String:
        case QVariant::Int:
            return value.toString();
        case QVariant::DateTime:
            return value.toDateTime().toString();
        case QVariant::Bool:
            return (value.toBool() ? QObject::tr("true") : QObject::tr("false"));
        default:
            qDebug() << "unhandled type:" << value.type();
            return QString();
    }
}

AccountViewer::AccountViewer(AccountService *service, QObject *parent)
    : QObject(parent)
    , m_accountService(service)
    , m_accountId(-1)
    , m_fields(new QMapListDataModel())
{
    m_fields->setParent(this);

    bool ok = connect(m_accountService, SIGNAL(accountsChanged(bb::pim::account::AccountsChanged)), SLOT(accountsChanged(bb::pim::account::AccountsChanged)));
    Q_ASSERT(ok);
    Q_UNUSED(ok);
}

void AccountViewer::updateAccount()
{
    m_fields->clear();

    const Account account = m_accountService->account(m_accountId);

    foreach (const QString &key, account.provider().settingsKeys()) {
        const QVariant value = account.settingsProperty(key);

        QVariantMap entry;
        entry["title"] = key;
        entry["value"] = valueToString(value);

        m_fields->append(entry);
    }
}

void AccountViewer::accountsChanged(const AccountsChanged &changed)
{
    if (changed.updatedAccountIds().contains(m_accountId))
        updateAccount();
}

void AccountViewer::setAccountId(AccountKey accountId)
{
    m_accountId = accountId;

    updateAccount();
}

bb::cascades::DataModel* AccountViewer::fields() const
{
    return m_fields;
}
