/*
 *  The Mana World
 *  Copyright (C) 2004  The Mana World Development Team
 *
 *  This file is part of The Mana World.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "gui/login.h"

#include "gui/okdialog.h"

#include "gui/widgets/button.h"
#include "gui/widgets/checkbox.h"
#include "gui/widgets/dropdown.h"
#include "gui/widgets/label.h"
#include "gui/widgets/layout.h"
#include "gui/widgets/passwordfield.h"
#include "gui/widgets/textfield.h"

#include "net/logindata.h"

#include "main.h"
#include "game.h"
#include "gui.h"
#include "configuration.h"

#include "utils/gettext.h"
#include "utils/stringutils.h"

#include "resources/resourcemanager.h"

static const int MAX_SERVER_LIST_SIZE = 5;
static const int LOGIN_DIALOG_WIDTH = 573;
static const int LOGIN_DIALOG_HEIGHT = 550;
static const int FIELD_WIDTH = LOGIN_DIALOG_WIDTH - 70;

class HelpWindow;

LoginDialog::LoginDialog(LoginData *loginData):
    Window(_("Login")),
    mLoginData(loginData)
{

    ResourceManager *resman = ResourceManager::getInstance();
    mBackGround = resman->getImage("graphics/elektrik/gui_login_window.png");
    gcn::Label *userLabel = new Label(_("Name:"));
    gcn::Label *passLabel = new Label(_("Password:"));
#ifdef EATHENA_SUPPORT
    gcn::Label *serverLabel = new Label(_("Server:"));
    gcn::Label *portLabel = new Label(_("Port:"));
    gcn::Label *dropdownLabel = new Label(_("Recent:"));

    std::vector<std::string> dfltServer;
    dfltServer.push_back("sunucu.elektrogame.net");
    std::vector<std::string> dfltPort;
    dfltPort.push_back("9601");
    mServerList = new DropDownList("MostRecent00", dfltServer, dfltPort,
                                   MAX_SERVER_LIST_SIZE);

    gcn::Label *captionLabel = new gcn::Label(_("-=GİRİŞ=-"));
    captionLabel->setFont(font_bas_b_1_16);
    captionLabel->setPosition(210,150);
    captionLabel->setForegroundColor(gcn::Color(0xaa,0xbb,0xcc));
    captionLabel->adjustSize();
    add(captionLabel);

#endif

    mUserField = new TextField(mLoginData->username);
    mPassField = new PasswordField(mLoginData->password);
#ifdef EATHENA_SUPPORT
    mServerField = new TextField(mServerList->getServerAt(0));
    mPortField = new TextField(mServerList->getPortAt(0));
    mServerDropDown = new DropDown(mServerList);
#endif

    mKeepCheck = new CheckBox(_("Remember username"), mLoginData->remember);
    mOkButton = new Button(_("OK"), "ok", this);
    mCancelButton = new Button(_("Cancel"), "cancel", this);
    mRegisterButton = new Button(_("Register"), "register", this);

    mUserField->setActionEventId("ok");
    mPassField->setActionEventId("ok");
#ifdef EATHENA_SUPPORT
    mServerField->setActionEventId("ok");
    mPortField->setActionEventId("ok");
    mServerDropDown->setActionEventId("changeSelection");
#endif

    mUserField->addKeyListener(this);
    mPassField->addKeyListener(this);
#ifdef EATHENA_SUPPORT
    mServerField->addKeyListener(this);
    mPortField->addKeyListener(this);
    mServerDropDown->addKeyListener(this);
#endif
    mUserField->addActionListener(this);
    mPassField->addActionListener(this);
#ifdef EATHENA_SUPPORT
    mServerField->addActionListener(this);
    mPortField->addActionListener(this);
    mServerDropDown->addActionListener(this);
    mKeepCheck->addActionListener(this);
#endif

    int x = 3;
    int y = 48;

    place(x+0, y+0, userLabel);
    place(x+0, y+1, passLabel);
#ifdef EATHENA_SUPPORT
    place(x+0, y+2, serverLabel);
    place(x+0, y+3, portLabel);
    place(x+0, y+4, dropdownLabel);
#endif
    place(x+1, y+0, mUserField, 3).setPadding(1);
    place(x+1, y+1, mPassField, 3).setPadding(1);
#ifdef EATHENA_SUPPORT
    place(x+1, y+2, mServerField, 3).setPadding(1);
    place(x+1, y+3, mPortField, 3).setPadding(1);
    place(x+1, y+4, mServerDropDown, 3).setPadding(1);
#endif
    place(x+0, y+5, mKeepCheck, 4);
//    place(x+0, y+6, mRegisterButton).setHAlign(LayoutCell::LEFT);
    place(x+1, y+6, mCancelButton);
    place(x+3, y+6, mOkButton);
    reflowLayout(340, 0);

    center();
    setVisible(true);

    if (mUserField->getText().empty())
        mUserField->requestFocus();
    else
        mPassField->requestFocus();

    mOkButton->setEnabled(canSubmit());
    setWidth(573);
    setHeight(507);

    hWindow = new HelpWindow;
    hWindow->loadFile("login");
    hWindow->setVisible(true);
    hWindow->setSize(400,200);
    hWindow->setPosition(0,getParent()->getHeight()-200);
    requestMoveToTop();
}

LoginDialog::~LoginDialog()
{
#ifdef EATHENA_SUPPORT
    delete mServerList;
#endif
//    ResourceManager *resman = ResourceManager::getInstance();
//    resman->release(mBackGround);
    delete hWindow;
}

void LoginDialog::action(const gcn::ActionEvent &event)
{
    if (event.getId() == "ok" && canSubmit())
    {
#ifdef EATHENA_SUPPORT
        mLoginData->hostname = mServerField->getText();
        mLoginData->port = getUShort(mPortField->getText());
#endif
        mLoginData->username = mUserField->getText();
        mLoginData->password = mPassField->getText();
        mLoginData->remember = mKeepCheck->isSelected();
        mLoginData->registerLogin = false;

        mOkButton->setEnabled(false);
        mRegisterButton->setEnabled(false);
#ifdef EATHENA_SUPPORT
        mServerList->save(mServerField->getText(), mPortField->getText());
        state = STATE_ACCOUNT;
#else
        state = STATE_LOGIN_ATTEMPT;
#endif
    }
#ifdef EATHENA_SUPPORT
    else if (event.getId() == "changeSelection")
    {
        int selected = mServerDropDown->getSelected();
        mServerField->setText(mServerList->getServerAt(selected));
        mPortField->setText(mServerList->getPortAt(selected));
    }
#endif
    else if (event.getId() == "cancel")
    {
#ifdef TMWSERV_SUPPORT
        state = STATE_SWITCH_ACCOUNTSERVER;
#else
        state = STATE_EXIT;
#endif
    }
    else if (event.getId() == "register")
    {
#ifdef EATHENA_SUPPORT
        // Transfer these fields on to the register dialog
        mLoginData->hostname = mServerField->getText();

        if (isUShort(mPortField->getText()))
            mLoginData->port = getUShort(mPortField->getText());
        else
            mLoginData->port = 9601;
#endif

        mLoginData->username = mUserField->getText();
        mLoginData->password = mPassField->getText();

        state = STATE_REGISTER;
    }
}

void LoginDialog::keyPressed(gcn::KeyEvent &keyEvent)
{
    mOkButton->setEnabled(canSubmit());
}

bool LoginDialog::canSubmit()
{
    return !mUserField->getText().empty() &&
           !mPassField->getText().empty() &&
#ifdef EATHENA_SUPPORT
           !mServerField->getText().empty() &&
           isUShort(mPortField->getText()) &&
#endif
           state == STATE_LOGIN;
}

#ifdef EATHENA_SUPPORT
bool LoginDialog::isUShort(const std::string &str)
{
    if (str.empty())
    {
        return false;
    }
    unsigned long l = 0;
    for (std::string::const_iterator strPtr = str.begin(), strEnd = str.end();
         strPtr != strEnd; ++strPtr)
    {
        if (*strPtr < '0' || *strPtr > '9')
            return false;

        l = l * 10 + (*strPtr - '0'); // *strPtr - '0' will never be negative

        if (l > 65535)
            return false;
    }
    return true;
}

unsigned short LoginDialog::getUShort(const std::string &str)
{
    unsigned long l = 0;
    for (std::string::const_iterator strPtr = str.begin(), strEnd = str.end();
         strPtr != strEnd; ++strPtr)
    {
        l = l * 10 + (*strPtr - '0');
    }
    return static_cast<unsigned short>(l);
}

void
LoginDialog::draw(gcn::Graphics *graphics)
{
    Graphics *g = static_cast<Graphics*>(graphics);
    g->drawImage(mBackGround,0,0);

    drawChildren(graphics);
}


/**
 * LoginDialog::DropDownList
 */

