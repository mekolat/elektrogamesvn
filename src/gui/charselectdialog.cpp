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

#include "gui/charselectdialog.h"
#include "gui/help.h"

#include "gui/charcreatedialog.h"
#include "gui/confirmdialog.h"
#include "gui/okdialog.h"
#include "gui/playerbox.h"
#include "gui/changepassworddialog.h"
#include "net/logindata.h"

#ifdef TMWSERV_SUPPORT
#include "gui/widgets/radiobutton.h"
#include "gui/widgets/slider.h"

#include "gui/unregisterdialog.h"
#include "gui/changeemaildialog.h"

#include "net/tmwserv/accountserver/account.h"
#else
#include "net/ea/protocol.h"
#endif

#include "gui/widgets/button.h"
#include "gui/widgets/label.h"
#include "gui/widgets/layout.h"
#include "gui/widgets/textfield.h"
#include "gui/gui.h"

#include "game.h"
#include "localplayer.h"
#include "main.h"
#include "units.h"

#include "net/charhandler.h"
#include "net/messageout.h"
#include "net/net.h"

#include "resources/colordb.h"
#include "resources/resourcemanager.h"

#include "utils/gettext.h"
#include "utils/stringutils.h"

#include <guichan/font.hpp>

#include <string>

/**
 * Listener for confirming character deletion.
 */
class CharDeleteConfirm : public ConfirmDialog
{
    public:
        CharDeleteConfirm(CharSelectDialog *master);
        void action(const gcn::ActionEvent &event);
    private:
        CharSelectDialog *master;
};

CharDeleteConfirm::CharDeleteConfirm(CharSelectDialog *m):
    ConfirmDialog(_("Confirm Character Delete"),
                  _("Are you sure you want to delete this character?"), m),
    master(m)
{
}

void CharDeleteConfirm::action(const gcn::ActionEvent &event)
{
    //ConfirmDialog::action(event);
    if (event.getId() == "yes")
    {
        master->attemptCharDelete();
    }
    ConfirmDialog::action(event);
}

CharSelectDialog::CharSelectDialog(LockedArray<LocalPlayer*> *charInfo,
                                   LoginData *loginData):
    Window(_("Account and Character Management")),
    mCharInfo(charInfo),
    mLoginData(loginData),
    mCharSelected(false)
#ifdef EATHENA_SUPPORT
    , mGender(loginData->sex)
