#ifndef EXPRTREE_H
#define EXPRTREE_H
#include "BinaryTreeNode.h"
#include "exception"
#include <fstream>

struct ExprNode
{
    double currValue;
    char oper;
};

class incorrectExpressionExc{};
class divisionByZeroExc{};

class ExprTree
{
public:
    ExprTree(double value = 0, char currOper = ' ');

    ~ExprTree()
    {
        delete root;
    }
    /**
     * @brief treeRoot returns pointer to expression tree root
     * @return BinaryTreeNode<ExprNode>*
     */
    BinaryTreeNode<ExprNode>* treeRoot()
    {
        return root;
    }

    void addLeft(BinaryTreeNode<ExprNode>* place, BinaryTreeNode<ExprNode>* node)
    {
        place->setLeft(node);
    }

    void addLeft(BinaryTreeNode<ExprNode>* place, double value = 0, char currOper = ' ')
    {
        ExprNode newNode;
        newNode.currValue = value;
        newNode.oper = currOper;
        BinaryTreeNode<ExprNode>* node  = new BinaryTreeNode<ExprNode>(newNode);
        addLeft(place,node);
    }

    void addRight(BinaryTreeNode<ExprNode>* place, BinaryTreeNode<ExprNode>* node)
    {
        place->setRight(node);
    }

    void addRight(BinaryTreeNode<ExprNode>* place, double value = 0, char currOper = ' ')
    {
        ExprNode newNode;
        newNode.currValue = value;
        newNode.oper = currOper;
        BinaryTreeNode<ExprNode>* node  = new BinaryTreeNode<ExprNode>(newNode);
        addRight(place,node);
    }

    double count() throw (incorrectExpressionExc)
    {
        return count(root);
    }

    /**
     * @brief parce
     *parcing expression to expression tree from file stream
     * @param exprStream ifstream source of expression to parce
     * @param outStream ofstream for dubug info
     */
    void parce(std::ifstream &exprStream, std::ofstream &outStream) throw (incorrectExpressionExc)
    {
        parce(exprStream, outStream, root);
    }

    /**
     * @brief printExprTree
     *print parced expression to target ofstream
     * @param outStream target ofstream
     */
    void printExprTree(std::ofstream &outStream)
    {
        printExprTree(outStream, root);
        outStream << std::endl;
    }

private:
    BinaryTreeNode<ExprNode>* root;

    double count(BinaryTreeNode<ExprNode>* currentRoot) throw (incorrectExpressionExc);

    void parce(std::ifstream &exprStream, std::ofstream &outStream, BinaryTreeNode<ExprNode> *place) throw (incorrectExpressionExc);

    double makeOperation(double lOperand, char oper, double rOperand) throw(divisionByZeroExc, incorrectExpressionExc);

    void printExprTree(std::ofstream &outStream, BinaryTreeNode<ExprNode> *source);


};

#endif // EXPRTREE_H
