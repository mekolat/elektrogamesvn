#include "missionwindow.h"

#include <SDL_mouse.h>

#include <guichan/widgets/label.hpp>

#include "gui/widgets/button.h"
#include "gui/gui.h"
#include "gui/viewport.h"
#include "elektro/bitbutton.h"
#include "elektro/imagewidget.h"

#include "../game.h"
//#include "../engine.h"
//#include "../particle.h"
//#include "../map.h"

#include "utils/stringutils.h"
#include "../resources/resourcemanager.h"
#include "../graphics.h"
#include "log.h"


#include "utils/xml.h"
#include <libxml/xmlwriter.h>

MissionWindow::MissionWindow():
    Window("Mission")
{
    setResizable(false);
    setDefaultSize(1010-400, 754-300, 400, 300);
    loadWindowState();
    setResizable(true);

    mContainerSub = new Container();
    mContainerSub->setDimension(gcn::Rectangle(0,0,250,300));
    mContainerSub->setOpaque(false);

    mContainerMain = new Container();
    mContainerMain->setDimension(gcn::Rectangle(0,0,145,380));
    mContainerMain->setOpaque(false);

    mContainerExp = new Container();
    mContainerExp->setDimension(gcn::Rectangle(0,0,145,100));
    mContainerExp->setOpaque(false);

    mScrollSub = new ScrollArea(mContainerSub);
    mScrollSub->setDimension(gcn::Rectangle(130,50,getWidth()-140,getHeight()-180));
    mScrollSub->setOpaque(false);
    mContainerSub->addActionListener(this);
    add(mScrollSub);

    mScrollMain = new ScrollArea(mContainerMain);
    mScrollMain->setDimension(gcn::Rectangle(0,10,135,getHeight()-50));
    mScrollMain->setOpaque(false);
    mContainerMain->addActionListener(this);
    add(mScrollMain);

    mScrollExp = new ScrollArea(mContainerExp);
    mScrollExp->setDimension(gcn::Rectangle(130,150,getWidth()-140,getHeight()-250));
    mScrollExp->setOpaque(false);
    mContainerExp->addActionListener(this);
    add(mScrollExp);

    ResourceManager *resman = ResourceManager::getInstance();
    mBackgroundPattern = resman->getImage("graphics/elektrik/gorev_background.png");

    setVisible(true);
    addMainMission("Eğitim Odası");
    addMainMission("Devre Tamamlama");
    addMainMission("Akım bulma");
    addMainMission("Gerilim bulma");
    putMissionButtons();

    TextBox *tl = new TextBox();
    tl->setText("Test npcleri eğitimi");
    tl->setWidth(100);
    tl->setOpaque(true);
    tl->setBackgroundColor(gcn::Color(156,184,184));
    tl->setVisible(false);
    mContainerSub->add(tl);

    TextBox *tl1 = new TextBox();
    tl1->setText("Robot dönüştürme eğitimi noexp");
    tl1->setWidth(100);
    tl1->setOpaque(true);
    tl1->setBackgroundColor(gcn::Color(156,184,184));
    tl1->setVisible(false);
    mContainerSub->add(tl1);

    TextBox *tl2 = new TextBox();
    tl2->setText("Kablo bağlama");
    tl2->setWidth(100);
    tl2->setOpaque(true);
    tl2->setBackgroundColor(gcn::Color(156,184,184));
    tl2->setVisible(false);
    mContainerSub->add(tl2);

    TextBox *tl3 = new TextBox();
    tl3->setWidth(100);
    tl3->setText("Item yerleştirme");
    tl3->setOpaque(true);
    tl3->setBackgroundColor(gcn::Color(156,184,184));
    tl3->setVisible(false);
    mContainerSub->add(tl3);

    BrowserBox *tt = new BrowserBox();
    tt->addRow("soranCan'a git");
    tt->addRow("onu yap ");
    tt->addRow("bunu yap");
    tt->addRow("falan filan");
    tt->setDimension(gcn::Rectangle(120,150,100,5));
    tt->setVisible(false);
    mContainerSub->add(tt);

    SmSubMission *ts = new SmSubMission;
    ts->oneTarget =tl;
    ts->oneExplain = tt;
    addSubMission("Eğitim Odası", ts);

    SmSubMission *ts1 = new SmSubMission;
    ts1->oneTarget =tl1;
    ts1->oneExplain = NULL;
    addSubMission("Eğitim Odası", ts1);

    SmSubMission *ts2 = new SmSubMission;
    ts2->oneTarget =tl2;
    ts2->oneExplain = tt;
    addSubMission("Eğitim Odası", ts2);

    SmSubMission *tss = new SmSubMission;
    tss->oneTarget =tl3;
    tss->oneExplain = tt;
    addSubMission("Devre Tamamlama", tss);

    s1 = new Button("Deneme","deneme",this);
    s1->setDimension(gcn::Rectangle(120,0,50,250));
    s1->showPart(gcn::Rectangle(10,70,10,10));

ImageWidget *im = new ImageWidget("elektrik/dugme.png");
im->setPosition(120,30);
mContainerSub->add(im);

//add(s1);
hideSubMissions();
//viewOneMission("Eğitim Odası");
    putSubMission();
    setVisible(false);
}

