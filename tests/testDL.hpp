#include "core/Core.hpp"
#include "Interfaces/IGame.hpp"
#include "Interfaces/IGraphic.hpp"
#include "Interfaces/IEntity.hpp"
#include "Interfaces/IText.hpp"
#include "Interfaces/ISound.hpp"

int testGood = 0;
int testBad = -1;

class testGame : public arcade::IGame {
    public :
        testGame(int returnValue) {
            this->returnValue = returnValue;
        };
        ~testGame() = default;
        int startGame() override {
            return returnValue;
        };
        int stopGame() override {
            return returnValue;
        };
        int getScore() override{
            return returnValue;
        };
        int simulate() override{
            return returnValue;
        };
        void catchKeyEvent(int key) override {
        };
        std::vector<std::shared_ptr<arcade::IEntity>> getEntities() override {
            return entities;
        };
        std::vector<std::shared_ptr<arcade::IText>> getTexts() override {
            return texts;
        };
        std::vector<std::shared_ptr<arcade::ISound>> getSounds() override {
            return sounds;
        };
    private :
        int returnValue;
        std::vector<std::shared_ptr<arcade::IEntity>> entities;
        std::vector<std::shared_ptr<arcade::IText>> texts;
        std::vector<std::shared_ptr<arcade::ISound>> sounds;
};

class testGraphic : public arcade::IGraphic {
    public :
        testGraphic(int returnValue) {
            this->returnValue = returnValue;
        };
        ~testGraphic() = default;
        bool isWindowOpen() const override{
            return true;
        };
        void closeWindow() override {
        };
        void clearWindow() override {
        };
        int getKeyEvent() override {
            return arcade::Keys::A;
        }
        void displayWindow() override {
        };
        void displayEntities(std::vector<std::shared_ptr<arcade::IEntity>> entities) override {
        };
        void displayText(std::vector<std::shared_ptr<arcade::IText>> texts) override {
        };
        void playSound(std::vector<std::shared_ptr<arcade::ISound>> sounds) override {
        };
    private :
            int returnValue;
};

class testEntity : public arcade::IEntity {
    public :
        testEntity() = default;
        ~testEntity() = default;
        virtual void setPos(std::size_t x, std::size_t y) override {
            pos[0] = x;
            pos[1] = y;
        };
        virtual void setSize(std::size_t x, std::size_t y) override {
            size[0] = x;
            size[1] = y;
        };
        virtual void setChar(char c) override {
            this->c = c;
        };
        virtual void setColor(std::unique_ptr<arcade::IColor> color) override {
            this->color = std::move(color);
        };
        virtual void setPath(const std::string &path) override {
            this->path = path;
        };
        virtual void setRotation(float rotation) override {
            this->rotation = rotation;
        };
        virtual std::vector<std::size_t> getPos() const override {
            return pos;
        };
        virtual std::vector<std::size_t> getSize() const override {
            return size;
        };
        virtual int getChar() const override {
            return c;
        };
        virtual std::shared_ptr<arcade::IColor> getColor() const override {
            return color;
        };
        virtual std::string getPath() const override {
            return path;
        };
        virtual float getRotation() const override {
            return rotation;
        }
    private :
        std::vector<std::size_t> pos;
        std::vector<std::size_t> size;
        char c;
        std::shared_ptr<arcade::IColor> color;
        std::string path;
        float rotation;
};