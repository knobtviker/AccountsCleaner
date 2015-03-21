import bb.cascades 1.4
import bb.system 1.2

NavigationPane {
    id: navigationPane
    
    function showError(code, message) {
        errorToast.body = code + " " + message
        errorToast.show()
    }
    
    function showInfo(deleteAcc) {
        if (deleteAcc) {
            infoToast.body = "Account deleted"
        } else {
            infoToast.body = "Account updated"
        }
        infoToast.show()
    }

    onCreationCompleted: {
        startDialog.show()
        _accounts.error.connect(navigationPane.showError)
        _accounts.success.connect(navigationPane.showInfo)
    }
    
    onPopTransitionEnded: {
        page.destroy()
        accountsList.clearSelection()
    }
    
    Page {
        titleBar: TitleBar {
            title: qsTr("Accounts")
        }
        Container {
            layout: DockLayout {
            }
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            Label {
                text: qsTr("No accounts found")
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                visible: accountsList.dataModel.size() == 0
                textStyle.base: SystemDefaults.TextStyles.BigText
            }
            ListView {
                id: accountsList
                
                function handleSelect(indexPath) {
                    accountsList.clearSelection()
                    accountsList.select(indexPath)
                    _accounts.setCurrentAccount(indexPath)
                }
                function viewAcc(indexPath, isExternal) {
                    accountsList.handleSelect(indexPath)
                    _accounts.viewAccount();
                    var accountViewerObject = accountViewer.createObject()
                    accountViewerObject.isExternal = isExternal
                    navigationPane.push(accountViewerObject)
                }
                function updateAcc(indexPath) {
                    accountsList.handleSelect(indexPath)
                    confirmDialog.deleteAcc = false
                    confirmDialog.show()
                } 
                function deleteAcc(indexPath) {
                    accountsList.handleSelect(indexPath)
                    confirmDialog.deleteAcc = true
                    confirmDialog.show()
                }

                horizontalAlignment: HorizontalAlignment.Fill
                verticalAlignment: VerticalAlignment.Fill
                listItemComponents: [
                    ListItemComponent {
                        type: "header"
                        Header {
                            title: ListItemData ? "External" : "Internal"
                        }
                    },
                    ListItemComponent {
                        type: "item"
                        StandardListItem {
                            id: accountsListItem
                            title: ListItemData.displayName
                            description: ListItemData.accountId
                            contextActions: [
                                ActionSet {
                                    title: ListItemData.displayName
                                    subtitle: ListItemData.accountId
                                    ActionItem {
                                        title: qsTr("View")
                                        imageSource: "asset:///icons/view.png"
                                        ActionBar.placement: ActionBarPlacement.InOverflow
                                        enabled: true
                                        onTriggered: {
                                            accountsListItem.ListItem.view.viewAcc(accountsListItem.ListItem.indexPath, ListItemData.isExternal)
                                        }
                                    }
                                    ActionItem {
                                        title: qsTr("Update")
                                        imageSource: "asset:///icons/update.png"
                                        ActionBar.placement: ActionBarPlacement.InOverflow
                                        enabled: ListItemData.isExternal
                                        onTriggered: {
                                            accountsListItem.ListItem.view.updateAcc(accountsListItem.ListItem.indexPath)
                                        }
                                    }
                                    DeleteActionItem {
                                        enabled: ListItemData.isExternal
                                        onTriggered: {
                                            accountsListItem.ListItem.view.deleteAcc(accountsListItem.ListItem.indexPath)
                                        }
                                    }
                                }
                            ]
                        }
                    }
                ]
                onTriggered: {
                    accountsList.viewAcc(indexPath, accountsList.dataModel.data(indexPath)["isExternal"])
                }
            }
        }
        actions: [
            ActionItem {
                title: qsTr("Refresh")
                imageSource: "asset:///icons/refresh.png"
                ActionBar.placement: ActionBarPlacement.Signature
                onTriggered: {
                    _accounts.loadAccounts()
                }
            }
        ]
    }
    attachedObjects: [
        ComponentDefinition {
            id: accountViewer
            source: "AccountViewer.qml"
        },
        SystemDialog {
            id: startDialog
            title: qsTr("Warning")
            body: qsTr("Use this application at your own risk.\nNone of the authors, contributors, administrators, vandals, or anyone else connected with this application, in any way whatsoever, can be held responsible for your use of the application.")
            buttonAreaLimit: 2
            defaultButton: startDialog.cancelButton
            dismissAutomatically: true
            cancelButton.label: qsTr("Quit")
            onFinished: {
                if (startDialog.buttonSelection() == startDialog.cancelButton) {
                    Application.quit()
                } else if (startDialog.buttonSelection() == startDialog.confirmButton) {
                    accountsList.dataModel = _accounts.model
                }
            }
        },
        SystemDialog {
            id: confirmDialog
            
            property bool deleteAcc: false
            
            title: qsTr("Confirm")
            body: confirmDialog.deleteAcc ? qsTr("There is no undo or going back if bad things happen on your device.\nAre you sure you want to delete this account from your device?") : qsTr("Update account removes require password flag from this account and stops random notifications.\n Are you sure you want to update this account on your device?")
            buttonAreaLimit: 2
            defaultButton: confirmDialog.cancelButton
            dismissAutomatically: false
            onFinished: {
                if (confirmDialog.buttonSelection() == confirmDialog.cancelButton) {
                    confirmDialog.cancel()
                } else if (confirmDialog.buttonSelection() == confirmDialog.confirmButton) {
                    if (confirmDialog.deleteAcc) {
                        _accounts.deleteAccount()
                    } else {
                        _accounts.updateAccount()
                    }
                    confirmDialog.cancel()
                }
                confirmDialog.deleteAcc = false
            }
        },
        SystemToast {
            id: errorToast
            autoUpdateEnabled: true
        },
        SystemToast {
            id: infoToast
            autoUpdateEnabled: true
        }
    ]
}
