#pragma once

#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

const string kYourNetID = "aali262";
const string kPathOutOfRegularMaze = "SESWENWNEEESWESWS";
const string kPathOutOfTwistyMaze = "NSENSSWSSEE";


bool isPathToFreedom(MazeCell *start, const string& moves) {
    if (start == nullptr) {
        return false;
    }

    bool hasSpellbook = false;
    bool hasPotion = false;
    bool hasWand = false;

    MazeCell* current = start;

    if (current->whatsHere == "Spellbook") {
        hasSpellbook = true;
    }
    else if (current->whatsHere == "Potion") {
        hasPotion = true;
    }
    else if (current->whatsHere == "Wand") {
        hasWand = true;
    }

    for (char move : moves) {
        switch (move) {
            case 'N':
                if (current->north != nullptr) {
                    current = current->north;
                } else {
                    return false;
                }
                break;
            case 'S':
                if (current->south != nullptr) {
                    current = current->south;
                } else {
                    return false;
                }
                break;
            case 'E':
                if (current->east != nullptr) {
                    current = current->east;
                } else {
                    return false;
                }
                break;
            case 'W':
                if (current->west != nullptr) {
                    current = current->west;
                } else {
                    return false;
                }
                break;
            default:
                return false;
        }

        if (current->whatsHere == "Spellbook") {
            hasSpellbook = true;
        }
        else if (current->whatsHere == "Potion") {
            hasPotion = true;
        }
        else if (current->whatsHere == "Wand") {
            hasWand = true;
        }
    }

    return hasSpellbook && hasPotion && hasWand;
}
