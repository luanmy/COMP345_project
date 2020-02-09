//
// Created by Meiyi Luan on 2020-02-09.
//
#include "Player.h";
#include <iostream>;
#include <string>;
using namespace std;
//default constructor
Player::Player(){
    name = nullptr;
    vgb= new VGB ();


    rms = new ResourceMarker[4];
    rg = new ResourcesGather;
    bsf = new BSF;
    order = nullptr;
}

//parametrized constructor
Player:: Player(string* name, int* order ) {
    this->name=name;
    vgb= new VGB ();


    rms = new ResourceMarker[4];
    rg = new ResourcesGather;
    bsf = new BSF;
    this->order=order;
}
Player::~Player(){
    delete vgb;
    delete tile;
    delete building;
    delete rm;
    delete rg;
    delete bsf;
}

//print the tile that player has
string Player::showTiles() {
    cout<<"\n";
    for(int i = 0; i < tiles.size; i++){
      cout<<"NO."<<i<<" tile is"<<tiles.at(i).getTile()<<"  ";
    }
}

//print the building cards that player has
string Player::showBuildings() {
    cout<<"\n";
    for(int i = 0; i < buildings.size; i++){
        cout<<"NO."<<i<<" building is"<<buildings.at(i).getTile()<<"  ";
    }
}

//print the location of the resource marker
string Player::showResourceMarkers() {
    for(ResourceMarkers rm: rms){
        cout<<rm.getLocation();
    }
}


//place a tile card on the game board. if the node already have tile return false
bool Player::PlaceHarvestTile(int index, int location) {
    if (index >= tiles.size()) {
        cout<<"\nout of bound";
        return false;
    }
    Land l= GBMaps.getLand(location);
    if(l.getTile() != nullptr){
        cout<<"\you cannot build here";
        return false;
    }
    string s;
    int times;
    while(ture) {
        cout << "do you want to change the direction of tile";
        try{
        cin >> s;}
        catch (exception e){
            cerr<<e.what();
        }
        if(s =='no')
            break;
        cout << "how many time you want to change with clock direction";
        try{
            cin >> times;
        }
        catch(exception e){
            cerr<<e.what();
        }
        for(int i = 0; 0 < times; i++){
            tiles.at(index).changeDirection();
        }
    }
    l.getTile=tiles.at(index);
    tiles.erase(index);
    return true;

}


//draw building
void Player::DrawBuilding() {
    Building n = buildingDeck.draw();
    buildings.add(n);
    cout<<"\nyou draw building "+ n;
}

//draw tile
void Player::DrawHarvestTile() {
    Tile t = tileDeck.draw();
    tiles.add(t);
    cout<<"\nyour draw tile "+ t;
}

//build building
bool Player::BuildingVillage(int index, int location) {
    if (index >= buildings.size()) {
        cout<<"\nout of bound";
        return false;
    }
    Land l= VGMaps.getLand(location);
    if(l.getBuilding() != nullptr){
        cout<<"\nyou cannot build there";
        return false;
    }
    l.getBuilding=buildings.at(index);
    buildings.erase(index);
    return true;
}

//calcaulate resources
int*  Player::CalculateResoureces() {
    int* arr = new int[4];
    arr[0]=rg.countWheet();
    arr[1]=rg.countSheep();
    arr[2]=rg.countStone();
    arr[3]=rg.countTimber();
    return arr;
}



