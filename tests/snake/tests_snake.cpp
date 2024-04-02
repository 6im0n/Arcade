/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** tests_snake
*/

#include <criterion/criterion.h>
#include <unistd.h>

#include "src/snake/Snake.hpp"
#include "src/snake/Entities/Wall.hpp"
#include "src/snake/Entities/Void.hpp"
#include "src/snake/SnakeGame.hpp"

static void generateWallLine(std::vector<std::shared_ptr<Arcade::IEntity>> &line, int y, int size)
{
    for (int i = 0; i < size; i++) {
        std::shared_ptr<Arcade::Wall> wall = std::make_shared<Arcade::Wall>(i + START_WIDTH, y + START_HEIGHT);
        line.push_back(wall);
    }
}

static void generateLine(std::vector<std::shared_ptr<Arcade::IEntity>> &line, int y, int size)
{
    std::shared_ptr<Arcade::Wall> wall = std::make_shared<Arcade::Wall>(START_WIDTH, y + START_HEIGHT);
    line.push_back(wall);
    for (int i = 1; i < size - 1; i++) {
        std::shared_ptr<Arcade::Void> void_case = std::make_shared<Arcade::Void>(i + START_WIDTH, y + START_HEIGHT);
        line.push_back(void_case);
    }
    std::shared_ptr<Arcade::Wall> wall2 = std::make_shared<Arcade::Wall>(size - 1 + START_WIDTH, y + START_HEIGHT);
    line.push_back(wall2);
}

std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> genMap()
{
    std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map;

    for (int i = 0; i < 15; i++) {
        std::vector<std::shared_ptr<Arcade::IEntity>> line;
        map.push_back(line);
    }
    generateWallLine(map[0], 0, 20);
    for (int i = 1; i < 14; i++) {
        generateLine(map[i], i, 20);
    }
    generateWallLine(map[14], 14, 20);
    return map;
}

Test(Snake, DefaultConstructor)
{
    Arcade::Snake snake;
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities = snake.getSnake();

    cr_assert_eq(snakeEntities.size(), 4, "Expected 4, got %lu", snakeEntities.size());
}

Test(Snake, MoveTooSpeed)
{
    Arcade::Snake snake;
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map = genMap();

    auto headpos = snakeEntities[0]->getPos();
    snake.setDirection(Arcade::D_RIGHT);
    cr_assert_eq(snake.moveSnake(map), 0);
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos(), headpos, "Expected %d %d, got %d %d", headpos[0], headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveNormalyRight)
{
    Arcade::Snake snake;
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map = genMap();

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(Arcade::D_RIGHT);
    cr_assert_eq(snake.moveSnake(map), 0);
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0] + 1, "Expected %d %d, got %d %d", headpos[0] + 1, headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveNormalyLeft)
{
    Arcade::Snake snake;
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map = genMap();

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(Arcade::D_UP);
    cr_assert_eq(snake.moveSnake(map), 0);
    sleep(1);
    snake.setDirection(Arcade::D_LEFT);
    cr_assert_eq(snake.moveSnake(map), 0);
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0] - 1, "Expected %d %d, got %d %d", headpos[0] - 1, headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveNormalyDown)
{
    Arcade::Snake snake;
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map = genMap();

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(Arcade::D_DOWN);
    cr_assert_eq(snake.moveSnake(map), -1);
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[1], headpos[1], "Expected %d %d, got %d %d", headpos[0], headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveNormalyUp)
{
    Arcade::Snake snake;
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map = genMap();

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(Arcade::D_UP);
    cr_assert_eq(snake.moveSnake(map), 0);
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[1], headpos[1] - 1, "Expected %d %d, got %d %d", headpos[0], headpos[1] - 1, snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveWithWallDirRight)
{
    Arcade::Snake snake;
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map = genMap();

    map[17 - START_HEIGHT][15 - START_WIDTH] = std::make_shared<Arcade::Wall>(17, 15);

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(Arcade::D_RIGHT);
    cr_assert_eq(snake.moveSnake(map), -1);
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0], "Expected %d %d, got %d %d", headpos[0], headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveWithWallDirLeft)
{
    Arcade::Snake snake;
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map = genMap();

    map[16 - START_HEIGHT][13 - START_WIDTH] = std::make_shared<Arcade::Wall>(16, 13);

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(Arcade::D_UP);
    cr_assert_eq(snake.moveSnake(map), 0);
    sleep(1);
    snake.setDirection(Arcade::D_LEFT);
    cr_assert_eq(snake.moveSnake(map), -1);
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0], "Expected %d %d, got %d %d", headpos[0], headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveWithWallDirUp)
{
    Arcade::Snake snake;
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map = genMap();

    map[16 - START_HEIGHT][14 - START_WIDTH] = std::make_shared<Arcade::Wall>(16, 14);

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(Arcade::D_UP);
    cr_assert_eq(snake.moveSnake(map), -1);
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0], "Expected %d %d, got %d %d", headpos[0], headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveWithWallDirDown)
{
    Arcade::Snake snake;
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map = genMap();

    map[18 - START_HEIGHT][14 - START_WIDTH] = std::make_shared<Arcade::Wall>(18, 14);

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(Arcade::D_DOWN);
    cr_assert_eq(snake.moveSnake(map), -1);
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0], "Expected %d %d, got %d %d", headpos[0], headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, Grow)
{
    Arcade::Snake snake;
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snakeEntities;

    snake.growSnake();

    snakeEntities = snake.getSnake();

    cr_assert_eq(snakeEntities.size(), 5, "Expected 5, got %lu", snakeEntities.size());
}
