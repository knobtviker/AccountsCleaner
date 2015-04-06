import bb.cascades 1.4
import bb.system 1.2

Page {
    id: rootAccountView
    
    property bool isExternal: false
    
    titleBar: TitleBar {
        title: qsTr ("Account Details")
    }
    actionBarVisibility: ChromeVisibility.Overlay
    actionBarAutoHideBehavior: ActionBarAutoHideBehavior.HideOnScroll
    Container {
        horizontalAlignment: HorizontalAlignment.Fill
        verticalAlignment: VerticalAlignment.Fill
        ListView {
            id: accountDetailsListView
            scrollRole: ScrollRole.Main
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            dataModel: _accounts.accountViewer.fields
            listItemComponents: ListItemComponent {
                type: ""
                StandardListItem {
                    title: ListItemData.title
                    description: ListItemData.value
                }
            }
        }
    }

    actions: [
        ActionItem {
            title: qsTr("Update")
            imageSource: "asset:///icons/update.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            enabled: rootAccountView.isExternal
            onTriggered: {
                confirmDialog.deleteAcc = false
                confirmDialog.show()
            }
        },
        ActionItem {
            title: qsTr("Delete")
            ActionBar.placement: ActionBarPlacement.Signature
            imageSource: "asset:///icons/delete.png"
            enabled: rootAccountView.isExternal
            onTriggered: {
                confirmDialog.deleteAcc = true
                confirmDialog.show()
            }
        }
    ]
    attachedObjects: [
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
                        navigationPane.pop()
                    } else {
                        _accounts.updateAccount()
                    }
                    confirmDialog.cancel()
                }
                confirmDialog.deleteAcc = false
            }
        },
        PageLayoutUpdateHandler {
            onBottomOverlayHeightChanged: {
                accountDetailsListView.bottomPadding = bottomOverlayHeight
            }
        }
    ]
}
