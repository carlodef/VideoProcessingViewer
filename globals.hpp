#pragma once

#include <vector>

namespace sf {
    class RenderWindow;
}

struct Sequence;
struct View;
struct Player;
struct Window;
struct Colormap;

extern sf::RenderWindow* SFMLWindow;
extern std::vector<Sequence*> gSequences;
extern std::vector<View*> gViews;
extern std::vector<Player*> gPlayers;
extern std::vector<Window*> gWindows;
extern std::vector<Colormap*> gColormaps;