#endif
{
    ResourceManager *resman = ResourceManager::getInstance();
    mBackGround = resman->getImage("graphics/elektrik/gui_login_window.png");

    gcn::Label *girisLabel = new gcn::Label(_("-=KARAKTER SEÇ=-"));
    girisLabel->setPosition(160,150);
    girisLabel->setFont(font_bas_b_1_16);
    girisLabel->setForegroundColor(gcn::Color(0xaa,0xbb,0xcc));
    girisLabel->adjustSize();
    add(girisLabel);

    mSelectButton = new Button(_("OK"), "ok", this);
    mCancelButton = new Button(_("Cancel"), "cancel", this);
    mPreviousButton = new Button(_("Previous"), "previous", this);
    mNextButton = new Button(_("Next"), "next", this);
    mAccountNameLabel = new Label(strprintf(_("Account: %s"), mLoginData->username.c_str()));
    mNameLabel = new Label(strprintf(_("Name: %s"), ""));
    mLevelLabel = new Label(strprintf(_("Level: %d"), 0));
    mChangePasswordButton = new Button(_("Change Password"), "change_password", this);
#ifdef TMWSERV_SUPPORT
    mNewCharButton = new Button(_("New"), "new", this);
    mDelCharButton = new Button(_("Delete"), "delete", this);
    mUnRegisterButton = new Button(_("Unregister"), "unregister", this);
    mChangeEmailButton = new Button(_("Change Email Address"), "change_email", this);

    mNameLabel = new Label(strprintf(_("Name: %s"), ""));
    mLevelLabel = new Label(strprintf(_("Level: %d"), 0));
    mMoneyLabel = new Label(strprintf(_("Money: %s"), ""));

    // Control that shows the Player
    mPlayerBox = new PlayerBox;
    mPlayerBox->setWidth(74);

    ContainerPlacer place;
    place = getPlacer(15, 9);
    place(0, 0, mAccountNameLabel);
    place(0, 1, mUnRegisterButton);
    place(0, 2, mChangePasswordButton);
    place(1, 2, mChangeEmailButton);
    place = getPlacer(10, 10);
    place(0, 0, mPlayerBox#include "gui/.h"
, 1, 5).setPadding(3);
    place(1, 0, mNameLabel, 3);
    place(1, 1, mLevelLabel, 3);
    place(1, 2, mMoneyLabel, 3);
    place(1, 3, mPreviousButton);
    place(2, 3, mNextButton);
    place(1, 4, mNewCharButton);
    place(2, 4, mDelCharButton);
    place.getCell().matchColWidth(1, 2);
    place = getPlacer(14, 12);
    place(0, 0, mSelectButton);
    place(1, 0, mCancelButton);
    reflowLayout(300, 400);
#else
    mCharInfo->select(0);
    LocalPlayer *pi = mCharInfo->getEntry();
    if (pi)
        mMoney = Units::formatCurrency(pi->getMoney());
    // Control that shows the Player
    mPlayerBox = new PlayerBox;
    mPlayerBox->setWidth(74);

    mJobLevelLabel = new Label(strprintf(_("Job Level: %d"), 0));
    mMoneyLabel = new Label(strprintf(_("Money: %s"), mMoney.c_str()));

    const std::string tempString = getFont()->getWidth(_("New")) <
                                   getFont()->getWidth(_("Delete")) ?
                                   _("Delete") : _("New");

    mNewDelCharButton = new Button(tempString, "newdel", this);

    ContainerPlacer place;
    place = getPlacer(30, 20);
    place(0, 0, mAccountNameLabel);
    place(0, 1, mChangePasswordButton);
    place = getPlacer(30, 21);
    place(0, 0, mPlayerBox, 1, 6).setPadding(3);
    place(1, 0, mNameLabel, 5);
    place(1, 1, mLevelLabel, 5);
    place(1, 2, mJobLevelLabel, 5);
    place(1, 3, mMoneyLabel, 5);
    place(1, 4, mNewDelCharButton);
    place.getCell().matchColWidth(1, 4);
    place = getPlacer(30, 22);
//    place(0, 0, mPreviousButton);
//    place(1, 0, mNextButton);
    place(4, 0, mCancelButton);
    place(5, 0, mSelectButton);

    reflowLayout(370, 390);
#endif
    setSize(573,507);

    center();
    setVisible(true);
    mSelectButton->requestFocus();
    updatePlayerInfo();

    hWindow = new HelpWindow;
    hWindow->loadFile("charselect");
    hWindow->setVisible(true);
    hWindow->setSize(400,200);
    hWindow->setPosition(0,getParent()->getHeight()-200);
    requestMoveToTop();
}

CharSelectDialog::~CharSelectDialog()
{
    delete hWindow;
}

void CharSelectDialog::action(const gcn::ActionEvent &event)
{
#ifdef TMWSERV_SUPPORT
    // The pointers are set to NULL if there is no character stored
    if (event.getId() == "ok" && (mCharInfo->getEntry()))
#else
    if (event.getId() == "ok" && n_character > 0)
#endif
    {
        // Start game
#ifdef TMWSERV_SUPPORT
        mNewCharButton->setEnabled(false);
        mDelCharButton->setEnabled(false);
        mUnRegisterButton->setEnabled(false);
#else
        mNewDelCharButton->setEnabled(false);
#endif
        mSelectButton->setEnabled(false);
        mPreviousButton->setEnabled(false);
        mNextButton->setEnabled(false);
        mCharSelected = true;
        attemptCharSelect();
    }
    else if (event.getId() == "cancel")
    {
#ifdef TMWSERV_SUPPORT
        mCharInfo->clear();
        state = STATE_SWITCH_ACCOUNTSERVER_ATTEMPT;
#else
        state = STATE_EXIT;
#endif
    }
#ifdef TMWSERV_SUPPORT
    else if (event.getId() == "new")
    {
        // TODO: Search the first free slot, and start CharCreateDialog
        //       maybe add that search to the constructor.
        if (!(mCharInfo->getEntry()))
        {
            // Start new character dialog
            hWindow->clearText();
            hWindow->loadFile("charcreate");

            CharCreateDialog *charCreateDialog =
                new CharCreateDialog(this, mCharInfo->getPos());
            Net::getCharHandler()->setCharCreateDialog(charCreateDialog);
        }
    }
    else if (event.getId() == "delete")
    {
        // Delete character
        if (mCharInfo->getEntry())
        {
            new CharDeleteConfirm(this);
        }
    }
#else
    else if (event.getId() == "newdel")
    {
        // Check for a character
        if (mCharInfo->getEntry())
        {
            new CharDeleteConfirm(this);
        }
        else if (n_character <= maxSlot)
        {
            // Start new character dialog
            hWindow->clearText();
            hWindow->loadFile("charcreate");

            CharCreateDialog *charCreateDialog =
                new CharCreateDialog(this, mCharInfo->getPos());
            Net::getCharHandler()->setCharCreateDialog(charCreateDialog);
        }
    }
#endif
    else if (event.getId() == "previous")
    {
        mCharInfo->prev();
        LocalPlayer *pi = mCharInfo->getEntry();
        if (pi)
            mMoney = Units::formatCurrency(pi->getMoney());
    }
    else if (event.getId() == "next")
    {
        mCharInfo->next();
        LocalPlayer *pi = mCharInfo->getEntry();
        if (pi)
            mMoney = Units::formatCurrency(pi->getMoney());
    }
    else if (event.getId() == "change_password")
    {
        new ChangePasswordDialog(this, mLoginData);
    }
#ifdef TMWSERV_SUPPORT
    else if (event.getId() == "unregister")
    {
        new UnRegisterDialog(this, mLoginData);
    }
    else if (event.getId() == "change_email")
    {
        new ChangeEmailDialog(this, mLoginData);
    }
#endif
}

