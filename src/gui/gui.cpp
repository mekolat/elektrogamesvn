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

#include "gui/gui.h"

#include "gui/focushandler.h"
#include "gui/palette.h"
#include "gui/sdlinput.h"
#include "gui/skin.h"
#include "gui/truetypefont.h"
#include "gui/viewport.h"

#include "gui/widgets/window.h"
#include "gui/widgets/windowcontainer.h"

#include "configlistener.h"
#include "configuration.h"
#include "graphics.h"
#include "log.h"

#include "resources/image.h"
#include "resources/imageset.h"
#include "resources/imageloader.h"
#include "resources/resourcemanager.h"

#include <guichan/exception.hpp>
#include <guichan/image.hpp>

// Guichan stuff
Gui *gui = 0;
Viewport *viewport = 0;                    /**< Viewport on the map. */
SDLInput *guiInput = 0;

// Bolded font
gcn::Font *boldFont = 0;
gcn::Font *font_bas_1_20 = 0;
gcn::Font *font_bas_1_18 = 0;
gcn::Font *font_bas_1_16 = 0;
gcn::Font *font_bas_1_14 = 0;
gcn::Font *font_bas_2_20 = 0;
gcn::Font *font_bas_2_18 = 0;
gcn::Font *font_bas_2_16 = 0;
gcn::Font *font_bas_2_14 = 0;
gcn::Font *font_bas_3_18 = 0;
gcn::Font *font_bas_3_16 = 0;
gcn::Font *font_bas_3_14 = 0;
gcn::Font *font_bas_3_12 = 0;
gcn::Font *font_bas_4_16 = 0;
gcn::Font *font_bas_4_14 = 0;
gcn::Font *font_bas_4_12 = 0;
gcn::Font *font_bas_4_10 = 0;
gcn::Font *font_bas_4_8 = 0;
gcn::Font *font_bas_5_16 = 0;
gcn::Font *font_bas_5_14 = 0;
gcn::Font *font_bas_5_12 = 0;
gcn::Font *font_bas_5_10 = 0;
gcn::Font *font_bas_5_8 = 0;
gcn::Font *font_bas_b_1_20 = 0;
gcn::Font *font_bas_b_1_18 = 0;
gcn::Font *font_bas_b_1_16 = 0;
gcn::Font *font_bas_b_1_14 = 0;
gcn::Font *font_bas_b_2_20 = 0;
gcn::Font *font_bas_b_2_18 = 0;
gcn::Font *font_bas_b_2_16 = 0;
gcn::Font *font_bas_b_2_14 = 0;
gcn::Font *font_el_1_14 = 0;
gcn::Font *font_el_1_12 = 0;
gcn::Font *font_el_1_10 = 0;
gcn::Font *font_el_2_14 = 0;
gcn::Font *font_el_2_12 = 0;
gcn::Font *font_el_2_10 = 0;
gcn::Font *font_el_3_14 = 0;
gcn::Font *font_el_3_12 = 0;
gcn::Font *font_el_3_10 = 0;
gcn::Font *font_el_b_1_14 = 0;
gcn::Font *font_el_b_1_12 = 0;
gcn::Font *font_el_b_1_10 = 0;
gcn::Font *font_el_b_2_14 = 0;
gcn::Font *font_el_b_2_12 = 0;
gcn::Font *font_el_b_2_10 = 0;
gcn::Font *font_txt_1_14 = 0;
gcn::Font *font_txt_1_12 = 0;
gcn::Font *font_txt_1_10 = 0;
gcn::Font *font_txt_2_14 = 0;
gcn::Font *font_txt_2_12 = 0;
gcn::Font *font_txt_2_10 = 0;
gcn::Font *font_txt_3_14 = 0;
gcn::Font *font_txt_3_12 = 0;
gcn::Font *font_txt_3_10 = 0;
gcn::Font *font_txt_4_14 = 0;
gcn::Font *font_txt_4_12 = 0;
gcn::Font *font_txt_4_10 = 0;
gcn::Font *font_txt_5_14 = 0;
gcn::Font *font_txt_5_12 = 0;
gcn::Font *font_txt_5_10 = 0;
gcn::Font *font_txt_6_14 = 0;
gcn::Font *font_txt_6_12 = 0;
gcn::Font *font_txt_6_10 = 0;
gcn::Font *font_txt_b_1_14 = 0;
gcn::Font *font_txt_b_1_12 = 0;
gcn::Font *font_txt_b_1_10 = 0;
gcn::Font *font_txt_b_2_14 = 0;
gcn::Font *font_txt_b_2_12 = 0;
gcn::Font *font_txt_b_2_10 = 0;
gcn::Font *font_txt_b_3_14 = 0;
gcn::Font *font_txt_b_3_12 = 0;
gcn::Font *font_txt_b_3_10 = 0;
gcn::Font *font_calibri_14 = 0;
gcn::Font *font_calibri_11 = 0;
gcn::Font *font_calibri_10 = 0;
gcn::Font *font_i_calibri_14 = 0;
gcn::Font *font_i_calibri_11 = 0;
gcn::Font *font_i_calibri_10 = 0;
gcn::Font *font_b_calibri_14 = 0;
gcn::Font *font_b_calibri_11 = 0;
gcn::Font *font_b_calibri_10 = 0;
gcn::Font *font_b_i_calibri_14 = 0;
gcn::Font *font_b_i_calibri_11 = 0;
gcn::Font *font_b_i_calibri_10 = 0;

