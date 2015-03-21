#ifndef ACCOUNTS_HPP
#define ACCOUNTS_HPP

#include <bb/cascades/GroupDataModel>
#include <bb/pim/account/AccountService>

#include <QtCore/QObject>

class AccountViewer;

class Accounts : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bb::cascades::GroupDataModel *model READ model CONSTANT);
    Q_PROPERTY(AccountViewer* accountViewer READ accountViewer CONSTANT);

public:
    Accounts(QObject *parent = 0);

public Q_SLOTS:
    void loadAccounts();
    void setCurrentAccount(const QVariantList &indexPath);
    void viewAccount();
    void deleteAccount();
    void updateAccount();

private:
    bb::cascades::GroupDataModel* model() const;
    AccountViewer* accountViewer() const;
    bb::pim::account::AccountService* m_accountService;
    bb::cascades::GroupDataModel* m_model;
    AccountViewer* m_accountViewer;
    bb::pim::account::AccountKey m_currentAccountId;

Q_SIGNALS:
    void error(int code, const QString &message);
    void success(bool delAcc);
};
#endif
