#include "graphnode.h"
#include "graphedge.h"

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode() {
  //// STUDENT CODE

  // TASK 0: Fix segmentation fault
  // delete _chatBot;

  //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}

//  TASK 4: Implement move semantics for GraphEdge ownership
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE

// TASK 5: move semantics to pass ChatBot instance into root node
void GraphNode::MoveChatbotHere(ChatBot chatbot) {
  _chatBot = std::move(chatbot);
  _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(std::move(_chatBot)); // TASK 5: transfer ownerships
  // _chatBot = nullptr;  // invalidate pointer at source
}

//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// STUDENT CODE

  // TASK 4: Return raw pointer to GraphEdge
  return _childEdges[index].get();

  //// EOF STUDENT CODE
}