class GuiConfigListener : public ConfigListener
{
    public:
        GuiConfigListener(Gui *g):
            mGui(g)
        {}

        void optionChanged(const std::string &name)
        {
            if (name == "customcursor")
            {
                bool bCustomCursor = config.getValue("customcursor", 1) == 1;
                mGui->setUseCustomCursor(bCustomCursor);
            }
        }
    private:
        Gui *mGui;
};

Gui::Gui(Graphics *graphics):
    mCustomCursor(false),
    mMouseCursors(NULL),
    mMouseCursorAlpha(1.0f),
    mMouseInactivityTimer(0),
    mmCursorType(CURSOR_POINTER)
{
    logger->log("Initializing GUI...");
    // Set graphics
    setGraphics(graphics);

    // Set image loader
    static ImageLoader imageLoader;
    gcn::Image::setImageLoader(&imageLoader);

    // Set input
    guiInput = new SDLInput;
    setInput(guiInput);

    // Set focus handler
    delete mFocusHandler;
    mFocusHandler = new FocusHandler;

    // Initialize top GUI widget
    WindowContainer *guiTop = new WindowContainer;
    guiTop->setDimension(gcn::Rectangle(0, 0,
                graphics->getWidth(), graphics->getHeight()));
    guiTop->setOpaque(false);
    Window::setWindowContainer(guiTop);
    setTop(guiTop);

    ResourceManager *resman = ResourceManager::getInstance();

    // Set global font
    const int fontSize = (int) config.getValue("fontSize", 11);
    std::string fontFile = branding.getValue("font", "fonts/dejavusans.ttf");
    std::string path = resman->getPath(fontFile);
    try
    {
        mGuiFont = new TrueTypeFont(path, fontSize);
        mInfoParticleFont = new TrueTypeFont(path, fontSize, TTF_STYLE_BOLD);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }

    // Set bold font
    fontFile = branding.getValue("boldFont", "fonts/dejavusans-bold.ttf");
    path = resman->getPath(fontFile);
    try
    {
        boldFont = new TrueTypeFont(path, fontSize);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
/*********************************************************/
/*                    ELEKTRO FONT                       */
/*********************************************************/
    fontFile = "fonts/bas-1.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_bas_1_20 = new TrueTypeFont(path, 20);
        font_bas_1_18 = new TrueTypeFont(path, 18);
        font_bas_1_16 = new TrueTypeFont(path, 16);
        font_bas_1_14 = new TrueTypeFont(path, 14);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/bas-2.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_bas_2_20 = new TrueTypeFont(path, 20);
        font_bas_2_18 = new TrueTypeFont(path, 18);
        font_bas_2_16 = new TrueTypeFont(path, 16);
        font_bas_2_14 = new TrueTypeFont(path, 14);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/bas-3.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_bas_3_18 = new TrueTypeFont(path, 18);
        font_bas_3_16 = new TrueTypeFont(path, 16);
        font_bas_3_14 = new TrueTypeFont(path, 14);
        font_bas_3_12 = new TrueTypeFont(path, 12);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/bas-4.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_bas_4_16 = new TrueTypeFont(path, 16);
        font_bas_4_14 = new TrueTypeFont(path, 14);
        font_bas_4_12 = new TrueTypeFont(path, 12);
        font_bas_4_10 = new TrueTypeFont(path, 10);
        font_bas_4_8 = new TrueTypeFont(path, 8);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/bas-5.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_bas_5_8 = new TrueTypeFont(path, 8);
        font_bas_5_10 = new TrueTypeFont(path, 10);
        font_bas_5_12 = new TrueTypeFont(path, 12);
        font_bas_5_14 = new TrueTypeFont(path, 14);
        font_bas_5_16 = new TrueTypeFont(path, 16);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }

    //---------------------------------------------------

    fontFile = "fonts/bas-b-1.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_bas_b_1_20 = new TrueTypeFont(path, 20);
        font_bas_b_1_18 = new TrueTypeFont(path, 18);
        font_bas_b_1_16 = new TrueTypeFont(path, 16);
        font_bas_b_1_14 = new TrueTypeFont(path, 14);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/bas-b-2.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_bas_b_2_20 = new TrueTypeFont(path, 20);
        font_bas_b_2_18 = new TrueTypeFont(path, 18);
        font_bas_b_2_16 = new TrueTypeFont(path, 16);
        font_bas_b_2_14 = new TrueTypeFont(path, 14);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }

    //-------------------------------------------------

    fontFile = "fonts/el-1.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_el_1_14 = new TrueTypeFont(path, 14);
        font_el_1_12 = new TrueTypeFont(path, 12);
        font_el_1_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/el-2.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_el_2_14 = new TrueTypeFont(path, 14);
        font_el_2_12 = new TrueTypeFont(path, 12);
        font_el_2_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/el-3.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_el_3_14 = new TrueTypeFont(path, 14);
        font_el_3_12 = new TrueTypeFont(path, 12);
        font_el_3_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    //----------------------------------------------------------
    fontFile = "fonts/el-b-1.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_el_b_1_14 = new TrueTypeFont(path, 14);
        font_el_b_1_12 = new TrueTypeFont(path, 12);
        font_el_b_1_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/el-b-2.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_el_b_2_14 = new TrueTypeFont(path, 14);
        font_el_b_2_12 = new TrueTypeFont(path, 12);
        font_el_b_2_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    //---------------------------------------------------------
    fontFile = "fonts/txt-1.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_txt_1_14 = new TrueTypeFont(path, 14);
        font_txt_1_12 = new TrueTypeFont(path, 12);
        font_txt_1_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/txt-2.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_txt_2_14 = new TrueTypeFont(path, 14);
        font_txt_2_12 = new TrueTypeFont(path, 12);
        font_txt_2_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/txt-3.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_txt_3_14 = new TrueTypeFont(path, 14);
        font_txt_3_12 = new TrueTypeFont(path, 12);
        font_txt_3_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/txt-4.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_txt_4_14 = new TrueTypeFont(path, 14);
        font_txt_4_12 = new TrueTypeFont(path, 12);
        font_txt_4_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/txt-5.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_txt_5_14 = new TrueTypeFont(path, 14);
        font_txt_5_12 = new TrueTypeFont(path, 12);
        font_txt_5_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/txt-6.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_txt_6_14 = new TrueTypeFont(path, 14);
        font_txt_6_12 = new TrueTypeFont(path, 12);
        font_txt_6_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    //-------------------------------------------------------
    fontFile = "fonts/txt-b-1.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_txt_b_1_14 = new TrueTypeFont(path, 14);
        font_txt_b_1_12 = new TrueTypeFont(path, 12);
        font_txt_b_1_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/txt-b-2.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_txt_b_2_14 = new TrueTypeFont(path, 14);
        font_txt_b_2_12 = new TrueTypeFont(path, 12);
        font_txt_b_2_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/txt-b-3.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_txt_b_3_14 = new TrueTypeFont(path, 14);
        font_txt_b_3_12 = new TrueTypeFont(path, 12);
        font_txt_b_3_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    //-------------------------------------------------------------
    fontFile = "fonts/txt-calibri.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_calibri_14 = new TrueTypeFont(path, 14);
        font_calibri_11 = new TrueTypeFont(path, 11);
        font_calibri_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/txt-b-calibri.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_b_calibri_14 = new TrueTypeFont(path, 14);
        font_b_calibri_11 = new TrueTypeFont(path, 11);
        font_b_calibri_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/txt-i-calibri.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_i_calibri_14 = new TrueTypeFont(path, 14);
        font_i_calibri_11 = new TrueTypeFont(path, 11);
        font_i_calibri_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }
    fontFile = "fonts/txt-b-i-calibri.ttf";
    path = resman->getPath(fontFile);
    try
    {
        font_b_i_calibri_14 = new TrueTypeFont(path, 14);
        font_b_i_calibri_11 = new TrueTypeFont(path, 11);
        font_b_i_calibri_10 = new TrueTypeFont(path, 10);
    }
    catch (gcn::Exception e)
    {
        logger->error(std::string("Unable to load '") + fontFile +
                      std::string("': ") + e.getMessage());
    }

