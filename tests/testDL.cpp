#include "core/Core.hpp"
#include "Interfaces/IGame.hpp"
#include "Interfaces/IGraphic.hpp"
#include "Interfaces/IEntity.hpp"
#include "Interfaces/IText.hpp"
#include "Interfaces/ISound.hpp"
#include "testDL.hpp"

testGame *entryPointGame()
{
    return new testGame(testGood);
}

testGraphic *entryPointGraphic()
{
    return new testGraphic(testGood);
}