void CharSelectDialog::updatePlayerInfo()
{
    LocalPlayer *pi = mCharInfo->getEntry();

    if (pi)
    {
        mNameLabel->setCaption(strprintf(_("Name: %s"),
                                          pi->getName().c_str()));
        mLevelLabel->setCaption(strprintf(_("Level: %d"), pi->getLevel()));
#ifdef EATHENA_SUPPORT
        mJobLevelLabel->setCaption(strprintf(_("Job Level: %d"),
                                              pi->getAttributeBase(JOB)));
#endif
        mMoneyLabel->setCaption(strprintf(_("Money: %s"), mMoney.c_str()));
        if (!mCharSelected)
        {
#ifdef TMWSERV_SUPPORT
            mNewCharButton->setEnabled(false);
            mDelCharButton->setEnabled(true);
#else
            mNewDelCharButton->setCaption(_("Delete"));
#endif
            mSelectButton->setEnabled(true);
        }
    }
    else
    {
        mNameLabel->setCaption(strprintf(_("Name: %s"), ""));
        mLevelLabel->setCaption(strprintf(_("Level: %d"), 0));
#ifndef TMWSERV_SUPPORT
        mJobLevelLabel->setCaption(strprintf(_("Job Level: %d"), 0));
#endif
        mMoneyLabel->setCaption(strprintf(_("Money: %s"), ""));
#ifdef TMWSERV_SUPPORT
        mNewCharButton->setEnabled(true);
        mDelCharButton->setEnabled(false);
#else
        mNewDelCharButton->setCaption(_("New"));
#endif
        mSelectButton->setEnabled(false);
    }

    mPlayerBox->setPlayer(pi);
}


void
CharSelectDialog::draw(gcn::Graphics *graphics)
{
    Graphics *g = static_cast<Graphics*>(graphics);
    g->drawImage(mBackGround,0,0);

    drawChildren(graphics);
}

void CharSelectDialog::attemptCharDelete()
{
    Net::getCharHandler()->deleteCharacter(mCharInfo->getPos(), mCharInfo->getEntry());
    mCharInfo->lock();
}

void CharSelectDialog::attemptCharSelect()
{
    Net::getCharHandler()->chooseCharacter(mCharInfo->getPos(), mCharInfo->getEntry());
    mCharInfo->lock();
}

void CharSelectDialog::logic()
{
    updatePlayerInfo();
}

bool CharSelectDialog::selectByName(const std::string &name)
{
    if (mCharInfo->isLocked())
        return false;

    unsigned int oldPos = mCharInfo->getPos();

    mCharInfo->select(0);
    do
    {
        LocalPlayer *player = mCharInfo->getEntry();

        if (player && player->getName() == name)
	{
	    mMoney = Units::formatCurrency(player->getMoney());
            return true;
	}

        mCharInfo->next();
    } while (mCharInfo->getPos());

    mCharInfo->select(oldPos);

    return false;
}
