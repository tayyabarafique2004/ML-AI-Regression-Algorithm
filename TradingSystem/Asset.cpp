#include "Asset.h"
#include<string>

Asset::Asset() : id(0), totalAssets(0.0) {}

Asset::Asset(int id, const string& name, const string& parentPair, const string& childPair, float totalAssets): id(id), name(name), parentPair(parentPair), childPair(childPair), totalAssets(totalAssets) {}

Asset::~Asset() {}

int Asset::getId() const { return id; }
void Asset::setId(int id) { this->id = id; }

string Asset::getName() const { return name; }
void Asset::setName(const string& name) { this->name = name; }

string Asset::getParentPair() const { return parentPair; }
void Asset::setParentPair(const string& parentPair) { this->parentPair = parentPair; }

string Asset::getChildPair() const { return childPair; }
void Asset::setChildPair(const string& childPair) { this->childPair = childPair; }

float Asset::getTotalAssets() const { return totalAssets; }
void Asset::setTotalAssets(float totalAssets) { this->totalAssets = totalAssets; }