void LoginDialog::DropDownList::saveEntry(const std::string &server,
                                          const std::string &port, int &saved)
{
    if (saved < MAX_SERVER_LIST_SIZE && !server.empty())
    {
        config.setValue(mConfigPrefix + "Server" + toString(saved), server);
        config.setValue(mConfigPrefix + "Port" + toString(saved), port);
        ++saved;
    }
}

LoginDialog::DropDownList::DropDownList(std::string prefix,
                                        std::vector<std::string> dflt,
                                        std::vector<std::string> dfltPort,
                                        int maxEntries) :
                                        mConfigPrefix(prefix),
                                        mMaxEntries(maxEntries)
{
    for (int i = 0; i < maxEntries; ++i)
    {
        std::string server = config.getValue(mConfigPrefix + "Server" +
                                             toString(i), "");
        if (server.empty()) // Just in case had original config entries
        {
            server = config.getValue(mConfigPrefix + "ServerList" +
                                     toString(i), "");
        }
        std::string port = config.getValue(mConfigPrefix + "Port" +
                                           toString(i), dfltPort.front());

        if (!server.empty())
        {
            mServers.push_back(server);
            mPorts.push_back(port);
        }
    }
    if (mServers.empty())
    {
        mServers.assign(dflt.begin(), dflt.end());
        mPorts.assign(dfltPort.begin(), dfltPort.end());
    }
}

void LoginDialog::DropDownList::save(const std::string &server,
                                     const std::string &port)
{
    int position = 0;
    saveEntry(server, port, position);
    for (std::vector<std::string>::const_iterator sPtr = mServers.begin(),
             sEnd = mServers.end(),
             pPtr = mPorts.begin(),
             pEnd = mPorts.end();
         sPtr != sEnd && pPtr != pEnd;
         ++sPtr, ++pPtr)
    {
        if (*sPtr != server || *pPtr != port)
            saveEntry(*sPtr, *pPtr, position);
    }
}

int LoginDialog::DropDownList::getNumberOfElements()
{
    return mServers.size();
}

std::string LoginDialog::DropDownList::getElementAt(int i)
{
    if (i < 0 || i >= getNumberOfElements())
      return "";

    return getServerAt(i) + ":" + getPortAt(i);
}

std::string LoginDialog::DropDownList::getServerAt(int i)
{
    if (i < 0 || i >= getNumberOfElements())
        return "";

    return mServers.at(i);
}


std::string LoginDialog::DropDownList::getPortAt(int i)
{
    if (i < 0 || i >= getNumberOfElements())
        return "";

    return mPorts.at(i);
}
#endif