/* ***************************************************** */



    gcn::Widget::setGlobalFont(mGuiFont);

    // Initialize mouse cursor and listen for changes to the option
    setUseCustomCursor(config.getValue("customcursor", 1) == 1);
    mConfigListener = new GuiConfigListener(this);
    config.addListener("customcursor", mConfigListener);

    // Create the viewport
    viewport = new Viewport;
    viewport->setDimension(gcn::Rectangle(0, 0,
                graphics->getWidth(), graphics->getHeight()));
    guiTop->add(viewport);
}

Gui::~Gui()
{
    config.removeListener("customcursor", mConfigListener);
    delete mConfigListener;

    if (mMouseCursors)
        mMouseCursors->decRef();

    delete mGuiFont;
    delete boldFont;
    delete mInfoParticleFont;
    delete viewport;
    delete getTop();

    delete guiInput;

    SkinLoader::deleteInstance();
}

void Gui::logic()
{
    // Fade out mouse cursor after extended inactivity
    if (mMouseInactivityTimer < 100 * 15)
    {
        ++mMouseInactivityTimer;
        mMouseCursorAlpha = std::min(1.0f, mMouseCursorAlpha + 0.05f);
    }
    else
        mMouseCursorAlpha = std::max(0.0f, mMouseCursorAlpha - 0.005f);

    guiPalette->advanceGradient();

    gcn::Gui::logic();
}

