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

static void generateWallLine(std::vector<std::shared_ptr<IEntity>> &line, int y, int size)
{
    for (int i = 0; i < size; i++) {
        std::shared_ptr<Wall> wall = std::make_shared<Wall>(i + START_WIDTH, y + START_HEIGHT);
        line.push_back(wall);
    }
}

static void generateLine(std::vector<std::shared_ptr<IEntity>> &line, int y, int size)
{
    std::shared_ptr<Wall> wall = std::make_shared<Wall>(START_WIDTH, y + START_HEIGHT);
    line.push_back(wall);
    for (int i = 1; i < size - 1; i++) {
        std::shared_ptr<Void> void_case = std::make_shared<Void>(i + START_WIDTH, y + START_HEIGHT);
        line.push_back(void_case);
    }
    std::shared_ptr<Wall> wall2 = std::make_shared<Wall>(size - 1 + START_WIDTH, y + START_HEIGHT);
    line.push_back(wall2);
}

std::vector<std::vector<std::shared_ptr<IEntity>>> genMap()
{
    std::vector<std::vector<std::shared_ptr<IEntity>>> map;

    for (int i = 0; i < 15; i++) {
        std::vector<std::shared_ptr<IEntity>> line;
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
    Snake snake;
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities = snake.getSnake();

    cr_assert_eq(snakeEntities.size(), 4, "Expected 4, got %lu", snakeEntities.size());
}

Test(Snake, MoveTooSpeed)
{
    Snake snake;
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<IEntity>>> map = genMap();

    auto headpos = snakeEntities[0]->getPos();
    snake.setDirection(D_RIGHT);
    cr_assert_eq(snake.moveSnake(map), 0);
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos(), headpos, "Expected %d %d, got %d %d", headpos[0], headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveNormalyRight)
{
    Snake snake;
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<IEntity>>> map = genMap();

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(D_RIGHT);
    cr_assert_eq(snake.moveSnake(map), 0);
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0] + 1, "Expected %d %d, got %d %d", headpos[0] + 1, headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveNormalyLeft)
{
    Snake snake;
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<IEntity>>> map = genMap();

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(D_LEFT);
    cr_assert_eq(snake.moveSnake(map), 0);
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0] - 1, "Expected %d %d, got %d %d", headpos[0] - 1, headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveNormalyDown)
{
    Snake snake;
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<IEntity>>> map = genMap();

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(D_DOWN);
    cr_assert_eq(snake.moveSnake(map), 0);
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[1], headpos[1] + 1, "Expected %d %d, got %d %d", headpos[0], headpos[1] + 1, snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveNormalyUp)
{
    Snake snake;
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<IEntity>>> map = genMap();

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(D_UP);
    cr_assert_eq(snake.moveSnake(map), 0);
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[1], headpos[1] - 1, "Expected %d %d, got %d %d", headpos[0], headpos[1] - 1, snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveWithWallDirRight)
{
    Snake snake;
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<IEntity>>> map = genMap();

    map[17 - START_HEIGHT][15 - START_WIDTH] = std::make_shared<Wall>(17, 15);

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(D_RIGHT);
    cr_assert_eq(snake.moveSnake(map), -1);
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0], "Expected %d %d, got %d %d", headpos[0], headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveWithWallDirLeft)
{
    Snake snake;
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<IEntity>>> map = genMap();

    map[17 - START_HEIGHT][13 - START_WIDTH] = std::make_shared<Wall>(17, 13);

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(D_LEFT);
    cr_assert_eq(snake.moveSnake(map), -1);
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0], "Expected %d %d, got %d %d", headpos[0], headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveWithWallDirUp)
{
    Snake snake;
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<IEntity>>> map = genMap();

    map[16 - START_HEIGHT][14 - START_WIDTH] = std::make_shared<Wall>(16, 14);

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(D_UP);
    cr_assert_eq(snake.moveSnake(map), -1);
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0], "Expected %d %d, got %d %d", headpos[0], headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, MoveWithWallDirDown)
{
    Snake snake;
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities = snake.getSnake();
    std::vector<std::vector<std::shared_ptr<IEntity>>> map = genMap();

    map[18 - START_HEIGHT][14 - START_WIDTH] = std::make_shared<Wall>(18, 14);

    auto headpos = snakeEntities[0]->getPos();
    sleep(1);
    snake.setDirection(D_DOWN);
    cr_assert_eq(snake.moveSnake(map), -1);
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities2 = snake.getSnake();
    cr_assert_eq(snakeEntities.size(), 4);
    cr_assert_eq(snakeEntities2.size(), 4);
    cr_assert_eq(snakeEntities2[0]->getPos()[0], headpos[0], "Expected %d %d, got %d %d", headpos[0], headpos[1], snakeEntities2[0]->getPos()[0], snakeEntities2[0]->getPos()[1]);
}

Test(Snake, Grow)
{
    Snake snake;
    std::vector<std::shared_ptr<SnakeBody>> snakeEntities;

    snake.growSnake();

    snakeEntities = snake.getSnake();

    cr_assert_eq(snakeEntities.size(), 5, "Expected 5, got %lu", snakeEntities.size());
}
