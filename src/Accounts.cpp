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
    m_model->setSortingKeys(QStringList()<<"isExternal"<<"displayName"<<"accountId");

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
    Result response = m_accountService->deleteAccount(m_currentAccountId);
    if (!response.isSuccess()) {
        emit this->error(response.errorCode(), response.message());
    } else {
        emit this->success(true);
    }
}

void Accounts::updateAccount()
{
    Result response = m_accountService->updateAccount(m_currentAccountId, m_accountService->account(m_currentAccountId));
    if (!response.isSuccess()) {
        emit this->error(response.errorCode(), response.message());
    } else {
        emit this->success(false);
    }
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

    //TODO: Once everyone has 10.3 uncomment this
    //const QList<Account> accounts = m_accountService->allAccounts();
    const QList<Account> accounts = m_accountService->accounts();

    foreach (const Account &account, accounts) {
        QVariantMap entry;
        entry["accountId"] = account.id();
        entry["displayName"] = account.displayName();
        entry["isExternal"] = account.isExternalData();

        m_model->insert(entry);
    }
}