void
MissionWindow::logic()
{
Window::logic();
}

void
MissionWindow::draw(gcn::Graphics* graphics)
{
    Window::draw(graphics);
    Graphics *g = static_cast<Graphics*>(graphics);
//    g->drawRescaledImage(mBackgroundPattern,
//                     0,0,120,10,
//                     mBackgroundPattern->getWidth(),mBackgroundPattern->getHeight(),
//                     getWidth()-130,getHeight()-30,false);
    g->drawImage(mBackgroundPattern,0,0);
    drawChildren(graphics);
}

void
MissionWindow::action(const gcn::ActionEvent &event)
{
    //ResourceManager *resman = ResourceManager::getInstance();
logger->log("action :%s",event.getId().c_str());
    if (event.getId() == "close")
    {
        setVisible(false);
    }
    for(TMainMissionsIter mit = mMainMission.begin(); mit != mMainMission.end(); ++mit)
    {

        SmMainMission *temp;
        temp = mit->second;
        if (mit->first == event.getId())
        {
            hideSubMissions();
            if (temp->subMissions.size() != 0)
                viewOneMission(event.getId());
                mScrollSub->setVerticalScrollAmount(0);
        }
    }

}

void
MissionWindow::clearMissions()
{
//    for(mSubMissionsIter = mSubMissions.begin(); mSubMissionsIter != mSubMissions.end(); mSubMissionsIter++)
//    {
//        delete (*mSubMissionsIter)->oneTarget;
//        delete (*mSubMissionsIter)->oneExplain;
//        ResourceManager *resman = ResourceManager::getInstance();
//        (*mSubMissionsIter)->oneImage->decRef();
//    }
}

void
MissionWindow::addSubMission(std::string mainname, SmSubMission *one)
{
    logger->log("addSubMission");
    TSubMissions *temp;
    SmMainMission *mn = mMainMission[mainname];
    mn->subMissions.push_back(one);
}

void
MissionWindow::addMainMission(std::string one)
{
    logger->log("addMainMission");
    Button *tmp = new Button(one,one,this);
    add(tmp);
    SmMainMission *smtmp = new SmMainMission;
    smtmp->mainButton = tmp;
    mMainMission[one] = smtmp;
}

void
MissionWindow::viewOneMission(std::string one)
{
    logger->log("viewOneMission");
    SmMainMission *temp;
    temp = mMainMission[one];
    TSubMissions subtemp= temp->subMissions;
//    if(subtemp.size() == 0) return;
    for(mSubMissionsIter = subtemp.begin(); mSubMissionsIter != subtemp.end(); mSubMissionsIter++)
    {
        if((*mSubMissionsIter)->oneTarget)
            (*mSubMissionsIter)->oneTarget->setVisible(true);
//            showWidgetPart((*mSubMissionsIter)->oneTarget,gcn::Rectangle(15,15,50,60));
//
//        if((*mSubMissionsIter)->oneExplain)
//            (*mSubMissionsIter)->oneExplain->setVisible(true);

        if((*mSubMissionsIter)->oneVisible)
            (*mSubMissionsIter)->oneVisible = true;
    }
}

void
MissionWindow::putMissionButtons()
{
logger->log(__FUNCTION__);
    int x = 5;
    int y = 10;
    int dy =27;
    for(mMainMissionIter = mMainMission.begin(); mMainMissionIter != mMainMission.end(); mMainMissionIter++)
    {
        SmMainMission *temp;
        temp = mMainMissionIter->second;
        Button *subtemp = temp->mainButton;
        subtemp->setPosition(x,y);
        subtemp->setWidth(110);
        y += dy;
    }
}

