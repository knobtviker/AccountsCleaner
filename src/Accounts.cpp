#include "Accounts.hpp"
#include "AccountViewer.hpp"

#include <bb/pim/account/Provider>
#include <bb/pim/account/Result>

using namespace bb::cascades;
using namespace bb::pim::account;

Accounts::Accounts(QObject *parent)
    : QObject(parent)
    , m_accountService(new AccountService())
    , m_model(new GroupDataModel(this))
    , m_accountViewer(new AccountViewer(m_accountService, this))
    , m_currentAccountId(-1)
{
    m_model->setGrouping(ItemGrouping::ByFirstChar);
    m_model->setSortedAscending(true);
    m_model->setSortingKeys(QStringList()<<"displayName"<<"accountId");

    bool ok = connect(m_accountService, SIGNAL(accountsChanged(bb::pim::account::AccountsChanged)), SLOT(loadAccounts()));
    Q_ASSERT(ok);
    Q_UNUSED(ok);

    this->loadAccounts();
}

void Accounts::setCurrentAccount(const QVariantList &indexPath)
{
    if (indexPath.isEmpty()) {
        m_currentAccountId = -1;
    } else {
        const QVariantMap entry = m_model->data(indexPath).toMap();
        m_currentAccountId = entry.value("accountId").toLongLong();
    }
}

void Accounts::viewAccount()
{
    m_accountViewer->setAccountId(m_currentAccountId);
}

void Accounts::deleteAccount()
{
    m_accountService->deleteAccount(m_currentAccountId);
}

void Accounts::updateAccount()
{
    m_accountService->updateAccount(m_currentAccountId, m_accountService->account(m_currentAccountId));
}

bb::cascades::GroupDataModel* Accounts::model() const
{
    return m_model;
}

AccountViewer* Accounts::accountViewer() const
{
    return m_accountViewer;
}

void Accounts::loadAccounts()
{
    m_model->clear();

    const QList<Account> accounts = m_accountService->allAccounts();

    foreach (const Account &account, accounts) {
        if (account.isExternalData()) {
            QVariantMap entry;
            entry["accountId"] = account.id();
            entry["displayName"] = account.displayName();

            m_model->insert(entry);
        }
    }
}