void Gui::draw()
{
    mGraphics->pushClipArea(getTop()->getDimension());
    getTop()->draw(mGraphics);

    int mouseX, mouseY;
    Uint8 button = SDL_GetMouseState(&mouseX, &mouseY);

    if ((SDL_GetAppState() & SDL_APPMOUSEFOCUS || button & SDL_BUTTON(1))
            && mCustomCursor
            && mMouseCursorAlpha > 0.0f)
    {
        Image *mouseCursor = mMouseCursors->get(mmCursorType);
        mouseCursor->setAlpha(mMouseCursorAlpha);

        static_cast<Graphics*>(mGraphics)->drawImage(
                mouseCursor,
                mouseX - 15,
                mouseY - 17);
    }

    mGraphics->popClipArea();
}

void Gui::setUseCustomCursor(bool customCursor)
{
    if (customCursor != mCustomCursor)
    {
        mCustomCursor = customCursor;

        if (mCustomCursor)
        {
            // Hide the SDL mouse cursor
            SDL_ShowCursor(SDL_DISABLE);

            // Load the mouse cursor
            ResourceManager *resman = ResourceManager::getInstance();
            mMouseCursors =
                resman->getImageSet("graphics/gui/mouse.png", 40, 40);

            if (!mMouseCursors)
                logger->error("Unable to load mouse cursors.");
        }
        else
        {
            // Show the SDL mouse cursor
            SDL_ShowCursor(SDL_ENABLE);

            // Unload the mouse cursor
            if (mMouseCursors)
            {
                mMouseCursors->decRef();
                mMouseCursors = NULL;
            }
        }
    }
}

void Gui::handleMouseMoved(const gcn::MouseInput &mouseInput)
{
    gcn::Gui::handleMouseMoved(mouseInput);
    mMouseInactivityTimer = 0;
}