void
MissionWindow::drawTree()
{

}

void
MissionWindow::putSubMission()
{
    logger->log(__FUNCTION__);

    for(mMainMissionIter = mMainMission.begin(); mMainMissionIter != mMainMission.end(); mMainMissionIter++)
    {
        int x  = 5;
        int y  = 10;
        int dy = 20;

        SmMainMission *temp;
        temp = mMainMissionIter->second;
        TSubMissions subtemp= temp->subMissions;

        for(mSubMissionsIter = subtemp.begin(); mSubMissionsIter != subtemp.end(); mSubMissionsIter++)
        {
                (*mSubMissionsIter)->oneTarget->setPosition(x,y);
                (*mSubMissionsIter)->oneTarget->setWidth(150);
                (*mSubMissionsIter)->oneTarget->showPart(gcn::Rectangle(0,0,100,5));
            y += dy;
        }
    }
}
void
MissionWindow::hideSubMissions()
{
    logger->log(__FUNCTION__);

    for(mMainMissionIter = mMainMission.begin(); mMainMissionIter != mMainMission.end(); mMainMissionIter++)
    {
        SmMainMission *temp;
        temp = mMainMissionIter->second;
        if (temp ==NULL) continue;
        TSubMissions subtemp= temp->subMissions;
        for(mSubMissionsIter = subtemp.begin(); mSubMissionsIter < subtemp.end(); mSubMissionsIter++)
        {
            if((*mSubMissionsIter)->oneTarget)
                (*mSubMissionsIter)->oneTarget->setVisible(false);

            if((*mSubMissionsIter)->oneExplain)
                (*mSubMissionsIter)->oneExplain->setVisible(false);

            (*mSubMissionsIter)->oneVisible = false;
        }
    }
}

void
MissionWindow::parse(std::string mDoc)
{
    ResourceManager *resman = ResourceManager::getInstance();
    logger->log(mDoc.c_str());

    xmlDocPtr mxmlDoc;
    mxmlDoc=xmlParseMemory(mDoc.c_str(),mDoc.size());
    if (!mxmlDoc)
    {
        localChatTab->chatLog("Bu üstad'ın morali bozuk :(", BY_SERVER);
        localChatTab->chatLog("Bu durumu bir yöneticiye haber versen çok iyi olur.", BY_SERVER);
        return;
    }

    xmlNodePtr rootNode = xmlDocGetRootElement(mxmlDoc);
    if (!rootNode || !xmlStrEqual(rootNode->name, BAD_CAST "mission"))
    {
        localChatTab->chatLog("Bu üstad'ın morali bozuk :(", BY_SERVER);
        localChatTab->chatLog("Bu durumu bir yöneticiye haber versen çok iyi olur.", BY_SERVER);
        return;
    }

    for_each_xml_child_node(node, rootNode)
    {
//         Ana görev
        if (xmlStrEqual(node->name, BAD_CAST "mainmission"))
        {
            std::string mainMisName = XML::getProperty(node, "name", "Ana Görev");
            for_each_xml_child_node(subnode, node)
            {
                if (xmlStrEqual(subnode->name, BAD_CAST "submission"))
                {
                        SmSubMission *tempSub = new SmSubMission;
                        TextBox *tempText = new TextBox();
                        tempText->setText(XML::getProperty(subnode, "label", "Alt görev."));
                        tempText->setWidth(100);
                        tempText->setOpaque(true);
                        tempText->setBackgroundColor(gcn::Color(156,184,184));
                        tempText->setVisible(false);
                }
            }
        }
    }
//
//                }
//                {
//                    mMessageText->addRow(XML::getProperty(subnode, "text", "\n"));
//                }
//                else if (xmlStrEqual(subnode->name, BAD_CAST "effect"))
//                {
//                    std::string effecttype= XML::getProperty(subnode, "type", "particle");
//                    std::string effectname= XML::getProperty(subnode, "name", "dogru1");
//                    std::string effectsound= XML::getProperty(subnode, "sound", "dogru1");
//                    makeEffect(effecttype,effectname,effectsound);
//                }
//            }
//        }


}

