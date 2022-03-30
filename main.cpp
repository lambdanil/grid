#include<iostream>
#include<vector>


void print_grid(std::string grid, int width, int height, bool Numbered) {
    std::string toprint;
    int index;
    bool addSpace = true;
    if (Numbered) {
        for (int i = 0; i < width; i++) {
            if (i < 10) {
                std::cout << " " << i+1; }
            else {
                std::cout << i+1; }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < height; i++) {
        toprint = "";
        for (int si = 0; si < width; si++) {
            addSpace = true;
            if (Numbered && si == 0) {
                std::cout << i+1;
                if (i+1 > 9) {
                    addSpace = false;
                }
            }
            if (addSpace) {
                toprint += " ";
            }
            toprint += (grid[i*si]);
        }
        std::cout << toprint << std::endl;
    }
}

std::string add_to_grid(std::string grid, int x, int y) {
    int total = (x-1)*(y-1);
    grid[total] = '.';
    return grid;
}

int main() {
    std::vector<char> grid;
    int width = 20;
    int height = 20;
    int total = width*height;
    for (int i = 0; i < total; i++) {
        grid.push_back('#');
    }
    std::string grid_str = "";
    for (int i = 0; i<(total); i++) {
        grid_str += (grid[i]);
    }
    grid_str = add_to_grid(grid_str, 8, 8);
    print_grid(grid_str, width, height, true);
}
