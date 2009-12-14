#include "battery.h"

Battery::Battery(gcn::ActionListener *listener, Node *n1, Node *n2):
    Component(listener, n1, n2)
{
    setType(BATTERY);
}

Battery::~Battery()
{
    //dtor
}

void Battery::draw(gcn::Graphics *graphics)
{
    std::string ss="graphics/elektrik/item-pil";

    if (getStatus()==BURNED) ss += "-b";

    ss += ".png";
    Graphics *g = static_cast<Graphics*>(graphics);
    ResourceManager *resman = ResourceManager::getInstance();
    ImageSet *res = resman->getImageSet(ss,32,32);
    g->drawImage(res->get(mAngel),4,4);
    Component::draw(graphics);
}