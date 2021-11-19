#include "RocketFactory.h"

RocketFactory::RocketFactory() {}
RocketFactory::~RocketFactory() {}

FalconRocket *RocketFactory::startFactory()
{
    return createRocket();
}