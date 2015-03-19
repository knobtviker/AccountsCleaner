#ifndef ACCOUNTVIEWER_HPP
#define ACCOUNTVIEWER_HPP

#include <bb/cascades/QListDataModel>
#include <bb/pim/account/AccountsChanged>
#include <bb/pim/account/AccountService>

#include <QtCore/QObject>

class AccountViewer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bb::cascades::DataModel* fields READ fields CONSTANT)

public:
    AccountViewer(bb::pim::account::AccountService *service, QObject *parent = 0);

    void setAccountId(bb::pim::account::AccountKey accountId);

private Q_SLOTS:
    void accountsChanged(const bb::pim::account::AccountsChanged &changed);

private:
    bb::cascades::DataModel* fields() const;
    void updateAccount();
    bb::pim::account::AccountService* m_accountService;
    bb::pim::account::AccountKey m_accountId;
    bb::cascades::QMapListDataModel* m_fields;
};
#endif
