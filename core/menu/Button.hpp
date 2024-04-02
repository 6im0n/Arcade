/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.hpp
*/

#pragma once
#include "Interfaces/IEntity.hpp"
#include "classes/Color.hpp"

namespace Arcade {
class Button : public IEntity {
        public :
            Button(std::string label, std::vector<std::size_t> pos, std::vector<std::size_t> size, char c, std::string path = "", float rotation = 0);
            ~Button() override;

            //setters
            void setPos(std::size_t x, std::size_t y) override;
            void setSize(std::size_t x, std::size_t y) override;
            void setChar(char c) override;
            void setColor(std::unique_ptr<IColor> color) override;
            void setPath(const std::string &path) override;
            void setRotation(float rotation) override;

            //getters
            std::vector<std::size_t> getPos() const override;
            std::vector<std::size_t> getSize() const override;
            int getChar() const override;
            std::shared_ptr<IColor> getColor() const override;
            std::string getPath() const override;
            float getRotation() const override;

            //methods
            std::string getLabel() const;
            void setNextButton(Button *nextButton);
            void setPrevButton(Button *prevButton);
            void setUpButton(Button *upButton);
            void setDownButton(Button *downButton);
            Button *getNextButton() const;
            Button *getPrevButton() const;
            Button *getUpButton() const;
            Button *getDownButton() const;
        private :
            std::vector<std::size_t> _pos;
            std::vector<std::size_t> _size;
            char _char;
            std::shared_ptr<IColor> _color;
            std::string _path;
            float _rotation;

            //button only
            const std::string _label;
            Button *_nextButton;
            Button *_prevButton;
            Button *_upButton;
            Button *_downButton;
            bool _destroy;
    };
}
