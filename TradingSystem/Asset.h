#include<iostream>
#include<string>
using namespace std;

#ifndef ASSET_H
#define ASSET_H

#pragma once

class Asset {
public:
    Asset();
    Asset(int id, const string& name, const string& parentPair, const string& childPair, float totalAssets);
    ~Asset();

    int getId() const;
    void setId(int id);

    string getName() const;
    void setName(const string& name);

    string getParentPair() const;
    void setParentPair(const string& parentPair);

    std::string getChildPair() const;
    void setChildPair(const string& childPair);

    float getTotalAssets() const;
    void setTotalAssets(float totalAssets);

private:
    int id;
    string name;
    string parentPair;
    string childPair;
    float totalAssets;
};

#endif