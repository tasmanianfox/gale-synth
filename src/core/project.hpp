#ifndef _GALE_CORE_PROJECT_PROJECT_H_
#define _GALE_CORE_PROJECT_PROJECT_H_

#include <vector>

#include "node/node.hpp"

using namespace std;

namespace Gale
{

/**
 * 
 */
class Project
{
public:
    void addNode(Node* node);
private:
    vector<Node*> nodes;
};

}

#endif