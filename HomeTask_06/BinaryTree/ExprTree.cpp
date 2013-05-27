#include "ExprTree.h"


ExprTree::ExprTree(double value, char currOper)
{
    ExprNode data;
    data.oper = currOper;
    data.currValue = value;
    root = new BinaryTreeNode<ExprNode>(data);
}


void ExprTree::parce(std::ifstream &exprStream, std::ofstream &outStream, BinaryTreeNode<ExprNode> *place)  throw (incorrectExpressionExc)
{
    try
    {
        char bracket = ' ';
        exprStream >> bracket;
        if (bracket != '(')
        {
            if ((bracket >= '0') && (bracket <= '9'))
            {
                exprStream.putback(bracket);
                double value;
                exprStream >> value;

                ExprNode data;
                data.oper = ' ';
                data.currValue = value;
                place->setValue(data);
            }
            else
                throw incorrectExpressionExc();
        }
        else
        {
            char oper = ' ';
            exprStream >> oper;

            ExprNode data;
            data.oper = oper;
            data.currValue = 0;
            place->setValue(data);

            BinaryTreeNode<ExprNode>* leftOperand = new BinaryTreeNode<ExprNode>(data);
            parce(exprStream, outStream, leftOperand);

            BinaryTreeNode<ExprNode>* rightOperand = new BinaryTreeNode<ExprNode>(data);
            parce(exprStream, outStream, rightOperand);

            addLeft(place, leftOperand);
            addRight(place, rightOperand);

            exprStream >> bracket;

            if (bracket != ')')
                throw incorrectExpressionExc();
        }



    }
    catch(incorrectExpressionExc)
    {
        outStream << "Invalid expression" << std::endl;
        throw;
    }
}

double ExprTree::count(BinaryTreeNode<ExprNode> *currentRoot) throw (incorrectExpressionExc)
{
    try
    {
        if (currentRoot->state() == 0)//Нет детей
            return currentRoot->value().currValue;
        else if (currentRoot->state() == 3)//Оба потомка
        {
            ExprNode newNode = currentRoot->value();
            newNode.currValue = makeOperation(count(currentRoot->left()), newNode.oper,count(currentRoot->right()));
            currentRoot->setValue(newNode);
            return newNode.currValue;
        }
        else
            throw incorrectExpressionExc();//Неполное дерево - нехватает операндов

    }
    catch(divisionByZeroExc)
    {
        throw incorrectExpressionExc();
    }
    return 0;
}

double ExprTree::makeOperation(double lOperand, char oper, double rOperand) throw (divisionByZeroExc, incorrectExpressionExc)
{
    {
        if (oper == '+')
            return lOperand + rOperand;
        else if (oper == '-')
            return lOperand - rOperand;
        else if (oper == '*')
            return lOperand * rOperand;
        else if (oper == '/')
            if (rOperand != 0)
                return lOperand / rOperand;
            else
            {
                throw divisionByZeroExc();
                return 0;
            }

        else
        {
            throw incorrectExpressionExc();
            return 0;
        }
    }
}

void ExprTree::printExprTree(std::ofstream &outStream, BinaryTreeNode<ExprNode> *source)
{
    if (source == NULL)
        return;

    if (source->value().oper != ' ')
    {
        outStream << "(";
        outStream << source->value().oper;
        outStream << " ";
        printExprTree(outStream, source->left());
        outStream << " ";
        printExprTree(outStream, source->right());
        outStream << " )";
    }
    else
        outStream << source->value().currValue;

}


