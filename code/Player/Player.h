//
// Created by Meiyi Luan on 2020-02-09.
//
#include <iostream>;
#include <vector>;
#ifndef COMP_345_PLAYER_H
#define COMP_345_PLAYER_H
using namespace std;
class Player{
    private:
        string* name;
        VGB* vgb;
        std::vector <Tile*> *tiles;
        vector <Building*> *buildings;
        ResourceMarker* rms [4];
        RescourcesGather* rg;
        BSF* bsf;
        int* order;

    public:
        //default constructor
        Player();
        //constructor
        Player(string* name,int* order);
        //destructor
        ~Player();

        //show tiles
        string showTiles();
        //show buildings
        string showBuildings();
        // show resource markers
        string showResourceMarkers();

        //fuctions on moodle
        bool PlaceHarvestTile(Tile* tile);
        void DrawBuilding();
        Tile* DrawHarvestTile();
        string ResourcesTracker();
        bool BuildingVillage();
        int [] CalculateResoureces();


};
#endif //COMP_345_PLAYER_H
