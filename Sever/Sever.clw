; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSeverDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Sever.h"
ODLFile=Sever.odl

ClassCount=4
Class1=CSeverApp
Class2=CSeverDlg
Class3=CAboutDlg
Class4=CSeverDlgAutoProxy

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SEVER_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_SEVER_DIALOG (English (U.S.))

[CLS:CSeverApp]
Type=0
HeaderFile=Sever.h
ImplementationFile=Sever.cpp
Filter=N

[CLS:CSeverDlg]
Type=0
HeaderFile=SeverDlg.h
ImplementationFile=SeverDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SeverDlg.h
ImplementationFile=SeverDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[CLS:CSeverDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_SEVER_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CSeverDlg

[DLG:IDD_SEVER_DIALOG (English (U.S.))]
Type=1
Class=?
ControlCount=7
Control1=IDC_OPEN,button,1342214153
Control2=IDC_STOP,button,1342214153
Control3=IDC_STATIC,static,1342308865
Control4=IDC_INFO,edit,1344342212
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_PORT,edit,1342251136

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

