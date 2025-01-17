#ifndef SIMILASYONPENCERESI_H
#define SIMILASYONPENCERESI_H

#include <guichan/widgets/window.hpp>
#include <guichan/actionlistener.hpp>
#include <guichan/graphics.hpp>
#include <guichan/widgets/label.hpp>
#include <libxml/xmlwriter.h>
#include <vector>
#include <map>

#include "../resources/animation.h"
#include "../resources/image.h"
#include "../resources/resourcemanager.h"
#include "../resources/imageset.h"
#include "../resources/iteminfo.h"

#include "gui/gui.h"
#include "gui/widgets/window.h"
#include "gui/widgets/button.h"
#include "gui/widgets/chattab.h"
#include "gui/widgets/scrollarea.h"
#include "gui/widgets/listbox.h"
#include "gui/widgets/textbox.h"
#include "gui/widgets/textfield.h"
#include "gui/widgets/radiobutton.h"
#include "gui/widgets/dropdown.h"
#include "gui/widgets/browserbox.h"

#include "utils/xml.h"
#include "utils/stringutils.h"
#include "utils/gettext.h"
#include "./typedef.h"
#include "./bitbutton.h"

#include "kutle.h"
#include "simpleanimation.h"
#include "kaldirac.h"
#include "item.h"
#include "log.h"


class SimilasyonPenceresi : public Window, public gcn::ActionListener
{
    public:
        SimilasyonPenceresi();
        virtual ~SimilasyonPenceresi();
        void action(const gcn::ActionEvent &event);
        void draw(gcn::Graphics *graphics);
        void nesneleriAyarla();
        void nesneyiAl(Item *it);
        void parseXML(std::string mDoc);
        void clearComponent();
        void kontrolEt();
        int findEmptyID();
        bool getPencereDurum();
        bool getKontrolEtDurum();
        void setKontrolEtDurum(bool durum);

        int kefe1,kefe2,kefe3;
        std::map<int,std::vector<int> > idKefe;
        std::map<int,std::vector<int> >::iterator idKefeIt;

        //Penceredeki bütün kütleleri tutan vektör
        std::vector<Kutle*> mvKutle;
        std::vector<Kutle*>::iterator miKutle;

        //Sadece kefelerdeki kütleleri tutan vektör
        std::vector<Kutle*> mvKutleKefe;
        std::vector<Kutle*>::iterator miKutleKefe;
    protected:
    private:
        bool startCancelDurum;
        bool kontrolEtDurum;

        Button *mCancel;
        Button *mClose;
        Button *mStart;
        Button *mControl;

        BrowserBox *mCevap;
        BrowserBox *mSoru;
        ScrollArea *mSoruArea;

        Kutle *nesne;
        Kaldirac *mKaldirac;

        std::vector<Kaldirac*> mvKaldirac;
        std::vector<Kaldirac*>::iterator miKaldirac;

        TmvAnim mvAnim;
        TmiAnim miAnim;

        xmlDocPtr mxmlDoc;
        xmlNodePtr rootNode;

        bool nesneDurum;
        bool pencereDurum;
};
#endif // SIMILASYONPENCERESI_H
